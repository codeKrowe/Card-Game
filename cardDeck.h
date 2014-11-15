// 
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////
#include "card.h"
#ifndef CARDDECK_H
#define CARDDECK_H


class cardDeck  
{
 public:
 	//Default
 	cardDeck();

 	//Destructor
 	~cardDeck();

 	//Generic
 	cardDeck(int size);

 	// copy constructor
  	cardDeck(cardDeck &orig);

  	//Accessor 
  	card &lookAtCard(int index) const;
  	card &accessCard(int index);
  	const int getSize(){return size;};

  	//Mutator
  	void deleteCard();
  	void deleteCardDeck();

  	void addCard(card c);
  	void shuffleDeck();
  	void initialiseCardDeck(int setNum);

  	void createInitialisedCardDeck(int num);

  	int &moveAllCards(int &destination);
  	//Test Funtions 
  	void testListContents();
  	void fill();
    void fillcards();


 private:
 void f(cardDeck deck);
 // Pointers for array
 int *deck;
 card *cdeck;
 int size;
};

#endif 