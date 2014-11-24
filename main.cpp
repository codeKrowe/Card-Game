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
    player P1(1);
    player P2(2);
    int playerHandSize = 7;

    cardDeckContainer Container;

    int no_of_decks;
    cout << "Please Enter a Number of Decks to play with" << endl;
    cin >> no_of_decks;

    for (int i = 0; i < no_of_decks; ++i)
    {
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

    // set up a container for each player one with empty deck
    // using a container because depending on game size, and pick ups
    // gives room for further decks
    // a limitiation in our implemenation
    // should have used a linked list from the start


    /* Player Deck Containers */
    // For the cards in the players hands
    cardDeckContainer player1Container;
    cardDeckContainer player2Container;

    cardDeck Player1Deck;
    cardDeck Player2Deck;

    Player1Deck.setID(1);
    Player2Deck.setID(1);

    player1Container.push(Player1Deck);
    player2Container.push(Player2Deck);

    /* Played Cards Deck Container */
    // for the played cards decks
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
    player1Container.returnSpecificDeck(1);
    player2Container.returnSpecificDeck(1);

    cardDeck *containerDeck = Container.accessPoppedData();

    // Get deck object, easier to work with rather than
    // going through the containers all the time
    // Easier to read then
    for (int i = 1;i <= playerHandSize*2; ++i)
    {
      if((i+2)%2 == 0)
      {
        Player2Deck.addCard(containerDeck->getTopCard());
      }
      else
      {
        Player2Deck.addCard(containerDeck->getTopCard());
      }
    }

    /// this is trickey, when decks become empty and when decks become full
    // such as the holderDeck for the played cards
    playedCardsContainer.returnSpecificDeck(1);
    int currentPlayedCardsDeck = 1;
    int currentDeck = Container.getNoCardsDecks();

    while (Container.getNoCardsDecks() > 0)
    {
      /* Turn a Card Over */

      // If played cards deck has room in it
      // Add a card from the game deck to the played cards
      if(containerDeck->getSize() > 0
      && playedCardsDeck.getSize() < 52)
      {
        playedCardsDeck.addCard(containerDeck->getTopCard());
      }
      else
      {
        // if the current deck in the container is empty
        // i.e all cards turned over from deck 1
        if(containerDeck->getSize() == 0)
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
        if (playedCardsDeck.getSize() > 51)
        {
          cardDeck TempPlayedCardsDeck;
          currentPlayedCardsDeck = currentPlayedCardsDeck  + 1;
          TempPlayedCardsDeck.setID(currentPlayedCardsDeck);
          playedCardsContainer.push(TempPlayedCardsDeck);
          playedCardsContainer.returnSpecificDeck(currentPlayedCardsDeck);
        }
      }

      /* GAME MOVES TO PLAYER 2*/
      /* Check if the played card is in player 1's hand */

      // Get the top card of the played cards deck
      card topcard = playedCardsDeck.lookAtTopCard();

      bool found = false;
      // Check is the top played card in player 1's hand
      card cardToAdd = Player1Deck.getCard(topcard, found);

      if (found == true)
      {
        cout << "Player 1 has a matching card!" << endl;

        // remove found card from player1's deck
        Player1Deck.getSpecificCard(cardToAdd);

        // Add found card to played cards
        playedCardsDeck.addCard(cardToAdd);

        // Finally check if player 1's hand is empty
        if (Player1Deck.getNumberOfCards() == 0)
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
        Player1Deck.addCard(containerDeck->getTopCard());
      }

      /* GAME MOVES TO PLAYER 2*/
      /* Check if played card in player 2's hand */

      // Get the top card of the played cards deck
      topcard = playedCardsDeck.lookAtTopCard();

      // reset found variable
      found = false;
      cardToAdd = Player2Deck.getCard(topcard, found);

      if (found == true)
      {
        cout << "Player 2 has a matching card!" << endl;

        // remove found card from player1's deck
        Player2Deck.getSpecificCard(cardToAdd);

        // Add found card to played cards
        playedCardsDeck.addCard(cardToAdd);

        // Finally check if player 1's hand is empty
        if (Player2Deck.getNumberOfCards() == 0)
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
        Player2Deck.addCard(containerDeck->getTopCard());
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
