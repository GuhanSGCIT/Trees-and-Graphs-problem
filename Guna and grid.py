"""
Recently, Guna got a grid with n rows and m columns. Rows are indexed from 1 to n and columns are indexed from 1 to m.
The cell (i,j) is the cell of intersection of row i and column j. Each cell has a number written on it. The number written
on cell (i,j) is equal to (i+j). Now, Guna wants to select some cells from the grid, such that for every pair of selected cells ,
the numbers on the cells are co-prime. Determine the maximum number of cells that Guna can select.

Timing:1sec
level:4

Input Description:
Single line containing integers n and m denoting number of rows and number of columns respectively.

Output description:
Single line containing the answer.

Constraints
    1≤n,m≤106

Input:
3 4
Output:
4

input:
45 65
Output:
29

input:
8 9
Output:
7

input:
5 6
Output:
5

input:
0 1
Output:
0

solution:
"""
def Sieve(n): 
    prime = [1 for i in range(n+1)]
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * 2, n+1, p): 
                prime[i] = 0
        p += 1
    return prime
try:
    n,m=list(map(int,input().split()))
    x=Sieve(n+m)
    print(sum(x)-2)
except:
    pass
