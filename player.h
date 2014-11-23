#ifndef PLAYER_H
#define PLAYER_H

//#include "cardDeck.h"

class player
{
	public:
	//Player constuctor
	player();
	player(int ID);
	//Displays the number of cards the player has
	inline int statusPlayer() {return no_of_cards;}
	//search for the "top card" in the player's deck
	//inline int searchCards() {return card;}
	inline int getPlayerID(){return id;}

	void setNoCards(int NOC);
	
	private:
	int id;
	int no_of_cards ;//no_of_cards

};


#endif
