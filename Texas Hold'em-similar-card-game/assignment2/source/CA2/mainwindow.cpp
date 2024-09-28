#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"Player.h"
#include <QMessageBox>
#include"Game.h"


#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QApplication>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), game("Human", "Computer") {
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->nextRoundButton, &QPushButton::clicked, this, &MainWindow::nextRound);


    // Initialize card back images
    initializeCardBacks();
    initializeHandTypeNames();

    // Set the background color of the entire window to light green
    this->setStyleSheet("QMainWindow { background-color: #90EE90; }"  // Light green
                        "QPushButton { background-color: white; }");  // Keep buttons white

    connect(ui->swapButton, &QPushButton::clicked, this, &MainWindow::on_swapButton_clicked);

    // 禁用 nextRoundButton
    ui->nextRoundButton->setDisabled(true);
    ui->swapButton->setDisabled(true); // Disable swapButton
}

MainWindow::~MainWindow() {
    delete ui;
}




// Initialize hand type names
void MainWindow::initializeHandTypeNames() {
    handTypeFullNames["stfl"] = "Straight Flush";
    handTypeFullNames["four"] = "Four of a Kind";
    handTypeFullNames["full"] = "Full House";
    handTypeFullNames["flsh"] = "Flush";
    handTypeFullNames["strt"] = "Straight";
    handTypeFullNames["trio"] = "Three of a Kind";
    handTypeFullNames["twop"] = "Two Pair";
    handTypeFullNames["pair"] = "One Pair";
    handTypeFullNames["high"] = "High Card";
}



// Initialize card backs
void MainWindow::initializeCardBacks() {
    QPixmap backPixmap(":/images/PNG-cards-1.3/back.png");  // Ensure the path is correct
    const int cardLabelsCount = 10;  // Assuming there are 10 labels
    QLabel* cardLabels[cardLabelsCount] = {
        ui->label1, ui->label2, ui->label3, ui->label4,
        ui->label5, ui->label6, ui->label7, ui->label8,
        ui->label9, ui->label10
    };

    for (int i = 0; i < cardLabelsCount; ++i) {
        cardLabels[i]->setPixmap(backPixmap.scaled(80, 120, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        cardLabels[i]->installEventFilter(this);  // Install event filter
        cardLabels[i]->setProperty("cardIndex", i);  // Set card index for identification
    }
}

// Update score display
void MainWindow::updateScoreDisplay() {
    ui->labelPlayerScore->setText(QString("Player Score:       %1").arg(game.getPlayer().getScore()));
    ui->labelComputerScore->setText(QString("Computer Score: %1").arg(game.getComputer().getScore()));



}

// Update round display
void MainWindow::updateRoundDisplay() {
    ui->labelCurrentRound->setText(QString("Current Round: %1 / 5").arg(game.getCurrentRound()));
}


class CustomMessageBox : public QDialog {
public:

    // Constructor to initialize the custom message box with a title and text
    CustomMessageBox(const QString& title, const QString& text, QWidget* parent = nullptr)
        : QDialog(parent)
    {
        setWindowTitle(title);    // Set the window title

        QVBoxLayout* layout = new QVBoxLayout(this);  // Create a vertical layout for the dialog

        QLabel* label = new QLabel(text, this);       // Create a label to display the text
        label->setAlignment(Qt::AlignCenter);         // Center-align the text

        QPushButton* okButton = new QPushButton(tr("Sure"), this);
        okButton->setFixedSize(100, 30);
        okButton->setStyleSheet(
            "QPushButton {"
            "   background-color: #5cb85c;"
            "   color: white;"
            "   border-radius: 5px;"
            "   padding: 5px 10px;"
            "}"
            "QPushButton:hover {"
            "   background-color: #4cae4c;"
            "}"
            "QPushButton:pressed {"
            "   background-color: #449d44;"
            "}"
            );

        layout->addWidget(label);
        layout->addWidget(okButton, 0, Qt::AlignCenter);

        connect(okButton, &QPushButton::clicked, this, &QDialog::accept);

        setStyleSheet(
            "QDialog {"
            "   background-color: #f0f0f0;"
            "   border: 2px solid #888;"
            "}"
            "QLabel {"
            "   font-size: 18px;"
            "   color: #333;"
            "}"
            );

        setFixedSize(400, 200);  // Adjust size as needed
    }
};


// Check if the game is over
void MainWindow::checkGameOver() {
    if (game.isGameOver()) {
        QString winner;
        QString message;

        int scorePlayer = game.getPlayer().getScore();
        int scoreComputer = game.getComputer().getScore();


        if (scorePlayer > scoreComputer) {
            winner = "Player Wins!";
            message = "Congratulations! You won this game!";
        } else if (scorePlayer < scoreComputer) {
            winner = "Computer Wins!";
            message = "Sorry, you lost this game.";
        } else {
            winner = "It's a Draw!";
            message = "This game is a draw.";
        }
       // QMessageBox::information(this, "Game Over", winner);



         CustomMessageBox msgBox("Game over", winner + "\n" + message, this);
        msgBox.exec();

        ui->nextRoundButton->setDisabled(true);  // Disable "Next Round" button

        // Check if it's the last round and update the button text
        if (game.getCurrentRound() >= 5) {
            ui->startButton->setText("Restart the game");
        } else {
            ui->startButton->setText("Start");
        }

        ui->startButton->setEnabled(true);  // Enable "Start" button to allow new game
    }
}




// Update card display
void MainWindow::updateCardDisplay() {
    const QVector<Card>& playerCards = game.getPlayer().getHand().getCards();
    const QVector<Card>& opponentCards = game.getComputer().getHand().getCards();

    // Update player cards
    for (int i = 0; i < playerCards.size(); ++i) {
        QLabel* cardLabel = findChild<QLabel*>(QString("label%1").arg(i + 1));  // Image display label
        QLabel* infoLabel  = findChild<QLabel*>(QString("labelCardInfo%1").arg(i + 1));  // Text description label
        if (cardLabel && infoLabel) {
            cardLabel->setPixmap(QPixmap(playerCards[i].getImageName()).scaled(80, 120));
            infoLabel->setText(playerCards[i].getName());  // Set card info
        }
    }

    // Update opponent cards
    for (int i = 0; i < opponentCards.size(); ++i) {
        QLabel* cardLabel = findChild<QLabel*>(QString("label%1").arg(i + 6));  // Image display label
        QLabel* infoLabel = findChild<QLabel*>(QString("labelCardInfo%1").arg(i + 6));  // Text description label
        if (cardLabel && infoLabel) {
            cardLabel->setPixmap(QPixmap(opponentCards[i].getImageName()).scaled(80, 120));
            infoLabel->setText(opponentCards[i].getName());   // Set card info
        }
    }
}



// Move to the next round
void MainWindow::nextRound() {
    if (!game.isGameOver()) {

        clearCardSelections();  // Clear previous round selections

        game.nextRound();

        hasSwappedThisRound = false;  // Reset swap flag
        if (game.getCurrentRound() == 5) {
            ui->swapButton->setEnabled(false);  // Disable swap button in the fifth round
        } else {
            ui->swapButton->setEnabled(true);
        }

        updateCardDisplay();
        updateWinnerDisplay();
        updateScoreDisplay();
        updateRoundDisplay();

        updateHandTypeDisplay();

        checkGameOver();
    }

}

 // Update winner display
void MainWindow::updateWinnerDisplay() {
    QString winner = game.determineWinner();
    if (winner == "Player One Wins!") {
        ui->labelWinner->setText("You will win this round.");
    } else if (winner == "Player Two Wins!") {
        ui->labelWinner->setText("The computer will win this round.");
    } else {
        ui->labelWinner->setText(winner);  // "It's a Draw!"
    }
}

// Start the game
void MainWindow::startGame() {

    game.startGame();
     ui->startButton->setText("Start");
     hasSwappedThisRound = false;  // Reset swap flag
     ui->swapButton->setEnabled(true);  // Re-enable swap button

    updateCardDisplay();  // Update card display

    updateWinnerDisplay();
    updateScoreDisplay(); // Update score display
    updateRoundDisplay(); // Update round display

    updateHandTypeDisplay();

    checkGameOver();      // Check if game is over
    ui->nextRoundButton->setEnabled(true);  // Enable "Next Round" button
    ui->startButton->setDisabled(true);      // Disable "Start" button

}







// Event filter for card selection
bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::MouseButtonPress) {
        QLabel *label = qobject_cast<QLabel*>(obj);
        if (label) {
            toggleCardSelection(label);
            return true;  // Event handled, do not propagate
        }
    }
    return false;  // Allow event to continue propagating
}

