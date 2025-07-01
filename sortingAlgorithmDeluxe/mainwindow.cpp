#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QRandomGenerator>
#include <QBrush>
#include <QColor>
#include <QKeyEvent>
#include <QDoubleValidator>
#include <QPixmap>
#include <QDesktopServices>
#include <cmath>
#include <SFML/Audio.hpp>
#include <QListView>
#include <unordered_set>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SortingAlgorithmDeluxe)
    , scene(new QGraphicsScene(this))
    , timer(new QTimer(this))
    , endTimer(new QTimer(this))
    , endSoundDuration(1000)
    , randomizationDuration(1500)
    , currentIndex(0)
    , endIndex(0)


    , maxFrequency(1000.0f)
    , minFrequency(30)

    , totalItemNumber(1500)
    , stepDelay(1)

    , spacingMultiplier(0.98)
    , itemWidth(10)
    , heightMultiplier(5)
    , topSpaceHeight(100)
    , littleGapToMakeItNice(10)
    , onFirstinitialization(true)
    , isReinitializing(false)
    , currentSortingMethod(0)
{
    ui->setupUi(this);
    ui->sortGraphicView->setScene(scene);


    connect(endTimer, &QTimer::timeout, this, &MainWindow::playSmoothEndSound);

    connect(ui->nerterButton, &QPushButton::clicked, this, &MainWindow::openLink);

    allSortingMethodsStrings = {"Quick Sort", "Merge Sort", "Radix Sort", "Heap Sort", "Shell Sort",
                                "Exchange Sort","Odd-Even Sort", "Circle Sort", "Gravity Sort", "Cycle Sort","Bubble Sort","Shaker Sort", "Insertion Sort",
                                /*"Selection Sort",*/ "Stalin Sort",
                                };


    for (int i = 0; i < allSortingMethodsStrings.size(); i++)
    {
        ui->sortingMethodsComboBox->addItem(allSortingMethodsStrings[i]);
    }


    sortiongFunctions.push_back([this]() { this->QuickSort(); });
    sortiongFunctions.push_back([this]() { this->MergeSort(); });
    sortiongFunctions.push_back([this]() { this->RadixSort(); });
    sortiongFunctions.push_back([this]() { this->HeapSort(); });
    sortiongFunctions.push_back([this]() { this->ShellSort(); });
    sortiongFunctions.push_back([this]() { this->ExchangeSort(); });
    sortiongFunctions.push_back([this]() { this->OddEvenTranspositionSort(); });
    sortiongFunctions.push_back([this]() { this->CircleSort(); });
    sortiongFunctions.push_back([this]() { this->GravitySort(); });
    sortiongFunctions.push_back([this]() { this->CycleSort(); });
    sortiongFunctions.push_back([this]() { this->BubbleSort(); });
    sortiongFunctions.push_back([this]() { this->ShakerSort(); });
    sortiongFunctions.push_back([this]() { this->InsertionSort(); });
    //sortiongFunctions.push_back([this]() { this->SelectionSort(); });
    sortiongFunctions.push_back([this]() { this->StalinSort(); });


    soundBuffer.loadFromSamples(generateSineWaveSound(maxFrequency / 2, 1.0f).data(), 44100, 1, 44100);
    sound.setBuffer(soundBuffer);
    sound.setVolume(10.0f);
    sound.setLoop(true);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openLink()
{
    QUrl url("https://nerter.fr");
    QDesktopServices::openUrl(url);
}



//Sound part




std::vector<sf::Int16> MainWindow::generateSineWaveSound(float frequency, float amplitude)
{
    int sampleRate = 44100;
    int numSamples = sampleRate;
    std::vector<sf::Int16> samples(numSamples);

    for (int i = 0; i < numSamples; i++) {

        float t = (float)i / sampleRate;

        float value = sin(2 * M_PI * frequency * t) * amplitude;

        samples[i] = (sf::Int16)(value * 32767);

    }

    return samples;
}

void MainWindow::updateFrequency(int frequencyProportion, int arraySize){

    sound.setPitch((frequencyProportion + minFrequency) * (maxFrequency / arraySize) / (maxFrequency / 2));


}

void MainWindow::playSmoothEndSound(){
    if(endIndex < data.size()){
        updateFrequency(data[endIndex], totalItemNumber);
        endIndex ++;
    }
    else{
        resetSmoothEndSound();
    }


}

void MainWindow::resetSmoothEndSound(){
    endTimer->stop();
    sound.stop();
    endIndex = 0;
}


//UI part

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    if(!hasSetUiDimensions){
        hasSetUiDimensions = true;
        setUIDimension();
        initializeData();
    }
}

