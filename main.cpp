#include "card.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  // Creates a single card
  card c1(card::Spades, card::Ace);
  cout << "Card created..." << endl;

  // Print out cards suit and rank in string format!
  cout << c1.getRankAsString() << endl;
  cout << c1.getSuitAsString() << endl;

  // generate a deck of card objects!
  for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  {
    for (int rank = card::Ace; rank <= card::King; ++rank)
    {
        // must cast the suit and rank integers back to enum type
        card c2((card::Suit) suit, (card::Rank) rank); 

        // print card rank and suit!
        cout << c2.getRankAsString() << endl;
        cout << c2.getSuitAsString() << endl;  
    }
  }
  
  return 0;
}
