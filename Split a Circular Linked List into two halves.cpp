/*
Given a Cirular Linked List split it into two halves circular lists. If there are odd number of nodes in the given circular
linked list then out of the resulting two halved lists, first list should have one node more than the second list. The resultant
lists should also be circular lists and not linear lists.

Input:
You have to complete the method which takes 3 argument: The address of the head of the linked list , addresses of the head
of the first and second halved resultant lists.. You should not read any input from stdin/console.
There are multiple test cases. For each test case, this method will be called individually.

Output:
Set the *head1_ref and *head2_ref to first resultant list and second resultant list respectively.

Constraints:
1<=T<=100
2<=N<=100

Example:
Input:
2
3
1 5 7
4
2 6 1 5

Output:
1 5
7
2 6
1 5

Explanation:
Testcase 2: Distributing the given circular linked list into two halves makes two linked list as 2, 6 and 1, 5.

input:
3
4
1 2 3 4
5
5 4 3 2 1
2
1 1

output:
1 2 
3 4 
5 4 3 
2 1 
1 
1

input:
1
8
5 4 7 1 2 3 6 8

output:
5 4 7 1 
2 3 6 8

input:
1
7
4 5 1 2 3 6 7

output:
4 5 1 2 
3 6 7

input:
2
3
1 2 3
5
4 8 5 2 1

output:
1 2 
3 
4 8 5 
2 1

hint:
Store the mid and last pointers of the circular linked list using tortoise and hare algorithm.Make the second half circular.
Make the first half circular.Set head (or start) pointers of the two linked lists.

*/
void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
// your code goes here
Node *s = head;
Node *f = head;
while(f -> next != head && f -> next -> next != head){
s = s -> next;
f = f -> next -> next;
}
if(f -> next == head){
f -> next = s -> next;
*head2_ref = f -> next;
}
if(f -> next -> next == head){
f = f -> next;
f -> next = s -> next;
*head2_ref = f -> next;
}
s -> next = head;
*head1_ref = head;