void MainWindow::UpdtateItemSize(){
    graphicViewWidth = windowSize.width() - littleGapToMakeItNice;
    graphicViewHeight = windowSize.height() - topSpaceHeight - littleGapToMakeItNice - 15;

    itemWidth = (graphicViewWidth - littleGapToMakeItNice / 2) / totalItemNumber;
    heightMultiplier = (graphicViewHeight - littleGapToMakeItNice / 2) / totalItemNumber;
}

void MainWindow::setUIDimension()
{
    windowSize = size();

    UpdtateItemSize();

    ui->sortGraphicView->setFixedSize(graphicViewWidth, graphicViewHeight);

    QGraphicsView *sortGraphicView = findChild<QGraphicsView*>("sortGraphicView");

    QFrame *topFrame = findChild<QFrame*>("topFrame");
    QPushButton *nerterButton = findChild<QPushButton*>("nerterButton");


    QPushButton *startSortingButton = findChild<QPushButton*>("startSortingButton");
    QPushButton *resetButton = findChild<QPushButton*>("resetButton");

    QLineEdit *itemNumberLineEdit = findChild<QLineEdit*>("itemNumberLineEdit");
    QLineEdit *delayLineEdit = findChild<QLineEdit*>("delayLineEdit");
    QLabel *itemNumberLabel = findChild<QLabel*>("itemNumberLabel");
    QLabel *delayLabel = findChild<QLabel*>("delayLabel");

    QLabel *sortingMethodsLabel = findChild<QLabel*>("sortingMethodsLabel");
    QComboBox *sortingMethodsComboBox = findChild<QComboBox*>("sortingMethodsComboBox");

    QCheckBox *reverseInitialisationBox = findChild<QCheckBox*>("reverseInitialisationBox");

    QLabel *swapNumberLabel = findChild<QLabel*>("stepNumberLabel");
    QLabel *leaveLabel = findChild<QLabel*>("leaveLabel");

    sortGraphicView->move(0 + littleGapToMakeItNice / 2, topSpaceHeight + (littleGapToMakeItNice / 2)- 7);

    topFrame->move(0, 0);
    topFrame->resize(windowSize.width(), topSpaceHeight);

    QIcon nerterLogo(":/res/nerterLogo.png");
    ui->nerterButton->setIcon(nerterLogo);
    ui->nerterButton->setIconSize(QSize(30, 30));
    nerterButton->move(-3, 0);
    nerterButton->resize(30, 30);

    startSortingButton->move(40, 17);
    resetButton->move(170, 27);


    itemNumberLabel->move(350, 18);
    itemNumberLineEdit->move(533, 15);
    delayLabel->move(350, 56);
    delayLineEdit->move(557, 53);


    sortingMethodsLabel->move(715, 2);
    sortingMethodsComboBox->move(660, 40);

    reverseInitialisationBox->move(984, 26);

    swapNumberLabel->move(1230, 30);
    ui->stepNumberLabel->setText(QString("Nombre d\'échanges : \n..."));
    leaveLabel->move(windowSize.width() - 135, 0);

    ui->itemNumberLineEdit->setText(QString("%1").arg(totalItemNumber));
    ui->delayLineEdit->setText(QString("%1").arg(stepDelay));

    ui->itemNumberLineEdit->setValidator(new QDoubleValidator(ui->itemNumberLineEdit));
    ui->delayLineEdit->setValidator(new QDoubleValidator(ui->delayLineEdit));

    connect(ui->sortingMethodsComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::onComboBoxIndexChanged);

    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::reset);
    connect(ui->startSortingButton, &QPushButton::clicked, this, &MainWindow::startSorting);

}


