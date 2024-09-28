#ifndef HAND_H
#define HAND_H
#include "Deck.h"
#include <vector>
#include <QVector>

#include "Card.h"

class Hand {
public:


    // Sort the hand by card values
    void sortValue();
    // Sort the hand by card groups (suits and values)
    void sortGroup();

    // Get a description of the hand
    QString getHandDescription() const;

    // Get a reference to the cards in the hand
    QVector<Card>& getCards();
    // Deal cards from the deck to the hand
    void dealHand(Deck& deck);

    // Get the best hand ranking
    QString getBest();
    // Check if the hand is a flush
    bool isFlush();
     // Check if the hand is a straight
    bool isStraight();

     // Get the value of the key card (highest value card in the hand)
    int getKeyCardValue() const;

    // Get the sorted values of the cards in the hand
    QVector<int> getSortedCardValues() const;

private:
    QVector<Card> cards; // Vector to hold the cards in the hand


};

#endif // HAND_H
