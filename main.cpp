#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Card c1(Card::Suit Spades, Card::Rank Two);
    cout << "Card created..." << endl;

    // This gives an error, no idea why???
    // Was trying different things to make it work.

    /*
    main.cpp:12:8: error: request for member ‘getCardRank’ in ‘c1’, which is of non-class type ‘Card(Card::Suit, Card::Rank)’
     c1.getCardRank();
    */


    c1.getCardRank();

    // cout << c.getCardRank << endl;
    // cout << c.getCardSuit << endl;
    // c.getCardRank;
    // c.getCardSuit;
    // string a = c1.getRankAsString();
    // string b = c1.getSuitAsString();

    return 0;
}