void MainWindow::startSorting()
{
    if(!isReinitializing){
        if(isSorting){
            reset();
            hasToSort = true;
        }



        if(totalItemNumber <= minFrequency * 2){
            minFrequency = 0;
        }
        sound.play();

        ui->stepNumberLabel->setText(QString("Nombre d\'échanges : \n..."));

        if(!isSorting){

            sortiongFunctions[currentSortingMethod]();
        }
        isSorting = true;
    }
}

void MainWindow::reset(){
    if(!isReinitializing){

        std::unordered_set<int> seen;
        for(int i =0; i < data.size(); i++){
            if (seen.find(data[i]) != seen.end()) {
                destroyItem(i);
            }
            seen.insert(data[i]);
        }



        resetSmoothEndSound();
        timer->stop();
        ui->stepNumberLabel->setText(QString("Nombre d\'échanges : \n%1").arg(swapCount));

        initializeData();



        hasToSort = false;
    }


}

void MainWindow::onComboBoxIndexChanged(int index)
{
    currentSortingMethod = index;
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Escape) {
        qApp->quit();
    }
    if (event->key() == Qt::Key_Return) {
        startSorting();
    }
    else {
        QMainWindow::keyPressEvent(event);
    }
}





//Sorting part






void MainWindow::startTimer(){
    timer->start(fmax(ui->delayLineEdit->text().toFloat(), 0));

}
void MainWindow::stopTimer(){
    timer->stop();
    ui->stepNumberLabel->setText(QString("Nombre d\'échanges : \n%1").arg(swapCount));

    endTimer->start(fmax(endSoundDuration / data.size(), 1));

}

QColor MainWindow::getRainbowColor(int value, int totalItems) {
    int hue = static_cast<int>((360.0 / (totalItems - 1)) * (value)) % 360;
    return QColor::fromHsv(hue, 255, 255);
}

void MainWindow::initializeData()
{

    swapCount = 0;
    totalItemNumber = fmax(ui->itemNumberLineEdit->text().toFloat(), 0);
    UpdtateItemSize();

    if(totalItemNumber <= 50){
        spacingMultiplier = 1;

    }

    indexStack.clear();
    randomizedList.clear();

    if(ui->reverseInitialisationBox->checkState()){
        for (int i = totalItemNumber; i > 0 ; --i) {
            randomizedList.append((i));
        }
    }
    else{
        for (int i = 0; i < totalItemNumber; ++i) {
            randomizedList.append((i + 1));

        }
        std::shuffle(randomizedList.begin(), randomizedList.end(), std::mt19937{ std::random_device{}()});
    }
    //randomizedList = {12,3,6,1,7,2};

    if(onFirstinitialization){
        onFirstinitialization = false;
        data = randomizedList;

        // Création des rectangles
        for (int i = 0; i < data.size(); ++i) {
            int rectHeight = data[i] * heightMultiplier;
            QGraphicsRectItem *rect = scene->addRect(i * (itemWidth * spacingMultiplier), -rectHeight + 10, itemWidth, rectHeight);
            QBrush rainbowBrush(getRainbowColor(data[i], data.size()));
            rect->setBrush(rainbowBrush);
            rect->setPen(Qt::NoPen);
            rects.append(rect);
            brushes.append(rainbowBrush);
        }
    }

    else{

        j = 0;
        k = 0;
        l = 0;
        m = 1;

        lastTotalItemNumber = data.size();
        if(lastTotalItemNumber > randomizedList.size()){
            destroySpeed = 1;
            spawnSpeed = std::ceil(lastTotalItemNumber / randomizedList.size());

        }
        else{
            destroySpeed = std::floor((float)(randomizedList.size()) / lastTotalItemNumber);
            spawnSpeed = 1;
        }

        sound.play();
        timer->disconnect();
        connect(timer, &QTimer::timeout, this, &MainWindow::animateRandomization);
        timer->start(fmax(randomizationDuration / fmax(totalItemNumber, lastTotalItemNumber), 1));
        isSorting = true;
        isReinitializing = true;



    }
}

