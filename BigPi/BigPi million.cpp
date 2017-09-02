/*
 * File Name: BigPi million.cpp
 * Author: Anurag Chowdhary (011550201)
 * Email Address: anurag.chowdhary@sjsu.edu
 * Assignment Number:4
 * Description: Program that computes value of pi upto 1000 & 1000000 digits using MPIR library
 * Created on: Feb 19, 2017
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <mpir.h>
#include <mpirxx.h>
#include <fstream>


using namespace std;

const int MAX_ITERATIONS = 10;
const int PLACES         = 1000000;        // desired decimal places computation
const int PRECISION      = PLACES + 1;  // +1 for the digit 3 before the decimal

const int BASE       = 10;  // base 10 numbers
const int BIT_COUNT  = 8;   // bits per machine word

const int BLOCK_SIZE = 10;                // print digits in blocks
const int LINE_SIZE  = 100;               // digits to print per line
//const int LINE_COUNT = PLACES/LINE_SIZE;  // lines to print
const int GROUP_SIZE = 5;                 // line grouping size

/***** Function declarations here. *****/
void print( mpf_class *pi);
void compute_big_pi(mpf_class*, mpf_class*,int);

/**
 * The main.
 * Set constants, initialize variables, and iterate
 * to compute pi to the desired number of decimal places.
 */
int main()
{
    mpf_set_default_prec(BIT_COUNT*PRECISION);  // precision in bits

    mpf_class a( 6-(4*sqrt(2)) , BIT_COUNT*PRECISION); // initialize value of a
    mpf_class y(sqrt(2)-1 , BIT_COUNT*PRECISION); // initialize value of y
    mpf_class pi(1,BIT_COUNT*PRECISION);

    for (int i = 1; i <= MAX_ITERATIONS; i++)
    {
    	compute_big_pi(&a,&y,i);
    }

    mpf_div(pi.get_mpf_t(),pi.get_mpf_t(),a.get_mpf_t()); //compute 1/a
    print(&pi);

    return 0;
}

/*
 * Computes value of a & y at every iteration i.
 * a converges to 1/pi
 * y converges to 0
 * */

void compute_big_pi(mpf_class *a, mpf_class *y, int i)
{
	mpf_set_default_prec(BIT_COUNT*PRECISION);

	mpf_class first_term(0, BIT_COUNT*PRECISION);
	mpf_class second_term(0, BIT_COUNT*PRECISION);
	mpf_class temp(1, BIT_COUNT*PRECISION);
	mpf_class temp2(0, BIT_COUNT*PRECISION);

	//*******calculate yi********

	//compute (1-yi^4)
	mpf_pow_ui(temp2.get_mpf_t(), (*y).get_mpf_t() , 4);
	mpf_sub(temp2.get_mpf_t(),temp.get_mpf_t() ,temp2.get_mpf_t());

	//compute ((1-yi^4))  ^(1/4)
	mpf_sqrt(temp2.get_mpf_t(),temp2.get_mpf_t());
	mpf_sqrt(temp2.get_mpf_t(),temp2.get_mpf_t());

	//compute 1-  ((1-yi^4))^(1/4)
	mpf_sub(first_term.get_mpf_t(), temp.get_mpf_t(), temp2.get_mpf_t());

	//compute 1+  ((1-yi^4))^(1/4)
	mpf_add(second_term.get_mpf_t(), temp.get_mpf_t(), temp2.get_mpf_t());

	//compute yi = (1-  ((1-yi^4))^(1/4))/(1+  ((1-yi^4))^(1/4))
	mpf_div( (*y).get_mpf_t() , first_term.get_mpf_t() , second_term.get_mpf_t()); // yi_first_term/yi_second_term



	// *****calculate ai******
	temp=1;
	temp2=0;
	first_term=0;
	second_term=0;

	//compute 1+yi ,
	mpf_add(first_term.get_mpf_t(),temp.get_mpf_t(), (*y).get_mpf_t());

	//compute (1+yi)^4
	mpf_pow_ui(first_term.get_mpf_t(), first_term.get_mpf_t(),4);

	//compute ai * (1+yi)^4
	mpf_mul(first_term.get_mpf_t(), first_term.get_mpf_t(), (*a).get_mpf_t());

	//compute 2 ^ (2*i +1) * yi
	temp = pow(2,(2*i)+1) ; // 2 ^ (2*i +1)
	mpf_mul(second_term.get_mpf_t(),temp.get_mpf_t(),(*y).get_mpf_t());

	//compute 1 + *y + (*y * *y);
	temp=1;
	temp2=0;
	mpf_pow_ui(temp2.get_mpf_t(), (*y).get_mpf_t(),2);
	mpf_add(temp.get_mpf_t(),temp.get_mpf_t(),(*y).get_mpf_t());
	mpf_add(temp.get_mpf_t(),temp.get_mpf_t(),temp2.get_mpf_t());

	//compute 2 ^ (2*i +1) * yi * (1 + yi * (yi * yi))
	mpf_mul(second_term.get_mpf_t(),second_term.get_mpf_t(),temp.get_mpf_t());

	//compute ai =( ai * (1+yi)^4 )- ( (2 ^ (2*i +1)) * yi * (1 + yi * (yi * yi)))
	mpf_sub((*a).get_mpf_t(),first_term.get_mpf_t(),second_term.get_mpf_t());

}

/*
 * Prints the value of Pi in the given format onto a .txt file and console
 * */
void print( mpf_class* pi)
{

	ofstream myfile;
	myfile.open ("BigMillionPi_011550201_Anurag_Chowdhary.txt");
	int count_block=0;
	int count_line=0;
	int count_line_block=0;

	mp_exp_t exp;
	std::string BigPi = (*pi).get_str(exp,BASE,BIT_COUNT*PRECISION); // convert mpf_class variable into string

	myfile<<BigPi[0]<<"."; // print 3. in the beginning
	cout<<BigPi[0]<<".";

	int i;

	// start loop from second digit
	for(i=1; i<PRECISION;i++)
	{

		myfile<<BigPi[i];

		cout<<BigPi[i];

		count_block++;
		count_line++;
		if(count_block==BLOCK_SIZE)
		{
			myfile<<" "; // give space after printing 10 digits in file
			cout<<"  "; // for console output
			count_block=0;
		}
		if(count_line==LINE_SIZE)
		{
			myfile<<"\n"; // go to next line after printing 10 blocks of 10 digits per line in file
			myfile<<"  ";

			cout<<"\n";// for console output
			cout<<"  ";


			count_line=0;
			count_line_block++;
		}
		if(count_line_block==GROUP_SIZE)
		{
			myfile<<"\n"; // give extra line after printing 5 line one below the other in file

			cout<<"\n";// for console output

			count_line_block=0;
			myfile<<"  ";

			cout<<"  ";

		}

	}
	myfile.close();
	cout<<"successfully printed output to BigMillionPi_011550201_Anurag_Chowdhary.txt \"view in full screen \" ";

}



