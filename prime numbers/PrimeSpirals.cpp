/*
 * File Name: PrimeSpirals.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:3 c
 * Description: Program that prints '#' if number is prime else prints '.' in an anti clockwise spiral starting from center with a start value..
 * Created on: Feb 14, 2017
 *
 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_START = 50;   // maximum starting number

void do_prime_spiral(const int n, const int start);
void make_spiral(const int n, vector< vector <int> >& ,const int start);
void print_spiral(vector< vector <int> >&);
bool compute_prime(int);

/**
 * The main: Generate and print prime spirals of various sizes.
 */
int main()
{
    do_prime_spiral(5, 1);
    do_prime_spiral(25, 11);
    do_prime_spiral(35, 0);
    do_prime_spiral(50, 31);
    do_prime_spiral(101, 41);
}


/*
 * Function : void do_prime_spiral(const int n, const int start)
 * Checks for size(n) and start value conditions and prints appropriate errors.
 * Calls following functions:
 * 	void make_spiral(const int n, vector<vector<int>>& ,const int start);
 * 	void print_spiral(vector< vector <int> >&);
 * @param 1: dimension of matrix
 * @param 2: start integer value
 * */

void do_prime_spiral(const int n, const int start)

{

	cout<<" Prime spiral of size "<<n<<" starting at "<<start<<"\n";
	if(n % 2 == 0)
	{
		cout<<" ***** Error: Size "<<n<<" must be odd."<<"\n\n";
		return;
	}

	if(n < 1)
	{
		cout<<" ***** Error: Size "<<n<<" must be greater than 0."<<"\n\n";
		return;
	}

	if(start < 1 || start > MAX_START)
	{
		cout<<" ***** Error: Starting value "<<start<<" < 1 or > 50"<<"\n\n";
		return;

	}
	cout<<"\n";

	vector< vector <int> > matrix;

	//initialize 2-D vector with -1 as test value.
	for(int i = 0 ; i < n ; i++)
	{	vector<int> row;
		for(int j = 0 ; j < n ; j++)
		{
			row.push_back(-1);
		}
		matrix.push_back(row);
	}
	make_spiral(n, matrix ,start);
	print_spiral(matrix);
}


/*
 *Function : void make_spiral(const int n, vector<vector<int>>& ,const int start)
 *Creates a vector with 0 if non-prime and 1 if prime in anti clockwise spiral starting with center of vector having start value.
 *@param 1: dimension of matrix
 *@param 2: 2-D integer vector
 *@param 3: start integer value
 */

void make_spiral(const int n, vector< vector <int> >& spiral , const int start)
{
	int last_index = spiral.size()-1;
	int currentval = (spiral.size() * spiral.size()) - 1;
	currentval += start; // Initializes currentval with highest integer vector value for the given vector size and start value.

	// placing start at the center of array
	if(compute_prime(start))
		spiral[last_index/2][last_index/2] = 1;
	else
		spiral[last_index/2][last_index/2] = 0;


	for(int i=last_index ; i>last_index/2 ; i--)
	{

		//Traversing the Bottom side
		for(int j = 0 ; j <= i ; j++)
		{
			if(spiral[i][i - j] == -1)
			{
				if(compute_prime(currentval))
					spiral[i][i - j] = 1;
				else
					spiral[i][i - j] = 0;
				currentval--;
			}
		}

		//Traversing the Left side
		for(int j=0 ; j<=i ; j++)
		{
			if(spiral[i - j][last_index - i] == -1)
			{
				if(compute_prime(currentval))
					spiral[i - j][last_index - i] = 1;
				else
					spiral[i - j][last_index - i] = 0;
					currentval--;
			}
		}

		//Traversing the Top side
		for(int j = 0 ; j <= i ; j++)
		{
			if(spiral[last_index - i][j] == -1)
			{
				if(compute_prime(currentval))
					spiral[last_index - i][j] = 1;
				else
					spiral[last_index - i][j] = 0;
				currentval--;
			}
		}

		//Traversing the Bottom side
		for(int j = 0 ; j <= i ; j++)
		{
			if(spiral[j][i] == -1)
			{
				if(compute_prime(currentval))
					spiral[j][i] = 1;
				else
					spiral[j][i] = 0;
				currentval--;
			}
		}

	}

}


void print_spiral(vector< vector <int> >& matrix)
{

	for(int i=0 ; i < matrix.size() ; i++)
	{
		cout<<" ";
		for(int j=0 ; j<matrix.size() ; j++)
		{
			if(matrix[i][j] == 1)
			{
				cout<<std::right<<"#";
			}
			else
			{
				cout<<std::right<<".";

			}

		}
	cout<<"\n";
	}
	cout<<"\n";
}



bool compute_prime(int num)
{

	if(num == 0)
		return false;
	if(num == 1)
		return false;
	if(num == 2)
		return true;
	if(num % 2 ==0)
		return false;

	for(int i = 3 ; i <= sqrt(num) ; i += 2)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}