void MainWindow::animateRandomization(){

    if(lastTotalItemNumber == randomizedList.size() && m < totalItemNumber){

        swapItems(std::find(randomizedList.begin(), randomizedList.end(), m) - randomizedList.begin(), std::find(data.begin(), data.end(), m) - data.begin(), false);
        m++;

    }

    if(lastTotalItemNumber != randomizedList.size() && (j < randomizedList.size() || l < lastTotalItemNumber)){

        if(k % spawnSpeed == 0 && j < randomizedList.size()){
            int rectHeight = randomizedList[j] * heightMultiplier;
            QGraphicsRectItem *rect = scene->addRect(j * (itemWidth * spacingMultiplier), - rectHeight + 10, itemWidth, rectHeight);
            QBrush rainbowBrush(getRainbowColor(randomizedList[j], randomizedList.size()));
            rect->setBrush(rainbowBrush);
            rect->setPen(Qt::NoPen);
            rects.append(rect);
            brushes.append(rainbowBrush);

            updateFrequency(randomizedList[j], randomizedList.size());
            j++;
        }


        if(k % destroySpeed == 0 && l < lastTotalItemNumber && l >= 0){
            destroyItem(0);
            l++;
        }
        k++;
    }

    if((j >= randomizedList.size() && l >= lastTotalItemNumber) || m >= totalItemNumber){
        isReinitializing = false;
        if(lastTotalItemNumber != randomizedList.size()){
        }

        data = randomizedList;
        timer->stop();
        if(hasToSort){
            isSorting = true;
            sortiongFunctions[currentSortingMethod]();
        }
        else{
            isSorting = false;
            sound.stop();

        }
    }
}


void MainWindow::swapItems(int firstIndex, int secondIndex, bool hasToCont){

    updateFrequency(data[firstIndex], totalItemNumber);

    if(hasToCont){
        swapCount ++;
    }

    std::swap(data[firstIndex], data[secondIndex]);
    std::swap(brushes[firstIndex], brushes[secondIndex]);

    qreal height1 = rects[firstIndex]->rect().height();
    qreal height2 = rects[secondIndex]->rect().height();

    rects[firstIndex]->setRect(rects[firstIndex]->rect().x(), rects[firstIndex]->rect().y() + height1 - height2, rects[firstIndex]->rect().width(), height2);
    rects[secondIndex]->setRect(rects[secondIndex]->rect().x(), rects[secondIndex]->rect().y() + height2 - height1, rects[secondIndex]->rect().width(), height1);

    rects[firstIndex]->setBrush(brushes[firstIndex]);
    rects[secondIndex]->setBrush(brushes[secondIndex]);

}

void MainWindow::changeItemHeight(int index,int height, bool hasToCont){

    updateFrequency(data[index], totalItemNumber);

    if(hasToCont){
        swapCount ++;
    }

    data[index] = height;
    rects[index]->setRect(rects[index]->rect().x(), - height * heightMultiplier + 10, rects[index]->rect().width(), height * heightMultiplier);
    QBrush rainbowBrush(getRainbowColor(data[index], data.size()));
    rects[index]->setBrush(rainbowBrush);
    brushes[index] = rainbowBrush;

    data[index] = height;
}

void MainWindow::destroyItem(int itemIndex){


    data.erase(data.begin() + itemIndex);
    brushes.erase(brushes.begin() + itemIndex);

    QGraphicsRectItem* rect = rects[itemIndex];
    scene->removeItem(rect);
    delete rect;

    rects.erase(rects.begin() + itemIndex);

}

