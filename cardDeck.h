// 
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////
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
  	int &lookAtCard(int index) const;
  	int &accessCard(int index);
  	const int getSize(){return size;};

  	//Mutator
  	void deleteCard();
  	void deleteCardDeck();

  	void addCard(int card);
  	void shuffleDeck();
  	void initialiseCardDeck(int setNum);

  	void createInitialisedCardDeck(int num);

  	int &moveAllCards(int &destination);
  	//Test Funtions 
  	void testListContents();
  	void fill();


 private:
 void f(cardDeck deck);
 int *deck;
 int size;
};

#endif 