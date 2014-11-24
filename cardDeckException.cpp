// Class for custom deck exceptions
//
//
// authors: Jonathan, Cathal, Nidhu
// date:  24.11.2014
//////////////////////////////////////////////////////////////////////
#include "cardDeckException.h"

cardDeckException::cardDeckException()
{
	exceptionName = "Unspecified CardDeck Exception";
	sizeErr = "Size is incorrect";
}


cardDeckException::cardDeckException(string name)
{
	exceptionName = name;
}

string cardDeckException::getException()
{
	return exceptionName;
}

