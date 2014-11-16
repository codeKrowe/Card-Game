#include <iostream>
#include "cardDeckException.h"

using namespace std;

cardDeckException::cardDeckException()
{
	exceptionName = "Unspecified CardDeck Exception";
	sizeErr = "Size is incorrect";
}


cardDeckException::cardDeckException(std::string name)
{
	exceptionName = name;
}

std::string cardDeckException::getException(){
	return exceptionName;
}

