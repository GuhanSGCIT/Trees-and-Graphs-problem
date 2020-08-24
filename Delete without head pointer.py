"""
You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you.

input:
The first line contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.
The third line Contains a single integer node.

output:
Print the list after remaining nodes.

input:
2
1 2
1

output:
2

Explanation:
After deleting 1 from the linked list, we have remaining nodes as 2.

input:
4
10 20 4 30
20

output:
10 4 30

input:
5
1 0 55 54 10
0

output:
1 55 54 10

input:
5
12 12 10 11 13
12

output:
12 10 11 13

input:
4
1 0 1 1
1

output:
0 1 1
hint:
Traverse the linked list until you find the node you want to delete. But this solution requires pointer to the head node which contradicts the problem statement.

"""
class Node(): 
    def __init__(self, val=None): 
        self.data = val 
        self.next = None
def push(head, val): 
    newnode = Node(val) 
    newnode.next = head.next
    head.next = newnode 
def print_list(head): 
  
    temp = head.next
    while(temp != None): 
        print(temp.data, end = ' ') 
        temp = temp.next
    print() 
  
def delete_node(node): 
  
    prev = Node() 
  
    if(node == None): 
        return
    else: 
        while(node.next != None): 
            node.data = node.next.data 
            prev = node 
            node = node.next
  
        prev.next = None
  
  
if __name__ == '__main__': 
    
    n=int(input())
    lst=[int(v) for v in input().split()]
    l=int(input())
    head = Node(l)
    for i in lst:
        push(head,i)
    delete_node(head.next)
    print_list(head)
