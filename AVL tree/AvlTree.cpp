#include <iostream>
#include "AvlTree.h"

using namespace std;

/**
 * Default constructor.
 */
AvlTree::AvlTree()
    : BinarySearchTree()
{
}

/**
 * Destructor.
 */
AvlTree::~AvlTree()
{
}

/**
 * Private method to compute the height of a subtree.
 * Overrides the base class method.
 * @param ptr pointer to the root node of the subtree.
 * @return the height of the subtree.
 */
int AvlTree::height( BinaryNode *ptr)
{
    return ptr == nullptr ? -1 : ptr->height;
}

/**
 * Private method to insert a data item into a subtree
 * and set the new root of the subtree.
 * Overrides the base class method.
 * @param data the data to insert.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::insert(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::insert(data, ptr);
    balance(ptr);
}

/**
 * Private method to remove a data item from a subtree
 * and set the new root node of the subtree.
 * Do nothing if the data item is not found.
 * Overrides the base class method.
 * @param data the data to remove.
 * @param ptr pointer to the root node of the subtree.
 */
void AvlTree::remove(const int data, BinaryNode* &ptr)
{
    BinarySearchTree::remove(data, ptr);
    balance(ptr);
}

/**
 * Private method to balance the tree.
 * @param ptr pointer to the node to balance.
 * @return pointer to the balanced node.
 */
BinaryNode *AvlTree::balance(BinaryNode* &ptr)
{
    if (ptr == nullptr) return ptr;

    // Left side too high.
    if (height(ptr->get_left()) - height(ptr->get_right()) > 1)
    {
        if (height(ptr->get_left()->get_left()) >= height(ptr->get_left()->get_right()))
        {
            ptr = singleRightRotation(ptr);
            //cout << "    --- Single right rotation at node "
              //   << ptr->data << endl;
        }
        else
        {
            ptr = doubleLeftRightRotation(ptr);
            //cout << "    --- Double left-right rotation at node "
              //   << ptr->data << endl;
        }
    }

    // Right side too high.
    else if (height(ptr->get_right()) - height(ptr->get_left()) > 1)
    {
        if (height(ptr->get_right()->get_right()) >= height(ptr->get_right()->get_left()))
        {
            ptr = singleLeftRotation(ptr);
            //cout << "    --- Single left rotation at node "
              //   << ptr->data << endl;
        }
        else
        {
            ptr = doubleRightLeftRotation(ptr);
           // cout << "    --- Double right-left rotation at node "
             //    << ptr->data << endl;
        }
    }

    // Recompute the node's height.
    ptr->height = (max(height(ptr->get_left()),
                       height(ptr->get_right())) + 1);

    if (checkBalance(ptr) < 0)
    {
        //cout << endl << "***** Tree unbalanced!" << endl;
    }

    return ptr;
}

/**
 * Case 1 (outside left-left): Rebalance with a single right rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::singleRightRotation(BinaryNode *k2)
{
    /***** Complete this member function. *****/

		BinaryNode *x = k2->get_left();
		BinaryNode *T2 = x->get_right();

	    // Perform rotation
	    x->get_right() = k2;
	    k2->get_left() = T2;

	    // Update heights
	    k2->height = max(height(k2->get_left()), height(k2->get_right()))+1;
	    x->height = max(height(x->get_left()), height(x->get_right()))+1;

	    // Return new root
	    return x;
}

/**
 * Case 2 (inside left-right): Rebalance with a double left-right rotation.
 * @param k3 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::doubleLeftRightRotation(BinaryNode *k3)
{
    /***** Complete this member function. *****/
	k3->get_left() = singleLeftRotation(k3->get_left());
	return (singleRightRotation(k3));
}

/**
 * Case 3 (inside right-left): Rebalance with a double left rotation.
 * @param k1 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::doubleRightLeftRotation(BinaryNode *k1)
{
    /***** Complete this member function. *****/
	k1->get_right() =singleRightRotation(k1->get_right());
	return (singleLeftRotation(k1));
}

/**
 * Case 4 (outside right-right): Rebalance with a single left rotation.
 * Update heights and return the new root node.
 * @param k2 pointer to the node to rotate.
 * @return pointer to the new root node.
 */
BinaryNode *AvlTree::singleLeftRotation(BinaryNode *k1)
{
    /***** Complete this member function. *****/
	BinaryNode *y = k1->get_right();
	BinaryNode *T2 = y->get_left();

	    // Perform rotation
	    y->get_left() = k1;
	    k1->get_right() = T2;

	    //  Update heights
	    k1->height = max(height(k1->get_left()), height(k1->get_right()))+1;
	    y->height = max(height(y->get_left()), height(y->get_right()))+1;

	    // Return new root
	    return y;
}

/**
 * Private method for a paranoid check of whether a tree node is balanced.
 * @param ptr pointer to the node to check.
 * @return the height of the node if balanced, -1 if the node is null,
 *         or -2 if unbalanced.
 */
int AvlTree::checkBalance(BinaryNode *ptr)
{
    if (ptr == nullptr) return -1;

    int leftHeight  = checkBalance(ptr->get_left());
    int rightHeight = checkBalance(ptr->get_right());

    if ((abs(height(ptr->get_left()) - height(ptr->get_right())) > 1)
        || (height(ptr->get_left())  != leftHeight)
        || (height(ptr->get_right()) != rightHeight))
    {
        return -2;       // unbalanced
    }

    return height(ptr);  // balanced
}
