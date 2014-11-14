// Definition of a card class
//
// Contains very basic card structure.

#ifndef CARD_H
#define CARD_H

#include <string>

class card
{
public:
    
    typedef enum  {Clubs, Spades, Hearts, Diamonds} Suit;
    
    typedef enum {Ace, Two, Three, Four, Five, Six,
                  Seven, Eight, Nine, Ten, Jack, Queen, King} Rank;



   // Create card of suit and rank
    card(Suit suit, Rank rank);

    // Accessors
    inline Rank getCardRank() {return rank;}
    inline Suit getCardSuit() {return suit;}

    // Mutators
    inline void setCardRank(Rank rank) {rank = rank;}
    inline void setCardSuit(Suit suit) {suit = suit;}

    // Method to get ranks and suits as strings.
    std::string getRankAsString();
    std::string getSuitAsString();

private:
    Rank rank;
    Suit suit;
};

#endif
