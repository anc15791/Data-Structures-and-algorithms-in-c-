#include <iostream>
#include <vector>
#include <string>
#include "WordVector.h"

using namespace std;
using namespace std::chrono;

WordVector::WordVector()
{
}

WordVector::~WordVector()
{
}

vector<Word>& WordVector::get_data() { return data; }

int WordVector::get_count(const string text) const
{
   return data[find(text,0,data.size()-1)].get_count();
}

void WordVector::insert(const string text)
{

	steady_clock::time_point start_time = steady_clock::now();

	if(data.empty()){
	    	Word s(text);
	    	data.push_back(s);
	    	steady_clock::time_point end_time = steady_clock::now();
	    	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_time - start_time).count());
	    	return;
	    }
	    vector<Word>::iterator it1;
	    it1=data.begin();
	    while(it1!=data.end() && text>it1->get_text()){
	    	it1++;
	    }
		if(it1->get_text()==text){
			it1->increment_count();
			steady_clock::time_point end_time = steady_clock::now();
			increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_time - start_time).count());
			return;
		}


	    if(it1==data.end()){
	    	Word s(text);
	    	data.push_back(s);
	    }
	    else{
	    	Word s(text);
	    	data.insert(it1,s);
	    }

	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_time - start_time).count());
}

vector<Word>::iterator WordVector::search(const string text)
{
	vector<Word>::iterator it = data.begin();
	steady_clock::time_point start_time = steady_clock::now();
    it= data.begin()+find(text,0,data.size()-1);
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_time - start_time).count());
	return it;
}

int WordVector::find(const string text, int low, int high) const
{
	while (low <= high) {
	       int mid = (low + high) / 2;  // compute mid point.
	       if (text > data[mid].get_text())
	           low = mid + 1;  // repeat search in top half.
	       else if (text < data[mid].get_text())
	    	   high = mid - 1; // repeat search in bottom half.
	       else
	           return mid;     // found it. return position /////
	   }
	   return -(low + 1);    // failed to find key
}


