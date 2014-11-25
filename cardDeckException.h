// CardDeck custom exception class
//
//
// authors: Jonathan, Cathal, Nidhu
// date:  19.11.2014
//////////////////////////////////////////////////////////////////////
#ifndef CARDDECKEXCEPTION_H
#define CARDDECKEXCEPTION_H

#include <string>
#include <exception>

using std::string;

class cardDeckException
{

  public:
    cardDeckException();
    //generic constructor with message set
    cardDeckException(string str);
    //get the message
    string getException();

  private:
    string exceptionName;
    string sizeErr;
};

#endif
