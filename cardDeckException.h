// Implementation of a linkedlist of decks
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
    cardDeckException(string str);
    string getException();

  private:
    string exceptionName;
    string sizeErr;
};

#endif
