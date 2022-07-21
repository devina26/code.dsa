#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void reverse(struct Node **head_ref)
{
    struct Node *temp = NULL;
    struct Node *current = *head_ref;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head_ref = temp->prev;
}

void push(struct Node **head_ref,
          int new_data)
{
    // Allocate node
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    // Put in the data
    new_node->data = new_data;

    /* Since we are adding at the beginning,
    prev is always NULL */
    new_node->prev = NULL;

    /* Link the old list off the new node */
    new_node->next = (*head_ref);

    /* Change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

// Driver code
int main()
{
    // Start with the empty list
    struct Node *head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("\nOriginal Linked list: \n");
    printList(head);

    // Reverse doubly linked list
    reverse(&head);

    printf("\nReversed Linked list: \n");
    printList(head);

    getchar();
}

