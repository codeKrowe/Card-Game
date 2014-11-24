#include <iostream>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"
#include "cardDeckContainer.h"
#include "player.h"

using namespace std;

int main()
{
  try{
  cardDeckContainer Container;

  int no_of_decks;
  cout << "Please Enter a Number of Decks to play with" << endl;
  cin >> no_of_decks;


  for (int i = 0; i < no_of_decks; ++i)
  {
    //cout << "\nCdECK ID = \n" << (i+1) << endl;
    //create sets of card decks (52 C's) for main deck, with INT ID's
    cardDeck cd(52,(i+1));
    cd.fill();
    cd.shuffleDeck();
    // push places to top of the Linked List
    // Under Head/
    // if you use insertNode you will have to got to a postion (head)
    // with gotoHead() beforehand
    Container.push(cd);
  }
  cardDeckContainer player1Container;
  cardDeck Player1Deck;
  Player1Deck.setID(1);
  player1Container.push(Player1Deck);


  cardDeckContainer player2Container;
  cardDeck Player2Deck;
  Player2Deck.setID(1);
  player2Container.push(Player2Deck);

  ///////////////////////////////////////
  /// Holder container//////////////////
  // for the played cards decks////////
  cardDeckContainer holderContainer;
  cardDeck holderDeck;
  holderDeck.setID(1);
  holderContainer.push(holderDeck);

  // this loop demos  placing seven cards into the player
  // decks one at a time
  // first get the number of decks in the container
  // so that the top one can be accessed
  int numberDecksMainContainer = Container.getNoCardsDecks();
  Container.returnSpecificDeck(numberDecksMainContainer);
  player2Container.returnSpecificDeck(1);
  player1Container.returnSpecificDeck(1);


  // cout << " player 2 container size" << endl;
  // cout << player2Container.accessPoppedData()->getSize() << endl;

 // cout << "  container size  " << endl;
  //cout << Container.accessPoppedData()->getSize() << endl;

  for (int i = 1;i <= 14; ++i)
  {
    if((i+2)%2 == 0)
    {

     player2Container.accessPoppedData()->addCard(Container.accessPoppedData()->getTopCard());
    }
    else
    {

     player1Container.accessPoppedData()->addCard(Container.accessPoppedData()->getTopCard());  
    }
  }

  //cout << "  container size after" << endl;
 // cout << Container.accessPoppedData()->getSize() << endl;

  holderContainer.returnSpecificDeck(1);
  int currentHolderDeck = 1;
  int currentDeck = Container.getNoCardsDecks();
  //Container.returnSpecificDeck(currentDeck);

  bool found = false;
  int counter = 2;

////////////////////////////////////////////////////////////////////////////////
//   Main Loop
/////////////////////////////////////////////////////////////////////////////////


  //cout << "Number of decks " << currentDeck << endl;
   while (Container.getNoCardsDecks() > 0)
  {
  
    //cout << "No Decks" <<Container.getNoCardsDecks()  << endl;
   // cout << "Container Elem size" <<Container.accessPoppedData()->getSize()  << endl;

   if(Container.accessPoppedData()->getSize() > 0 
    && holderContainer.accessPoppedData()->getSize() < 52)
   {
   // cout << "here Holder Size " << holderContainer.accessPoppedData()->getSize() << endl;
    
    // Get out the Top card for comparision with Either Player one or player 2
    card topcard = Container.accessPoppedData()->getTopCard();
    if(counter % 2 == 0)
    {
        found = false;
        //holderContainer.accessPoppedData()->addCard(Container.accessPoppedData()->getTopCard());

        card cardToAdd = player1Container.accessPoppedData()->getCard(topcard, found);
        if (found == true)
          {
            counter = counter + 1;
            cout << "Player 1 has a matching card!" << endl;
            // remove found card from player1's deck
            player1Container.accessPoppedData()->getSpecificCard(cardToAdd);
            // Add found card to played cards
            holderContainer.accessPoppedData()->addCard(cardToAdd);
            // Finally check if player 1's hand is empty
            if (player1Container.accessPoppedData()->getNumberOfCards() == 0)
            {
              cout << "Player 1 is the winner!!" << endl;
              return 0 ;
            }
          }
          else
          {
            cout << "Player 1 has no matching cards" << endl;
            cout << "Player 1 draws a card" << endl;
            // add card from container deck to player 1 deck
            // so we want to remove the top card from the container
            player1Container.accessPoppedData()->addCard(Container.accessPoppedData()->getTopCard());
            counter = counter + 1;
          }

    }
///////////////////////////// PLayer 2 Section ///////////////////////////////////
else
{
    found = false;
    // card topcard2 = Container.accessPoppedData()->getTopCard();
    card cardToAdd2 = player2Container.accessPoppedData()->getCard(topcard, found);
    if (found == true)
      {
        counter = counter + 1;
        cout << "Player 2 has a matching card!" << endl;
        // remove found card from player1's deck
        player2Container.accessPoppedData()->getSpecificCard(cardToAdd2);
        // Add found card to played cards
        holderContainer.accessPoppedData()->addCard(cardToAdd2);
        // Finally check if player 1's hand is empty
        if (player2Container.accessPoppedData()->getNumberOfCards() == 0)
        {
          cout << "Player 2 is the winner!!" << endl;
          return 0 ;
        }
      }
      else
      {
        cout << "Player 2 has no matching cards" << endl;
        cout << "Player 2 draws a card" << endl;

        // add card from container deck to player 1 deck
        // so we want to remove the top card from the container
        player2Container.accessPoppedData()->addCard(Container.accessPoppedData()->getTopCard());
        counter = counter + 1;
      }

}
    /////////////////////////////////////////////////////////////////////////////
///////////////////////////////////Switching Through Decks Section////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
   }
   else
   {

      if(Container.accessPoppedData()->getSize() == 0)
      {
        //cout << "****************Deck Deleted******************** " << endl;
        Container.del_empty();
        currentDeck = currentDeck -1;
      }
      //ut << "$$$$$$$$Current Container Deck$$$$$$$$$$$$$$$$$ " << currentDeck << endl;
      
      Container.returnSpecificDeck(currentDeck);

      if (holderContainer.accessPoppedData()->getSize() > 51)
      {
          //cout << "Here at second " << endl; 
          cardDeck TempholderDeck;
          currentHolderDeck = currentHolderDeck  + 1;
          TempholderDeck.setID(currentHolderDeck);
          holderContainer.push(TempholderDeck);
          holderContainer.returnSpecificDeck(currentHolderDeck);
          //cout << "currentHolderDeck  " <<currentHolderDeck<< endl;           
      }
   }

  }
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@///
  //
  //
  // Gonna have issues dealing with the multiple dercsk
  //
  //
  //

  } catch (const char *ex) {
    cout << "\n\nException detected:\n";
    cout << ex << endl;
  } catch (...) {
    cout << "\n\nUnknown exception detected:\n";
  }


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
    // cardDeck d1(4);

    // d1.fill();

    // d1.testListContents();


    // card temp;

    // temp = d1.getSpecificCard(c1);
 
    // cout << "card return test " << temp.getRankAsString() << " " << temp.getSuitAsString() << endl;
    // cout << "Print out with Re-arrangement" << endl;
    // d1.testListContents();


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
    
    // cardDeckContainer list;
    // cardDeck d1(4);
    // cardDeck d2(4);
    // cardDeck d3(4);
    // cardDeck d4(4);
    // cardDeck d5(4);
    // cardDeck d6(4);   
    // // // print empty list
    // // cout << "empty list:\n";
    // // list.printList();
    // // cout << d3.getID() << endl;
    // // // insert one element and print again
    // list.insertNode(d1);
    // // cout << "\n\nlist with one element:\n";
    // // list.printList();
    
    // // // insert more elements and print again
    // list.insertNode(d2);
    // list.insertNode(d4);
    // list.insertNode(d3);
    // list.insertNode(d5);    
    // list.insertNode(d6);
    // d1.fill();
    // d2.fill();
    // d3.fill();
    // d4.fill();
    // d5.fill();
    // d6.fill();
    // // list.insertNode(d3);
    // // cout << "\n\nlist with multiple elements:\n";
    // // list.printList();
    // list.printList();
    // // // create copy of linked list and print copy
    // // llist copy(list);
    // // cout << "\n\nCopy of list:\n";
    // // copy.printList();

    // // // remove second element and print
    // // list.gotoHead();
    // // list.deleteNode(d2);
    // // cout << "\n\nlist with second element removed:\n";
    // // list.printList();
    // list.gotoHead();
    // // // attempt to get data of head
    // list.gotoNextNode();
    // cout << list.accessData().getID() << endl;
    // list.gotoNextNode();
    // cout << list.accessData().getID() << endl;

    // cout << "delete node" << endl;
    // cout << list.deleteNode(d1) << endl;

    // list.printList();

    // list.gotoHead();
    // list.gotoNextNode();
    // cout << list.accessData().getID() << endl;
    // list.gotoNextNode();
    // cout << list.accessData().getID() << endl;
    // card c = list.accessData().getTopCard();

    // cout << c.getRankAsString() << endl;;

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
