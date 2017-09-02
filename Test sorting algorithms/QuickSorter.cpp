/*
 * QuickSorter.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: sparta
 */

#include <iostream>
#include "QuickSorter.h"
using namespace std;

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

/**
 * Destructor.
 */
QuickSorter::~QuickSorter() {}

/**
 * Run the quicksort algorithm.
 * @throws an exception if an error occurred.
 */
void QuickSorter::run_sort_algorithm() throw (string)
{

    quicksort(0, size-1);

}

/**
 * The quicksort algorithm recursively sorts data subranges.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 */
void QuickSorter::quicksort(const int left, const int right)
{
	int p;
	if (left < right)
	{
		/* Partitioning index */
		p = partition(left, right,choose_pivot(left,right));
		quicksort(left,p-1);
		quicksort(p+1,right);
	}
}

/**
 * Choose the pivot according to a pivot strategy.
 * The chosen pivot will be moved temporarily to the right end.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @return the pivot value.
 */
Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

/**
 * Partition the subrange by moving data elements < pivot to the left
 * and data elements > pivot to the right.
 * @param left the left index of the partition to sort.
 * @param right the right index of the partition to sort.
 * @param pivot the pivot value.
 *
 * Referenced:
 * - GeeksforGeeks
 * - http://quiz.geeksforgeeks.org/quick-sort/
 *
 */
int QuickSorter::partition(const int low, const int high, const Element& pivot)
{

	int leftBoundary = low;
	int rightBoundary = high;
	while(leftBoundary < rightBoundary)
	{
		while(rightBoundary > leftBoundary)
		{
			compare_count++;
			if(pivot < data[rightBoundary])
				rightBoundary--;
			else
				break;
		}
		swap(leftBoundary,rightBoundary);

		while(leftBoundary < rightBoundary)
		{
			compare_count++;
			if(pivot >= data[leftBoundary])
				leftBoundary++;
			else
				break;
		}
		swap(rightBoundary, leftBoundary);
	}

	data[leftBoundary] = pivot;
	move_count++;
	return leftBoundary;

}

