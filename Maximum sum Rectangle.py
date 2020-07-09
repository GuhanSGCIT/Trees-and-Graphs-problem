"""
Solution:-
   Our mathematics staff gives us a puzzle to find the sun matrix ,which gives maximum sum of the elements in it.
You are in that game,find the solution from the given 2D array.

Tag:
Matrix,Array,

Input Discription:-
First line of every test case consists of T test case.
First line of every test case consists of 2 integers R and C ,
denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output Discription:-
Single line output, print the Max sum forming a rectangle in a 2-D matrix


Testcases:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29

Input:
2
2 2
1 2 1 2
3 3
4 5 6 1 2 3 7 8 9
Output:
6
45

Input:
1
1 1
2
Output:
2

"""
import numpy as np
def kadane(arr, start, finish, n): 
    Sum = 0
    maxSum = -999999999999
    i = None
    finish[0] = -1
    local_start = 0
    for i in range(n): 
        Sum += arr[i]  
        if Sum < 0: 
            Sum = 0
            local_start = i + 1
        elif Sum > maxSum: 
            maxSum = Sum
            start[0] = local_start  
            finish[0] = i 
    if finish[0] != -1:  
        return maxSum  
    maxSum = arr[0]  
    start[0] = finish[0] = 0
    for i in range(1, n): 
        if arr[i] > maxSum: 
            maxSum = arr[i]  
            start[0] = finish[0] = i 
    return maxSum 
def findMaxSum(M): 
    global ROW, COL 
    maxSum, finalLeft = -999999999999, None
    finalRight, finalTop, finalBottom = None, None, None
    left, right, i = None, None, None
    temp = [None] * ROW 
    Sum = 0
    start = [0] 
    finish = [0]  
    for left in range(COL): 
        temp = [0] * ROW  
        for right in range(left, COL): 
            for i in range(ROW): 
                temp[i] += M[i][right]  
            Sum = kadane(temp, start, finish, ROW)  
            if Sum > maxSum: 
                maxSum = Sum
                finalLeft = left  
                finalRight = right  
                finalTop = start[0]  
                finalBottom = finish[0] 
    print(maxSum) 
  
# Driver Code 
for i in range(int(input())):
    ROW ,COL=map(int,input().split())
    G=[int(v) for v in input().split()]
    M = np.array(G).reshape(ROW ,COL)
        
    findMaxSum(M) 
