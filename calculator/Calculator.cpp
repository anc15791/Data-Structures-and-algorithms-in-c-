/*
 * Calculator.cpp
 * Calculates the result of expression in a recursive manner. The result is visible in the vector.
 *
 *  Created on: Apr 12, 2017
 *      Author: Anurag Chowdhary
 */
#include "Calculator.h"


/*
 * This function handles numbers and parenthesis and calls Lookup().
 * */
void Calculator::factor(vector<string>& v) throw(const char*){

	bool ob=false;
	bool cb=false;
	if(isResult(v))
		return;

	if(isdigit(v.at(0)[0])){

		//To handle expression like 5)
		if(v.at(1)==")"){
			v.erase(v.begin()+1);
		}
		LookUp(v);
	}
	else if(v.at(0)=="("){
		ob=true;
		v.erase(v.begin());
		factor(v);
	}
	else if(v.at(0)==")"){
		cb=true;
		v.erase(v.begin());
		LookUp(v);
	}
}

/*
 * Term understands * and / operator. It will call factor for parenthesis.
 *
 * */
void Calculator::term(vector<string>& v) throw(const char*){
	double op1;
	double op2;
	string op;

	if(isResult(v))
		return;

	op1 = atof(v.at(0).c_str()); // Take first number.
	op=v.at(1); // Take the operator.
	v.erase(v.begin(),v.begin()+2);

	if(!isdigit(v.at(0)[0])){
		factor(v);
	}

	op2=atof(v.at(0).c_str()); // Take the second number.
	v.erase(v.begin());

	if(op=="*"){
		v.insert(v.begin(),to_string(op1*op2));
		factor(v);
	}
	if(op=="/"){
		if(op2==0){
			throw "******  Division by zero";
		}
		v.insert(v.begin(),to_string(op1/op2));
		factor(v);
	}
}

/*
 * Expression handles + and - operators and call factor function for braces.
 * */
void Calculator::expression(vector<string>& v)throw(const char*){

		double op1;
		double op2;
		string op;

		if(isResult(v))
			return;

		op1 = atof(v.at(0).c_str());
		op=v.at(1);
		v.erase(v.begin(),v.begin()+2);

		factor(v);

		op2=atof(v.at(0).c_str());
		v.erase(v.begin());

		if(op=="+"){
			v.insert(v.begin(),to_string(op1+op2));
			factor(v);
		}
		if(op=="-"){
			v.insert(v.begin(),to_string(op1-op2));
			factor(v);
		}


}

// This function calls the appropriate function depending upon the operator.
void Calculator::LookUp(vector<string>& v) throw(const char*){

	if(isResult(v))
		return;

	if(v.at(1)=="*" || v.at(1)=="/"){
		term(v);
	}
	else if(v.at(1)=="+" || v.at(1)=="-"){
		expression(v);
	}
	else if(v.at(1)=="%" || v.at(1)=="^" || v.at(1)=="[" || v.at(1)=="]" || v.at(1)=="{" || v.at(1)=="}" || v.at(1)==")" || isalpha(v.at(1)[0])){
		cout<<"****** Unexpected "<<v.at(1);
		throw "";
	}



}


// Returns the values of vector as a string
string Calculator::print(vector<string>& v) throw(const char*){
	string res="";
	for(string s:v){
		res+=s+"";
	}
	return res;
}

//Returns true only if there is a single number in the vector - which is considered as the result of the expression.
bool Calculator::isResult(vector<string>& v) throw(const char*){
	bool result=false;
	for(string s:v){

		if(isdigit(s[0])){
			if(!result)
				result=true;
			else{
				result=false;
				return result;
			}
		}
		else{
			if(s[0]=='-'){
				if(!result)
					result=true;
					else{
						result=false;
						return result;
					}
			}
		}
	}
	return (result);
}

