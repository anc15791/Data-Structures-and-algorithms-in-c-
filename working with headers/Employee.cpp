/*
 * File Name: Employee.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:6
 * Description: This implements the Wmployee.h by providing all definitions and helper methods.
 * Created on: Mar 1, 2017
 */

#include "Employee.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>


Employee::Employee():id(0),last(""),first(""),salary(0){}
Employee::Employee(int eid, string last_name, string first_name, double sal):id(eid),last(last_name),first(first_name),salary(sal){}


int Employee::get_id() const{ return id;}
double Employee::get_salary() const{ return salary;}
string Employee::get_last() const {return last;}
string Employee::get_first() const {return first;}

void Employee::set_id(int eid) {id=eid;}
void Employee::set_salary(double sal) {salary=sal;}
void Employee::set_last(string last_name) {last=last_name;}
void Employee::set_first(string first_name) {first=first_name;}



ostream& operator <<( ostream& outs, const Employee& e )
{

	outs << " Employee{ID="<<e.get_id()<<", last="<<e.get_last()<<", first="<<e.get_first()<<", salary="<<e.get_salary()<<"}";
	return outs;
}


istream& operator >>( istream& ins, Employee& e )
{
	ins >> std::ws; // bypass white spaces
	char line[256];
	ins.getline(line,256);
	string input(line);
	int commaCount=0;
	int start_substring=0;
	for(int i=0;i<input.length();i++)
	{
		if(input[i]==',')
		{
			commaCount++;
			if(commaCount==1)
			{	std::string::size_type sz;   // alias of size_t
				e.set_id(stoi(input.substr(start_substring,i-start_substring),&sz  ));
			}
			if(commaCount==2)
			{
				e.set_last(input.substr(start_substring,i-start_substring));
			}
			if(commaCount==3)
			{
				e.set_first(input.substr(start_substring,i-start_substring));
			}



			start_substring=i+1;

		}

		if(i==input.length()-1)
		{
			std::string::size_type sz;   // alias of size_t
			e.set_salary( (double)stoi(input.substr(start_substring,i-start_substring+1),&sz  ));
		}

	}
	return ins;



}
