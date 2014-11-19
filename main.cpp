/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CARD - MAIN - LOGIC
 
1.create a main playin deck,deck-1 ,create another empty deck-"to eput down",deck-2
2.creat a deck for player a,deck-3
3.create a deck for player b,deck-4
4.shuffle the card deck
5 player 1 gets seven cards
6.player 2 gets seven cards
 
scenario-1

if the "top card" from deck-2 matches with the card(s) in the players deck(in suit or rank) then the matched card goes to deck-2
control goes to player-2
if the top card is a match with any of the cards in player-2's deck,the cards goes into deck-2
control goes to player-1---plays until scenario-2

scenario-2
if the player does not have any card in his deck which matches the topmost card of deck-1,then next top card from the deck-1 goes to
player's deck (deck-3 or deck-4)
control goes to the next player--plays until scenario-3

scenario-3--ok ??

 "If the hidden stack is empty
before any player has an empty hand, the played car
ds are taken, shuffled and then used as the
new hidden deck. "

deck-2 becomes empty,deck-3 and deck-4 are not empty--->shuffle-deck-2-cards-->deck-2 becomes the main deck
the top card and the resulting cards drawn from deck-2,play again

scenario-4-final round
the player(deck-3 or deck-4) has empty deck---declared winner
---------------------------------------------------------------------------------------------------------------------

"Simulate the game: Remove the topmost card from the
shuffled deck to the “played card
deck”.
o
If player one has a matching card, let player one p
lay this card (remove it from his
hand and move it to the played card deck – there is
no need for any intelligent
behaviour: just use the first card in the hand that
matches the played deck).
o
If player one has no matching card, s/he picks the
topmost card from the shuffled
deck and adds it to deck of cards modelling the pla
yer.
o
Also, print a message to the screen, either “Player
one played card xxx” or “Player
one takes a card from the shuffled deck”. If a play
er takes a card, also print all
cards in the player’s hand. "
* eal out 7 cards to each player by picking them fro
m the beginning of the shuffled deck –
give one card to each player in turn, i.e. the firs
t card in the shuffled deck goes to the first
player, the second card to the second player, the t
hird card again to the first player and so
on. 
* 

* ---------------------------------------------------------------
* the way to hand out the 7 cards to the players initially
* 
* 
* Deal out 7 cards to each player by picking them fro
m the beginning of the shuffled deck –
give one card to each player in turn, i.e. the firs
t card in the shuffled deck goes to the first
player, the second card to the second player, the t
hird card again to the first player and so
on. 

* 
* ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include "card.h"
#include "cardDeck.h"
#include "cardDeckException.h"

int main()
{
	
//creating cards	
	
//////Cards//////////////
//
// c1-c13=Clubs
//c14-c26=Spades 
//c27-c39=Hearts
//c40-c52=Diamonds
//
/////////////////////////


//first set of Cards

card c1	(card::Clubs,card::Ace);
card c2 (card::Clubs,card::Two);
card c3 (card::Clubs,card::Three);
card c4 (card::Clubs,card::Four);
card c5 (card::Clubs,card::Five);
card c6 (card::Clubs,card::Six);
card c7 (card::Clubs,card::Seven);
card c8 (card::Clubs,card::Eight);
card c9 (card::Clubs,card::Nine);
card c10(card::Clubs,card::Ten);
card c11(card::Clubs,card::Jack);
card c12(card::Clubs,card::Queen);
card c13(card::Clubs,card::King);
//---second set
card c14(card::Spades,card::Ace);
card c15(card::Spades,card::Two);
card c16(card::Spades,card::Three);
card c17(card::Spades,card::Four);
card c18(card::Spades,card::Five);
card c19(card::Spades,card::Six);
card c20(card::Spades,card::Seven);
card c21(card::Spades,card::Eight);
card c22(card::Spades,card::Nine);
card c23(card::Spades,card::Ten);
card c24(card::Spades,card::Jack);
card c25(card::Spades,card::Queen);
card c26(card::Spades,card::King);
//third set
card c27(card::Hearts,card::Ace);
card c28(card::Hearts,card::Two);
card c29(card::Hearts,card::Three);
card c30(card::Hearts,card::Four);
card c31(card::Hearts,card::Five);
card c32(card::Hearts,card::Six);
card c33(card::Hearts,card::Seven);
card c34(card::Hearts,card::Eight);
card c35(card::Hearts,card::Nine);
card c36(card::Hearts,card::Ten);
card c37(card::Hearts,card::Jack);
card c38(card::Hearts,card::Queen);
card c39(card::Hearts,card::King);
//fourth set
card c40(card::Diamonds,card::Ace);
card c41(card::Diamonds,card::Two);
card c42(card::Diamonds,card::Three);
card c43(card::Diamonds,card::Four);
card c44(card::Diamonds,card::Five);
card c45(card::Diamonds,card::Six);
card c46(card::Diamonds,card::Seven);
card c47(card::Diamonds,card::Eight);
card c48(card::Diamonds,card::Nine);
card c49(card::Diamonds,card::Ten);
card c50(card::Diamonds,card::Jack);
card c51(card::Diamonds,card::Queen);
card c52(card::Diamonds,card::King);


//printing out the suit and the ranks of the objects created
//checking

cout<<" c1-Rank="<<c1.getRankAsString()<<endl;
cout<<" c1-Suit="<<c1.getSuitAsString()<<endl;
cout<<"c52-Rank="<<c52.getRankAsString()<<endl;
cout<<"c52-Suit="<<c52.getSuitAsString()<<endl;

////////////////////////////////////////////////////////////////////////////
//
//Creating a empty deck-D2 or the deck to which the 
//cards are handed in-
//NAMING IT-PLAYING DECK OR PD
//
////////////////////////////////////////////////////////////////////////////

cardDeck PD();

/////////////////////////////////////////////////////////////////////////////
//
//Creating a deck of size 52-the main deck or deck-1
//NAMING IT- HD OR HIDDEN DECK--thats how he wants to call it
//
//////////////////////////////////////////////////////////////////////////////

cardDeck HD();

//////////////////////////////////////////////////////////////////////////////
//
//adding a card into the hidded deck-HD
//
//////////////////////////////////////////////////////////////////////////////

//HD.addCard(c1);-----does not work :(


///////////////////////////////////////
//Logic
// HD()-----contains all the cards
/////////////////////////////////////////
//
//create an empty deck for player-A
//Naming it--PL1
//
/////////////////////////////////////////

cardDeck PL1();

/////////////////////////////////////////
//
//creating an empyty deck for player-B
//NAMING IT=PL2
//
 

cardDeck PL2();

/////////////////////////////////////////
//
//HD.shuffleDeck()
//cards in the deck shuffled
//

/////////////////////////////////////
//
//Allocating the seven cards to both the players 1 & 2
//getTopCard(HD) ---needs to be added to cardDeck.cpp
//first top card to player 1
//next topo card to player 2
// till both have seven cards each
////////////////////////////////////////////
//game 
//After allocating the seven cards
//pass the top card to player1's or 2's deck
//if rank or suit in the players deck
//move the card to PD
//destroy the object from PL1 or PL2
/////////////////////////////////////////////


return 0;
}


