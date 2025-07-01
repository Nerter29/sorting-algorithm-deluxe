#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <QStack>

#include <SFML/Audio.hpp>
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class SortingAlgorithmDeluxe; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int getJ() const;
    void setJ(int newJ);


private slots:
    void openLink();
private:

    Ui::SortingAlgorithmDeluxe *ui;
    QGraphicsScene *scene;
    QVector<int> data;
    QVector<int> randomizedList;
    QVector<QGraphicsRectItem*> rects;
    QVector<QBrush> brushes;
    QTimer *timer;
    QTimer *endTimer;




    QSize windowSize;
    float graphicViewWidth;
    float graphicViewHeight;
    int topSpaceHeight;
    int littleGapToMakeItNice;
    float spacingMultiplier;
    float itemWidth;
    float heightMultiplier;
    int swapCount;
    QVector<QString> allSortingMethodsStrings;
    int currentSortingMethod;
    bool hasSetUiDimensions = false;
    bool isSorting = false;
    bool hasToSort;
    bool onFirstinitialization;
    bool isReinitializing;

    float totalItemNumber;
    int stepDelay;

    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    const float maxFrequency;
    float minFrequency;

    int endIndex;
    int endSoundDuration;

    int randomizationDuration;
    float lastTotalItemNumber;
    int destroySpeed;
    int spawnSpeed;


    //random sorting indexes
    int currentIndex;
    int currentNumber;

    int j, k, l, m, n; // pure indexes
    int lowIndex, highIndex, pivotIndex;
    int largestIndex;
    int smallestIndex;
    int iterationNumber;
    int currentIteration;
    QStack<QPair<int, int>> indexStack;

    //quick variables
    int pivot;

    //stalin variables
    int currentSmallestItemSize;

    //merge variables
    int mergeSize;
    int mergeStartIndex;
    int leftIndex, rightIndex, midIndex;
    bool isMerging;
    QVector<double> leftList;
    QVector<double> rightlist;

    //heap variables
    int heapSize;
    int currentRoot;
    int sortingState;
    int buildHeapIndex;

    //shell variables
    int gap;

    //radix variables

    int currentDigitPosition;
    int maxDigitsNumber;
    int currentDigit;
    QVector<int> nextdataList;

    //shaker variables
    bool ascending;

    //gravity variables
    QVector<QVector<bool>> boolItemsList;
    QVector<int> nextData;
    QVector<int> oldData;

    //cycle variables
    int lessNumberCount;
    bool hasToContinue;

    //circle variables

    int currentDivision;
    int currentSpot;
    int ItemNumberPowerOf2;





    void resizeEvent(QResizeEvent *event);
    void UpdtateItemSize();
    void setUIDimension();
    void startSorting();
    void reset();
    void keyPressEvent(QKeyEvent *event);
    void onComboBoxIndexChanged(int index);

    std::vector<sf::Int16> generateSineWaveSound(float frequency, float amplitude);
    void updateFrequency(int frequencyProportion, int arraySize);
    void playSmoothEndSound();
    void resetSmoothEndSound();

    void stopTimer();
    void startTimer();
    void initializeData();
    void animateRandomization();
    QColor getRainbowColor(int index, int totalItems);
    void swapItems(int firstIndex, int secondIndex, bool hasToCount);
    void changeItemHeight(int index, int height, bool hasToCount);

    void destroyItem(int itemIndex);
    int countDigit(long long n);

    std::vector<std::function<void()>> sortiongFunctions;

    void BubbleSort();
    void BubbleSortStep();

    void QuickSort();
    void QuickSortStep();

    void StalinSort();
    void StalinSortStep();

    void MergeSort();
    void MergeSortStep();

    void HeapSort();
    void HeapSortStep();
    void HeapifyStep();
    void HeapifyInit(int i);

    void ShellSort();
    void ShellSortStep();

    void InsertionSort();
    void InsertionSortStep();

    void SelectionSort();
    void SelectionSortStep();

    void RadixSort();
    void RadixSortStep();

    void ExchangeSort();
    void ExchangeSortStep();

    void OddEvenTranspositionSort();
    void OddEvenTranspositionSortStep();
    int oddNumber;

    void ShakerSort();
    void ShakerSortStep();

    void GravitySort();
    void GravitySortStep();

    void CycleSort();
    void CycleSortStep();

    void CircleSort();
    void CircleSortStep();

};

#endif // MAINWINDOW_H
