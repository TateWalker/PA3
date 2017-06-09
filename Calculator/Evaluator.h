#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Parser.h"
#include "RuntimeException.h"
#include <math.h>

class Evaluator {
public:
  class DivisionByZeroException : public RuntimeException {
    public:
      DivisionByZeroException() : RuntimeException("Division by zero") {}
  };
private:
  LinkedQueue<Token> postfix;
  LinkedStack<double> valStack;
  Parser parse;

public:
  Evaluator(Parser& par) : parse(par) {} // constructor
  double getValue(); // returns the result of expression evaluation
  bool isOp(Token t);
  void subOperands(vector<double> vec);
};

#endif
