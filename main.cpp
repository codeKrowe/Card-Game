#include <iostream>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"

using namespace std;

int main()
{
  /* Test Card Class */

  // Creates a single card
  card c1(card::Spades, card::Ace);
  cout << "Card created..." << endl;

  // Print out cards suit and rank in string format!
  cout << c1.getRankAsString() << endl;
  cout << c1.getSuitAsString() << endl;

  /////////////////////////////////

  /* Test cardDeck Class */
  /* Creating an empty deck */

  // Create a cardDeck.
  cardDeck cd1;

  // Get number of cards in empty deck.
  cout << "Number of cards: " << cd1.getNumberOfCards() <<  endl;

  // Add card to empty deck.
  cd1.addCard(c1);

  // Get number of cards in deck after 1 card is added.
  cout << "Number of cards: " << cd1.getNumberOfCards() <<  endl;

  /* Create a deck dynamically and fill */

  // card *cdeck;
  // cdeck =  new card[52];
  // // generate a deck of card objects!
  // int counter = 0;
  // for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  // {
  //   for (int rank = card::Ace; rank <= card::King; ++rank)
  //   {
  //       counter = counter + 1;
  //       cout << counter << endl;
  //       // must cast the suit and rank integers back to enum type
  //       card c2((card::Suit) suit, (card::Rank) rank);
  //       cdeck[counter] = c2;
  //       // // print card rank and suit!
  //       // cout << c2.getRankAsString() << endl;
  //       // cout << c2.getSuitAsString() << endl;
  //   }
  // }

  // for (int i = 0; i < 52; ++i)
  // {
  //   cout << cdeck[i].getRankAsString() << endl;
  //   cout << cdeck[i].getSuitAsString() << endl;
  // }

  /* Code from other main */

  // cardDeck D1(4);
  // D1.fill();
  // cout << D1.getSize() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getSize() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getSize() << endl;
  // cout << D1.getACard().getRankAsString() << endl;


  // card c1(card::Spades, card::Ace);
  // card c2(card::Spades, card::Two);
  // card c3(card::Spades, card::Nine);

  // int i,size, size2, newElem;

  // cardDeck D1(4);



  // D1.fill();
  // D1.addCard(c1);

  // cout << "***************" << endl;
  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  //   cout << "Card " << i << endl;
  //  cout << D1.accessCard(i).getRankAsString() << endl;
  //  cout << D1.accessCard(i).getSuitAsString() << endl;
  // }

  // D1.deleteCard();
  // cout << "********DELETE*******" << endl;

  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  //   cout << "Card " << i << endl;
  //  cout << D1.accessCard(i).getRankAsString() << endl;
  //  cout << D1.accessCard(i).getSuitAsString() << endl;
  // }




 //  card c1(card::Spades, card::Ace);
 //  cardDeck shuffleTest(52);
 //  shuffleTest.fill();



 //  // test for error handling in LookatCard
 //  try{
 //  shuffleTest.lookAtCard(53);
 //  }
 //  catch(cardDeckException ex){cout << ex.getException() <<endl;}
 //  // Will throw an exception to custom class cause too big
 //  // shuffleTest.addCard(c1);




 //  for (int i = 0; i < shuffleTest.getSize() ;++i)
 //  {
 //    cout << "Card " << i << endl;
 //   cout << shuffleTest.accessCard(i).getRankAsString() << endl;
 //   cout << shuffleTest.accessCard(i).getSuitAsString() << endl;
 //  }



 //  cout << "*****SHUFFLE TEST *******" << endl;
 // cout << "***************" << endl;
 //  cout << "***************" << endl;

 //  shuffleTest.shuffleDeck();

 //    cout << "***************" << endl;
 //  for (int i = 0; i < shuffleTest.getSize() ;++i)
 //  {
 //    cout << "Card " << i << endl;
 //   cout << shuffleTest.accessCard(i).getRankAsString() << endl;
 //   cout << shuffleTest.accessCard(i).getSuitAsString() << endl;
 //  }





  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  //  cout << D1.accessCard(i) << endl;
  // }

  // cout << "After  2 deleted Cards" << endl;

  // D1.deleteCard();
  // D1.deleteCard();

  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  //  cout << D1.accessCard(i) << endl;
  // }

  return 0;
}
