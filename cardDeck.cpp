// 
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
#include "cardDeck.h"
#include "card.h"


using namespace std;

//////////////////////////////////////////////////////////////////////
// cardDeck(newsize, initvalue=0)
// constructor to create a new dynamic deck with size newsize 
// if memory cannot be allocated, exception is thrown
//
// parameter: newsize - size of dynamic array
//////////////////////////////////////////////////////////////////////

cardDeck::cardDeck(int newSize)
{ 
  size = newSize;
  try {
    //deck = new int[size];
    cdeck = new card[size];
    //cdeck = new card[size]
  } catch (bad_alloc ex) {
    // report error to cerr and rethrow exception
    cerr << "Error when allocation memory in constructor "
    << "dynArray(newsize)\n";
    throw ex;
  }
}

//////////////////////////////////////////////////////////////////////
// dynarray(orig)
// copy constructor to create copy of a card deck with its own
// memory. if memory cannot be allocated, exception is thrown
// parameter: orig - reference to original deck
//////////////////////////////////////////////////////////////////////
cardDeck::cardDeck(cardDeck &orig)
{ 
  // try {
  //   size = orig.size;
  //   deck = new int[52];
  
  //   for (int i=0; i<size; i++)
  //     deck[i] = orig.deck[i];
  // } catch (bad_alloc ex) {

  //   //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  //   /// Need to change this to custom Exceptions class
  //   //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

  //   // report error to cerr and rethrow exception
  //   cerr << "Error when allocation memory in copy constructor "
  //  << "dynArray(orig)\n";
  //   throw ex;
  // }
}

//////////////////////////////////////////////////////////////////////
// ~cardDeck()
// destructor for class - frees up 
// the dynamically allocated
// memory
//
// parameter: none
//////////////////////////////////////////////////////////////////////

cardDeck::~cardDeck()
{
  delete[] cdeck;
}

//////////////////////////////////////////////////////////////////////
// deleteCard()
//////////////////////////////////////////////////////////////////////


void cardDeck::deleteCard()
{
  // If less that the current size
  // then it is better to just reduce the
  // index total size rather than waste
  // processing copying
  //
  // Simple and effective
  if (size > 0){size = size-1;}
}

//////////////////////////////////////////////////////////////////////
// addCard()
//////////////////////////////////////////////////////////////////////

void cardDeck::addCard(card passedCard)
{
  /*
  need to make sure that cards cant be added
  above 52

  Also the delete function just 
  make an index unaccessable
  so test to make sure index are
  just not hidden before wasting 
  resouces --- Note to Self

  Correct Error handling too
  */
  int i;
  card *newDeck;
  int newsize = size +1;

  newDeck = new card[newsize];

  for (i=0; i<newsize; i++) {
    if (i<size) newDeck[i] = cdeck[i];
    else newDeck[i] = passedCard;
  }
  // deallocate old memory
  delete[] cdeck;
  // use newdata as data
  cdeck = newDeck;
  size = newsize;

}

//////////////////////////////////////////////////////////////////////
// lookAtCard(index)
// provides access (both reading and writing) to the top element
// of the card deck.
// 
// Does not modify the Deck
//
// parameter: index - index of element to be accessed
//////////////////////////////////////////////////////////////////////

card &cardDeck::lookAtCard(int index) const
{
  return cdeck[index]; 
}

card &cardDeck::accessCard(int index) 
{
  return cdeck[index]; 
}


///////////////////////////////////////////////////////////
//
// Incomplete Funtions 
//////////////////////

//////////////////////////////////////////////////////////////////////
//moveAllCards(destination): Moves all cards 
//from the CardDeck source to CardDeck destination.
//
//Pre: source and destination are valid instantiations of the ADT CardDeck.
//Post: All cards have been moved from source (which now is empty) 
//to destination (which now contains additionally all cards previously in source)
//////////////////////////////////////////////////////////////////////

int &cardDeck::moveAllCards(int &destination)
{
return destination;
}

//////////////////////////////////////////////////////////////////////
// shuffleDeck()
//
//
//Uses a starting seed from time and generates a random sequence
//this sequecnce does not end up distributing uniformly
//when attempting to generate a 52 number sequence, 
//so an "Mangled" Bubble swap has been used, where one
//side of the swap is a random number(r) in range up to the 
//current counter postition counter (i).
//This swaps at random, and so it doesnt matter if the same index
//is swaped at some stage as both index objects
//remain in the Deck regardless.
//
//pre:a valid Deck exists
//post:the contents of that deck have been shuffled in position
//////////////////////////////////////////////////////////////////////

void cardDeck::shuffleDeck()
{
    srand (time(0));
    for (int i = 52-1; i > 0; i--)
    {
        int r = rand() % (i+1);
        card temp = cdeck[i];
        cdeck[i] = cdeck[r];
        cdeck[r] = temp;
    }
}


//////////////////////////////////////////////////////////////////////
//initialiseCardDeck(int setNum)
//////////////////////////////////////////////////////////////////////

void cardDeck::initialiseCardDeck(int setNum)
{


}


void cardDeck::deleteCardDeck()
{


}


void cardDeck::createInitialisedCardDeck(int s)
{


}

void cardDeck::fillcards()
{
  int counter = 0;
  for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  {
    for (int rank = card::Ace; rank <= card::King; ++rank)
    {
    counter = counter + 1;
    card cc((card::Suit) suit, (card::Rank) rank); 
    cdeck[counter] = cc;
    }
  }
}

//////////////////////////////////////////////////////////////////////
// 
// Development Testing Funtions
//
//////////////////////////////////////////////////////////////////////

void cardDeck::testListContents()
{
    for (int i=0; i<size+2; ++i) 
    {

    }
}


void cardDeck::fill()
{
  int counter = 0;
  for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  {
    for (int rank = card::Ace; rank <= card::King; ++rank)
    {
    if (counter < size)
    {

    card cc((card::Suit) suit, (card::Rank) rank); 
    cdeck[counter] = cc;}
    counter = counter + 1;
    }
  }
}