int MainWindow::countDigit(long long n)
{
    if (n == 0)
        return 1;
    int count = 0;
    while (n != 0) {
        n = n / 10;
        ++count;
    }
    return count;
}





// algorithms part





void MainWindow::BubbleSort()
{
    currentIndex = 0;
    l = 0;
    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::BubbleSortStep);
    startTimer();
}

void MainWindow::BubbleSortStep()
{
    if (currentIndex >= data.size() - 1) {
        stopTimer();
        return;
    }

    if (l < data.size() - currentIndex - 1) {
        if (data[l] > data[l + 1]) {
            swapItems(l, l+1, true);
        }
        ++l;
    } else {
        l = 0;
        ++currentIndex;
    }
}




void MainWindow::QuickSort() {
    for (int i = 0;  i < 2; i++){
        indexStack.push(qMakePair(0, totalItemNumber - 1));
    }

    lowIndex = -1;
    highIndex = -1;
    pivotIndex = -1;
    k = -1;
    l = -1;
    pivot = -1;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::QuickSortStep);
    startTimer();

}

void MainWindow::QuickSortStep() {

    if (!indexStack.isEmpty()) {
        if (lowIndex == -1 && highIndex == -1) {
            auto range = indexStack.pop();
            lowIndex = range.first;
            highIndex = range.second;

            pivot = rects[highIndex]->rect().height();
            k = lowIndex - 1;
            l = lowIndex;
        } else if (l <= highIndex - 1) {
            //Partition
            if (rects[l]->rect().height() < pivot) {
                k++;
                swapItems(k, l, true);
            }
            l++;

            if (l > highIndex - 1) {
                swapItems(k + 1, highIndex, true);
                pivotIndex = k + 1;
            }

        } else {
            if (pivotIndex - 1 > lowIndex) {
                indexStack.push(qMakePair(lowIndex, pivotIndex - 1));
            }
            if (pivotIndex + 1 < highIndex) {
                indexStack.push(qMakePair(pivotIndex + 1, highIndex));
            }

            lowIndex = -1;
            highIndex = -1;
            pivotIndex = -1;
        }
    }
    else{
        stopTimer();
    }
}



void MainWindow::StalinSort() {
    currentIndex = 0;
    l = 0;
    currentSmallestItemSize = 0;
    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::StalinSortStep);
    startTimer();

}

void MainWindow::StalinSortStep(){


    if (l < data.size()) {
        if (data[l] < currentSmallestItemSize) {
            destroyItem(l);
            updateFrequency(data[l], totalItemNumber);

        }
        else{
            currentSmallestItemSize = data[l];
            ++l;
        }
    } else {
        stopTimer();
        return;
    }
}

void MainWindow::MergeSort(){

    mergeSize = 1;
    mergeStartIndex= 0;
    isMerging = false;
    j = 0;
    k = 0;
    l = 0;


    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::MergeSortStep);
    startTimer();

}

