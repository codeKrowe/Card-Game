//
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////
#ifndef CARDDECK_H
#define CARDDECK_H

#include "card.h"

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
    int getNumberOfCards() const;
  	//Mutator
    card getACard();
    card lookAtCard() const;
  	void deleteCardDeck();
  	void addCard(card c);
  	void shuffleDeck();
  	void initialiseCardDeck(int setNum/* ,cardDeckcontainer */);
    void createInitialisedCardDeck(int NumSets);
  	int &moveAllCards(int &destination);

  	//Test Functions
  	void testListContents();
  	void fill();
    void fillcards();
    card &accessCard(int index);
    void deleteCard();
    const int getSize(){return size;};

<<<<<<< HEAD
  private:
    void f(cardDeck deck);
    // Pointers for array
    card *cdeck;
    int size;
=======
 private:
 void f(cardDeck deck);
 // Pointers for array
 card **cardDeckContainer;
 card *cdeck;
 int size;
>>>>>>> 1dfe0e67c346f71c9c728ae4aaaca69e6591843e
};

#endif
