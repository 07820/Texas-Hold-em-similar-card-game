// Card.cpp
#include <QString>
#include <QStringList>

#include "Card.h"

// Get the value of the card
int Card::getValue() const {
    return (value == 1) ? 14 : value;  // If it's an Ace, return 14, otherwise return the original value
}

// Get the suit of the card
QString Card::getSuit() const {
    return suit;
}


// Get the names of J, Q, K, A, and other cards below 10
QString Card::getValueName() const {
    QString valueName;
    switch (value) {
    case 1:
        valueName = "ace";
        break;
    case 11:
        valueName = "jack";
        break;
    case 12:
        valueName = "queen";
        break;
    case 13:
        valueName = "king";
        break;
    default:
        valueName = QString::number(value);
        break;
    }
    return valueName;
}

// Get the name of the card (combination of value and suit)
QString Card::getName() const {

    // Use the `getValueName` method to retrieve the name of the value.
    return QString("%1 of %2").arg(getValueName()).arg(suit);
}

// Get the image path of the card
QString Card::getImageName() const {

    // Use the `getValueName` method to retrieve the name of the value.
    return QString(":/images/PNG-cards-1.3/%1_of_%2.png").arg(getValueName()).arg(suit);
}





