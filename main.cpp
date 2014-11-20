#include <iostream>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"
#include "cardDeckContainer.h"

using namespace std;

int main()
{
  /* Test Card Class */

  // Creates a single card
    card c1(card::Clubs, card::Two);
  // cout << "Card created..." << endl;

  // // Print out cagirds suit and rank in string format!
  // cout << c1.getRankAsString() << endl;
  // cout << c1.getSuitAsString() << endl;

  /////////////////////////////////

  /* Test cardDeck Class */
  /* Creating an empty deck */

  // Create a cardDeck.
  // cout << "...Deck 1..." << endl;
  // cardDeck d1;

  // // Get number of cards in empty deck.
  // cout << "Number of cards: " << d1.getNumberOfCards() <<  endl;

  // // Add card to empty deck.
  // d1.addCard(c1);

  // // Get number of cards in deck after 1 card is added.
  // cout << "Number of cards: " << d1.getNumberOfCards() <<  endl;


  /* Test moveAllCards() */
  // cout << "...Deck 2 & Deck 3..." << endl;
    cardDeck d1(4);

    d1.fill();

    d1.testListContents();


    card temp;

    temp = d1.getSpecificCard(c1);
 
    cout << "card return test " << temp.getRankAsString() << " " << temp.getSuitAsString() << endl;
    cout << "Print out with Re-arrangement" << endl;
    d1.testListContents();


  // // d1.addCard(c1);
  // cardDeck d3;
  //   cardDeck d4;
  // cardDeck d5;
  // cardDeck d6;
  // cardDeck d7;


  // // int counter = 0;
  // // for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  // // {
  // //   for (int rank = card::Ace; rank <= card::King; ++rank)
  // //   {
  // //       counter = counter + 1;
  // //       // must cast the suit and rank integers back to enum type
  // //       card c2((card::Suit) suit, (card::Rank) rank);
  // //       d2.addCard(c2);
  // //   }
  // // }

  // cardDeck::moveAllCards(d2, d3);

  // cout << "Size after move" << endl;
  // cout << "deck 1: " << d2.getSize() << endl;
  // cout << "deck 2: " << d3.getSize() << endl;
  // cout << d2.getID() << endl;

  // cout << d3.getID() << endl;
  // cout << d7.getID() << endl;



  // cout << "linked list test code" << endl;

  try {
    // data d1 = {1,"t1","testdata1"};
    // data d2 = {2,"t2","testdata2"};
    // data d3 = {3,"t3","testdata3"};
    
    cardDeckContainer list;
    cardDeck d1(4);
    cardDeck d2(4);
    cardDeck d3(4);
    cardDeck d4(4);
    cardDeck d5(4);
    cardDeck d6(4);   
    // // print empty list
    // cout << "empty list:\n";
    // list.printList();
    // cout << d3.getID() << endl;
    // // insert one element and print again
    list.insertNode(d1);
    // cout << "\n\nlist with one element:\n";
    // list.printList();
    
    // // insert more elements and print again
    list.insertNode(d2);
    list.insertNode(d4);
    list.insertNode(d3);
    list.insertNode(d5);    
    list.insertNode(d6);
    d1.fill();
    d2.fill();
    d3.fill();
    d4.fill();
    d5.fill();
    d6.fill();
    // list.insertNode(d3);
    // cout << "\n\nlist with multiple elements:\n";
    // list.printList();
    list.printList();
    // // create copy of linked list and print copy
    // llist copy(list);
    // cout << "\n\nCopy of list:\n";
    // copy.printList();

    // // remove second element and print
    // list.gotoHead();
    // list.deleteNode(d2);
    // cout << "\n\nlist with second element removed:\n";
    // list.printList();
    list.gotoHead();
    // // attempt to get data of head
    list.gotoNextNode();
    cout << list.accessData().getID() << endl;
    list.gotoNextNode();
    cout << list.accessData().getID() << endl;

    cout << "delete node" << endl;
    cout << list.deleteNode(d1) << endl;

    list.printList();

    list.gotoHead();
    list.gotoNextNode();
    cout << list.accessData().getID() << endl;
    list.gotoNextNode();
    cout << list.accessData().getID() << endl;
    card c = list.accessData().getACard();

    cout << c.getRankAsString() << endl;;

  } catch (const char *ex) {
    cout << "\n\nException detected:\n";
    cout << ex << endl;
  } catch (...) {
    cout << "\n\nUnknown exception detected:\n";
  }
  return 0;




  /* Create a deck dynamically and fill */

  // card *cdeck;
  // cdeck =  new card[52];
  // // generate a deck of card objects!
  // int counter = 0;
  // for (int suit = card::Clubs; suit <= card::Diamonds; ++suit)
  // {
  //   for (int rank = card::Ace; rank <= card::King; ++rank)
  //   {
  //       counter = counter + 1;
  //       cout << counter << endl;
  //       // must cast the suit and rank integers back to enum type
  //       card c2((card::Suit) suit, (card::Rank) rank);
  //       cdeck[counter] = c2;
  //       // // print card rank and suit!
  //       // cout << c2.getRankAsString() << endl;
  //       // cout << c2.getSuitAsString() << endl;
  //   }
  // }

  // for (int i = 0; i < 52; ++i)
  // {
  //   cout << cdeck[i].getRankAsString() << endl;
  //   cout << cdeck[i].getSuitAsString() << endl;
  // }

  /* Code from other main */

  // cardDeck D1(4);
  // D1.fill();
  // cout << D1.getSize() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getSize() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getACard().getRankAsString() << endl;
  // cout << D1.getSize() << endl;
  // cout << D1.getACard().getRankAsString() << endl;


  // card c1(card::Spades, card::Ace);
  // card c2(card::Spades, card::Two);
  // card c3(card::Spades, card::Nine);

  // int i,size, size2, newElem;

  // cardDeck D3;

  // D3.fill();
  // cout << "...Deck 3..." << endl;
  // cout << D3.getSize() << endl;
  // // D1.addCard(c1);

  // cout << "***************" << endl;
  // for (int i = 0; i < D3.getSize() ;++i)
  // {
  //   cout << "Card " << i << endl;
  //  cout << D3.accessCard(i).getRankAsString() << endl;
  //  cout << D3.accessCard(i).getSuitAsString() << endl;
  // }

  // D3.deleteCard();
  // cout << "********DELETE*******" << endl;

  // for (int i = 0; i < D3.getSize() ;++i)
  // {
  //   cout << "Card " << i << endl;
  //  cout << D3.accessCard(i).getRankAsString() << endl;
  //  cout << D3.accessCard(i).getSuitAsString() << endl;
  // }




 //  card c1(card::Spades, card::Ace);
 //  cardDeck shuffleTest(52);
 //  shuffleTest.fill();



 //  // test for error handling in LookatCard
 //  try{
 //  shuffleTest.lookAtCard(53);
 //  }
 //  catch(cardDeckException ex){cout << ex.getException() <<endl;}
 //  // Will throw an exception to custom class cause too big
 //  // shuffleTest.addCard(c1);




 //  for (int i = 0; i < shuffleTest.getSize() ;++i)
 //  {
 //    cout << "Card " << i << endl;
 //   cout << shuffleTest.accessCard(i).getRankAsString() << endl;
 //   cout << shuffleTest.accessCard(i).getSuitAsString() << endl;
 //  }



 //  cout << "*****SHUFFLE TEST *******" << endl;
 // cout << "***************" << endl;
 //  cout << "***************" << endl;

 //  shuffleTest.shuffleDeck();

 //    cout << "***************" << endl;
 //  for (int i = 0; i < shuffleTest.getSize() ;++i)
 //  {
 //    cout << "Card " << i << endl;
 //   cout << shuffleTest.accessCard(i).getRankAsString() << endl;
 //   cout << shuffleTest.accessCard(i).getSuitAsString() << endl;
 //  }





  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  //  cout << D1.accessCard(i) << endl;
  // }

  // cout << "After  2 deleted Cards" << endl;

  // D1.deleteCard();
  // D1.deleteCard();

  // for (int i = 0; i < D1.getSize() ;++i)
  // {
  //  cout << D1.accessCard(i) << endl;
  // }

 
}
