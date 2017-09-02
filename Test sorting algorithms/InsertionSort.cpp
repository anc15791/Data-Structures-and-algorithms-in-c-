/*
 * InsertionSort.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 *
 *
 */

#include "InsertionSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
InsertionSort::InsertionSort(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
InsertionSort::~InsertionSort() {}

/**
 * Run the insertion sort algorithm.
 * @throws an exception if an error occurred.
 *
 * Referenced:
 * - GeeksforGeeks
 * - http://quiz.geeksforgeeks.org/insertion-sort/
 */
void InsertionSort::run_sort_algorithm() throw (string)
{
	for(int i = 1; i < size; i++){

		Element val = data[i];
			//move_count++;
			int j = i - 1;

			while(j >= 0 ){

				compare_count++;
				if(data[j] > val){
					data[j + 1] = data[j];
					move_count++;
					j = j - 1;
				}
				else break;

			}//end while

			data[j + 1] = val;

		}
}


