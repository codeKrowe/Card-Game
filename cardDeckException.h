#include <iostream>

#ifndef CARDDECKEXCEPTION_H
#define CARDDECKEXCEPTION_H

using std::string;

class cardDeckException{

public:
cardDeckException();
cardDeckException(std::string str);
std::string getException();

private:
std::string exceptionName;
std::string sizeErr;
};


#endif
