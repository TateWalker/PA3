#include "Parser.h"
using namespace std;

  vector<Token> Parser::getToken(string inp){
  vector<Token> tokenz;
  Token t;
  char c;
  stringstream in;
  in.str(inp);
  in >> c;
  int lp = 0;
  int rp = 0;

  while(!(c == '=')){
  	switch(c){
  		case '(':
  			lp++;
  			t = Token(c , 100);
  			break;
  		case ')':
  			rp++;
  			t = Token(c, 99);
  			break;
  		case '+': case '-':
  			t = Token(c, 2);
  			break;
  		case '*': case '/':
  			t = Token(c, 6);
  			break;
  		case '^':
  			t = Token(c, 8);
  			break;
  		case '0': case '1': case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':case '.':
  		{
  			in.putback(c);
  			double v;
  			in >> v;
  			t = Token('9', v);
  			break;
  		}
  		case 'a':case 'b':case 'c':case 'd':case 'e':case 'f':case 'g':case 'h':
  		case 'i':case 'j':case 'k':case 'l':case 'm':case 'n':case 'o':case 'p':
  		case 'q':case 'r':case 's':case 't':case 'u':case 'v':case 'w':case 'x':
  		case 'y':case 'z':
  			in.putback(c);
        //char b;
        in >> c;
        t = Token(c, 0);
  			break;
  		default:
  			cerr << "Invalid input"<<endl;

  	}
  	tokenz.push_back(t);
  	in >> c;
  }
  if(!(lp==rp)) {cerr<<"Unbalanced Parenthesis\n";}
  	else{tokenz.push_back(Token('=',0)); //was 1
      return tokenz;}
}

void Parser::printPostfix() {
  //postfix = toPostfix();
  //cout<<postfix<<endl;
  //cout<<opStack<<endl;
  cout<<"Postfix: "<<toPostfix()<<endl;
}

LinkedQueue<Token> Parser::toPostfix(){
	vector<Token> toks = getToken(inp);
	LinkedQueue<Token> postfix;
  LinkedStack<Token> tempfix;
	opStack.push(Token('=',0));
	for(int i = 0; i<toks.size(); i++){
		 Token t = toks[i];
		if((t.getType() == '9')){
			postfix.enqueue(t);
		}
		else if((isalpha(t.getType()))){
			postfix.enqueue(t);
		}
		else{
			if(t.getType() == ')'){
			     //if(opStack.isEmpty()){cerr<<"Stack is empty";}
			     while(opStack.top().getType() != '('){
               Token tstack = opStack.top();
               opStack.pop();
			         postfix.enqueue(tstack);
			     }
			     opStack.pop();
			}
			else if(t.getType() == '='){
				if(opStack.isEmpty()){cerr<<"Stack is empty";}
				while(!((opStack.top()).getType() == '=')){
					Token tstack = opStack.top();
					opStack.pop();
					postfix.enqueue(tstack);
				}
        //opStack.pop();
			}
			else if(t.getType() == '(') {opStack.push(t);}
			else{
				int prior = t.getValue();
				if( opStack.isEmpty()){cerr<<"Stack is empty";}
				while((opStack.top().getValue() >= prior)){
          Token tstack = opStack.top();
					postfix.enqueue(tstack);
          opStack.pop();
				}
        opStack.push(t);
			}
		}
	}
    for(int i = 0; i <opStack.size()-1; i++){
        postfix.enqueue(opStack.top());
        opStack.pop();
    }
	return postfix;
}