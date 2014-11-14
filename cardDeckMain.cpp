
#include <iostream>
#include "cardDeck.h"
using namespace std;


int main() 
{
  int i,size, size2, newElem;
	
  cardDeck D1(4);

  D1.fill();

  D1.deleteCard();

  D1.addCard(3);
  D1.addCard(55);
  D1.addCard(55);
  D1.addCard(88);

  D1.deleteCard();


  for (int i = 0; i < D1.getSize() ;++i)
  {
  	cout << D1.accessCard(i) << endl;
  }
  return 0;
}

