
#include <iostream>
#include "cardDeck.h"
#include "card.h"
#include <string>

using namespace std;

///

int main() 
{

  card c1(card::Spades, card::Ace);
  card c2(card::Spades, card::Two);
  card c3(card::Spades, card::Nine);

  int i,size, size2, newElem;
	
  cardDeck D1(4);

 

  D1.fill();
  D1.addCard(c1);

  cout << "***************" << endl;
  for (int i = 0; i < D1.getSize() ;++i)
  {
    cout << "Card " << i << endl;
   cout << D1.accessCard(i).getRankAsString() << endl;
   cout << D1.accessCard(i).getSuitAsString() << endl;   
  }

  D1.deleteCard();
  cout << "********DELETE*******" << endl;

  for (int i = 0; i < D1.getSize() ;++i)
  {
    cout << "Card " << i << endl;
   cout << D1.accessCard(i).getRankAsString() << endl;
   cout << D1.accessCard(i).getSuitAsString() << endl;   
  }  



   cout << "*****SHUFFLE TEST *******" << endl;
  cardDeck shuffleTest(52);
  shuffleTest.fill();
 cout << "***************" << endl;
  cout << "***************" << endl;
  for (int i = 0; i < shuffleTest.getSize() ;++i)
  {
    cout << "Card " << i << endl;
   cout << shuffleTest.accessCard(i).getRankAsString() << endl;
   cout << shuffleTest.accessCard(i).getSuitAsString() << endl;   
  }

  shuffleTest.shuffleDeck();

    cout << "***************" << endl;
  for (int i = 0; i < shuffleTest.getSize() ;++i)
  {
    cout << "Card " << i << endl;
   cout << shuffleTest.accessCard(i).getRankAsString() << endl;
   cout << shuffleTest.accessCard(i).getSuitAsString() << endl;   
  }

  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  // 	cout << D1.accessCard(i) << endl;
  // }

  // cout << "After  2 deleted Cards" << endl;

  // D1.deleteCard();
  // D1.deleteCard();

  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  // 	cout << D1.accessCard(i) << endl;
  // }
  return 0;
}

