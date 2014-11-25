// llist.h: interface for the llist class.
//
//////////////////////////////////////////////////////////////////////
#include "cardDeck.h"
#ifndef CARDDECKCONTAINER_H
#define CARDDECKCONTAINER_H

// define single node of linked list
class llDeckNode {
 public:
  llDeckNode(cardDeck newd, llDeckNode *nextNode=NULL);
  inline cardDeck &getData() { return d;}
  inline llDeckNode *getSuccessor() {return successor;}
  inline void setSuccessor(llDeckNode *nextNode){ successor = nextNode;}
 private:
  cardDeck d;
  llDeckNode *successor;
};


class cardDeckContainer
{
 public:
  // define error-conditions
  typedef enum {ok,noMemory,illegalNode} llError;

  // Container data manipulations 
  bool push(cardDeck &data);
  bool pop();
  bool del_empty();
  // access data last popped from the stack
  cardDeck * accessPoppedData();
  //return a spefic Deck from the container based on ID
  llError returnSpecificDeck(int id);
  //return the number of decks in the container
  inline int getNoCardsDecks(){return NoCardDecks;};


  // Used by member methods
  cardDeck & accessData();
  inline void gotoHead() {current = head;}
  llError gotoNextNode();
  llError deleteNode(cardDeck &d);

  //Constructors and Deststructors
  cardDeckContainer(cardDeckContainer &orig);
  cardDeckContainer();
  virtual ~cardDeckContainer();

 private:
  int NoCardDecks;
  cardDeck *obby;
  llDeckNode *head;
  llDeckNode *tail;
  llDeckNode *current;
};

#endif
