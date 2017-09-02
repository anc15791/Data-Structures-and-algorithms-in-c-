/*
 * Assignment 9. STL vector and list comparison.
 *
 * contains Sorted vector methods to perform all the operations.
 *
 * Author: Anurag Chowdhary
 *
*/

#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedVector::SortedVector()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedVector::~SortedVector()
{
    Node::reset();
}

/**
 * @return the size of the data vector.
 */
int SortedVector::size() const { return data.size(); }

/**
 * Check that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedVector::check() const
{
    if (data.size() == 0) return true;

    vector<Node>::const_iterator it = data.begin();
    vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than the previous node.
    while ((it != data.end()) && (*it > *prev))
    {
        prev = it;
        it++;
    }

    return it == data.end();  // Good if reached the end.
}

/**
 * Insert a new node at the beginning of the data vector.
 * @param value the new node's value.
 */
void SortedVector::prepend(const long value)
{
	vector<Node>::iterator it;
    Node s(value);
    it=data.begin();
    data.insert(it,s);
}

/**
 * Append a new node at the end of the data vector.
 * @param value the new node's value.
 */
void SortedVector::append(const long value)
{
    Node s(value);
    data.push_back(s);
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedVector::remove(const int index)
{
    vector<Node>::iterator it1=data.begin();
    std::advance(it1,index);
    data.erase(it1);
}

/**
 * Insert a new node into the data vector at the
 * appropriate position to keep the vector sorted.
 */
void SortedVector::insert(const long value)
{
    if(data.empty()){
    	Node s(value);
    	data.push_back(s);
    	return;
    }
    vector<Node>::iterator it1;
    it1=data.begin();
    while(it1!=data.end() && value>it1->get_value()){
    	it1++;
    }
	if(it1->get_value()==value)
	   return;

    if(it1==data.end()){
    	Node s(value);
    	data.push_back(s);
    }
    else{
    	Node s(value);
    	data.insert(it1,s);
    }
	/*
	cout<<" vector insert: value-"<<value;
    if(data.empty()){
    	Node s(value);
    	data.push_back(s);
    	return;
    }
    vector<Node>::iterator it1=data.begin();
    vector<Node>::reverse_iterator rit = data.rbegin();
    int mid=data.size()/2;

    if(value>data[mid].get_value()){
    	while(rit!=data.rend()){
        	if(value > rit->get_value() || value == rit->get_value())
        		break;
        	rit++;
    	}
    	it1=rit.base();
    	it1--;
    }
    else{
    	while(it1!=data.end()){
    		if(value < it1->get_value() || value == it1->get_value())
    			break;
    		it1++;
    	}
    }
    cout<<" data["<<mid<<"]:"<<data[mid].get_value()<<" it1->value:"<<it1->get_value()<<endl;

    if(it1->get_value()==value)
	   return;

    if(it1==data.end()){
    	Node s(value);
    	data.push_back(s);
    }
    else{
    	Node s(value);
    	data.insert(it1,s);
    }
    */
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node SortedVector::at(const int index) const
{
    return data.at(index);
}

vector<Node> SortedVector::get_vector() const {return data;}


void SortedVector::size_reserve(int size){
	data.reserve(size);
}
