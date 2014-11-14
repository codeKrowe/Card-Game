// 
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////

#include <iostream>
#include <exception>
#include "cardDeck.h"

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
    deck = new int[size];
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
  try {
    size = orig.size;
    deck = new int[size];
  
    for (int i=0; i<size; i++)
      deck[i] = orig.deck[i];
  } catch (bad_alloc ex) {

    //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /// Need to change this to custom Exceptions class
    //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    // report error to cerr and rethrow exception
    cerr << "Error when allocation memory in copy constructor "
   << "dynArray(orig)\n";
    throw ex;
  }
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
  delete[] deck;
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

void cardDeck::addCard(int card)
{
  /*
  need to make sure that cards cant be added
  above 52
  Correct Error handling too
  */
  int i;
  int *newDeck;
  int newsize = size +1;

  newDeck = new int[newsize];

  for (i=0; i<newsize; i++) {
    if (i<size) newDeck[i] = deck[i];
    else newDeck[i] = card;
  }
  // deallocate old memory
  delete[] deck;
  // use newdata as data
  deck = newDeck;
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

int &cardDeck::lookAtCard(int index) const
{
  return deck[index]; 
}
int &cardDeck::accessCard(int index) 
{
  return deck[index]; 
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
//////////////////////////////////////////////////////////////////////

void cardDeck::shuffleDeck()
{

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



//////////////////////////////////////////////////////////////////////
// 
// Development Testing Funtions
//
//////////////////////////////////////////////////////////////////////

void cardDeck::testListContents()
{
    for (int i=0; i<size+2; ++i) 
    {
    cout << deck[i] << endl;

    }
}

void cardDeck::fill()
{
    for (int i=0; i< size; ++i) 
    {
    deck[i] = i;
    }
}


