#include <iostream>
#include <map>
#include <string>
#include "WordMap.h"

using namespace std;
using namespace std::chrono;

WordMap::WordMap()
{
}

WordMap::~WordMap()
{
}

map<string, Word>& WordMap::get_data() { return data; }

int WordMap::get_count(const string text) const
{
    return data.find(text)->second.get_count();
}

void WordMap::insert(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();
    pair<map<string, Word>::iterator,bool> p = data.insert(make_pair(text,Word(text)));
    if(p.second==false){
    	p.first->second.increment_count();
    }
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_time - start_time).count());
}

map<string, Word>::iterator WordMap::search(const string text)
{
	steady_clock::time_point start_time = steady_clock::now();
	map<string, Word>::iterator it = data.find(text);
	steady_clock::time_point end_time = steady_clock::now();
	increment_elapsed_time(duration_cast<std::chrono::microseconds>(end_time - start_time).count());
	return it;
}
