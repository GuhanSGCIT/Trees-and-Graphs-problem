"""
Vijay and Ajith like to play games. Aijth gives Vijay 2 numbers N and M and allowes him to perform following operations
on the numbers-
    Subtract 1 from any one of the numbers.
    Divide both the numbers by their gcd.

Now, Vijay wants to know the minimum number of operations to convert (N,M) to (1,1).

timing:1.5sec
level:6

Input
First line contains T - Number of test cases.
Next T lines contain 2 integers N, M

Output
Minimum operations to convert both N and M to 1.

Constraints
    1≤T≤10^4
    1≤N,M≤500

Sample Input
1
8 4

Sample Output
2

Explaination
-Operation 2: N=2 M=1
-Operation 1(on N): N=1 M=1

input:
2
4 8
9 5

output:
2
4

input:
3
1 2
8 4
9 6

output:
1
2
3

input:
4
2 1
2 2
54 89
43 16

output:
1
1
8
6

input:
1
41 30

output:
4

hint:
For every pair of N and M there are atmost 3 ways to proceed. Decrease N, or decrease M or
N/=GCD(M,N) and M/=GCD(M,N).
"""
from math import gcd
def abc(n,m):
    global d
    if n==1 and m==1:
        return 0;
    if n==1:
        return m-1;
    if m==1:
        return n-1;
    try:
        return d[(n,m)]
    except:
        pass
    x=gcd(n,m)
    if x==1:
        d[(n,m)] = 1 + min(abc(n-1,m),abc(n,m-1))
        return d[(n,m)]
        
    d[(n,m)] = 1+min(min(abc(n-1,m),abc(n,m-1)),abc(n//x,m//x))
    return d[(n,m)]

l=[]
d={}
for i in range(1,501):
    k=[]
    for j in range(1,501):
        k.append(abc(i,j))
    l.append(k)

t=int(input())
        
for _ in range(t):
    n,m=map(int,input().split())
    print(l[n-1][m-1])
        
