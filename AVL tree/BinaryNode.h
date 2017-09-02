/**
 * A node of a binary tree.
 */

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

class BinaryNode
{
public:
    BinaryNode(const int data);
    BinaryNode(const int data, BinaryNode *left, BinaryNode *right);
    virtual ~BinaryNode();

    BinaryNode* &get_left();
    BinaryNode* &get_right();
   // BinaryNode* get_leftptr();
    //BinaryNode* get_rightptr();
    int get_data();

    int data;
    int height;  // node height

    BinaryNode *left;
    BinaryNode *right;

    static long probe_count, compare_count;
    static void reset();
};


#endif // BINARY_TREE_PRINTER_H
