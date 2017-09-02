/*
 * MergeSort.cpp
 *
 *  Created on: Apr 26, 2017
 *      Author: Anurag Chowdhary
 *
 * Referenced:
 * - GeeksforGeeks
 * - http://www.geeksforgeeks.org/merge-sort-for-linked-list/
 */

#include <string>
#include "MergeSort.h"

/**
 * Constructor.
 * @param name the name of the algorithm.
 */
MergeSort::MergeSort(string name) : ListSorter(name) {}

/**
 * Destructor.
 */
MergeSort::~MergeSort() {}

/**
 * Run the mergesort algorithm.
 * @throws an exception if an error occurred.
 */
void MergeSort::run_sort_algorithm()
    throw (string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

/**
 * The mergesort algorithm recursively splits and merges data lists.
 * @param list the list of data to sort.
 */
void MergeSort::mergesort(LinkedList& list)
{
	  Node* head = list.get_head();
	  LinkedList a;
	  LinkedList b;

	  /* Base case -- length 0 or 1 */
	  if ((head == NULL) || (head->next == NULL))
	  {
	    return;
	  }

	  /* Split head into 'a' and 'b' sublists */
	  list.split(a,b);

	  /* Recursively sort the sublists */
	  //mergesort(a);
	  //mergesort(b);

	  /* answer = merge the two sorted lists together */
	  //merge(list,a, b);
}

/**
 * Merge two sublists back into a single list.
 * @param list the merged list.
 * @param sublist1 the first sublist.
 * @param sublist2 the second sublist.
 */
void MergeSort::merge(LinkedList& list,
                      LinkedList& sublist1, LinkedList& sublist2)
{
	Node* a = sublist1.get_head();
	Node* b = sublist2.get_head();
	Node* temp;

	if(a == nullptr){  //checking whether sublist1 is empty
	    compare_count++;
	    Node* pt = sublist2.get_head();
	    while(pt != nullptr){
	        move_count++;
	        pt = pt->next;
	    }
	    list.concatenate(sublist2); //appending sublist2
	    return;
	}
	else if(b == nullptr){ //checking whether sublist2 is empty
	    compare_count++;
	    Node* pt = sublist2.get_head();
	    while(pt != nullptr){
	        move_count++;
	        pt = pt->next;
	    }
	    list.concatenate(sublist1); //appending sublist1
	    return;
	}
	else {
	    while (a != nullptr && b != nullptr) {  //iterating till any one list reaches to the end
	        compare_count++;
	        if (a->element <= b->element) { //comparing the value of the elements
	            temp = a->next;
	            move_count++;
	            list.add(sublist1.remove_head());  //adding to the list
	            a = temp;
	        } else {
	            temp = b->next;
	            move_count++;
	            list.add(sublist2.remove_head()); //adding to the list
	            b = temp;
	        }
	    }
	    merge(list,sublist1,sublist2);
	}
}

/**
 * Clear the data.
 */
void MergeSort::clear() { data.clear(); }


//Finding the middle element of the list for splitting
 Node getMiddle(Node head) {

}
