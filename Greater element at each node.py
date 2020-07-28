"""
Solution:-
  In the internals exam,some students wrote two answers at different pages for single question,but the answers are different,
the evaluvater need to consider the greatest mark for that question, this is the rule.Evaluvater has no time to get it.You need to
help the staff to identify the highest mark,and enter the marks in new form.

  Given two linked list of the same size, the task is to create a new linked list using those linked lists.Consider question as index
values.

Input Discription:-
Two linked list are given in separate lines having same size.

Output Discription:-
Print the greater node among both linked list as discripted

Testcases:
Input:
4 6 2 8
9 5 6 5
Output:
New List:9 6 6 8

Input:
1 2 8 4 5
0 2 4 4 5
Output:
New List:1 2 8 4 5

Input:
0 0 1 2 5
2 1 3 4 5
Output:
New List:2 1 3 4 5

Input:
0 0 0 1 2
1 0 0 0 3
Output:
New List:1 0 0 1 3
  
Solution:-
"""
class Node:  
    def __init__(self, data):  
        self.data = data  
        self.next = None
def insert(root, item): 
    temp = Node(0) 
    temp.data = item 
    temp.next = None
    if (root == None): 
        root = temp 
    else : 
        ptr = root 
        while (ptr.next != None):
            ptr = ptr.next
        ptr.next = temp 
    return root 
def newList(root1, root2): 
    ptr1 = root1 
    ptr2 = root2 
    root = None
    while (ptr1 != None) : 
        temp = Node(0) 
        temp.next = None
        if (ptr1.data < ptr2.data): 
            temp.data = ptr2.data 
        else: 
            temp.data = ptr1.data 
  
        if (root == None): 
            root = temp 
        else : 
            ptr = root 
            while (ptr.next != None): 
                ptr = ptr.next
  
            ptr.next = temp 
          
        ptr1 = ptr1.next
        ptr2 = ptr2.next
      
    return root 
  
def display(root): 
  
    while (root != None) : 
        print(root.data, end = " ") 
        root = root.next
      
    print(" "); 
  
# Driver Code  
if __name__=='__main__':  
  
    root1 = None
    root2 = None
    root = None
  
    # First linked list
    l=[int(v) for v in input().split()]
    l1=[int(b) for b in input().split()]
    for i in l:
        root1 = insert(root1, i) 
      
  
    # Second linked list
    for h in l1:
        root2 = insert(root2, h) 
  
    root = newList(root1, root2) 
    print("New List:", end = "") 
    display(root) 
  
