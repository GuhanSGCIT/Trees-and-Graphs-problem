"""
Question:-
    kosaksi pasapugazh is learning Combinatorics in his college. He find it very interesting to calculate number of ways of going
to point (c,d) from point (a,b) in co-ordinate plane. We can take horizontal and vertical steps only and can not visit at a point
twice.In a step, you can move one unit only. We have to reach to the point (c,d) from the point (a,b) using abs(a-c)+ abs(b-d)
steps only.

    kosaksi pasapugazh has two sets of points. Set A contains points having X co-ordinate 0 and Y co-ordinates varying
from 1 to N(both inclusive).Set B contains points having X co-ordinate K and Y co-ordinates varying from 1 to N(both inclusive).
Both sets contains N number of integral points. He wants to calculate the sum of number of ways to going to the each point
of set B from the each point of set A .

As the answer can be large, print it modulo 1000000007.

Input Discription:
First line of input contains an integer T denoting number of test cases.
Next T lines will contain pair of integers N and K.

Output Discription:
For each test case, print a single integer representing the answer of that test case.

Sample Input:
2
2 2
4 5

Sample Output:
8
236

Explanation:-
For the first sample case,
ways[(0,1)->(2,1)]= 1
ways[(0,2)->(2,2)]= 1
ways[(0,1)->(2,2)]= 3
ways[(0,2)->(2,1)]= 3
So, the total number of ways = 8. 

Testcases:
Input:
2
2 2
4 5
Output:
8
236

Input:
1
5 5
Output:
655

Input:
3
1 1
2 2
3 3
Output:
1
8
39

Input:
1
0 0
Output:
784160317

Solution:-
"""
t = int(input())

q = [1] 
for i in range(1, 2000002):
    q.append(q[-1] * i % (10 ** 9 + 7))
inv = lambda x : pow(q[x],10 ** 9 + 5,10 ** 9 + 7)
for i in range(t):
    n, k = map(int,input().split())
    print ((2 * q[k + n + 1] * inv(k + 2) * inv(n - 1) - n) % (10 ** 9 + 7))
