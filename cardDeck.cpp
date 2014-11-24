// Class for cardDeck
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"

using namespace std;



///////////////////////////////////////////////////////////////////////
// cardDeck() - createEmptyCardDeck()
//    Deafult constructor
// Pre: None
// Post: An Empty deck is created.
///////////////////////////////////////////////////////////////////////
cardDeck::cardDeck()
{
  id = assign_id() + 100;
  // No need to create a dynamic array since empty
  // card deck will have 52 memory slots allocated to it.

  // Set size to zero to note the deck is "empty"
  size = 0;

  // Allocate 52 spaces for card objects.
  cdeck = new card[52];
  //deckContainer = new cardDeck[23];
}

//////////////////////////////////////////////////////////////////////
// cardDeck(newsize, initvalue=0)
// constructor to create a new dynamic deck with size newsize
// if memory cannot be allocated, exception is thrown
//
// parameter: newsize - size of dynamic array
//////////////////////////////////////////////////////////////////////
cardDeck::cardDeck(int newSize, int ID)
{
  id = ID;
  size = newSize;

  try
  {
    cdeck = new card[size];
  }
  catch (bad_alloc ex)
  {
    // report error to cerr and rethrow exception
    cerr << "Error with allocation of memory "
    << "deck(newsize)\n";
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
  try
  {
    size = orig.size;
    id = orig.getID();
    cdeck = new card[size];

    for (int i=0; i<size; i++)
      cdeck[i] = orig.cdeck[i];
  }
  catch (bad_alloc ex)
  {
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
  delete[] cdeck;
}

// Returns a specific card, doesn't delete it!
card cardDeck::getCard(card c, bool &found)
{
  int position;
  card temp;

  for (int i =0; i < size; ++i)
  {
    if(cdeck[i].getCardRank() == c.getCardRank()
      || cdeck[i].getCardSuit() == c.getCardSuit())
    {
      temp = cdeck[i];
      found = true;
    }
  }

  return temp;
}

//////////////////////////////////////////////////////////////////////
//getNumberOfCards()
//////////////////////////////////////////////////////////////////////
int cardDeck::getNumberOfCards() const
{
  return size;
}


//////////////////////////////////////////////////////////////////////
// getTopCard()
//////////////////////////////////////////////////////////////////////
card cardDeck::getTopCard()
{
  // If less that the current size
  // then it is better to just reduce the
  // index total size rather than waste
  // processing copying
  //
  // Simple and effective
  card temp;
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  // THIS THROWS TO MAIN --- Needs Matching CATCH
  // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  try
  {
    int size2 = size - 1;
    if(size2 < 0)
    {
      throw cardDeckException("Size in the negative -- incorrect");
    }
    else
    {
      temp= cdeck[size];
      size = size - 1;
    }
  }
  catch(cardDeckException ex)
  // Silence this because it show randomly in output of game
  // but this has no effect on the game because only temp size2 has been changed
  {/*cout << ex.getException() << endl;*/
    ex.getException();
  }
  return temp;
}

// Returns a specific card, when it finds the card it deletes it while
// moving the cards above it down one postition

card cardDeck::getSpecificCard(card c)
{
  int position;
  card temp;

  for (int i =0; i < size; ++i)
  {
    if(cdeck[i].getCardRank() == c.getCardRank()
      || cdeck[i].getCardSuit() == c.getCardSuit() )
    {
      size = size - 1;
      temp = cdeck[i];
      for (int j = i; j <size; ++j )
      {
        cdeck[j] = cdeck[j+1];
      }
      //needs a break otherwise may delete 2 indexs as the suit and
      //rank may exist in the deck.
      break;
    }
  }

  return temp;
}

//////////////////////////////////////////////////////////////////////
// addCard()
//////////////////////////////////////////////////////////////////////
bool cardDeck::addCard(card passedCard)
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
  bool status = false;
  int i;
  card *newDeck;

  try
  {
    int newsize = size +1;
    if (newsize > 52)
    {
      throw cardDeckException("Size is incorrect");
    }

    newDeck = new card[newsize];
    for (i=0; i<newsize; i++)
    {
      if (i<size)
      {
        newDeck[i] = cdeck[i];
      }
      else
      {
        newDeck[i] = passedCard;
      }
    }
    // deallocate old memory
    delete[] cdeck;
    // use newdata as data
    cdeck = newDeck;
    size = newsize;
    status = true;
  }
  catch(cardDeckException ex)
  {
    cout << ex.getException() << endl;
    size = size - 1;
  }
  catch (bad_alloc memex)
  {
    cerr << "Memory allocation Issue"  << endl;
    throw memex;
  }
  return status;
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
  if (index > size){throw cardDeckException("Index out of range");}
  else {return cdeck[index];}
  return cdeck[index];
}

//////////////////////////////////////////////////////////////////////
//moveAllCards(destination): Moves all cards
//from the CardDeck source to CardDeck destination.
//
//Pre: source and destination are valid instantiations of the ADT CardDeck.
//Post: All cards have been moved from source (which now is empty)
//to destination (which now contains additionally all cards previously in source)
//////////////////////////////////////////////////////////////////////

void cardDeck::moveAllCards(cardDeck &source, cardDeck &destination)
{
  // pass in 2 decks.
  // check if source deck size > 0
  // start looping through the source deck.
  // copy object over to destination deck.
  // after all cards are copied over, delete cards from source

  int sourceSize = source.getNumberOfCards();
  int destSize = destination.getNumberOfCards();

  if (source.getNumberOfCards() > 0)
  {
    for (int i = 0; i < sourceSize; ++i)
    {
      // get card in source deck at position i
      card c = source.lookAtCard(i);

      // add i'th card to destination deck
      destination.addCard(c);
    }

    // all cards moved over, delete source deck
    // delete source;
    source.setSize(0);
  }
  else
  {
    throw cardDeckException("Error No Cards in Source Deck!!");
  }
}

//////////////////////////////////////////////////////////////////////
// shuffleDeck()
//
//
//  Uses a starting seed from time and generates a random sequence
//  this sequecnce does not end up distributing uniformly
//  when attempting to generate a 52 number sequence,
//  so an "Mangled" Bubble swap has been used, where one
//  side of the swap is a random number(r) in range up to the
//  current counter postition counter (i).
//  This swaps at random, and so it doesnt matter if the same index
//  is swaped at some stage as both index objects
//  remain in the Deck regardless.
//  The counter decrements
//
//pre:a valid Deck exists
//post:the contents of that deck have been shuffled
//////////////////////////////////////////////////////////////////////

void cardDeck::shuffleDeck()
{
    srand (time(0));
    for (int i = size-1; i > 0; i--)
    {
      int r = rand() % (i+1);
      card temp = cdeck[i];
      cdeck[i] = cdeck[r];
      cdeck[r] = temp;
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
        cdeck[counter] = cc;
      }
        counter = counter + 1;
    }
  }
}

void cardDeck::setSize(int s)
{
	size = s;
}

//////////////////////////////////////////////////////////////////////
//
// Development Testing Funtions
//
//////////////////////////////////////////////////////////////////////

void cardDeck::testListContents()
{
    for (int i=0; i<size; ++i)
    {
      cout << cdeck[i].getSuitAsString() << " " << cdeck[i].getRankAsString() << endl;
    }
}
