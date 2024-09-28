#include "Player.h"


// Constructor initializes the player's name and sets the initial score to zer
Player::Player(const QString& name)
    : name(name), score(0) {}
// Sets the player's name
void Player::setName(const QString& name) {
    this->name = name;
}
// Returns the player's name
QString Player::getName() const {
    return name;
}
// Adds points to the player's score
void Player::addScore(int points) {
    score += points;
}

// Returns the player's score
int Player::getScore() const {
    return score;
}
// Deals a hand to the player from the deck
void Player::dealHand(Deck& deck) {
    hand.dealHand(deck);  // Call the Hand class method to deal cards to the player
}

// Returns a description of the player's hand
QString Player::getHandDescription() const {
    return hand.getHandDescription();  // Get a description of the player's hand
}


// Returns a non-const reference to the player's hand
 Hand& Player::getHand() {
     return hand; // Return a reference to the player's hand
 }

 // Resets the player's score to zero
 void Player::resetScore() {
     score = 0;
 }
