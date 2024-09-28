    #include "Game.h"
#include <QMap>
#include <vector>
#include <algorithm>

Game::Game(const QString& playerName, const QString& playerComputerName)
    : player(playerName), Computer(playerComputerName) {

    //deck.createDeck();

    deck.shuffleDeck();  // Shuffle the deck when the game starts
}

void Game::startGame() {

    currentWinner="";
    deck.createDeck();  // Recreate the deck
    deck.shuffleDeck(); // Shuffle the deck
    player.resetScore();  // Reset player scores
    Computer.resetScore();

    currentRound = 0;   // Reset round count

    currentRound++;
    player.dealHand(deck); // Deal cards to the playes
    Computer.dealHand(deck);

    // Sort each player's hand
    player.getHand().sortGroup();
    Computer.getHand().sortGroup();

}



void Game::nextRound() {
    if (currentRound < totalRounds) {



        // Apply scores from the previous round before starting a new one
        applyScores();

        currentRound++;
        player.dealHand(deck); // Deal cards to the player
        Computer.dealHand(deck);

        // Sort each player's hand
        player.getHand().sortGroup();
        Computer.getHand().sortGroup();

        // Determine the winner without updating the score immediately
        currentWinner = determineWinner();

        // Update scores immediately after the fifth round
        if (currentRound == totalRounds) {
            applyScores();  // Apply scores from the fifth round
        }
    }
}



void Game::applyScores() {
    currentWinner = determineWinner();

    if (currentWinner == "Player One Wins!") {
        player.addScore(1);
    } else if (currentWinner == "Player Two Wins!") {
        Computer.addScore(1);
    }
    currentWinner.clear();  // Clear the current winner information for the next round
}



bool Game::isGameOver() const {
    return currentRound >= totalRounds ;
}

int Game::getCurrentRound() const {
    return currentRound;
}

QString Game::getPlayerHand() const {
    return player.getHandDescription();  // Get player's hand description
}




QString Game::getComputerHand() const {
    return Computer.getHandDescription();
}




int Game::getPlayerScore() const {
    return player.getScore();
}

int Game::getComputerScore() const {
    return Computer.getScore();
}



Player& Game::getPlayer() {
    return player;  // Return the player reference
}



Player& Game::getComputer() {
    return Computer;  // Return the Computer reference用
}


QString Game::determineWinner() {
    QString resultOne = player.getHand().getBest();
    QString resultTwo = Computer.getHand().getBest();

    int scoreOne = getScoreForHand(resultOne);
    int scoreTwo = getScoreForHand(resultTwo);

    if (scoreOne > scoreTwo) {
        return "Player One Wins!";

    } else if (scoreOne < scoreTwo) {
        return "Player Two Wins!";

    } else {

       // Compare the values of key cards
        int keyOne = player.getHand().getKeyCardValue();
        int keyTwo = Computer.getHand().getKeyCardValue();
        if (keyOne > keyTwo) {
            return "Player One Wins!";

        } else if (keyOne < keyTwo) {
            return "Player Two Wins!";

        }

        // If key cards are the same, compare all cards
        QVector<int> sortedValuesOne = player.getHand().getSortedCardValues();
        QVector<int> sortedValuesTwo = Computer.getHand().getSortedCardValues();
        for (int i = 0; i < sortedValuesOne.size(); ++i) {
            if (sortedValuesOne[i] > sortedValuesTwo[i]) {
                return "Player One Wins!";

            } else if (sortedValuesOne[i] < sortedValuesTwo[i]) {
                return "Player Two Wins!";

            }
        }
        return "It's a Draw!";
    }


}


int Game::getScoreForHand(const QString& result) {
    static const QMap<QString, int> handStrength = {
        {"stfl", 8}, {"four", 7}, {"full", 6}, {"flsh", 5},
        {"strt", 4}, {"trio", 3}, {"twop", 2}, {"pair", 1}, {"high", 0}
    };
    return handStrength.value(result, 0);
}

