#include "Hand.h"
#include <algorithm>
#include <map>


// Sorts the cards by their value in ascending order
void Hand::sortValue() {
    std::sort(cards.begin(), cards.end(), [](const Card &a, const Card &b) {
        return a.getValue() < b.getValue();
    });
}
// Sorts the cards by the frequency of their values
void Hand::sortGroup() {
    std::map<int, int> frequencyMap;
    for (const auto& card : cards) {
        frequencyMap[card.getValue()]++;  // Count the occurrences of each card value
    }

    std::sort(cards.begin(), cards.end(), [&frequencyMap](const Card& a, const Card& b) {
        int freqA = frequencyMap[a.getValue()];
        int freqB = frequencyMap[b.getValue()];
        if (freqA == freqB) {
            return a.getValue() < b.getValue();  // If frequencies are the same, sort by value
        }
        return freqA > freqB;
    });
}
// Generates a description of the hand in HTML format with images of the cards
QString Hand::getHandDescription() const{
    QString description;
    for (const Card& card : cards) {
        description += "<img src='" + card.getImageName() + "' width='80' height='120'>";
    }
    return description;
}

// Deals a hand by drawing five cards from the deck
void Hand::dealHand(Deck& deck) {
    cards = deck.dealCards(5); //Deal 5 cards from deck
}

// Returns a reference to the cards in the hand
QVector<Card>& Hand::getCards()  {
    return cards;
}
// Determines the best poker hand from the cards
QString Hand::getBest() {
    sortGroup(); // Sort cards by value frequency to help identify hand types

     // Frequency count of card values
    std::map<int, int> valueCount;
    for (const Card& card : cards) {
        valueCount[card.getValue()]++;
    }

    int maxFrequency = 0;
    std::vector<int> frequencies;
    for (const auto& pair : valueCount) {
        maxFrequency = std::max(maxFrequency, pair.second);
        frequencies.push_back(pair.second);
    }
    std::sort(frequencies.begin(), frequencies.end(), std::greater<int>());

    // Identify the hand type
    if (isStraight() && isFlush()) {
        return "stfl";  // Straight flush
    }
    if (maxFrequency == 4) {
        return "four";  // Four of a kind
    } else if (maxFrequency == 3 && frequencies.size() > 1 && frequencies[1] == 2) {
        return "full";  // Full house
    } else if (isFlush()) {
        return "flsh";  // Flush
    } else if (isStraight()) {
        return "strt";  // Straight
    } else if (maxFrequency == 3) {
        return "trio";  // Three of a kind
    } else if (frequencies.size() >= 2 && frequencies[0] == 2 && frequencies[1] == 2) {
        return "twop";  // Two pair
    } else if (maxFrequency == 2) {
        return "pair";  // One pair
    } else {
        return "high";  // High card
    }
}


// Checks if all cards have the same suit
bool Hand::isFlush() {
    QString suit = cards[0].getSuit();
    for (const Card& card : cards) {
        if (card.getSuit() != suit) return false;
    }
    return true;
}

// Checks if the cards form a straight
bool Hand::isStraight() {
    if (cards.empty()) return false;

    QVector<Card> sortedCards = cards;  // Use a copy for operations

    // Sort cards by value
    std::sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
        return a.getValue() < b.getValue();
    });

    // Check for straight
    bool straight = true;
    for (int i = 0; i < sortedCards.size() - 1; i++) {
        if (sortedCards[i].getValue() + 1 != sortedCards[i + 1].getValue()) {
            straight = false;
            break;
        }
    }

    if (!straight && sortedCards[0].getValue() == 14) {
        // Retry considering Ace as 1
        sortedCards[0].value = 1;
        std::sort(sortedCards.begin(), sortedCards.end(), [](const Card& a, const Card& b) {
            return a.getValue() < b.getValue();
        });

        straight = true;
        for (int i = 0; i < sortedCards.size() - 1; i++) {
            if (sortedCards[i].getValue() + 1 != sortedCards[i + 1].getValue()) {
                straight = false;
                break;
            }
        }

    }

    return straight;
}


// Returns the value of the key card in the hand
int Hand::getKeyCardValue() const {
    std::map<int, int> valueCount;
    for (const Card& card : cards) {
        valueCount[card.getValue()]++;
    }

    int keyValue = 0;
    int maxFreq = 0;
    for (const auto& vc : valueCount) {
        if (vc.second > maxFreq || (vc.second == maxFreq && vc.first > keyValue)) {
            keyValue = vc.first;
            maxFreq = vc.second;
        }
    }

    return keyValue;
}

// Returns the sorted values of the cards in descending order
QVector<int> Hand::getSortedCardValues() const {
    QVector<int> values;
    for (const Card& card : cards) {
        values.append(card.getValue());
    }
    std::sort(values.begin(), values.end(), std::greater<int>());
    return values;
}
