
#include <stdio.h>  
#include <stdlib.h>  
	   
	//Represent a node of the doubly linked list  
	  
	struct node{  
	    int data;  
	    struct node *previous;  
	    struct node *next;  
	};      
	   
	//Represent the head and tail of the doubly linked list  
	struct node *head, *tail = NULL;  
	   
	//addNode() will add a node to the list  
	void addNode(int data) {  
	    //Create a new node  
	    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
	    newNode->data = data;  
	      	    //If list is empty  
	    if(head == NULL) {  
	        //Both head and tail will point to newNode  
	        head = tail = newNode;  
	        //head's previous will point to NULL  
	        head->previous = NULL;  
	        //tail's next will point to NULL, as it is the last node of the list  
	        tail->next = NULL;  
	    }  
	    else {  
	        //newNode will be added after tail such that tail's next will point to newNode  
	        tail->next = newNode;  
	        //newNode's previous will point to tail  
	        newNode->previous = tail;  
	        //newNode will become new tail  
	        tail = newNode;  
	        //As it is last node, tail's next will point to NULL  
	        tail->next = NULL;  
	    }  
	}  
	   
	//searchNode() will search a given node in the list  
	void searchNode(int value) {  
	    int i = 1;  
	    bool flag = false;  
	    //Node current will point to head  
	    struct node *current = head;  
	      
	    //Checks whether the list is empty  
	    if(head == NULL) {  
	        printf("List is empty\n");  
	        return;  
	    }  
	    while(current != NULL) {  
	        //Compare value to be searched with each node in the list  
	        if(current->data == value) {  
	            flag = true;  
	            break;  
	        }  
	        current = current->next;  
	        i++;  
	    }  
	    if(flag)  
	         printf("Node is present in the list at the position : %d\n", i);  
	    else  
	         printf("Node is not present in the list\n");  
	}  
	   
	int main()  
	{  
	    //Add nodes to the list  
	    addNode(1);  
	    addNode(5);  
        addNode(4);  
	    addNode(2);  
	    addNode(3);  
	      
	    //Search for node 4 in the list  
	    searchNode(4);  
	    //Search for node 9 in the list  
	    searchNode(9);  
	   
	    return 0;  
	} 


