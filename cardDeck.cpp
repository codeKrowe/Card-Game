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
// dynarray(orig)
// copy constructor to create copy of dynamic array with its own
// memory. if memory cannot be allocated, exception is thrown
// parameter:	orig - reference to original array
//////////////////////////////////////////////////////////////////////
cardDeck::cardDeck(cardDeck &orig)
{	
  try {
    size = orig.size;
    deck = new int[size];
  
    for (int i=0; i<size; i++)
      deck[i] = orig.deck[i];
  } catch (bad_alloc ex) {
    // report error to cerr and rethrow exception
    cerr << "Error when allocation memory in copy constructor "
	 << "dynArray(orig)\n";
    throw ex;
  }
}

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

void cardDeck::deleteCard()
{
  // If less that the current size
  // then it is better to just reduce the
  // index total size rather than waste
  // processing copying
  size = size-1;
}


void cardDeck::addCard(int card)
{
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



int &cardDeck::accessCard(int index) 
{
  return deck[index]; 
}


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


