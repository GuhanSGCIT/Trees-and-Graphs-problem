"""
Question:-
    Perm is learning linear algebra. Recently, he learnt that for a square matrix M, trace(M) is defined as the sum of all
elements on the main diagonal of M(an element lies on the main diagonal if its row index and column index are equal).

    Now, Perm wants to solve some excercises related to this new quantity, so he wrote down a square matrix A
with size N×N. A square submatrix of A with size l×l is a contiguous block of l×l elements of A. Formally, if B is a
submatrix of A with size l×l, then there must be integers r and c (1 ≤ r,c ≤ N+1−l) such that Bi,j = Ar+i−1,c+j−1 for each 1≤i,j≤l.

Help Perm find the maximum trace of a square submatrix of A.

Input Discription:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains N space-separated integers Ai,1,Ai,2,…,Ai,N denoting
the i-th row of the matrix A.

Output Discription:
For each test case, print a single line containing one integer — the maximum possible trace.

Example Input:
1
3
1 2 5
6 3 4
2 7 1
Example Output
13

Explanation:-
Example case 1: The submatrix with the largest trace is
6 3
2 7
which has trace equal to 6+7=13. (This submatrix is obtained for r=2,c=1,l=2.)

Testcases:
Input:
1
3
1 2 5
6 3 4
2 7 1
Ouput:
13

Input:
2
2
2 2
1 1
1
5
Output:
3
5

Input:
1
2
0 1
1 0
Output:
1

Input:
2
3
1 2 3
8 5 6
7 4 0
4
1 2 3 5
2 5 8 4
9 6 3 2
4 5 6 9
Output:
12
18

Solution:-
"""
from operator import add

for _ in range(int(input())):
    n = int(input())
    m = []
    for i in range(n):
        row = list(map(int, input().split()))
        m.append(row)
    trace = m[-1]
    for i in range(n-2, -1, -1):
        prev = [0]*(n-i-1) + m[i]
        trace.append(0)
        trace = list(map(add, trace, prev))
    print(max(trace))