// Toggle card selection
void MainWindow::toggleCardSelection(QLabel* cardLabel) {
    if (selectedCards.contains(cardLabel)) {
        selectedCards.remove(cardLabel);
        cardLabel->setStyleSheet(""); // Deselect
    } else if (selectedCards.size() < 3) {
        selectedCards.insert(cardLabel);
        cardLabel->setStyleSheet("border: 2px solid red;"); // Show selection effect
    }
}





void MainWindow::on_swapButton_clicked() {
    if (!game.isGameOver() && game.getCurrentRound() < 5) {
        QVector<Card>& playerCards = game.getPlayer().getHand().getCards();
        QVector<Card> newCards = game.getDeck().dealCards(selectedCards.size());

        // Store cards to be swapped out
        QVector<Card> cardsToReinsert;

        for (QLabel* label : selectedCards) {
            int cardIndex = label->property("cardIndex").toInt();  // Get card index
            if (cardIndex < playerCards.size()) {
                cardsToReinsert.push_back(playerCards[cardIndex]);  // Save card to be swapped
                playerCards[cardIndex] = newCards.takeFirst();      // Replace with new card
                label->setPixmap(QPixmap(playerCards[cardIndex].getImageName()));  // Set new image
                 label->setStyleSheet("");  // Clear selection effect
            }
        }

        // Randomly reinsert swapped-out cards back into the deck
        for (const Card& card : cardsToReinsert) {
            game.getDeck().insertCardRandomly(card);
        }

        selectedCards.clear();  // Clear selected cards
        updateCardDisplay();    // Update display



        game.computerDecision(); // Let computer make its decision

      updateCardDisplay();  // Update display again

        updateWinnerDisplay();  // Update winner display
        updateHandTypeDisplay();  // Update hand type display


         hasSwappedThisRound = true;  // Mark as swapped
        ui->swapButton->setEnabled(false);  // Disable swap button
    }
}









// Update hand type display
void MainWindow::updateHandTypeDisplay() {
    QString playerHandType = game.getPlayer().getHand().getBest();
    QString ComputerHandType = game.getComputer().getHand().getBest();


    ui->labelPlayer1HandType->setText(handTypeFullNames[playerHandType]);
    ui->labelPlayer2HandType->setText(handTypeFullNames[ComputerHandType]);
}

// Clear card selections
void MainWindow::clearCardSelections() {
    QLabel* cardLabels[] = {
        ui->label1, ui->label2, ui->label3, ui->label4,
        ui->label5, ui->label6, ui->label7, ui->label8,
        ui->label9, ui->label10
    };
    for (QLabel* label : cardLabels) {
        if (label) {
            label->setStyleSheet("");  // Remove specific styles like border
        }
    }
    selectedCards.clear();  // Clear selected cards set
}
