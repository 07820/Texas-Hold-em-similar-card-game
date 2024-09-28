#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
#include "Hand.h"

class Player {
public:
    // Constructor that initializes the player with a name
    Player(const QString& name);

    // Sets the player's name
    void setName(const QString& name);
    // Returns the player's name
    QString getName() const;

     // Adds points to the player's score
    void addScore(int points);

    // Returns the player's score
    int getScore() const;

    // Deals a hand to the player from the deck
    void dealHand(Deck& deck);

    // Returns a description of the player's hand
    QString getHandDescription() const;

    // Resets the player's score to zero
   void resetScore();

   // Returns a  reference to the player's hand
     Hand& getHand();



private:
    QString name; // Player's name
    int score;    // Player's score
    Hand hand;  // The hand of cards the player has
};

#endif // PLAYER_H
