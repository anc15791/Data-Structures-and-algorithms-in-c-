/*
 * ShellSortOptimal.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 *
 *        Referenced:
 * - GeeksforGeeks
 * - https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_algorithm.htm
 */

#include "ShellSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
ShellSortOptimal::ShellSortOptimal(string name) :VectorSorter(name) {}

/**
 * Destructor.
 */
ShellSortOptimal::~ShellSortOptimal() {}

/**
 * Run the optimal shellsort algorithm.
 * According to Don Knuth:
 * h = 3*i + 1 for i = 0, 1, 2, ... used in reverse.
 * @throws an exception if an error occurred.
 */
void ShellSortOptimal::run_sort_algorithm() throw (string)
{

	int interval=0;
	while(interval<size/3)
		interval = interval*3+1;

	while(interval>0)
	    {
		for (int i = interval; i < size; i++)
		{
			Element temp = data[i];
			int j;
			for (j = i; j >= interval ; j -= interval){
				compare_count++;
				if(data[j - interval] > temp){
					data[j] = data[j - interval];
					move_count++;
				}
				else
					break;
			}
			data[j] = temp;

		}

		interval = (interval -1) /3;
	    }


}