// Return a reference to the Deck
Deck& Game::getDeck() {
    return deck;
}



bool Game::isCloseToStraight(const QVector<Card>& cards, QVector<int>& valuesToComplete) {
    QVector<Card> sortedCards = cards;
    std::sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
        return a.getValue() < b.getValue();
    });

    int maxSequenceLength = 0;
    int currentSequenceLength = 1;
    QVector<Card> longestSequence;

     // Find the longest consecutive sequence
    for (int i = 1; i < sortedCards.size(); i++) {
        if (sortedCards[i].getValue() == sortedCards[i - 1].getValue() + 1) {
            currentSequenceLength++;
            if (currentSequenceLength > maxSequenceLength) {
                maxSequenceLength = currentSequenceLength;
                longestSequence.clear();
                for (int j = i - maxSequenceLength + 1; j <= i; j++) {
                    longestSequence.push_back(sortedCards[j]);
                }
            }
        } else if (sortedCards[i].getValue() != sortedCards[i - 1].getValue()) { // Skip duplicates
            currentSequenceLength = 1;
        }
    }

    // If the longest sequence contains four cards, find the cards to be completed
    if (maxSequenceLength == 4) {
        QVector<int> cardIndicesInLongestSequence;
        for (const Card& card : longestSequence) {
            cardIndicesInLongestSequence.push_back(card.getValue());
        }

        for (const Card& card : sortedCards) {
            if (!cardIndicesInLongestSequence.contains(card.getValue())) {
                valuesToComplete.push_back(card.getValue());
            }
        }

        return true;
    }

    return false;
}

void Game::computerDecision() {
    QString winner = determineWinner();
    if (winner == "Player Two Wins!") return;  // If the computer is already the winner, do not swap cards

    QVector<Card>& computerCards = Computer.getHand().getCards();
    std::map<int, int> cardValueCount;
    std::map<QString, int> suitCount;
    QVector<int> valuesToCompleteStraight;
    QString mostCommonSuit;
    int mostSuitCount = 0;

    // Count the number of each value and suit
    for (const Card& card : computerCards) {
        cardValueCount[card.getValue()]++;
        suitCount[card.getSuit()]++;
        if (suitCount[card.getSuit()] > mostSuitCount) {
            mostSuitCount = suitCount[card.getSuit()];
            mostCommonSuit = card.getSuit();
        }
    }

    // Check if close to a flush or a straight
    bool closeToFlush = (mostSuitCount >= 3);
    bool closeToStraight = isCloseToStraight(computerCards, valuesToCompleteStraight);

    QVector<int> swapIndices;  // Store the indices of cards to be swapped
    if (closeToFlush) {
        // Try to complete a flush
        for (int i = 0; i < computerCards.size(); ++i) {
            if (computerCards[i].getSuit() != mostCommonSuit && swapIndices.size() < 3) {
                swapIndices.push_back(i);
            }
        }
    } else if (closeToStraight && swapIndices.size() < 3) {
        // Try to complete a straight
        for (int i = 0; i < computerCards.size(); ++i) {
            if (!valuesToCompleteStraight.contains(computerCards[i].getValue())) {
                swapIndices.push_back(i);
            }
        }
    } else {
        // Swap out the lowest non-pair cards
        for (int i = 0; i < computerCards.size() && swapIndices.size() < 3; ++i) {
            if (cardValueCount[computerCards[i].getValue()] == 1) {
                swapIndices.push_back(i);
            }
        }
    }

    if (!swapIndices.empty()) {
        QVector<Card> newCards = deck.dealCards(swapIndices.size());
        QVector<Card> cardsToReinsert;

        for (int index : swapIndices) {
            cardsToReinsert.push_back(computerCards[index]);
            computerCards[index] = newCards.takeFirst();
        }

        // Reinsert the swapped cards into the deck
        for (const Card& card : cardsToReinsert) {
            deck.insertCardRandomly(card);
        }

        // Re-evaluate the hand
        Computer.getHand().sortGroup();
    }
}





