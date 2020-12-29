"""
Given an M x N matrix .In the given matrix, you have to print the elements of the matrix in the snake pattern.

i des
First line contains two space separated integers M,N,which denotes the dimensions of matrix.
Next for each M lines contains N space separated integers,denotes the values. 

Odes
print the snake

Exp
From sample
the first row is printed as same and the second row is appended reversed with the first.
1 2 3 7 6 5

Hin
We traverse all rows. For every row, we check if it is even or odd. If even, we print from left to
right else print from right to left.

In
3 3
1 2 3
4 5 6
7 8 9

Ot
1 2 3 6 5 4 7 8 9

In
2 3
1 2 3 
5 6 7

ot
1 2 3 7 6 5

In
1 1
1

ot
1

In
3 2
1 1
1 1
1 1

ot
1 1 1 1 1 1
In
5 3
1 2 3 
4 5 6
7 8 9
1 2 3
4 5 6

ot
1 2 3 6 5 4 7 8 9 3 2 1 4 5 6 
T
600

""" 
M,N=map(int,input().split())

def printf(mat): 
	global M, N 
	for i in range(M): 
		

		if i % 2 == 0: 
			for j in range(N): 
				print(str(mat[i][j]), 
						end = " ") 

		else: 
			for j in range(N - 1, -1, -1): 
				print(str(mat[i][j]), 
						end = " ") 

mat=[]
for i in range(M):
    l=list(map(int,input().split()))
    mat.append(l)

printf(mat) 
