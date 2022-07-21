#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node_type
{
    int data;
    struct tree_node_type *left;
    struct tree_node_type *right;
} bst_node;

void insert(bst_node **, int);
void delete_node(bst_node **, int);
void inorder(bst_node *);
void preorder(bst_node *);
void postorder(bst_node *);
int count_nodes(bst_node *);
int count_internal_nodes(bst_node *);
int count_leaf_nodes(bst_node *);

int main()
{
    bst_node *root = NULL;
    int ch, newitem, dataitem;
    while (1)
    {
        printf("\n\n");
        printf("binary search tree operations \n");
        printf("-----------------------\n");
        printf("1. Insertion\n");
        printf("2. In-order Traversal\n");
        printf("3. Pre-order Traversal\n");
        printf("4. Post-order Traversal\n");
        printf("5. Deltion\n");
        printf("6. Number of nodes \n");
        printf("7. NUmber of leaf nodes\n");
        printf("8. Number of internal nodes\n");
        printf("9. EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the number to be inserted : ");
            scanf("%d", &newitem);
            insert(&root, newitem);
            break;
        case 2:
            printf("\n");
            printf("In-order Traversal\n");
            printf("-----------------\n");
            inorder(root);
            break;
        case 3:
            printf("\n");
            printf("Pre-order Traversal\n");
            printf("-----------------\n");
            preorder(root);
            break;
        case 4:
            printf("\n");
            printf("Post-order Traversal\n");
            printf("-----------------\n");
            postorder(root);
            break;
        case 5:
            printf("enter data to be deleted : ");
            scanf("%d", &dataitem);
            delete_node(&root, dataitem);
            break;
        case 6:
            printf("total nodes = %d ", count_nodes(root));
            break;
        case 7:
            printf("total leaf nodes = %d", count_leaf_nodes(root));
            break;
        case 8:
            printf("Internal nodes = %d", count_internal_nodes(root));
            break;
        case 9:
            exit(0);
            break;
        default:
            printf("please enter choice between 1 to 9 : ");
            break;
        }
    }
}

void insert(bst_node **root, int item)
{
    bst_node *p = (bst_node *)malloc(sizeof(bst_node));
    bst_node *parent;
    bst_node *ptr;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    if (root == NULL)
    {
        *root = p;
    }
    else
    {
        parent = NULL;
        ptr = *root;
        while (ptr != NULL)
        {
            parent = NULL;
            if (item > ptr->data)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
        if (item < parent->data)
        {
            parent->left = p;
        }
        else
        {
            parent->right = p;
        }
    }
}

void delete_node(bst_node **root, int item)
{
    bst_node *ptr;
    bst_node *parent;
    int flag = 0;
    if (*root == NULL)
    {
        printf("tree is empty: deletion not possible\n");
        return;
    }
    ptr = *root;
    while (ptr != NULL)
    {
        if (ptr->data == item)
        {
            flag = 1;
            break;
        }
        else
        {
            parent = ptr;
            if (item > ptr->data)
            {
                ptr = ptr->right;
            }
            else
            {
                ptr = ptr->left;
            }
        }
    }
    if (flag == 0)
    {
        printf("item not found");
        return;
    }
    if (ptr->left == NULL && ptr->right == NULL)
    {
        if (parent->left == ptr)
            parent->left = NULL;
        else
            parent->right = NULL;
        return;
    }
    if ((ptr->left == NULL && ptr->right != NULL) || (ptr->left != NULL && ptr->right == NULL))
    {
        if (ptr->left == NULL && ptr->right != NULL)
        {
            if (parent->left == ptr)
                parent->left = ptr->right;
            else
                parent->right = ptr->right;
        }
        else
        {
            if (parent->left == ptr)
                parent->left = ptr->left;
            else
                parent->right = ptr->left;
        }
        return;
    }
    if (ptr->left != NULL && ptr->right != NULL)
    {
        bst_node *succ, *temp;
        succ = ptr->right;
        if ((succ->left == NULL) && (succ->right == NULL))
        {
            temp = ptr->left;
            ptr = succ;
            ptr->right = NULL;
            ptr->left = temp;
            if (parent->data < ptr->data)
            {
                parent->right = ptr;
            }
            else
            {
                parent->left = ptr;
            }
        }
        else
        {
            if (succ->left != NULL)
            {
                bst_node * lptr;
                bst_node * lptrp;
                lptrp = ptr->right;
                lptr = lptrp-> left;
                while (lptr->left != NULL)
                {
                    lptrp = lptr;
                    lptr = lptr->left;
                }
                ptr->data = lptr->data;
                lptrp-> left = NULL;
            }
            else
            {
                bst_node *temp;
                temp = ptr->right;
                ptr->data = temp->data;
                ptr->right = temp->right;
            }
        }
        return;
    }
}

void inorder(bst_node*ptr){
    if (ptr!=NULL)
    {
        inorder(ptr->left);
        printf("%d",ptr->data);
        inorder(ptr->right);
    } 
}

void preorder(bst_node*ptr){
    if (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        preorder(ptr->left);
        preorder(ptr->right);
    } 
}

void postorder(bst_node*ptr){
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        printf("%d",ptr->data);
    }
}

int count_nodes(bst_node*ptr){
    if (ptr==NULL)
    {
        return 0;
    }
    else
    {
        return (count_nodes(ptr->left)+count_nodes(ptr->right)+1);
    }   
}

int count_internal_nodes(bst_node*ptr){
    if((ptr==NULL)||((ptr->left==NULL)&&(ptr->right==NULL))){
        return 0;
    }
    else{
        return (count_internal_nodes(ptr->left)+count_internal_nodes(ptr->right)+1);
    }
}

int count_leaf_nodes(bst_node*ptr){
    if(ptr==NULL)
    return 0;
    else if((ptr->left==NULL)&&(ptr->right==NULL))
    return 1;
    else
    return(count_leaf_nodes(ptr->left)+count_leaf_nodes(ptr->right));
}
