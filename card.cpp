// Definition of a card class
//
// Contains very basic card structure.

#include "card.h"
using namespace std;


card::card()
{
    suit = card::Spades;

    rank = card::Ace;
}

card::card(Suit newSuit, Rank newRank)
{
    suit = newSuit;
    rank = newRank;
}

string card::getRankAsString()
{
  string rankString;

  switch(rank)
  {
    case Ace:
      rankString = "Ace";
      break;
    case Two:
      rankString = "Two";
      break;
    case Three:
      rankString = "Three";
      break;
    case Four:
      rankString = "Four";
      break;
    case Five:
      rankString = "Fice";
      break;
    case Six:
      rankString = "Six";
      break;
    case Seven:
      rankString = "Seven";
      break;
    case Eight:
      rankString = "Eight";
      break;
    case Nine:
      rankString = "Nine";
      break;
    case Ten:
      rankString = "Ten";
      break;
    case Jack:
      rankString = "Jack";
      break;
    case Queen:
      rankString = "Queen";
      break;
    case King:
      rankString = "King";
      break;
    default:
      rankString = "Undefined Rank";
      break;
  }

    return rankString;
}

string card::getSuitAsString()
{
    string suitString;

    switch(suit)
    {
        case Clubs:
          suitString = "Clubs";
          break;
        case Spades:
          suitString = "Spades";
          break;
        case Hearts:
          suitString = "Hearts";
          break;
        case Diamonds:
          suitString = "Diamonds";
          break;
        default:
          suitString = "Unknown Suit";
          break;
    }

    return suitString;
}
