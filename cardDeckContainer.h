// llist.h: interface for the llist class.
//
//////////////////////////////////////////////////////////////////////
#include "cardDeck.h"
#ifndef CARDDECKCONTAINER_H
#define CARDDECKCONTAINER_H

// define single node of linked list
class llnode {
 public:
  llnode(cardDeck newd, llnode *nextNode=NULL);
  inline cardDeck &getData() { return d;}
  inline llnode *getSuccessor() {return successor;}
  inline void setSuccessor(llnode *nextNode){ successor = nextNode;}
 private:
  cardDeck d;
  llnode *successor;
};



// define linked list class
class cardDeckContainer  
{
 public:
  // define error-conditions
  typedef enum {ok,noMemory,illegalNode} llError;
  cardDeck & accessData();
  inline void gotoHead() {current = head;}
  llError gotoNextNode();
  llError deleteNode(cardDeck &d);
  llError insertNode(cardDeck &newdata);
  void printList();
  cardDeckContainer(cardDeckContainer &orig);
  cardDeckContainer();
  virtual ~cardDeckContainer();
  
 private:
  llnode *head;
  llnode *tail;
  llnode *current;
};

#endif 
