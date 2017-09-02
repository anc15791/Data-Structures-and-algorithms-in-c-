/*
 * Calculator.h
 *
 *
 *  Created on: Apr 13, 2017
 *      Author: Anurag Chowdhary
 */
#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

class Calculator{

public:
	void factor(vector<string>& v) throw(const char*);
	void term(vector<string>& v) throw(const char*);
	void expression(vector<string>& v) throw(const char*);
	bool isResult(vector<string>& v) throw(const char*);
	string print(vector<string>& v) throw(const char*);
	void LookUp(vector<string>& v) throw(const char*);

};
#endif /* CALCULATOR_H_ */
