"""
Given a sorted array. Write a program that creates a Balanced Binary Search Tree using array elements. If there are N elements in
array, then floor(n/2)'th element should be chosen as root and same should be followed recursively.

Input:
The first line of input contains an integer T, denoting the number of test cases.
The first line of each test case is N(size of array). The second line of each test case contains N input A[].

Output:
Print the preorder traversal of constructed BST.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
1 ≤ A[i] ≤ 10000

Input:
1
7
1 2 3 4 5 6 7

Output:
4 2 1 3 6 5 7

input:
2
7
4 5 6 7 8 9 10
9
9 8 7 6 5 4 3 2 1

output:
7 5 4 6 9 8 10
5 7 8 9 6 2 3 4 1

input:
1
13
4 5 6 1 2 5 8 4 45 21 32 44 88

output:
8 1 5 4 6 5 2 32 45 4 21 88 44

input:
2
6
4 5 2 1 3 6
4
1 5 9 6

output:
1 5 4 2 6 3
9 5 1 6

input:
3
3
5 4 2
5
4 8 7 5 6
2
2 1

output:
4 5 2
7 8 4 6 5
1 2

hint:
Get the Middle of the array and make it root.Recursively do same for left half and right half.
a) Get the middle of left half and make it left child of the root created in step 1.
b) Get the middle of right half and make it right child of the root created in step 1.
"""
class Node: 
    def __init__(self, d): 
        self.data = d 
        self.left = None
        self.right = None
def sortedArrayToBST(arr): 
      
    if not arr: 
        return None
    mid = int((len(arr)) / 2)
    root = Node(arr[mid]) 
    root.left = sortedArrayToBST(arr[:mid]) 
    root.right = sortedArrayToBST(arr[mid+1:]) 
    return root 
def preOrder(node): 
    if not node:
        return
      
    print(node.data,end=" ") 
    preOrder(node.left) 
    preOrder(node.right)  
  
for i in range(int(input())):
    n=int(input())
    arr = [int(v) for v in input().split()] 
    root = sortedArrayToBST(arr) 
    print(preOrder(root)) 
