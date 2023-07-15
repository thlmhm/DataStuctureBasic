#include <iostream>
using namespace std;
struct treeNode{
	int data; // data of each node
	treeNode * leftmost_child;
	treeNode * right_sibling;
};
treeNode * Root;
