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
    cardDeck(int size, int ID);

    // copy constructor
    cardDeck(cardDeck &orig);

   //typedef enum  {player1 = 9999, player2 =10000} playingDecks;

//////////////// Member Functions //////////////////////
    
    //same as getSize -- one should be redundant
    int getNumberOfCards() const;
    //Mutator
    // access the topcard while "deleting" it.
    card getTopCard();
    // gets a specific card and reorders the deck when removed
    card getSpecificCard(card c);
    // Returns a card but does not delete it
    card lookAtCard() const;
    card &lookAtCard(int index) const;    
    void deleteCardDeck();
    // Pop a card on to the top of the Deck
    bool addCard(card c);
    // Shuffle a Decks cards 
    void shuffleDeck();
    void initialiseCardDeck(int setNum/* ,cardDeckcontainer */);
    void createInitialisedCardDeck(int NumSets);
    int &moveAllCards(int &destination);
    static void moveAllCards(cardDeck &source, cardDeck &Destination);

    // Fills a card deck with "Size" number of cards
    void fill();
    card &accessCard(int index);
    //void deleteCard();
    // return the number of cards in the Deck
    const int getSize(){return size;};
    // set the number of cards that will be in the Deck
    void setSize(int s); 
    //Return an  identifier for use in the linked list implementation
    int getID(){return id;};
    inline void setID(int ID){id = ID;}
    inline bool equals(cardDeck &d) {return id == d.id;}



    card getCard(card c, bool &found);

//////Test Functions//////////////////////////////////
    void testListContents();
    void fillcards();

    inline static int assign_id()
    {
    static int next_id;
    return next_id++;
    }

  private:
    int id;
    void f(cardDeck deck);
    // Pointers for array
    // extern cardDeckContainer *Container;
    card *cdeck;
    int size;
};

#endif
