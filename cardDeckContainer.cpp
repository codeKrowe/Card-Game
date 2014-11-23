// llist.cpp: implementation of the llist class.
//
// simple implementation of single linked list
// 
// author:	reiner dojen
// date:	17.10.2003
//////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <iostream>
#include <exception>

#include "cardDeckContainer.h"
#include "cardDeck.h"
#include "card.h"

using namespace std;


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// class llist
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// list()
// default constructor of linked list, creates an empty linked list
// consisting of head and tail, head points to tail
// 
// parameter: none
//////////////////////////////////////////////////////////////////////
cardDeckContainer::cardDeckContainer()
  :head(NULL), tail(NULL)
{
  try{
    cardDeck dummy;
    head = new llnode(dummy);
    tail = new llnode(dummy);
    // adjust links
    head->setSuccessor(tail);
    tail->setSuccessor(NULL);
    current = head;
  } catch (bad_alloc ex) {
    // check if any node has been allocated and clean up
    if (head != NULL) {
      delete head;
      head = NULL;
    }
    if (tail != NULL) {
      delete tail;
      tail = NULL;
    }
    // throw exception
    throw "Allocation Error in default constructor llist()";
  }
}

//////////////////////////////////////////////////////////////////////
// llist(orig)
// copy constructor
// as class makes use of dynamic memory allocation, explicit copy 
// constructor is required. creates an exact copy of orig.
//
// parameter: llist &orig - reference to original linked list
//////////////////////////////////////////////////////////////////////
cardDeckContainer::cardDeckContainer(cardDeckContainer &orig)
{
  try {
    cardDeck dummy;
    // safe old current node
    llnode *oldcurrent = orig.current;
    
    // allocate nodes for new list
    head = new llnode(dummy);
    tail = new llnode(dummy);
    
    // adjust links
    head->setSuccessor(tail);
    tail->setSuccessor(NULL);
    current = head;
    
    // copy contents of linked list
    orig.gotoHead();
    while (orig.gotoNextNode() == ok) {
      if (orig.current == orig.tail) break;
      insertNode(orig.accessData());
      gotoNextNode();
    }
    
    // find current node in original and copied list
    orig.gotoHead();
    gotoHead();
    while (orig.current != oldcurrent) {
      orig.gotoNextNode();
      gotoNextNode();
    }
  } catch (bad_alloc ex) {
    // check if any node has been allocated and clean up
    if (head != NULL) {
      delete head;
      head = NULL;
    }
    if (tail != NULL) {
      delete tail;
      tail = NULL;
    }
    // throw exception
    throw "Allocation Error in copy constructor llist(orig)";
  }
    
}
  
//////////////////////////////////////////////////////////////////////
// ~llist()
// destructor
// as class uses dynamic memory, explicit destructor is required
//////////////////////////////////////////////////////////////////////
cardDeckContainer::~cardDeckContainer()
{
  gotoHead();
  while (gotoNextNode() == ok) {
    deleteNode(current->getData());
  }
  delete head;
  delete tail;
}

//////////////////////////////////////////////////////////////////////
// member function definition
//////////////////////////////////////////////////////////////////////
// insertNode(newdata)
// creates a new node, associates newdata with it and inserts the
// new node after the current node
//
// parameter: data &newdata - reference to data for node
// return: ok - node has been inserted
//         noMemory - no memory was available for construction of
//                          node
//         illegalNode - cannot insert node after tail
//////////////////////////////////////////////////////////////////////
cardDeckContainer::llError cardDeckContainer::insertNode(cardDeck &newdata)
{
  llnode *newnode;
  llError returnvalue=ok;
  try {
    // test if insertion is possible at current location
    if (current == tail) {
      returnvalue = illegalNode;
    } else {
      // insert node
      newnode = new llnode(newdata,current->getSuccessor());
      newnode->setSuccessor(current->getSuccessor());
      current->setSuccessor(newnode);
    }
  } catch (bad_alloc ex) {
    // deal with allocation failure
    returnvalue = noMemory;
  }    
  return returnvalue;		
}

//////////////////////////////////////////////////////////////////////
// gotoNextNode()
// sets current node to successor of current node, thus traversing
// eventually the entire linked list
//
// parameter: none
// return: ok - goto successfull
//         illegalNode - successor of current is tail 
//////////////////////////////////////////////////////////////////////
cardDeckContainer::llError cardDeckContainer::gotoNextNode()
{
  llError returnvalue=ok;
  if (current->getSuccessor() == tail) {
    // end reached, cannot move
    returnvalue = illegalNode;
  } else {
    // move current to next node
    current = current->getSuccessor();
  }
  return returnvalue;
}

//////////////////////////////////////////////////////////////////////
// deleteNode(data)
// removes the successor of current from the list (current will be
// modified)
//
// parameter: none
// return: ok - removal successful
//         illegalNode - cannot find node to be removed.
//////////////////////////////////////////////////////////////////////
cardDeckContainer::llError cardDeckContainer::deleteNode(cardDeck &d)
{
  llnode *delnode=NULL, *delnodePredecessor=NULL;
  llError returnvalue=illegalNode;
  bool foundNode=false;
  current = head;
  while (current->getSuccessor() != tail) {
    delnodePredecessor = current;
    current = current->getSuccessor();
    if (current->getData().equals(d)) {
      foundNode = true;
      delnode = current;
      break;
    }
  } 

  // test if node carrying data has been found
  if (foundNode) {
    // yes, node found, delete it
    returnvalue = ok;
    // unlink node to be deleted
    delnodePredecessor->setSuccessor(delnode->getSuccessor());
    // remove node
    delete delnode;
    // adjust current to predecessor
    current = delnodePredecessor;
  } // node not found, no action required
  return returnvalue;
}

//////////////////////////////////////////////////////////////////////
// accessData()
// accesses the data of the current node, allows both reading and
// writing access.
//
// parameter: none
// return: reference to data associated with current node
//////////////////////////////////////////////////////////////////////
cardDeck &cardDeckContainer::accessData()
{
  if (current == head) throw "Accessing data of head node";

  return current->getData();
}

//////////////////////////////////////////////////////////////////////
// printList()
// prints the entire linked list to the screen (standard output)
// attention: the member current of the linked list should not be 
// modified
//
// parameter: none
// return: void
//////////////////////////////////////////////////////////////////////
void cardDeckContainer::printList() 
{
  llnode *printCurrent=head->getSuccessor();
  cout << "Head" << endl;
  while (printCurrent != tail) {
    cout << "ID: " 
	   << printCurrent->getData().getID() << endl;
    printCurrent = printCurrent->getSuccessor();
  }
	cout << "Tail" << endl;
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// class llnode
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// llnode(newd, nextNode)
// default constructor
// constructs a new node, associates newd as data and sets its
// successor to nextNode
//
// parameter: data newd - data for the new node
//            llnode *nextNode - pointer to successor of new node
//////////////////////////////////////////////////////////////////////
llnode::llnode(cardDeck newd, llnode *nextNode) 
  : d(newd), successor(nextNode)
{
}

