"""
Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.

input:
The first line contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
The third line Contains a single integer X.

output:
Print the output in string as True or False.

input:
3
1 3 4
2

output:
True

Explanation:
In above test case N = 3. The linked list with nodes N = 3 is given. Then value of x=2 is given which means last node is connected with xth node of linked list. Therefore, there exists a loop.

input:
4
1 8 3 4
0

output:
False

input:
5
12 24 102 21 2
6

output:
False

input:
3
1 2 3
2

output:
True

input:
6
5 4 1 2 3
2

output:
True

hint:
Using hare turtle theorem, create two pointers: hare and turtle.point both of them to head at first.
Now, turtle moves by one position and hare moves by two position.If these two pointers meet at some time then loop exists. If we reach null without any meeting then no loop exists.
"""
def detectLoop(head):
    #hare turtle theorem
    hare = head
    turtle = head

    while hare and turtle and turtle.next:
        hare=hare.next
        turtle=turtle.next.next
        
        if hare == turtle :
            return True
    
    return False
