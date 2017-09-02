#include <iostream>
#include <iterator>
#include "SortedList.h"

using namespace std;

/**
 * Defaut constructor.
 * Reset the global Node counters.
 */
SortedList::SortedList()
{
    Node::reset();
}

/**
 * Destructor.
 * Reset the global Node counters.
 */
SortedList::~SortedList()
{
    Node::reset();
}

/**
 * @return the size of the data list.
 */
int SortedList::size() const { return data.size(); }

/**
 * that the data is sorted.
 * @return true if sorted, false if not.
 */
bool SortedList::check()
{
    if (data.size() == 0) return true;

    list<Node>::iterator it = data.begin();
    list<Node>::iterator prev = it;

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
 * Insert a new node at the beginning of the data list.
 * @param value the new node's value.
 */
void SortedList::prepend(const long value)
{
	Node s(value);
    data.push_front(s);
}

/**
 * Append a new node at the end of the data list.
 * @param value the new node's value.
 */
void SortedList::append(const long value)
{
	Node s(value);
    data.push_back(s);
}

/**
 * Remove a node.
 * @param index the index of the node to remove.
 */
void SortedList::remove(const int index)
{
    list<Node>::iterator it1;
    it1=data.begin();
    std::advance(it1,index);
    data.erase(it1);
}

/**
 * Insert a new node into the data list at the
 * appropriate position to keep the list sorted.
 */
void SortedList::insert(const long value)
{

    if(data.empty()){
    	Node s(value);
    	data.push_back(s);
    	return;
    }
    list<Node>::iterator it1;
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
}

/**
 * Return the data node at the indexed position.
 * @param the index of the node.
 * @return a copy of the data node.
 */
Node SortedList::at(const int index)
{
    list<Node>::iterator it1=data.begin();
    //list<Node>::reverse_iterator rit = data.rbegin();

    std::advance(it1,index);
    return *it1;
}



list<Node> SortedList::get_list() const {return data;}
/*
void SortedList::print(){
	copy(data.begin(), data.end(),
	        	      ostream_iterator<int>(cout, " "));
	        	   cout << endl;
}
*/
