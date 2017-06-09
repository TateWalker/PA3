//Token.h
#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

using namespace std;

class Token {
private: 
	friend class Parser;
	
public:
	Token();
	Token(char typ, int v);
	void setType(char o);
	char getType() const;
	void setValue(int x);
	int getValue() const;
	char type;
	int val;

};

ostream& operator<<(ostream& os,  const Token& t);
#endif