void MainWindow::MergeSortStep(){


    int n = data.size();
    if (mergeSize < n) {
        if (!isMerging) {
            if (mergeStartIndex < n - mergeSize) {
                int mid = mergeStartIndex + mergeSize - 1;
                int high = std::min(mergeStartIndex + 2 * mergeSize - 1, n - 1);

                leftList.clear();
                rightlist.clear();

                for (int i = 0; i <= mid - mergeStartIndex; ++i) {
                    leftList.append(data[mergeStartIndex + i]);
                }
                for (int j = 0; j < high - mid; ++j) {
                    rightlist.append(data[mid + 1 + j]);
                }

                j = 0;
                k = 0;
                l = mergeStartIndex;


                isMerging = true;
            } else {
                mergeStartIndex = 0;
                mergeSize *= 2;
            }
        } else {


            if (j < leftList.size() && k < rightlist.size()) {
                if (leftList[j] <= rightlist[k]) {
                    if (data[l] != leftList[j]) {
                        for (int i = 0; i < data.size(); ++i) {
                            if (data[i] == leftList[j]){
                                swapItems(i, l, true);
                            }
                        }

                    }
                    ++j;
                } else {
                    if (data[l] != rightlist[k]) {
                        for (int i = 0; i < data.size(); ++i) {
                            if (data[i] == rightlist[k]){
                                swapItems(i, l, true);
                            }
                        }
                    }
                    ++k;
                }
                ++l;
            } else if (j < leftList.size()) {
                if (data[l] != leftList[j]) {
                    for (int i = 0; i < data.size(); ++i) {
                        if (data[i] == leftList[j]){
                            swapItems(i, l, true);
                        }
                    }
                }
                ++j;
                ++l;
            } else if (k < rightlist.size()) {
                if (data[l] != rightlist[k]) {
                    for (int i = 0; i < data.size(); ++i) {
                        if (data[i] == rightlist[k]){
                            swapItems(i, l, true);
                        }
                    }
                }
                ++k;
                ++l;
            } else {
                mergeStartIndex += 2 * mergeSize;
                isMerging = false;
            }
        }
    }

    if (mergeSize >= data.size() && !isMerging) {
        stopTimer();
    }
}




void MainWindow::HeapSort()
{
    heapSize = data.size();
    currentRoot = 0;
    sortingState = 0;
    buildHeapIndex = data.size() / 2 - 1;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::HeapSortStep);
    startTimer();

}

void MainWindow::HeapSortStep()
{
    if (buildHeapIndex >= 0) {

        if (buildHeapIndex >= 0) {
            if (sortingState == 0) {
                HeapifyInit(buildHeapIndex);
                buildHeapIndex--;
            } else {
                HeapifyStep();
            }
        } else {
            sortingState = 0; // Finished building the heap
            heapSize = data.size();
        }


    } else {

        if (heapSize > 1) {
            if (sortingState == 0) {
                --heapSize;
                swapItems(0, heapSize, true);
                HeapifyInit(0);
            } else {
                HeapifyStep();
            }
        }

    }


    if (heapSize <= 1 && buildHeapIndex < 0) {
        stopTimer();
    }
}


void MainWindow::HeapifyInit(int i)
{
    currentRoot = i;
    leftIndex = 2 * i + 1;
    rightIndex = 2 * i + 2;
    largestIndex = i;
    sortingState = 1; // Move to state 1 for heapify step
}

void MainWindow::HeapifyStep()
{
    switch (sortingState)
    {
    case 1: // Compare left child
        if (leftIndex < heapSize && data[leftIndex] > data[largestIndex]) {
            largestIndex = leftIndex;
        }
        sortingState = 2; // Move to state 2 for next step
        break;
    case 2: // Compare right child
        if (rightIndex < heapSize && data[rightIndex] > data[largestIndex]) {
            largestIndex = rightIndex;
        }
        sortingState = 3; // Move to state 3 for next step
        break;
    case 3: // Swap and recurse if necessary
        if (largestIndex != currentRoot) {
            swapItems(currentRoot, largestIndex, true);
            HeapifyInit(largestIndex); // Recurse
        } else {
            sortingState = 0; // Finished heapify
        }
        break;
    }
}


void MainWindow::ShellSort(){

    gap = data.size() / 2;
    j = gap;
    k = j;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::ShellSortStep);
    startTimer();
}



void MainWindow::ShellSortStep()
{
    if (gap > 0) {
        if (j < data.size()) {
            if (k >= gap && data[k - gap] > data[k]) {
                swapItems(k, k - gap, true);
                k -= gap;
            } else {
                j++;
                k = j;
            }
        } else {
            gap /= 2;
            j = gap;
            k = j;
        }
    } else {
        stopTimer();
    }
}



void MainWindow::InsertionSort()
{
    currentIndex = 1;
    j= 0;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::InsertionSortStep);
    startTimer();
}

