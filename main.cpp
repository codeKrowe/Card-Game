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

  card *cdeck;
  cdeck =  new card[52];
  // generate a deck of card objects!
  int counter = 0;
  for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  {
    for (int rank = card::Ace; rank <= card::King; ++rank)
    {
        counter = counter + 1;
        cout << counter << endl;
        // must cast the suit and rank integers back to enum type
        card c2((card::Suit) suit, (card::Rank) rank); 
        cdeck[counter] = c2;
        // // print card rank and suit!
        // cout << c2.getRankAsString() << endl;
        // cout << c2.getSuitAsString() << endl;  
    }
  }

  for (int i = 0; i < 52; ++i)
  {
    cout << cdeck[i].getRankAsString() << endl;
    cout << cdeck[i].getSuitAsString() << endl;
  }
  
  return 0;
}
