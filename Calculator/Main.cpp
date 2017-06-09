#include "RuntimeException.h"
#include "Parser.h"
#include "Evaluator.h"
#include <stdlib.h>
#include <string>
#include <stdio.h>
using namespace std;

int main (){
	string inp;
	cout << "Enter expression ending with an '='. (Cannot handle parenthesis) Type 'Stop' to close.:"<<endl;
	getline(cin,inp);
	while(inp.compare("Stop")!=0){
		Parser parse(inp);
		cout << "Infix: " <<inp<<endl;
		parse.printPostfix();

		//cout << "Evaluate? (y/n)";
		//char answer;
		//cin >> answer;
		//if(answer == 'y'){
			//Evaluator e(parse);
			// char* endptr = 0;
			// string test = inp;
			// atof(test);//,&endptr);
			// if(*endptr != '\0' || endptr == test){
			// 	cout <<"\n Enter the variable values in the order you want them evaluated, separated by space. End with '='\n";
			// 	cout <<"Variable values: ";
			// 	vector<double> opValues;
			// 	char cha;
			// 	cin >> cha;
			// 	while(!(cha=='=')){
			// 		cin.putback(cha);
			// 		double val;
			// 		cin >> val;
			// 		opValues.push_back(val);
			// 		cin>>cha;
			// 	}
			// 	cout<<endl;
			// 	e.subOperands(opValues);
			// 	double res = e.getValue();
			// 	cout<< "After Eval: " << res << endl;
			// }
			// else{
				Evaluator e(parse);
				cout<<inp<<e.getValue();
			//}

		//}
			cout<<endl<<endl;
			cout << "Enter expression ending with an '='. (Cannot handle parenthesis) Type 'Stop' to close.:"<<endl;
			getline(cin,inp);	
	}
	cout << "Done." <<endl;
	return 0;
}

