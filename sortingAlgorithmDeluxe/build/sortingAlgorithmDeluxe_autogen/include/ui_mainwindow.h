/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SortingAlgorithmDeluxe
{
public:
    QWidget *centralwidget;
    QGraphicsView *sortGraphicView;
    QFrame *topFrame;
    QPushButton *startSortingButton;
    QPushButton *resetButton;
    QLineEdit *delayLineEdit;
    QLabel *delayLabel;
    QLabel *itemNumberLabel;
    QLineEdit *itemNumberLineEdit;
    QLabel *leaveLabel;
    QComboBox *sortingMethodsComboBox;
    QLabel *sortingMethodsLabel;
    QLabel *stepNumberLabel;
    QPushButton *nerterButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SortingAlgorithmDeluxe)
    {
        if (SortingAlgorithmDeluxe->objectName().isEmpty())
            SortingAlgorithmDeluxe->setObjectName("SortingAlgorithmDeluxe");
        SortingAlgorithmDeluxe->resize(734, 500);
        SortingAlgorithmDeluxe->setStyleSheet(QString::fromUtf8("* {\n"
"    font-family: \"Renogare\"; \n"
"	background-color: #111111;\n"
"}\n"
"\n"
""));
        centralwidget = new QWidget(SortingAlgorithmDeluxe);
        centralwidget->setObjectName("centralwidget");
        sortGraphicView = new QGraphicsView(centralwidget);
        sortGraphicView->setObjectName("sortGraphicView");
        sortGraphicView->setGeometry(QRect(-340, 170, 500, 500));
        sortGraphicView->setStyleSheet(QString::fromUtf8("    border: none;"));
        topFrame = new QFrame(centralwidget);
        topFrame->setObjectName("topFrame");
        topFrame->setGeometry(QRect(0, -20, 731, 80));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(26, 26, 26, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(67, 67, 67, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(56, 56, 56, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(22, 22, 22, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(30, 30, 30, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush4);
        QBrush brush7(QColor(255, 255, 220, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush6);
        QBrush brush8(QColor(255, 255, 255, 127));
        brush8.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush6);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush8);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush6);
        QBrush brush9(QColor(45, 45, 45, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush6);
        QBrush brush10(QColor(22, 22, 22, 127));
        brush10.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush10);
#endif
        QBrush brush11(QColor(32, 32, 32, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush11);
        topFrame->setPalette(palette);
        topFrame->setStyleSheet(QString::fromUtf8("background-color: #1a1a1a;    border: none;"));
        topFrame->setFrameShape(QFrame::StyledPanel);
        topFrame->setFrameShadow(QFrame::Raised);
        startSortingButton = new QPushButton(topFrame);
        startSortingButton->setObjectName("startSortingButton");
        startSortingButton->setGeometry(QRect(10, 20, 120, 60));
        QFont font;
        font.setFamilies({QString::fromUtf8("Renogare")});
        font.setPointSize(24);
        startSortingButton->setFont(font);
        startSortingButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #cccccc;\n"
"	color:  #1a1a1a;\n"
"	border-radius: 5px;\n"
" 	border: 2px solid #222222;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;\n"
"}\n"
""));
        resetButton = new QPushButton(topFrame);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(140, 20, 160, 40));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Renogare")});
        font1.setPointSize(16);
        resetButton->setFont(font1);
        resetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #cccccc;\n"
"	color:  #1a1a1a;\n"
"	border-radius: 5px;\n"
" 	border: 2px solid #222222;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;\n"
"}\n"
""));
        delayLineEdit = new QLineEdit(topFrame);
        delayLineEdit->setObjectName("delayLineEdit");
        delayLineEdit->setGeometry(QRect(530, 0, 80, 30));
        delayLineEdit->setFont(font1);
        delayLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: #cccccc;\n"
"	color:  #1a1a1a;\n"
"	border-radius: 5px;\n"
" 	border: 2px solid #222222;\n"
"	padding: 0 0 2px\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;\n"
"}\n"
"QLineEdit:focus {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;}"));
        delayLabel = new QLabel(topFrame);
        delayLabel->setObjectName("delayLabel");
        delayLabel->setGeometry(QRect(270, 0, 261, 20));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Renogare")});
        font2.setPointSize(12);
        delayLabel->setFont(font2);
        delayLabel->setStyleSheet(QString::fromUtf8("	color: #eee;\n"
""));
        itemNumberLabel = new QLabel(topFrame);
        itemNumberLabel->setObjectName("itemNumberLabel");
        itemNumberLabel->setGeometry(QRect(270, 30, 231, 20));
        itemNumberLabel->setFont(font2);
        itemNumberLabel->setStyleSheet(QString::fromUtf8("	color: #eee;\n"
""));
        itemNumberLineEdit = new QLineEdit(topFrame);
        itemNumberLineEdit->setObjectName("itemNumberLineEdit");
        itemNumberLineEdit->setGeometry(QRect(500, 30, 80, 30));
        itemNumberLineEdit->setFont(font1);
        itemNumberLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	background-color: #cccccc;\n"
