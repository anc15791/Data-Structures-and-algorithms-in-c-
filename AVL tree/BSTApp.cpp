/**
 * Test the binary search tree and AVL tree implementations.
 * The AVL tree is derived from the binary search tree.
 *
 * Create a tree of height 5 and then repeatedly
 * delete the root. The AVL tree should remain balanced
 * after each node insertion and deletion.
 */

#include <iostream>
//#include <time.h>
#include <ctime>
//#include <chrono>
#include <iomanip>
//#include <cstdlib>

#include "BinarySearchTree.h"
#include "AvlTree.h"

int N=10;
int step=10000;
using namespace std;
using namespace std::chrono;
string commafy(long n);
void tree_operations(BinarySearchTree& tree,double counts[][6]);
//void search_tree(BinarySearchTree& tree,double counts[][10]);
void print_results(double bst_counts[][6],double avl_counts[][6]);


int main(){
	srand(0);
	double bst_counts[10][6];
	double avl_counts[10][6];
	BinarySearchTree bst;
	AvlTree avl;
	tree_operations(bst,bst_counts);
	tree_operations(avl,avl_counts);
	print_results(bst_counts,avl_counts);


	return 0;
}


void tree_operations(BinarySearchTree& tree,double counts[][6]){

	for(int i=1;i<=N;i++){

		tree.clear();
		tree.setRoot();
		int size = step*i;

		BinaryNode::reset();
		int j=0;
		//cout<<" insert-"<<i<<" "<<(tree.getRoot()==nullptr)<<" "<<BinaryNode::probe_count<< " "<<BinaryNode::compare_count<<endl;
		steady_clock::time_point start_time = steady_clock::now();
		while(j<size){
			int elem = rand()%size;
			tree.insert(elem);
			j++;
		}
		steady_clock::time_point end_time = steady_clock::now();
		int elapsed_time = duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		counts[i-1][0]=BinaryNode::probe_count;
		counts[i-1][1]=BinaryNode::compare_count;
		counts[i-1][2]=elapsed_time;
		//cout<<" insert: "<<counts[i-1][0]<<" "<<counts[i-1][1]<<" "<<counts[i-1][2]<<" "<<endl;
		BinaryNode::reset();

		//cout<<" search-"<<i<<" "<<(tree.getRoot()==nullptr)<<" "<<BinaryNode::probe_count<< " "<<BinaryNode::compare_count<<endl;
		j=0;
		start_time = steady_clock::now();
		while(j<size){
			int elem = rand()%size;
			tree.contains(elem);
			j++;
		}

		end_time = steady_clock::now();
		elapsed_time = duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
		counts[i-1][3]=BinaryNode::probe_count;
		counts[i-1][4]=BinaryNode::compare_count;
		counts[i-1][5]=elapsed_time;
		//cout<<" search: "<<counts[i-1][3]<<" "<<counts[i-1][4]<<" "<<counts[i-1][5]<<" "<<endl<<endl;

	}



}


void print_results(double bst_counts[][6],double avl_counts[][6]){

	for(int i=0;i<N;i++){
		std::cout.precision(0);
		cout<<step*(i+1);
		for(int j=0;j<6;j++){
			cout<< std::fixed<<","<<bst_counts[i][j]<<","<<avl_counts[i][j]<<"";
		}
		cout<<endl;
	}

}


/**
 * Convert a number to a string with commas.
 * @param n the number.
 */
string commafy(long n)
{
    string str = to_string(n);
    int pos = str.length() - 3;

    while (pos > 0)
    {
        str.insert(pos, ",");
        pos -= 3;
    }

    return str;
}
