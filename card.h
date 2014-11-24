// Definition of a card class
//
// Contains very basic card structure.
// authors: Jonathan, Cathal, Nidhu
// date:    01.11.2014
//////////////////////////////////////////////////////////////////////
#ifndef CARD_H
#define CARD_H

#include <string>

using std::string;

class card
{
public:

    typedef enum  {Clubs, Spades, Hearts, Diamonds} Suit;

    typedef enum {Ace, Two, Three, Four, Five, Six,
                  Seven, Eight, Nine, Ten, Jack, Queen, King} Rank;

    //default constructor required for custom onject array
    card();
    // Create card of suit and rank
    card(Suit suit, Rank rank);

    // Accessors
    inline Rank getCardRank() {return rank;}
    inline Suit getCardSuit() {return suit;}

    // Mutators
    inline void setCardRank(Rank rank) {rank = rank;}
    inline void setCardSuit(Suit suit) {suit = suit;}

    // Method to get ranks and suits as strings.
    string getRankAsString();
    string getSuitAsString();

private:
    Rank rank;
    Suit suit;
    card *ptr;
};

#endif
