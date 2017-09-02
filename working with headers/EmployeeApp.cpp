/*
 * File Name: EmployeeApp.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:6
 * Description: Program to read employee data from a file and perform required operation as mentioned in the file with csv values.
 * Created on: Mar 1, 2017
 */

#include "Employee.h"
#include <vector>

using namespace std;

void execute( char command, vector<Employee>& list, istream& input);
void print_all(vector<Employee> & list );
void print_stats( vector<Employee> & list  );
bool add_to_list(Employee e,vector<Employee>& list);
bool remove_from_list(int eid,vector<Employee>& list);

enum ERROR_CODE {NO_ERROR, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

const string INPUT_FILE_NAME = "commands.in";

int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }

    vector<Employee> e_list;
    char command;
    vector<Employee> list;

    input >> command;
    while (!input.eof())
    {
    	execute(command,list,input);
        input >> command;
    }



   print_all(list);
   print_stats(list  );

    return 0;
}


//Execute Each command according to the rules
void execute(char command, vector<Employee>& list, istream& input)
{
    Employee e;
    int eid;
	if(command=='+')
	{
		input>> std::ws;
		input>>e;
		if(add_to_list(e,list))
			cout<<command<<" "<<e.get_id()<<":"<<e<<endl;
		else
			cout<<command<<" "<<e.get_id()<<": *** Duplicate ID ***"<<endl;
		input>> std::ws;
	}
	else if(command=='-')
	{

		input>> std::ws;
		input>>eid;
		bool temp= remove_from_list(eid,list);


		input>> std::ws;
	}
	else if(command=='?')
	{
		input>> std::ws;
		input>>eid;
		int i=0;
		for(Employee temp:list)
		{	i++;
			if(temp.get_id()==eid)
			{
				cout<<command<<" "<<eid<<":"<<temp<<endl;
				break;
			}
		}
		if(i==list.size())
			cout<<command<<" "<<eid<<": "<<"*** ID not found ***"<<endl;
		input>> std::ws;

	}
	else
	{
		input>> std::ws;
		input>>e;
		cout<<command<<" "<<e.get_id()<<": "<<"*** Invalid command ***"<<endl;
		input>> std::ws;
	}




}

// add the employee data to list only if not a duplicate and maintain the sorted order.
bool add_to_list(Employee e,vector<Employee>& list)
{
	bool not_duplicate=true;
	int i=0;
	if(list.empty())
	{
		list.push_back(e);
		return not_duplicate;
	}

	for(; i<list.size();i++)
	{
		if(e.get_id()<list.at(i).get_id())
			break;
		if(e.get_id()==list.at(i).get_id())
			return false;
	}

	if(i==list.size())
	{
		list.push_back(e);
	}
	if(i<list.size())
	{
		list.insert(list.begin()+i, e);
	}

	return not_duplicate;

}

//Remove employee data from list only if the emp_id is available.
bool remove_from_list(int eid,vector<Employee>& list)
{

	//bool id_found=true;
	int i=0;
	for(Employee temp:list)
	{
		if(temp.get_id()==eid)
		{
			cout<<'-'<<" "<<eid<<":"<<temp<<endl;
			list.erase(list.begin() + i);
			return true;
		}
		i++;
	}

	if(i==list.size())
	{
		cout<<'-'<<" "<<eid<<": "<<"*** ID not found ***"<<endl;
		return false;
	}


}

void print_all(vector<Employee>& list)
{

	list.erase(list.begin() + list.size()-1);
	cout<<"\n"<<" All employees"<<"\n"<<" -------------"<<"\n";

	for(Employee temp:list)
	{
		cout<<temp<<endl;
	}

}


//Print the stats from the  data in employee list.
void print_stats(vector<Employee>& list)
{
	double min_sal,max_sal,avg=0;
	cout<<"\n"<<" Statistics"<<"\n"<<" ----------"<<"\n";
	min_sal=list.at(0).get_salary();
	max_sal=list.at(0).get_salary();

	for(int i=0;i<list.size()-1;i++)
	{
		if(list.at(i).get_salary()<min_sal)
			min_sal=list.at(i).get_salary();
		if(list.at(i).get_salary()>max_sal)
			max_sal=list.at(i).get_salary();

		avg+=list.at(i).get_salary();

	}

	std::cout << std::fixed;
	std::cout.precision(2);

	cout<<" Minimum salary = $ "<<min_sal<<endl;
	cout<<" Maximum salary = $"<<max_sal<<endl;
	cout<<" Average salary = $"<<(avg+list.at(list.size()-1).get_salary())/(list.size())<<endl;

}

