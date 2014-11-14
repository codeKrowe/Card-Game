
#ifndef CARDDECK_H
#define CARDDECK_H


class cardDeck  
{
 public:
 	cardDeck();

 	cardDeck(int size);
 	// copy constructor
  	cardDeck(cardDeck &orig);
  	int &accessCard(int index);
 	// //void deleteCardDeck(&Deck);
  	// 	int addCard(int e);
  	void deleteCard();
  	void addCard(int card);
  	int getSize(){return size;};

  	//Test Funtion listing contents of array
  	void testListContents();
  	void fill();

 private:
 void f(cardDeck deck);
 int *deck;
 int size;
};

#endif 