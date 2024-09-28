#include "Deck.h"
#include <algorithm>
#include <random>
#include <QStringList>
#include <chrono>  // Include for time-based seeding

//Constructor
Deck::Deck() {
    createDeck(); //Create a deck
}

// Create a new deck of cards,specify the suit and value when creating.
void Deck::createDeck() {
    const QStringList suits = {"hearts", "diamonds", "clubs", "spades"};
    for (const auto &suit : suits) {
        for (int value = 1; value <= 13; ++value) {
            deck.emplace_back(suit, value);
        }
    }
}

//Shuffle the deck
void Deck::shuffleDeck() {
    // Use current time as seed for the random generator
    auto now = std::chrono::high_resolution_clock::now();
    auto seed = now.time_since_epoch().count();
    auto rng = std::default_random_engine{ static_cast<unsigned int>(seed) };  // Shuffle the deck using the random number generator

    std::shuffle(std::begin(deck), std::end(deck), rng);
}

//deal cards
QVector<Card> Deck::dealCards(int count) {
    QVector<Card> dealtCards;
    for (int i = 0; i < count; ++i) {
        if (!deck.empty()) {
            dealtCards.push_back(deck.back()); // Deal the top card from the deck to the player
            deck.pop_back();  // Remove the dealt card from the deck
        }
    }
    return dealtCards;  // Return the dealt card
}

// Insert a card randomly into the deck
void Deck::insertCardRandomly(const Card& card) {
    std::default_random_engine generator(std::random_device{}());
    std::uniform_int_distribution<int> distribution(0, deck.size());
    int randomIndex = distribution(generator); // Generate a random index
    deck.insert(deck.begin() + randomIndex, card); // Insert the card at this random position
}
