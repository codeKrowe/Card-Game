#ifndef CARD_H
#define CARD_H

#include <string>

class Card
{
public:
    typedef enum {Ace, Two, Three, Four, Five, Six,
                  Seven, Eight, Nine, Ten, Jack, Queen, King} Rank;

    typedef enum  {Clubs, Spades, Hearts, Diamonds} Suit;


   // Create card of suit and rank
    Card(Suit suit, Rank rank);

    // Accessors
    inline Rank getCardRank() {return rank;}
    inline Suit getCardSuit() {return suit;}

    // Mutators
    inline void setCardRank(Rank rank) {rank = rank;}
    inline void setCardSuit(Suit suit) {suit = suit;}

    // Method to get ranks and suits as strings.
    std::string getRankAsString(Rank rank);
    std::string getSuitAsString(Suit suit);

private:
    Rank rank;
    Suit suit;
};

#endif
