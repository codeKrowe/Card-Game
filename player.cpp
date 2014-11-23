// player.cpp
//
// authors:	Jonathan, Cathal, Nidhu
// date:	01.11.2014
//////////////////////////////////////////////////////////////////////

#include "player.h"

player::player()
{
	id = 0;
	no_of_cards=0;
}

player::player(int ID)
{
	id = ID;
}

void player::setNoCards(int NOC){
	no_of_cards = NOC;
}