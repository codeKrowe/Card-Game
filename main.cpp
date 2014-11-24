#include <iostream>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"
#include "cardDeckContainer.h"
#include "player.h"

using namespace std;

int main()
{
  try
  {
    cardDeckContainer Container;

    int no_of_decks;
    cout << "Please Enter a Number of Decks to play with" << endl;
    cin >> no_of_decks;


    for (int i = 0; i < no_of_decks; ++i)
    {
      //create sets of card decks (52 Cards) for main deck, with INT ID's
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

    /* Played Cards Container */
    // for the played cards decks////////
    cardDeckContainer playedCardsContainer;
    cardDeck playedCardsDeck;
    playedCardsDeck.setID(1);
    playedCardsContainer.push(playedCardsDeck);

    // this loop demos  placing seven cards into the player
    // decks one at a time
    // first get the number of decks in the container
    // so that the top one can be accessed
    int numberDecksMainContainer = Container.getNoCardsDecks();
    Container.returnSpecificDeck(numberDecksMainContainer);
    player2Container.returnSpecificDeck(1);
    player1Container.returnSpecificDeck(1);

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

    playedCardsContainer.returnSpecificDeck(1);
    int currentHolderDeck = 1;
    int currentDeck = Container.getNoCardsDecks();

    bool found = false;
    int counter = 2;

  ////////////////////////////////////////////////////////////////////////////////
  //   Main Loop
  /////////////////////////////////////////////////////////////////////////////////

    while (Container.getNoCardsDecks() > 0)
    {

     if(Container.accessPoppedData()->getSize() > 0
      && playedCardsContainer.accessPoppedData()->getSize() < 52)
     {

      // Get out the Top card for comparision with Either Player one or player 2
      card topcard = Container.accessPoppedData()->getTopCard();

      if(counter % 2 == 0)
      {
          found = false;
          card cardToAdd = player1Container.accessPoppedData()->getCard(topcard, found);
          counter = counter + 1;

          if (found == true)
            {
              cout << "Player 1 has a matching card!" << endl;
              cout << "Player 1 plays " << cardToAdd.getRankAsString() << " " << cardToAdd.getSuitAsString() <<endl;

              // Remove found card from player1's deck
              player1Container.accessPoppedData()->getSpecificCard(cardToAdd);
              // Add found card to played cards
              playedCardsContainer.accessPoppedData()->addCard(cardToAdd);
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
              // Add card from container deck to player 1 deck
              // so we want to remove the top card from the container
              player1Container.accessPoppedData()->addCard(Container.accessPoppedData()->getTopCard());
            }

      }
  ///////////////////////////// PLayer 2 Section ///////////////////////////////////
  else
  {
      found = false;
      card cardToAdd2 = player2Container.accessPoppedData()->getCard(topcard, found);
      counter = counter + 1;

      if (found == true)
        {
          cout << "Player 2 has a matching card!" << endl;
          cout << "Player 2 plays " << cardToAdd2.getRankAsString() << " " << cardToAdd2.getSuitAsString() <<endl;

          // Remove found card from player1's deck
          player2Container.accessPoppedData()->getSpecificCard(cardToAdd2);
          // Add found card to played cards
          playedCardsContainer.accessPoppedData()->addCard(cardToAdd2);
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
          Container.del_empty();
          currentDeck = currentDeck -1;
        }

        Container.returnSpecificDeck(currentDeck);

        if (playedCardsContainer.accessPoppedData()->getSize() > 51)
        {
          cardDeck TempholderDeck;
          currentHolderDeck = currentHolderDeck  + 1;
          TempholderDeck.setID(currentHolderDeck);
          playedCardsContainer.push(TempholderDeck);
          playedCardsContainer.returnSpecificDeck(currentHolderDeck);
        }
     }
    }
  }
  catch (const char *ex)
  {
    cout << "\n\nException detected:\n";
    cout << ex << endl;
  }
  catch (...)
  {
    cout << "\n\nUnknown exception detected:\n";
  }
}
