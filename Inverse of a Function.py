"""
The beauty of a sequence of non-negative integers is computed in the following way: for each of its non-empty (not necessarily contiguous) subsequences, compute the XOR of all elements of this subsequence; then, sum up all the XORs you obtained.

Let F(N,B)denotes the number of non-negative integer sequences with length N which have beauty B. You are given three integers N, X and M. Find the smallest non-negative integer B such that F(N,B)modM=X, or determine that there is no such B.
Since even the smallest such B might be very large, compute its remainder modulo 998,244,35.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers N, X and M.

Output
For each test case, print a single line containing one integer ― the smallest valid B(modulo 998,244,353), or −1 if there is no valid B.

Constraints
1≤T≤100
1≤N≤1010,000
1≤M≤10^9
0≤X<M
 
Input
3
2 2 7
4 3 17
3 5 13

Output
6
-1
28

input:
4
1 5 8
2 4 6
4 8 3
1 1 12

output:
-1
-1
-1
0

input:
2
1 2 1
1 1 2

output:
0
0

input:
1
12 24 48

output:
-1

input:
1
4 5 9

output:
-1

hint:
Let ppp be the number of distinct bits (powers of 2) which appear in at least one element of the sequence. If we fix the p bits
which appear in the sequence, there is only one possible beauty for the sequence, and there are (2N−1)^p such sequences (this value
mod  M should be X). The minimum beauty is 2^(N−1)⋅(2^p−1) and it occurs when we choose the first p bits (2^0,2^1,…,2^(p−1)).
Finding the minimum value of ppp is a discrete logarithm problem.
"""
from sys import stdin, stdout
import math
mod=998244353
def gcd(a,b):
    if b:
        return gcd(b,a%b)
    else:
        return a
def modified_baby_step_giant_step(a,b,p):
    a%=p
    b%=p
    if b==1:
        return 0
    count=0
    t=1
    g=gcd(a,p)
    while(g!=1):
        if b%g:
            return -1
        p=p//g
        b=b//g
        t=int(int(int(t*a)//g)%p)
        count+=1
        if b==t:
            return count
        g=gcd(a,p)
    hash={}
    base=b
    m=int(math.sqrt(1.0*p)+1)
    for i in range(m):
        hash[base]=i
        base = (base * a) % p
    base=pow(a,m,p)
    temp=t
    for i in range(1,m+2):
        temp = (temp * base) % p
        if temp in hash.keys():
            return (i * m) - hash[temp] + count
    return -1
t=int(stdin.readline())
for _ in range(t):
    n,x,m=map(int,stdin.readline().split())
    if 1%m==x:
        print(0)
        continue
    if x==0 and m==1:
        print(0)
        continue
    if x==0 and n!=1:
        print(1)
        continue
    var=((pow(2,n,m)-1+m))%m
    power=modified_baby_step_giant_step(var,x,m)
    if power==-1:
        print(-1)
        continue
    ans=(pow(2,n-1,mod)*((pow(2,power,mod)-1+mod))%mod)%mod
    if ans==0:
        if 1%m!=x:
            ans=-1
    if ans==1:
        if 1%m!=x or n!=-1:
            ans-=1
    stdout.write(str(ans)+"\n")
