#ifndef CARD_H
#define CARD_H
#include <QString>

class Card {
public:
     // Constructor function used for initializing the suit and value of the card.
    Card(QString suit, int value) : value(value), suit(suit) {}

    int getValue() const;          // Get card value.

    QString getSuit() const;       // Get card suit.

    QString getName() const;       // Get card name.  Like 2_of_clubs

    QString getImageName() const;   //Get card image path.

    int value;  //Card value

    QString getValueName() const;

private:

    QString suit;  //Card suit


};

#endif // CARD_H
