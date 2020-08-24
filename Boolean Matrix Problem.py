"""
Given a boolean matrix mat[M][N] of size M X N, modify it such that if a matrix cell mat[i][j] is 1 (or true) then make
all the cells of ith row and jth column as 1.

timing:1sec
level:7

Input:
The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is r and c, r is the number of rows and c is the number of columns.
The second line of each test case contains all the elements of the matrix in a single line separated by a single space.

Output:
Print the modified array.

Constraints:
1 ≤ T ≤ 100
1 ≤ r, c ≤ 1000
0 ≤ A[i][j] ≤ 1

Input:
3
2 2
1 0
0 0
2 3
0 0 0 
0 0 1
4 3
1 0 0
1 0 0
1 0 0
0 0 0

Output:
1 1
1 0
0 0 1 
1 1 1
1 1 1
1 1 1
1 0 0

Explanation:
Since only first element of matrix has 1 (at index 1,1) as value, so first row and first column are modified to 1.

input:
2
3 3
1 0 1
0 1 0
1 0 1
4 5
0 0 1 1 1
1 1 0 1 0
0 0 1 0 0
1 1 0 1 1

output:
1 1 1 
1 1 1 
1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1

input:
1
5 5
1 0 1 0 0
1 1 1 1 1
0 0 0 0 1
1 0 1 1 1
0 1 1 1 0

output:
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1

input:
2
2 2
1 0
0 1
3 3
0 0 1
0 1 0
1 0 0

output:
1 1 
1 1 
1 1 1 
1 1 1 
1 1 1

input:
1
6 6
1 1 1 0 0 0
0 1 0 1 0 1
0 0 0 1 1 1
1 1 0 0 1 1
0 1 0 1 0 1
1 1 0 1 0 1

output:
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1 
1 1 1 1 1 1

hint:
Create two temporary arrays row[M] and col[N]. Initialize all values of row[] and col[] as 0.
Traverse the input matrix mat[M][N]. If you see an entry mat[i][j] as true, then mark row[i] and col[j] as true.
Traverse the input matrix mat[M][N] again. For each entry mat[i][j], check the values of row[i] and col[j].
If any of the two values (row[i] or col[j]) is true, then mark mat[i][j] as true.

"""

def modifyMatrix(mat): 
    row = [0] * R  
    col = [0] * C  
    for i in range(0, R): 
        row[i] = 0
    for i in range(0, C) : 
        col[i] = 0
    for i in range(0, R) : 
          
        for j in range(0, C) : 
            if (mat[i][j] == 1) : 
                row[i] = 1
                col[j] = 1
    for i in range(0, R) : 
          
        for j in range(0, C): 
            if ( row[i] == 1 or col[j] == 1 ) : 
                mat[i][j] = 1
                  
# A utility function to print a 2D matrix  
def printMatrix(mat) : 
    for i in range(0, R): 
          
        for j in range(0, C) : 
            print(mat[i][j], end = " ") 
        print() 
          
for i in range(int(input())):
    R,C=map(int,input().split())
    mat=[]
    for j in range(R):
        mat.append([int(v) for v in input().split()])
    
    modifyMatrix(mat) 
    printMatrix(mat) 
