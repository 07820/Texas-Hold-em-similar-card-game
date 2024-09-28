/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startButton;
    QPushButton *nextRoundButton;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLabel *label8;
    QLabel *label9;
    QLabel *label10;
    QLabel *labelWinner;
    QLabel *labelPlayerScore;
    QLabel *labelComputerScore;
    QLabel *labelCurrentRound;
    QPushButton *swapButton;
    QLabel *labelCardInfo1;
    QLabel *labelCardInfo2;
    QLabel *labelCardInfo3;
    QLabel *labelCardInfo4;
    QLabel *labelCardInfo5;
    QLabel *labelCardInfo6;
    QLabel *labelCardInfo7;
    QLabel *labelCardInfo8;
    QLabel *labelCardInfo9;
    QLabel *labelCardInfo10;
    QLabel *labelPlayer1HandType;
    QLabel *labelPlayer2HandType;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(952, 627);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/PNG-cards-1.3/red_joker.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        startButton = new QPushButton(centralwidget);
        startButton->setObjectName("startButton");
        startButton->setGeometry(QRect(20, 200, 121, 41));
        startButton->setStyleSheet(QString::fromUtf8(""));
        nextRoundButton = new QPushButton(centralwidget);
        nextRoundButton->setObjectName("nextRoundButton");
        nextRoundButton->setGeometry(QRect(20, 260, 121, 41));
        nextRoundButton->setStyleSheet(QString::fromUtf8(""));
        label1 = new QLabel(centralwidget);
        label1->setObjectName("label1");
        label1->setGeometry(QRect(140, 380, 80, 120));
        label2 = new QLabel(centralwidget);
        label2->setObjectName("label2");
        label2->setGeometry(QRect(260, 380, 80, 120));
        label3 = new QLabel(centralwidget);
        label3->setObjectName("label3");
        label3->setGeometry(QRect(390, 380, 80, 120));
        label4 = new QLabel(centralwidget);
        label4->setObjectName("label4");
        label4->setGeometry(QRect(510, 380, 80, 120));
        label5 = new QLabel(centralwidget);
        label5->setObjectName("label5");
        label5->setGeometry(QRect(620, 380, 80, 120));
        label6 = new QLabel(centralwidget);
        label6->setObjectName("label6");
        label6->setGeometry(QRect(140, 20, 80, 120));
        label7 = new QLabel(centralwidget);
        label7->setObjectName("label7");
        label7->setGeometry(QRect(260, 20, 80, 120));
        label8 = new QLabel(centralwidget);
        label8->setObjectName("label8");
        label8->setGeometry(QRect(390, 20, 80, 120));
        label9 = new QLabel(centralwidget);
        label9->setObjectName("label9");
        label9->setGeometry(QRect(510, 20, 80, 120));
        label10 = new QLabel(centralwidget);
        label10->setObjectName("label10");
        label10->setGeometry(QRect(620, 20, 80, 120));
        labelWinner = new QLabel(centralwidget);
        labelWinner->setObjectName("labelWinner");
        labelWinner->setGeometry(QRect(340, 250, 311, 31));
        QFont font;
        font.setPointSize(11);
        labelWinner->setFont(font);
        labelPlayerScore = new QLabel(centralwidget);
        labelPlayerScore->setObjectName("labelPlayerScore");
        labelPlayerScore->setGeometry(QRect(340, 290, 171, 19));
        QFont font1;
        font1.setBold(true);
        labelPlayerScore->setFont(font1);
        labelComputerScore = new QLabel(centralwidget);
        labelComputerScore->setObjectName("labelComputerScore");
        labelComputerScore->setGeometry(QRect(340, 220, 181, 19));
        labelComputerScore->setFont(font1);
        labelCurrentRound = new QLabel(centralwidget);
        labelCurrentRound->setObjectName("labelCurrentRound");
        labelCurrentRound->setGeometry(QRect(160, 250, 171, 19));
        labelCurrentRound->setFont(font1);
        swapButton = new QPushButton(centralwidget);
        swapButton->setObjectName("swapButton");
        swapButton->setGeometry(QRect(710, 240, 151, 51));
        swapButton->setStyleSheet(QString::fromUtf8("\n"
"    border: 1px solid black;         \n"
"    border-radius: 5px;            \n"
"    padding: 5px;                 \n"
"    "));
        labelCardInfo1 = new QLabel(centralwidget);
        labelCardInfo1->setObjectName("labelCardInfo1");
        labelCardInfo1->setGeometry(QRect(140, 510, 91, 19));
        labelCardInfo2 = new QLabel(centralwidget);
        labelCardInfo2->setObjectName("labelCardInfo2");
        labelCardInfo2->setGeometry(QRect(260, 510, 121, 19));
        labelCardInfo3 = new QLabel(centralwidget);
        labelCardInfo3->setObjectName("labelCardInfo3");
        labelCardInfo3->setGeometry(QRect(390, 510, 121, 19));
        labelCardInfo4 = new QLabel(centralwidget);
        labelCardInfo4->setObjectName("labelCardInfo4");
        labelCardInfo4->setGeometry(QRect(510, 510, 111, 19));
        labelCardInfo5 = new QLabel(centralwidget);
        labelCardInfo5->setObjectName("labelCardInfo5");
        labelCardInfo5->setGeometry(QRect(620, 510, 111, 19));
        labelCardInfo6 = new QLabel(centralwidget);
        labelCardInfo6->setObjectName("labelCardInfo6");
        labelCardInfo6->setGeometry(QRect(140, 140, 131, 19));
        labelCardInfo7 = new QLabel(centralwidget);
        labelCardInfo7->setObjectName("labelCardInfo7");
        labelCardInfo7->setGeometry(QRect(260, 140, 141, 19));
        labelCardInfo8 = new QLabel(centralwidget);
        labelCardInfo8->setObjectName("labelCardInfo8");
        labelCardInfo8->setGeometry(QRect(390, 140, 111, 19));
        labelCardInfo9 = new QLabel(centralwidget);
        labelCardInfo9->setObjectName("labelCardInfo9");
        labelCardInfo9->setGeometry(QRect(510, 140, 111, 19));
        labelCardInfo10 = new QLabel(centralwidget);
        labelCardInfo10->setObjectName("labelCardInfo10");
        labelCardInfo10->setGeometry(QRect(620, 140, 111, 19));
        labelPlayer1HandType = new QLabel(centralwidget);
        labelPlayer1HandType->setObjectName("labelPlayer1HandType");
        labelPlayer1HandType->setGeometry(QRect(800, 410, 111, 61));
        labelPlayer1HandType->setFont(font);
        labelPlayer2HandType = new QLabel(centralwidget);
        labelPlayer2HandType->setObjectName("labelPlayer2HandType");
        labelPlayer2HandType->setGeometry(QRect(790, 50, 131, 41));
        labelPlayer2HandType->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(570, 190, 371, 71));
        label->setAcceptDrops(false);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        label->setWordWrap(true);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(790, 30, 91, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(800, 390, 91, 31));
        label_5->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 952, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Card Game", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        nextRoundButton->setText(QCoreApplication::translate("MainWindow", "Next Round", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label4->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label5->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label10->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        labelWinner->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-style:italic;\">Click start button to play</span></p></body></html>", nullptr));
        labelPlayerScore->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Player Score</span></p></body></html>", nullptr));
        labelComputerScore->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Computer Score</span></p></body></html>", nullptr));
        labelCurrentRound->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Current round: 0</span></p></body></html>", nullptr));
        swapButton->setText(QCoreApplication::translate("MainWindow", "Swap cards", nullptr));
        labelCardInfo1->setText(QString());
        labelCardInfo2->setText(QString());
        labelCardInfo3->setText(QString());
        labelCardInfo4->setText(QString());
        labelCardInfo5->setText(QString());
        labelCardInfo6->setText(QString());
        labelCardInfo7->setText(QString());
        labelCardInfo8->setText(QString());
        labelCardInfo9->setText(QString());
        labelCardInfo10->setText(QString());
        labelPlayer1HandType->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Top rank1</span></p></body></html>", nullptr));
        labelPlayer2HandType->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Top rank2</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-style:italic;\">Click to choose up to three cards to swap, but the computer may also exchange cards afterwards</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Top rank:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Top rank:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
