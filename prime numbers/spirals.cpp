/*
 * File Name: spirals.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:3 b
 * Description: Program that prints incremental array values in an anti clockwise spiral with start value at center.
 * Created on: Feb 13, 2017
 *
 */
#include <iostream>
using namespace std;

const int MAX_SIZE  = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number



void do_spiral(const int n, const int start);
void make_spiral(int,int[][MAX_SIZE], int);
void print_spiral(int,int[][MAX_SIZE]);

/**
 * The main: Generate and print spirals of various sizes.
 */
int main()
{
    do_spiral(1, 1);
    do_spiral(5, 1);
    do_spiral(9, 11);
    do_spiral(12, 13);
    do_spiral(15, 17);

    return 0;
}


/*
 * Function : void do_spiral(int size, int start)
 * Checks for size and start value conditions and prints appropriate errors.
 * Calls following functions:
 * 	void make_spiral(int,int[][MAX_SIZE], int)
 * 	void print_spiral(int,int[][MAX_SIZE])
 * @param 1: dimension of array
 * @param 2: start in value
 * */
void do_spiral(int size, int start)
{
	cout<<"Spiral of size "<<size<<" starting at "<<start<<"\n";
	if(size%2 == 0)
	{
		cout<<"***** Error: Size "<<size<<" must be odd."<<"\n\n";
		return;
	}

	if(size < 1 || size > MAX_SIZE)
	{
		cout<<"***** Error: Size "<<size<<" must be through 1 and 101."<<"\n\n";
		return;
	}

	if(start < 1 || start > MAX_START)
	{
		cout<<"***** Error: start "<<start<<" must be through 1 and 50."<<"\n\n";
		return;

	}
	cout<<"\n";

	int matrix[MAX_SIZE][MAX_SIZE];

	// initializing array with test value -1
	for(int i=0 ; i<size ; i++)
		for(int j=0 ; j<size ; j++)
			matrix[i][j]=-1;


	make_spiral(size,matrix,start);
	print_spiral(size,matrix);

}

/*
 *Function : void make_spiral(int size, int spiral[][MAX_SIZE], int start )
 *Creates an array with incremental array values in an anti clockwise spiral with start value at center.
 *@param 1: dimension of array
 *@param 2: 2-D array
 *@param 3: start integer value
 */

void make_spiral(int size, int spiral[][MAX_SIZE], int start )
{
	int array_high_index = size-1;
	int currentval = (size * size) - 1;
	currentval += start; // Initializes currentval with highest integer array value for the given array dimension and start

	spiral[array_high_index/2][array_high_index/2] = start; // placing start at the center of array

	for(int i=array_high_index ; i>array_high_index/2 ; i--)
	{

		//Traversing the Bottom side
		for(int j = 0 ; j <= i ; j++)
		{
			if(spiral[i][i - j] == -1)
			{
				spiral[i][i - j] = currentval--;
			}
		}

		//Traversing the Left side
		for(int j=0 ; j<=i ; j++)
		{
			if(spiral[i - j][array_high_index - i] == -1)
			{
				spiral[i - j][array_high_index - i] = currentval--;
			}
		}

		//Traversing the Top side
		for(int j = 0 ; j <= i ; j++)
		{
			if(spiral[array_high_index - i][j] == -1)
			{
				spiral[array_high_index - i][j] = currentval--;
			}
		}

		//Traversing the Bottom side
		for(int j = 0 ; j <= i ; j++)
		{
			if(spiral[j][i] == -1)
			{
				spiral[j][i] = currentval--;
			}
		}

	}

}



void print_spiral(int size, int spiral_matrix[][MAX_SIZE])
{

	for(int i=0;i<size;i++)
	{
		cout<<" ";
		for(int j=0;j<size;j++)
		{
			cout.width(3);
			cout<<std::right<<spiral_matrix[i][j]<<" ";

		}
	cout<<"\n";
	}
	cout<<"\n";
}

