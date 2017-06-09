//Token.cpp
#include "token.h"
#include <iostream>

	
	Token::Token(){
		type = 'z';
		val = 0;
	}
	Token::Token(char typ, int v){
		type = typ;
		val = v;
	}
	void Token::setType(char o){
		type = o;
	}
	char Token::getType() const{
		return type;
	}
	void Token::setValue(int x){
		val = x;
	}
	int Token::getValue()const {
		return val;
	}

	ostream& operator<<(ostream& os, const Token& t){
		if(t.type == '9'){
			os << t.getValue();
		}
		else{
			os << t.getType();
		}
		return os;
		}