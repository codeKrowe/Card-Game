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

