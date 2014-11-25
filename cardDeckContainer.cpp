// Class for Deck Container System
// Will hold the individual card deck objects
//
//
// authors: Jonathan, Cathal, Nidhu
// date:	19.11.2014
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
// class cardDeckContainer
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// cardDeckContainer()
// default constructor of cardDeckContainer list, creates an empty cardDeckContainer
// consisting of head and tail, with the head pointing to the tail
//
// parameter: none
//////////////////////////////////////////////////////////////////////
cardDeckContainer::cardDeckContainer()
  :head(NULL), tail(NULL)
{
  try{
    //Dummy card Deck created (empty) to fill
    //to be used to fill the Head aand Tail of the cardDeckContainer
    cardDeck dummy;
    head = new llDeckNode(dummy);
    tail = new llDeckNode(dummy);
    // adjust links between the head and tail, the tail has none, and the head
    // has a sucessor of the tail
    head->setSuccessor(tail);
    tail->setSuccessor(NULL);
    current = head;
    // Set the current amout of card Decks to Zero
    NoCardDecks = 0;
    // Memory allocation handling 
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
// cardDeckContainer(orig)
// copy constructor
// As this class makes use of dynamic memory allocation, an explicit copy
// constructor is required. It creates an exact copy of orig cardDeckContainer.
//
// parameter: cardDeckContainer &orig - reference to original cardDeckContainer
//////////////////////////////////////////////////////////////////////
cardDeckContainer::cardDeckContainer(cardDeckContainer &orig)
{
  try {
    //Copy over the CardDeck pointer Utilised for 
    //accessing nodes data in a convienient manner
    obby = orig.accessPoppedData();
    cardDeck dummy;
    // safe old current node
    llDeckNode *oldcurrent = orig.current;
    NoCardDecks = orig.getNoCardsDecks();
    // allocate nodes for new list
    head = new llDeckNode(dummy);
    tail = new llDeckNode(dummy);

    // adjust links
    head->setSuccessor(tail);
    tail->setSuccessor(NULL);
    current = head;

    // copy contents of linked list
    orig.gotoHead();
    while (orig.gotoNextNode() == ok) {
      if (orig.current == orig.tail) break;
      push(orig.accessData());
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
// ~cardDeckContainer()
// destructor
// since this class uses dynamic memory, an
// explicit destructor is required
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

//////////////////////////////////////////////////////////////////////
// gotoNextNode()
// sets current node to successor of current node, thus traversing
// the entire linked list one step at a time
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
  llDeckNode *delnode=NULL, *delnodePredecessor=NULL;
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
    NoCardDecks = NoCardDecks - 1;
    // adjust current to predecessor
    current = delnodePredecessor;
  } // node not found, no action required
  return returnvalue;
}


//////////////////////////////////////////////////////////////////////
// returnSpecificDeck(data)
// removes the successor of current from the list (current will be
// modified)
//
// parameter: none
// return: ok - removal successful
//         illegalNode - cannot find node to be removed.
//////////////////////////////////////////////////////////////////////
cardDeckContainer::llError cardDeckContainer::returnSpecificDeck(int ID)
{
  llError returnvalue=illegalNode;
  bool foundNode=false;
  current = head;
  while (current->getSuccessor() != tail) {
    current = current->getSuccessor();
    if (current->getData().getID() == ID) {
      foundNode = true;
      obby = &current->getData();
      break;
    }
  }

  // test if node carrying data has been found
  if (foundNode) {
    // yes, node found
    returnvalue = ok;
    current = head;
  } // node not found, no action required
  //cout << "reached here" << endl;
  return returnvalue;

}

//////////////////////////////////////////////////////////////////////
// accessData()
// accesses the data of the (current node), allows both reading and
// writing access. Kept for compatability
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
// push(cardDeck &data)
// Pushes a new CardDeck into the cardDeckContainer in the manner
// of a stack based linked list
// 
// added the new cardDeck underNeath the Head
// parameter: cardDeck &data
// return: Boolean status 
//////////////////////////////////////////////////////////////////////

bool cardDeckContainer::push(cardDeck &data)
{
  //return status
  bool returnvalue=true;
  try {
    // Pointer for new node
    llDeckNode *newnode;
    // make sure starts at Head, current = head
    gotoHead();
    // double check
    if (current == tail) {
      returnvalue = false;
    } else {
      // insert node to top of the stack undearneath the Head
      newnode = new llDeckNode(data,current->getSuccessor());
      newnode->setSuccessor(current->getSuccessor());
      current->setSuccessor(newnode);
      NoCardDecks = NoCardDecks + 1;
    }
  } catch (bad_alloc ex) {
    // deal with allocation failure
    returnvalue = noMemory;
  }
  return returnvalue;
}


//////////////////////////////////////////////////////////////////////
// pop()
// removes the successor of HEAD from the stack
//
// stores the nodes object for access
// through another method accessPoppedData()
//
// parameter: none
// return: true - removal successful
//         false - cannot find or can find node to be removed.
//////////////////////////////////////////////////////////////////////

bool cardDeckContainer::pop()
{

  bool status = false;
  // Pointers for node for deletion and its predecessor
  llDeckNode *delnode=NULL, *delnodePredecessor=NULL;
  //again start at head as this is a stack
  current = head;
  try{
    // double check
  if (current->getSuccessor() != tail) {
    //
    // stores the predessor as the Head
    delnodePredecessor = current;
    //set the current as the next node, successor of Head
    current = current->getSuccessor();
    //store the object - this is the object that is popped
    // store it in a member attribute for access from another method
    obby = &current->getData();
    // set the current node for deletion - ready for pop
    //Delete node under Head
    delnode = current;
    //connect the the deleted nodes Predecessor [Head] to its successor
    delnodePredecessor->setSuccessor(delnode->getSuccessor());
    // remove the popped node
    delete delnode;
    // adjust current to predecessor [HEAD]
    current = delnodePredecessor;
    status = true;
    // reduce the number of decks specified to be in
    // the container
    NoCardDecks = NoCardDecks - 1;
    }
    else{cout << "Empty STACK -- Nothing to POP" << endl;}
  }catch (bad_alloc ex){cout << "Memory Error" << endl;}
 return status;
}

//////////////////////////////////////////////////////////////////////
// del_empty() 
// removes the successor of HEAD from the stack but does not pop
// was required to fully realise the final Main game logic
//
//
// parameter: none
// return: true - removal successful
//         false - cannot find or can find node to be removed.
//////////////////////////////////////////////////////////////////////

bool cardDeckContainer::del_empty()
{

  bool status = false;
  // Pointers for node for deletion and its predecessor
  llDeckNode *delnode=NULL, *delnodePredecessor=NULL;
  //again start at head as this is a stack
  current = head;
  try{
    // double check
  if (current->getSuccessor() != tail) {
    //
    // stores the predessor as the Head
    delnodePredecessor = current;
    //set the current as the next node, successor of Head
    current = current->getSuccessor();
    // set the current node for deletion - ready for pop
    //Delete node under Head
    delnode = current;
    //connect the the deleted nodes Predecessor [Head] to its successor
    delnodePredecessor->setSuccessor(delnode->getSuccessor());
    // remove the popped node
    delete delnode;
    // adjust current to predecessor [HEAD]
    current = delnodePredecessor;
    status = true;
    NoCardDecks = NoCardDecks - 1;
    }
    else{cout << "Empty STACK -- Nothing to POP" << endl;}
  }catch (bad_alloc ex){cout << "Memory Error" << endl;}
 return status;
}


//////////////////////////////////////////////////////////////////////
// accessPoppedData()
// accesses the data of the popped node
// which is stored in the "obby" class attribute 
// this allowed a simular method of access to a stack
// while not having to deal with Null object returns if
// such an element did not exist in the other functions 
//
// also meant that we did not have to traverse the Container
// using gotos() ect.
//
// parameter: none
// return: reference to data popped from node
//////////////////////////////////////////////////////////////////////

cardDeck *cardDeckContainer::accessPoppedData()
{

  if (obby->getID() == 0)
  {
  throw "There is no popped object available";
  }
  return obby;
  //return current->getData();
}


//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
// class llDeckNode
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
// llDeckNode(newd, nextNode)
// default constructor
// constructs a new node, associates newd as a new Deck and sets its
// successor to nextNode
//
// parameters: data newd - new deck for the node
//            llDeckNode *nextNode - pointer to successor of new node
//////////////////////////////////////////////////////////////////////
llDeckNode::llDeckNode(cardDeck newd, llDeckNode *nextNode)
  : d(newd), successor(nextNode)
{
}

