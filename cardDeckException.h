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
