/*
 * Assignment 7. U.S. Cities
 *
 * Print a map of the U.S. with its major cities.
 * Input files contain geographic coordinates.
 *
 * Author: Anurag Chowdhary
 * */
#include "SortedLinkedList.h"

//default constructor
SortedLinkedList::SortedLinkedList():head(nullptr){}

//destructor
SortedLinkedList::~SortedLinkedList(){

	Node* temp;
	Node* prev;
	prev=head;
	while(temp!=nullptr){
		temp=prev->next;
		delete prev;
		prev=temp;
	}
	head=nullptr;
}

//getter
Node *SortedLinkedList::get_head() const { return head; }

/**
 * Insert a new node into the sorted linked list.
 * Uses the overloaded Node::operator > to compare nodes.
 * @param node points to the node to insert.
 */
void SortedLinkedList::insert(Node *node)
{


	if(head==nullptr){
		head=node;

	}
	else if(*head>*node){
		node->next=head;
		head=node;

	}
	else{

		Node* prev;
		Node* temp=head;
		while((temp!=nullptr) && (*node>*temp)){
			prev=temp;
			temp=temp->next;
		}

		prev->next=node;
		node->next=temp;
	}

}


// Overloaded stream output insertion operator.

ostream& operator <<(ostream& outs, const SortedLinkedList& list){

	int col_count=0;
	int row_count=0;
	Node *n = list.get_head();
	while ( n != nullptr){


		if(n->get_row()!=row_count){
			col_count=0;
			cout<<endl;
			row_count++;
			while(n->get_row() > row_count){
				cout<<"\n";
				row_count++;
			}
		}


		if(col_count<=n->get_col()){

			while(col_count<n->get_col()){
				cout<<" ";
				col_count++;
			}
			cout<<*n;
			col_count++;
			if(n->get_name().length()>0){
				int i=0;
				int size=n->get_name().length()+n->get_state().length();
				for(i=0;i<=size;i++){}
				col_count+=i;

			}
		}


		n = n->next;
	}

	return outs;
}
