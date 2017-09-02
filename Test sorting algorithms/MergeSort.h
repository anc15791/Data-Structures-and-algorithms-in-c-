/*
 * MergeSort.h
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_

#include <string>
#include "LinkedList.h"
#include "ListSorter.h"

using namespace std;
/**
 * The class that implements the mergesort algorithm
 * for a singly linked list of data.
 */
class MergeSort: public ListSorter
{
public:
    MergeSort(string name);
    virtual ~MergeSort();

    virtual void run_sort_algorithm() throw (string);

private:
    void mergesort(LinkedList& list);
    void merge(LinkedList& list, LinkedList& sublist1, LinkedList& sublist2);

    void clear();
    Node getMiddle(Node head);
};

#endif /* MERGESORT_H_ */
