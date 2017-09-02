/*
 * File Name: Employee.h
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:6
 * Created on: Mar 1, 2017
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

class Employee
{
public:



    friend ostream& operator <<( ostream& outs, const Employee& e );
    friend istream& operator >>( istream& ins, Employee& e );

    Employee();
    Employee(int eid, string last_name, string first_name, double sal);


    int get_id() const;
    double get_salary() const;
    string get_last() const;
    string get_first() const;

    void set_id(int eid);
    void set_salary(double sal);
    void set_last(string last_name);
    void set_first(string first_name);



private:

    int id;
    string last;
    string first;
    double salary;



};

#endif /* EMPLOYEE_H_ */
