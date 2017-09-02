/*
 * File Name: primes.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:3 a
 * Description: Program that computes prime numbers from(2-1000) using Sieve of Eratosthenes
 * Created on: Feb 13, 2017
 */


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int MAX_NUMBER = 1000;  // maximum possible prime number
const int ROW_SIZE   = 20;    // row size for printing

void print_primes(int[],bool[]);
void compute_primes(int[],bool[]);

/**
 * The main: Compute and print the prime numbers up to MAX_NUMBER.
 */
int main()
{

	int numbers[MAX_NUMBER-1];
	bool primes[MAX_NUMBER-1];
	for(int i=0;i<MAX_NUMBER-1;i++)
	{
		numbers[i]=i+2;
		primes[i]=true;
	}
	compute_primes(numbers,primes);
	print_primes(numbers,primes);
	cout<<"\n \n"<<"Done!";

	return 0;
}

/*
 * Function : void print_primes(int[],bool[]);
 * print_primes: To print output in a matrix format
 * @param 1: matrix of numbers to be printed
 * @param 2: bool array with prime positions marked as true
 */

void print_primes(int out[],bool primes[])
{

	int counter=0;
	for(int i=0;i<MAX_NUMBER;i++)
	{
		if(primes[i])
		{
			cout.width(3);
			cout<<std::right<<out[i]<<" ";
			counter++;

		}
		if(counter==ROW_SIZE)
		{
			cout<<"\n";
			counter=0;
		}
	}
}

/*
 * Function : void compute_primes(int[],bool[]);
 * compute_primes : using Sieve of Eratosthenes algorithm compute prime numbers among 2-1000
 * @param 1: array of integers
 * @param 2: array of bool values initialized to true
 */

void compute_primes(int nums[], bool out[])
{
	int counter=1;
	for(int i=0;i<MAX_NUMBER-1;i++)
	{
		if(out[i])
		{
			for(int j=i;j<MAX_NUMBER;j++)
			{
				if(nums[j]== (nums[i]+(nums[i]*counter)))
				{
					out[j]=false;
					counter++;
				}
			}
		}
		counter=1;
	}


}


