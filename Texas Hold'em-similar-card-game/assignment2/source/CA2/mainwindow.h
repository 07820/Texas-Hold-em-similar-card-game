#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <vector>
#include "Card.h"
#include"Hand.h"
#include "Deck.h"
#include"Player.h"
#include "Game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override; // Event filter



private slots:
    void on_swapButton_clicked(); // Swap button click event

    void startGame();
    void nextRound();
    void updateCardDisplay();

    void updateWinnerDisplay();

   void updateScoreDisplay();
    void updateRoundDisplay();
   void checkGameOver();
    void initializeCardBacks();


private:
    Ui::MainWindow *ui;

      Game game;

       bool hasSwappedThisRound;  // Track if cards have been swapped this round


QSet<QLabel*> selectedCards; // Selected cards

void toggleCardSelection(QLabel* cardLabel);
void clearCardSelections();
void applyScores(const QString& winner);
void updateHandTypeDisplay();

QMap<QString, QString> handTypeFullNames;

void initializeHandTypeNames();

};
#endif // MAINWINDOW_H
