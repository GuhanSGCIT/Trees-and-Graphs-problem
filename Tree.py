"""
Question
Construct the level order tree from the list and find the left most node
of kth node.If k is the last node then print that node itself.

Input description
First line has list of numbers and second line has k

Output description
left most node

Explanation
1 2 3 4 5
                            1
                            /\
                           2  3
                          / \
                         4   5
if k=1
ouput=4
if k=2
output=4
if k=5
output=5 

Input
1 2 3 4 5
1

Output
4

Input
1 2 3
3

Output
3

Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14
3

Output
12

Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14 
2

Output
8

Input
1 2 3 4 5 6 7 8 9 10 11 12 13 14
5

Output
10

Hint:
Find the left most node from the kth node

solution:"""
class newNode: 
	def __init__(self, data): 
		self.data = data 
		self.left = self.right = None 
def insertLevelOrder(arr, root, i, n): 
	if i < n: 
		temp = newNode(arr[i]) 
		root = temp 
		root.left = insertLevelOrder(arr, root.left, 2 * i + 1, n) 
		root.right = insertLevelOrder(arr, root.right, 2 * i + 2, n) 
	return root 


def inOrder(root,k): 
    current = root  
    stack = []
    st=[]
    done = 0
    c=0
    
    while True:
        if current is not None:  
            stack.append(current)
            current = current.left  
        elif(stack): 
            current = stack.pop()
            ans.append(current.data)
            if current.data==k:
                    while True:
                            if current is not None:
                                    st.append(current)
                                    current = current.left
                            elif(st):
                                    current = st.pop()
                                    res.append(current.data)
                                    c+=1
                                    current = current.right
                                    if res[-1]==k:
                                            return
                                    else:
                                            return
                                    
                    
                    
            current = current.right  
  
        else: 
            break
   
    

arr = input().split()
k=input()
n = len(ar
r)
ans=[]
res=[]
root = None
root = insertLevelOrder(arr, root, 0, n)
inOrder(root,k)
if(len(res)==0):
        print()
print(*res)
