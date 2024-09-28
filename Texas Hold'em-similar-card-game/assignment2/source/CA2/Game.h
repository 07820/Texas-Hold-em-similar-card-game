#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Deck.h"

class Game {
public:
    Game(const QString& playerOneName, const QString& playerTwoName); // Constructor

    // Start the game
    void startGame();

    // Proceed to the next round
    void nextRound();

    // Get the hand of player as a string
    QString getPlayerHand() const;
    // Get the hand of computer as a string
    QString getComputerHand() const;
    // Get the score of player
    int getPlayerScore() const;

    // Get the score of computer
    int getComputerScore() const;


     // Determine the winner of each round
    QString determineWinner();

    // Get the score for a particular hand.Score is used to compare the hierarchy of Shunzi, Tonghua, etc
    int getScoreForHand(const QString& result);


    // Get the current round number
     int getCurrentRound() const;



     // Get a constant reference to player
     Player& getPlayer();

     // Get a reference to computer player
     Player& getComputer();


     // Determine the final winner of the game
    QString determineFinalWinner() const;

     // Check if the game is over
    bool isGameOver() const;

     // Get a reference to the deck
     Deck& getDeck();

     // Apply players's scores after each round
    void applyScores();

     // Let the computer make decisions whether to swap the cards
     void computerDecision();


   // Check if the cards are close to a straight
   bool isCloseToStraight(const QVector<Card>& cards, QVector<int>& valuesToComplete) ;





private:
    Player player;
    Player Computer;
    Deck deck;

    int currentRound = 0;
    static const int totalRounds  = 5;  // Maximum number of rounds

     QString currentWinner;  // Store the winner of the current round





};

#endif // GAME_H
