/*
 * Tester.cpp
 * User can input various mathematical expression and get the result.
 *
 *  Created on: Apr 13, 2017
 *      Author: Anurag Chowdhary
 */

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Calculator.h"
#include <iomanip>
using namespace std;

int TokenLength(string str);
void isEvenPara(vector<string>& v);

int main(){
	Calculator c;

	while(true){
		try{
			vector<string> cmd;
			string command="";
			cout<<"Expression? ";
			getline(cin,command);

			std::string::iterator end_pos = std::remove(command.begin(), command.end(), ' ');
			command.erase(end_pos, command.end());

			if(command=="."){
				cout<<"\n"<<"Done!";
				return 0;
			}

			// build the vector with correct token values.
			while(!command.empty()){
				string temp;
				int tokenPos = TokenLength(command); //Get the position of first token

				if(isdigit(command[0])){
					temp = command.substr(0,tokenPos); //  Get the complete number
					command = command.substr(tokenPos);
				}
				else{
					temp = command.substr(0,1);
					command = command.substr(1);
				}
				cmd.push_back(temp);
			}


			if(cmd[cmd.size()-1]!="="){
				throw "***** Missing = ";
			}
			cmd.erase(cmd.end()-1);

			isEvenPara(cmd); // check for correct brackets

			c.factor(cmd); // start the calculations

			cmd.erase(std::remove(cmd.begin(), cmd.end(), "("), cmd.end());
			cmd.erase(std::remove(cmd.begin(), cmd.end(), ")"), cmd.end());


			if(c.isResult(cmd)){
				string s=c.print(cmd);
				double r=stof(s.c_str());
				std::cout <<r<<endl;
			}
			else
				throw "****** unexpected result "+c.print(cmd);
		}
		catch(const char* s){
			cout<<s<<endl;
		}
	}

}


/*
 * Function to return the position of a valid token like : *, ', -, +, =
 */
int TokenLength(string str){

	int position=0;
	for(position=0;position<str.length();position++){
		if( str[position]=='/' || str[position]=='*' || str[position]=='(' || str[position]==')' || str[position]=='='){
			break;
		}
		if(str[position]=='+' || str[position]=='-'){
			if(str[position-1] == 'E' || str[position-1] == 'e')
				position++;
			else
				break;
		}
		if(str[position]=='%' || str[position]=='^' || str[position]=='[' || str[position]==']' || str[position]=='{' || str[position]=='}' ){
			cout<<"****** Unexpected "<<str[position]<<endl;
			throw "";
			}
	}
	return position;

}


// Function to check for correctness of parenthesis.
void isEvenPara(vector<string>& v){
	int ob=0;
	int cb=0;
	for(string s:v){
		if(s=="(")
			ob++;
		if(s==")")
			cb++;
	}
	if(ob>cb){
		throw "***** Missing )";
	}
	if(cb>ob){
		throw "***** Missing (";
	}
}

//1+2-4 *(4/5)
//2*(44/5)*(3/4)*5=
//2*4/1*21/5=
//12/(5.5*(17 * 0.00314E+3)) =
