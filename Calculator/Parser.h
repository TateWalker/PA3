#ifndef PARSER_H
#define PARSER_H
#include "token.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RuntimeException.h"
#include <string>
#include <vector>
#include <sstream>
#include <ctype.h>

class Parser {
private:
   std::string inp;

   LinkedQueue<Token> postfix;
   LinkedStack<Token> opStack;

public:
  
  Parser() :inp("") {}
  Parser(std::string s) {inp = s;}
  LinkedQueue<Token> toPostfix();
  std::string getInp() {return inp;}

  void setInp(string s) {inp = s;}

  vector<Token> getToken(string inp);
  void printPostfix();
};


#endif