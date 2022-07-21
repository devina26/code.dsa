#include <stdio.h>
#include <stdlib.h>

// structure of Node with prev and next pointers
struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * head, *last;
void createList(int n);
void displayList();
void search_element(int data);

int main()
{
    int n, data;
    head = NULL;
    last = NULL;
    printf("\nEnter the total number of nodes in list : "); // Input the number of nodes
    scanf("%d", &n);
    createList(n);
    printf("\n\nTHE DOUBLY LINKED LIST IS :\n\n");
    displayList();
    printf("\n\nEnter the element you want to search : ");
    scanf("%d", &data);
    search_element(data);
    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *newNode;
    if (n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter data of node 1 : ");
        scanf("%d", &data);
        head->data = data;
        head->prev = NULL; // HEAD nodes's prev is set to NULL
        head->next = NULL; // HEAD nodes's next is set to NULL
        last = head;
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("\nEnter data of node %d : ", i);
            scanf("%d", &data);
            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;
            last->next = newNode; // Link previous node with the new node
            last = newNode;       // Make new node as last node
        }
    }
}
void displayList()
{
    struct node *temp;
    int n = 1;
    if (head == NULL)
    {
        printf("\nList is empty.\n");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            n++;
            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}

void search_element(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == data) // Element is found
        {
            printf("\n\nThe element %d is at index %d in the list", data, pos); // If found, print and exit
            exit(0);
        }
        else
        {
            temp = temp->next; // If not found, traverse the list
            pos++;
        }
    }
    printf("\n\nThe element %d is not found in the list", data);
}
