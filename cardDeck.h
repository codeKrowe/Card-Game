// Class for cardDeck
//
// authors: Jonathan, Cathal, Nidhu
// date:  01.11.2014
//////////////////////////////////////////////////////////////////////
#ifndef CARDDECK_H
#define CARDDECK_H

#include "card.h"

class cardDeck
{
  public:

    /* Construction/Destruction */

    //Default
    cardDeck();

    //Destructor
    ~cardDeck();

    //Generic
    cardDeck(int size, int ID);

    // Copy constructor
    cardDeck(cardDeck &orig);

    /* Member Functions */

    // Various Methods for getting/looking up cards,
    // as well as operations on decks

    // Look for a specific card.
    card getCard(card c, bool &found);

    // Look for a specific card and removes it.
    card getSpecificCard(card c);

    // Gets top card of a deck and removes it.
    card getTopCard();

    // Returns a reference to a specific card.
    card &lookAtCard(int index) const;

    // Return size of a deck
    int getNumberOfCards() const;

    // Return id of a deck
    inline int getID() {return id;}

    // Adds a card object to a cardDeck
    bool addCard(card c);

    // Shuffle a cardDeck
    void shuffleDeck();

    // Move all cards from one deck to another
    static void moveAllCards(cardDeck &source, cardDeck &Destination);

    // Check if two cardDeck id's match
    inline bool equals(cardDeck &d) {return id == d.id;}

    // fill a deck up to 52 cards
    void fill();

    // set the size of a deck
    void setSize(int s);

    // Return an identifier for use in the linked list implementation
    inline void setID(int ID){id = ID;}

    // Assign an id to a deck
    inline static int assign_id()
    {
        static int next_id;
        return next_id++;
    }

    /*Test Functions*/
    void testListContents();

  private:
    // pointer for an array of cards
    card *cdeck;
    int id;
    int size;
};

#endif
