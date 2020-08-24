/*
Given a singly linked list of N nodes. The task is to find the middle of the linked list.
For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element.
For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

input:
The line contains linked list of integers A1,A2,….

output:
Print the middle of the linked list.

input:
1 2 3 4 5

output:
3

input:
2 4 6 7 5 1

output:
7

input:
25 22 55 32 65 56 250

output:
32

input:
4 5 8 8 6 8 1 4

output:
6

input:
6 5 4 1 1 2 1

output:
1

hint:
Traverse the whole linked list and count the no. of nodes. Now traverse the list again till count/2 and return the node at count/2.
*/

#include<stdio.h>  
#include<stdlib.h>  
  
/* Link list node */
struct Node  
{  
    int data;  
    struct Node* next;  
};  
  
/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)  
{  
    struct Node *slow_ptr = head;  
    struct Node *fast_ptr = head;  
  
    if (head!=NULL)  
    {  
        while (fast_ptr != NULL && fast_ptr->next != NULL)  
        {  
            fast_ptr = fast_ptr->next->next;  
            slow_ptr = slow_ptr->next;  
        }  
        printf([%d]\n\n", slow_ptr->data);  
    }  
}  
  
void push(struct Node** head_ref, int new_data)  
{  
    /* allocate node */
    struct Node* new_node =  
        (struct Node*) malloc(sizeof(struct Node));  
  
    /* put in the data */
    new_node->data = new_data;  
  
    /* link the old list off the new node */
    new_node->next = (*head_ref);  
  
    /* move the head to point to the new node */
    (*head_ref) = new_node;  
}  
  
// A utility function to print a given linked list  
void printList(struct Node *ptr)  
{  
    while (ptr != NULL)  
    {  
        printf("%d->", ptr->data);  
        ptr = ptr->next;  
    }  
    printf("NULL\n");  
}  
  
/* Driver program to test above function*/
int main()  
{  
    /* Start with the empty list */
    struct Node* head = NULL;  
    int i;  
  
    for (i=5; i>0; i--)  
    {  
        push(&head, i);  
        printList(head);  
        printMiddle(head);  
    }  
  
    return 0;  
}  