"	color:  #1a1a1a;\n"
"	border-radius: 5px;\n"
" 	border: 2px solid #222222;\n"
"	padding: 0 0 2px\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;\n"
"}\n"
"QLineEdit:focus {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;}"));
        leaveLabel = new QLabel(topFrame);
        leaveLabel->setObjectName("leaveLabel");
        leaveLabel->setGeometry(QRect(650, 0, 191, 31));
        leaveLabel->setFont(font2);
        leaveLabel->setStyleSheet(QString::fromUtf8("	color: #eee;\n"
""));
        sortingMethodsComboBox = new QComboBox(topFrame);
        sortingMethodsComboBox->setObjectName("sortingMethodsComboBox");
        sortingMethodsComboBox->setGeometry(QRect(430, 60, 300, 40));
        sortingMethodsComboBox->setFont(font1);
        sortingMethodsComboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	background-color: #cccccc;\n"
"	color:  #1a1a1a;\n"
"	border-radius: 5px;\n"
" 	border: 2px solid #222222;\n"
"	padding: 0 0 0 7px\n"
"\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"	background-color: #eeeeee;\n"
" 	border: 2px solid #666666;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"            	background-color: #1a1a1a;\n"
"				color:  #eeeeee;\n"
"        }\n"
""));
        sortingMethodsComboBox->setMaxVisibleItems(15);
        sortingMethodsLabel = new QLabel(topFrame);
        sortingMethodsLabel->setObjectName("sortingMethodsLabel");
        sortingMethodsLabel->setGeometry(QRect(510, 20, 191, 40));
        sortingMethodsLabel->setFont(font1);
        sortingMethodsLabel->setStyleSheet(QString::fromUtf8("	color: #eee;\n"
""));
        sortingMethodsLabel->setAlignment(Qt::AlignCenter);
        stepNumberLabel = new QLabel(topFrame);
        stepNumberLabel->setObjectName("stepNumberLabel");
        stepNumberLabel->setGeometry(QRect(190, 10, 320, 61));
        stepNumberLabel->setFont(font1);
        stepNumberLabel->setStyleSheet(QString::fromUtf8("	color: #eee;\n"
""));
        stepNumberLabel->setAlignment(Qt::AlignCenter);
        nerterButton = new QPushButton(topFrame);
        nerterButton->setObjectName("nerterButton");
        nerterButton->setGeometry(QRect(140, 40, 83, 29));
        delayLabel->raise();
        itemNumberLabel->raise();
        startSortingButton->raise();
        resetButton->raise();
        leaveLabel->raise();
        delayLineEdit->raise();
        itemNumberLineEdit->raise();
        sortingMethodsLabel->raise();
        stepNumberLabel->raise();
        sortingMethodsComboBox->raise();
        nerterButton->raise();
        SortingAlgorithmDeluxe->setCentralWidget(centralwidget);
        topFrame->raise();
        sortGraphicView->raise();
        menubar = new QMenuBar(SortingAlgorithmDeluxe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 734, 26));
        SortingAlgorithmDeluxe->setMenuBar(menubar);
        statusbar = new QStatusBar(SortingAlgorithmDeluxe);
        statusbar->setObjectName("statusbar");
        SortingAlgorithmDeluxe->setStatusBar(statusbar);

        retranslateUi(SortingAlgorithmDeluxe);

        QMetaObject::connectSlotsByName(SortingAlgorithmDeluxe);
    } // setupUi

    void retranslateUi(QMainWindow *SortingAlgorithmDeluxe)
    {
        SortingAlgorithmDeluxe->setWindowTitle(QCoreApplication::translate("SortingAlgorithmDeluxe", "SortingAlgorithmDeluxe", nullptr));
        startSortingButton->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "Trier", nullptr));
        resetButton->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "R\303\251initialiser", nullptr));
        delayLineEdit->setText(QString());
        delayLabel->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "D\303\251lai en millisecondes :", nullptr));
        itemNumberLabel->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "Nombre d'\303\251l\303\251ments :", nullptr));
        leaveLabel->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "Quitter [\303\251chap]", nullptr));
        sortingMethodsLabel->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "Mode de Tri :", nullptr));
        stepNumberLabel->setText(QCoreApplication::translate("SortingAlgorithmDeluxe", "Nombre d'\303\251changes: \n"
"...", nullptr));
        nerterButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SortingAlgorithmDeluxe: public Ui_SortingAlgorithmDeluxe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
