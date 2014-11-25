#include <iostream>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"
#include "cardDeckContainer.h"


using namespace std;

int main()
{
  try
  {
    cardDeckContainer Container;

    int no_of_decks = 0;

    // Number of cards in each players hand.
    int handSize = 7;

    // Must enter 1 or more decks to play with.
    while (no_of_decks <= 0)
    {
      cout << "Please Enter a Number of Decks to play with" << endl;
      cin >> no_of_decks;
    }

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

    ////// Player Containers //////
    cardDeckContainer player1Container;
    cardDeck Player1Deck;
    Player1Deck.setID(1);
    player1Container.push(Player1Deck);


    cardDeckContainer player2Container;
    cardDeck Player2Deck;
    Player2Deck.setID(1);
    player2Container.push(Player2Deck);

    /* Played Cards Container */
    // for the played cards decks //
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

    for (int i = 1;i <= handSize*2; ++i)
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

    // boolean to indicate if cards from game deck have
    // run out and a reshuffle of the played cards has occurred
    bool shuffled = false;

    // while there are Decks
    while (Container.getNoCardsDecks() > 0)
    {
      // if the conatainers have a temp Deck stored that is not full or empty
      // depending on the use - full for PLayed
      // empty fot the main container deck
      if(Container.accessPoppedData()->getNumberOfCards() > 0
      && playedCardsContainer.accessPoppedData()->getNumberOfCards() < 52)
      {

        // Get out the Top card for comparision with Either Player one or player 2
        card topcard = Container.accessPoppedData()->getTopCard();

        //switch turns between players
        if(counter % 2 == 0)
        {
          found = false;
          // pull a card out of player container if it matches the topcard from the played deck
          card cardToAdd = player1Container.accessPoppedData()->getCard(topcard, found);
          // add to counter so that it will switch turns
          counter = counter + 1;

          // if found add card to played container from players hand
          if (found == true)
          {
            cout << "Player 1 has a matching card!" << endl;
            cout << "Player 1 plays " << cardToAdd.getRankAsString() << " " << cardToAdd.getSuitAsString() <<endl;

            // Remove found card from player1's deck
            player1Container.accessPoppedData()->getSpecificCard(cardToAdd);
            // Add found card to played cards
            playedCardsContainer.accessPoppedData()->addCard(cardToAdd);
            // Finally check if player 1's hand is empty

            // if player ones hand is empty they are the winner
            if (player1Container.accessPoppedData()->getNumberOfCards() == 0)
            {
              cout << "Player 1 is the winner!!" << endl;
              return 0 ;
            }
          }
          else
          {
            //else they draw a card from the deck and add it to ther own
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
        /// all same as player 1
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
        // After the code section above, container will
        // be set to another deck if one is available

        // Check if containers current deck is empty
        if (Container.accessPoppedData()->getNumberOfCards() == 0)
        {
          // deck shuffled once before already
          // end game as a draw
          if (shuffled == true)
          {
            // Game is a draw, terminate
            cout << "Game is a draw, no winnners this time!" << endl;
            return 0;
          }

          cout << "Game deck is empty!" << endl;
          // Take current deck in playedCardsContainer, move all
          // but top most card to hidden deck.

          // Before move, store last played card.
          card lastplayed = playedCardsContainer.accessPoppedData()->getTopCard();

          // Move all cards that have been played to the game deck.
          cardDeck::moveAllCards(playedCardsContainer.accessPoppedData(), Container.accessPoppedData());

          // playedCardContainers, Deck is now empty

          // Add back the last card played that we stored.
          playedCardsContainer.accessPoppedData()->addCard(lastplayed);

          // Shuffle new game deck
          Container.accessPoppedData()->shuffleDeck();

          // We've done a reshuffle of the played cards into the game deck once
          // if no winner after this, game will end in a draw
          shuffled = true;

          cout << "\nCards already played mixed into a new game deck.\n" << endl;
          cout << "Deck reshuffled..." << endl;
        }

        // if the current deck in the container is empty
        // i.e all cards turned over from deck 1
        if(Container.accessPoppedData()->getNumberOfCards() == 0)
        {
          // delete that deck object from container
          Container.del_empty();
          // update and move onto next deck
          currentDeck = currentDeck -1;
        }

        // set next deck to use
        Container.returnSpecificDeck(currentDeck);

        // if played cards deck becomes full
        // create another deck and start filling that one
        if (playedCardsContainer.accessPoppedData()->getNumberOfCards() > 51)
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
