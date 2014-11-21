#ifndef PLAYER_H
#define PLAYER_H

#include <cardeck.h>

class Player
{
	public:
	//Player constuctor
	Player();
	//Displays the number of cards the player has
	inline int statusPlayer() {return no_of_cards;}
	//search for the "top card" in the player's deck
	inline int searchCards() {return card;}
	}
private:

int nrofcards;//no_of_cards

};










#endif
