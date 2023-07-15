#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *left, *right;
};
int count = 0;
class BST
{
    public:
        /*
         * Function to create new nodes
         */
        struct node *createnode(int key)
        {
            struct node *newnode = new node;
            newnode->info = key;
            newnode->left = NULL;
            newnode->right = NULL;
            return(newnode);
        }
        int internalnodes(struct node *newnode)
        {
            if(newnode != NULL)
            {
                internalnodes(newnode->left);
                if((newnode->left != NULL) || (newnode->right != NULL))
                {
                    count++;
                }
                internalnodes(newnode->right);
            }
            return count;
        }
};
int main()
{
   /* Creating first Tree. */
    BST t1,t2,t3;
    struct node *newnode = t1.createnode(25);
    newnode->left = t1.createnode(19);
    newnode->right = t1.createnode(29);
    newnode->left->left = t1.createnode(17);
    newnode->left->right = t1.createnode(20);
    newnode->right->left = t1.createnode(27);
    newnode->right->right = t1.createnode(55);
    /* Sample Tree 1. Balanced Tree
     *               25
     *             /    \
     *            19    29
     *           / \     / \
     *         17  20   27 55
     */
    cout<<"Number of internal nodes in first Tree are "<<t1.internalnodes(newnode);
    cout<<endl;
    count = 0;
 
    /* Creating second tree */
    struct node *node = t2.createnode(1);
    node->right = t2.createnode(2);
    node->right->right = t2.createnode(3);
    node->right->right->right = t2.createnode(4);
    node->right->right->right->right = t2.createnode(5);
    /* Sample Tree 2. Right Skewed Tree (Unbalanced).
     *               1
     *                \
     *                 2
     *                  \
     *                   3
     *                    \
     *                     4
     *                      \
     *                       5
     */
    cout<<"\nNumber of internal nodes in second tree are "<<t2.internalnodes(node);
    cout<<endl;
    count = 0;
 
    /* Creating third Tree. */
    struct node *root = t3.createnode(15);
    /* Sample Tree 3. Tree having just one root node.
     *              15
     */
    cout<<"\nNumber of internal nodes in third tree are "<<t3.internalnodes(root);
    return 0;
}
