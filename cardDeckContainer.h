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



// define linked list class
class cardDeckContainer
{
 public:
  bool push(cardDeck &data);
  bool pop();
  bool del_empty();

  // define error-conditions
  typedef enum {ok,noMemory,illegalNode} llError;

  // access data last popped from the stack
  cardDeck * accessPoppedData();
  // Used by member methods

  inline int getNoCardsDecks(){return NoCardDecks;};

  cardDeck & accessData();
  inline void gotoHead() {current = head;}
  llError gotoNextNode();
  llError deleteNode(cardDeck &d);
  llError insertNode(cardDeck &newdata);

  llError returnSpecificDeck(int id);

  void printList();
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
