#ifndef DECK_H
#define DECK_H

#include <vector>
#include <QVector>
#include "Card.h"

class Deck {
public:
    Deck(); // Constructor
    void createDeck();  // Create a new deck of cards
    void shuffleDeck(); // Shuffle the deck
   QVector<Card> dealCards(int count); //Deal cards to 2 players

    void insertCardRandomly(const Card& card); // Insert a card randomly into the deck

private:
    std::vector<Card> deck;


};

#endif // DECK_H
