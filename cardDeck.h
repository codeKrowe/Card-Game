//
//
// authors: Jonathan, Cathal, Nidhu
// date:  01.11.2014
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
    int getNumberOfCards() const;
    //Mutator
    card getACard();
    card lookAtCard() const;
    void deleteCardDeck();
    void addCard(card c);
    void shuffleDeck();
    void initialiseCardDeck(int setNum/* ,cardDeckcontainer */);
    void createInitialisedCardDeck(int NumSets);
    // int &moveAllCards(int &destination);
    static void moveAllCards(cardDeck &source, cardDeck &Destination);

    //Test Functions

    card getSpecificCard(card c);

    void testListContents();
    void fill();
    void fillcards();


    card &accessCard(int index);
    void deleteCard();
    const int getSize(){return size;};
    void setSize(int s);
    int getID(){return id;};

    inline bool equals(cardDeck &d) {return id == d.id;}

    inline static int assign_id()
    {
    static int next_id;
    return next_id++;
    }
    // inline void incrementID(){NEXTID++;};
    // int getID() const { return ID; }

  private:
    int id;
    void f(cardDeck deck);
    // Pointers for array
    // extern cardDeckContainer *Container;
    card *cdeck;
    int size;
};

#endif
