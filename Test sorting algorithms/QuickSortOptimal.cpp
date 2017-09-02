/*
 * QuickSortOptimal.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: sparta
 */

#include "QuickSortOptimal.h"

/**
 * Constructor.
 * @param name the name of this algorithm.
 */
QuickSortOptimal::QuickSortOptimal(string name) : QuickSorter(name) {}

/**
 * Destructor.
 */
QuickSortOptimal::~QuickSortOptimal() {}

/**
 * Choose a good pivot, the median-of-three:
 * The middle value of the leftmost, rightmost, and center elements.
 * This is a compromise since the most optimal pivot would be the
 * median of the subrange, but that's too expensive to compute.
 * @param left the left index of the subrange to sort.
 * @param right the right index of the subrange to sort.
 * @return the chosen pivot value.
 */
Element& QuickSortOptimal::choose_pivot_strategy(const int left, const int right)
{

	int middle=(left+right)/2;
		if((data[left].get_value()<=data[middle].get_value() && data[middle].get_value()<=data[right].get_value()) || (data[right].get_value()<=data[middle].get_value() && data[middle].get_value()<=data[left].get_value()))
		{
			compare_count+=4;
			swap(middle,left);
		}
		else if((data[left].get_value()<=data[right].get_value() && data[right].get_value()<=data[middle].get_value()) || (data[middle].get_value()<=data[right].get_value() && data[right].get_value()<=data[left].get_value())){
			compare_count+=4;
			swap(right,left);
		}


		return data[left];
}


