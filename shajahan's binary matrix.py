"""
shajahan's friend has given him a problem to solve but he is busy with his final exam. So he asked you to solve the problem.
The problem is that you have been given a N*N matrix A containing only 0 and 1. Your task is to AND every element of the matrix
with the elements of its corresponding row and column and output the resulting matrix.

timing:1.5sec
level:6

Input Description:
    First line of input contains an integer T, denoting the number of test cases.
    First line of each test case contains a integer N, the size of each side of the matrix.
    N lines follow. The ith(1 <= i <= N) of these lines contain N space-separated integers the jth(1 <= j <= N)
of which is the element A[i][j].

Output Description:
For each test case, print the final matrix after performing the required task.

Constraints
    1 ≤ T ≤ 100
    1 ≤ N ≤ 1000
    0 ≤ A[i][j] ≤ 1

Example Input
1
3
1 1 0 
1 1 1 
1 1 1
Example Output
0 0 0 
1 1 0 
1 1 0

Explanation:
self explanatory

hint:
if a an element is 0, then the result of ANDing the elements of its corresponding row or column will be 0 also
(Recall (0 AND something) = 0). So we can keep two arrays, one corresponding each column and one corresponding each row.
Initially we set all the elements of the array to false. Now, if we find a 0, then we will set the corresponding row of the 0
in the row array to true and do the same with the column array also. So, now when printing the matrix, if we see that the
corresponding row or column array index has a true value, then a 0 was present in the corresponding row or column,
thus making the result of the AND to 0.

Input:
1
4
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1

output:
1 0 0 1
0 0 0 0
0 0 0 0
1 0 0 1

Input:
1
3
0 0 0
1 1 0
1 1 0

output:
0 0 0
0 0 0
0 0 0

Input:
2
4
1 1 1 1
1 1 1 1
0 1 1 1
0 1 1 1
2
1 1
1 1

output:
0 1 1 1
0 1 1 1
0 0 0 0
0 0 0 0
1 1
1 1

Input:
1
5
1 1 1 1 1
0 1 0 1 0
1 1 1 1 1
0 1 0 1 0
1 1 1 1 1

output:
0 1 0 1 0
0 0 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 0 1 0

code:
"""
from math import *
from string import *
from itertools import *

T = int(input())
for _ in range(T):
	N = int(input())
	I = []
	J = []
	for i in range(N):
		l = list(map(int, input().split()))	
		for j in range(N):
			if(l[j] == 0):
				I.append(i)
				J.append(j)
	J = list(set(J))
	I = list(set(I))
	a = []
	for i in range(N):
		if(i in I):
			a = [0]*N
		else:
			a = [1]*N
			for j in range(len(J)):
				a[J[j]] = 0
		print(*a)
