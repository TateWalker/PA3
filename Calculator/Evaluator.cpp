#include <set>
#include "Evaluator.h"

using namespace std;

double Evaluator::getValue() {

	set<char> operators = {'+','-','*','/','^'};
	postfix = parse.toPostfix();
	double res;
	
	LinkedStack<Token> pstemp;
	postfix.dequeue();
	LinkedQueue<Token> ptemp = postfix;
	while(ptemp.isEmpty() == false){
		pstemp.push(ptemp.dequeue());
	}
	while(pstemp.isEmpty() == false){
		Token curTok = pstemp.pop();
		if(operators.find(curTok.getType()) == operators.end()){
			//cout<<"Variable\n";
			valStack.push(curTok.getValue());
		}
		else{
			char op = curTok.getType();
			double second = valStack.top();
			valStack.pop();
			double first = valStack.top();
			valStack.pop();
			if (op == '^') res =  static_cast<int>(pow(first, second));
			else if (op == '+') res = first+second;
			else if (op == '-') res = first-second;
			else if (op == '*') res = first*second;
			else if (op == '/'){
				if (second != 0){
					res = first/second;
				}
				else {throw DivisionByZeroException();
				}
			}
			else{ cerr << "Invalid operator"<<endl;}
			valStack.push(res);
		}
	}
	double ans = valStack.top();
	return ans;
}

bool Evaluator::isOp(Token t){
	char op = t.getType();
	if(op=='+' || op=='-'|| op=='*'|| op=='/'|| op=='^'){
		return true;
	}
	else{return false;}
}

void Evaluator::subOperands(vector<double> vec){
	vector<Token> tokens = parse.getToken(parse.getInp());
	int vars = 0;
	for(int i = 0; i < tokens.size(); i++){
		if(tokens[i].getType() == 'a') vars++;
	}
	if(vars != vec.size()) {cerr<<"SubOp Error"<<endl;}

	int index = 0;
	stringstream os;

	for(int i = 0; i<tokens.size(); i++){
		Token tok = tokens[i];
		if(tok.getType() == 'a'){
			cout << "value of " << tok.getType() << " = " <<vec[index] <<endl;
			tok.setType('6');
			tok.setValue(vec[index]);
			os << vec[index];
			index++;
		}
		else if(tok.getType() == '9')
			os << (int) tok.getValue();
		else
			os << tok.getType();
	}
	cout <<endl;
	parse.setInp(os.str());
	cout<< "Input expression after subs: " <<os.str() << endl;
}