void MainWindow::InsertionSortStep()
{
    if (currentIndex >= data.size()) {
        stopTimer();
        return;
    }
    if(data[currentIndex - j] < data[currentIndex - j - 1]){
        swapItems( currentIndex - j - 1, currentIndex - j, true);
        j++;
    }
    else{
        currentIndex++;
        j= 0;
    }

}




void MainWindow::SelectionSort()
{
    currentSmallestItemSize = data.size();
    currentIndex = 0;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::SelectionSortStep);
    startTimer();
}

void MainWindow::SelectionSortStep()
{
    if (currentIndex >= data.size() - 1) {
        stopTimer();
        return;
    }

    for (int i = currentIndex; i < data.size(); i++){
        if(data[i] < currentSmallestItemSize){
            currentSmallestItemSize = data[i];
            smallestIndex = i;
        }
    }
    swapItems(smallestIndex, currentIndex, true);
    currentIndex ++;
    currentSmallestItemSize = data.size();

}


void MainWindow::RadixSort(){
    currentDigitPosition = 1;
    currentDigit = 0;
    currentIndex = 0;
    j= 0;
    maxDigitsNumber = countDigit(totalItemNumber);
    nextdataList.clear();

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::RadixSortStep);
    startTimer();

}

void MainWindow::RadixSortStep()
{
    if(currentDigit <= 9){
        for (int i = 0; i < data.size(); i++){
            if((int)(data[i]/pow(10,(currentDigitPosition-1))) % 10 == currentDigit){
                nextdataList.append(data[i]);
            }
        }

        currentDigit ++;
    }
    else{

        if(j < data.size()){
            swapItems(std::find(data.begin(), data.end(), nextdataList[j]) - data.begin(), j, true);
            j++;
        }
        else{
            if(currentDigitPosition >= maxDigitsNumber){
                stopTimer();

                return;

            }

            currentDigit = 0;
            j = 0;

            currentDigitPosition ++;
            nextdataList.clear();
        }
    }
}



void MainWindow::ExchangeSort(){

    j = 0;
    k = 1;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::ExchangeSortStep);
    startTimer();
}

void MainWindow::ExchangeSortStep(){
    if(j < data.size()){
        if(k < data.size()){
            if(data[k] < data[j]){
                swapItems(k, j, true);
            }
            k++;
        }
        else {
            j++;
            k = j + 1;
        }
    }
    else{
        stopTimer();
    }

}


void MainWindow::OddEvenTranspositionSort(){

    j = 0;
    k = 0;
    l = 0;
    oddNumber = 0;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::OddEvenTranspositionSortStep);
    startTimer();
}



void MainWindow::OddEvenTranspositionSortStep(){

    if(l >= data.size() / 2){
        stopTimer();
        return;
    }

    k = 2 * j + oddNumber;

    if(k < data.size() - 1){
        if(data[k] > data[k+1]){
            swapItems(k, k + 1, true);
        }
        else{
            l++;
        }
        j++;
    }
    else{
        j = 0;
        l = 0;
        if(oddNumber == 0){
            oddNumber = 1;
        }
        else{
            oddNumber = 0;
        }
    }

}


void MainWindow::ShakerSort()
{
    ascending = true;
    currentIndex = 0;
    l = 0;
    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::ShakerSortStep);
    startTimer();
}

void MainWindow::ShakerSortStep()
{

    if (currentIndex >= data.size() / 2 ) {
        stopTimer();
        return;
    }
    if(ascending){
        if (l < data.size() - currentIndex - 1) {
            if (data[l] > data[l + 1]) {
                swapItems(l, l+1, true);
            }
            ++l;
        } else {
            ascending = false;
            ++currentIndex;
            l = data.size() - currentIndex;
        }
    }
    else{

        if (l > currentIndex - 1) {
            if (data[l] < data[l - 1]) {
                swapItems(l, l-1, true);
            }
            --l;
        } else {
            ascending = true;
            l = currentIndex;
        }
    }
}



