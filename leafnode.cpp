#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int info;
    struct node* left, *right;
 
};
 
/*
 * Function to create new nodes
 */
 
struct node* createnode(int key)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = key;
    newnode->left = NULL;
    newnode->right = NULL;
 
    return(newnode);
}
 
/* 
 * Function to count number of leaf nodes
 */
 
int count = 0;
int leafnodes(struct node* newnode)
{
 
    if(newnode != NULL)
    {
        leafnodes(newnode->left);
        if((newnode->left == NULL) && (newnode->right == NULL))
        {
            count++;
        }
        leafnodes(newnode->right);
    }
    return count;
 
}
 
/*
 * Main Function
 */
 
int main()
{
   /* Creating first Tree.*/
 
    struct node *newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
 
    /* Sample Tree 1- Balanced Tree
 
 
                    25
                  /    \
                 27     19
                / \     / \
              17  91   13 55
 
    */
    printf("Number of leaf nodes in first Tree are\t%d\n",leafnodes(newnode));
    count = 0;
 
    struct node *node = createnode(1);
    node->right = createnode(2);
    node->right->right = createnode(3);
    node->right->right->right = createnode(4);
    node->right->right->right->right = createnode(5);
 
    /* Sample Tree 2-   Right Skewed Tree (Unbalanced).
 
                    1
                     \
                      2
                       \
                        3
                         \
                          4
                           \
                            5
    */
 
    printf("\nNumber of leaf nodes in second tree are\t%d\n",leafnodes(node));
    count = 0;
 
    /*Creating third Tree. */
 
    struct node *root = createnode(15);
 
    /* Sample Tree 3-  Tree having just one root node.
 
                   15
    */
 
    printf("\nNumber of leaf nodes in third tree are\t%d",leafnodes(root));
 
    return 0;
}