void MainWindow::GravitySort()
{
    boolItemsList.clear();
    //initialize the list with bools values
    for(int i = 0; i < data.size(); i++){
        boolItemsList.append(QVector<bool>{true});

        for(int j = 0; j < data.size() - 1; j++){
            boolItemsList[i].append( j < data[i] - 1);
        }
    }
    nextData.clear();
    oldData.clear();
    currentIndex = totalItemNumber;
    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::GravitySortStep);
    startTimer();
}

void MainWindow::GravitySortStep()
{

    if(currentIndex >= totalItemNumber){
        for(int i = totalItemNumber - 2; i >= 0 ; i--){
            for(int j = 1; j < totalItemNumber; j++){
                //swap one true
                if(boolItemsList[i + 1][j] == false && boolItemsList[i][j] == true){
                    boolItemsList[i][j] = false;
                    boolItemsList[i + 1][j] = true;
                }
            }
        }
        nextData.clear();
        for(int i = 0; i < totalItemNumber; i++){
            auto it = std::find(boolItemsList[i].begin(), boolItemsList[i].end(), false);
            nextData.append(std::distance(boolItemsList[i].begin(),it));

        }
        currentIndex = 0;
        oldData = data;

    }
    else{
        changeItemHeight(currentIndex, nextData[currentIndex], true);
        currentIndex ++;
    }

    if(std::is_sorted(oldData.begin(), oldData.end())){
        stopTimer();
        return;
    }
}



void MainWindow::CycleSort()
{
    currentIndex = 0;
    currentNumber = data[currentIndex];
    lessNumberCount = 0;
    hasToContinue = true;
    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::CycleSortStep);
    startTimer();
}

void MainWindow::CycleSortStep()
{

    if(std::is_sorted(data.begin(), data.end())){
        stopTimer();
        return;
    }

    if(lessNumberCount != currentIndex || hasToContinue){
        lessNumberCount = 0;

        for(int i = 0; i < data.size(); i++){
            if(data[i] < currentNumber){
                lessNumberCount ++;

            }
        }
        currentNumber = data[lessNumberCount];
        swapItems(lessNumberCount , currentIndex, true);

        hasToContinue = false;
    }
    else{
        currentIndex ++;
        hasToContinue = true;
    }

}

unsigned int roundToNextPowerOf2(unsigned int n) {
    if (n == 0) return 1; // Cas spécial pour 0
    if ((n & (n - 1)) == 0) return n;
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}

void MainWindow::CircleSort()
{
    ItemNumberPowerOf2 = roundToNextPowerOf2(totalItemNumber);

    currentIndex = 0;
    currentSpot = 0;
    currentDivision = ItemNumberPowerOf2;
    currentIteration = 1;
    iterationNumber = 1;

    timer->disconnect();
    connect(timer, &QTimer::timeout, this, &MainWindow::CircleSortStep);
    startTimer();
}



void MainWindow::CircleSortStep()
{

    if(std::is_sorted(data.begin(), data.end())){
        stopTimer();
        return;
    }

    int indextoSwap = (currentDivision * currentIteration) - currentSpot - 1;

    if(indextoSwap < totalItemNumber && currentIndex < totalItemNumber){ // if any index is above max element, we ignore it, it is only useful for the logic;

        if(data[indextoSwap] < data[currentIndex]){
            swapItems(currentIndex, (currentDivision * currentIteration) - currentSpot - 1, true);
        }

    }

    currentIndex++;
    currentSpot++;

    if(currentSpot > currentDivision / 2 - 1){
        currentIndex = currentDivision * currentIteration;
        currentSpot = 0;

        if(currentIteration == iterationNumber){
            iterationNumber *=2;
            currentDivision /= 2;

            if(currentDivision == 1){
                currentDivision = ItemNumberPowerOf2;
                iterationNumber = 1;
            }

            currentIndex = 0;
            currentIteration = 0;
        }
        currentIteration ++;
    }
}









