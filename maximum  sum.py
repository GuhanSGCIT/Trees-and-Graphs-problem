"""
Given an array of size N and two integers K and S, the special sum of a subarray is defined as follows:
(Sum of all elements of the subarray) * (K - p * S)
Where p = number of distinct prime factors of “product of all elements of the subarray”.
Find the maximum sum by considering all non-empty subarrays of the given array.

level:6
Timing:0.83 -3sec

Input Description:
First line contains 3 integers N, K and S.
Second line contains N integers, the elements of the array.

Output Description:
Output a single integer. The maximum sum considering all non-empty subarrays of the array.

Constraints:
1≤N,K,S≤10^5
0≤K/S≤20
1<Any element of array <10^5

Input:
4 10 2
14 2 7 15

Output
138

Explanation:
Consider the subarray {14, 2, 7}
Total number of distinct prime factors in it is 2 (2 and 7).
Therefore, value of special sum is (14 + 2 + 7) * (10 - 2 * 2) = 138.
This is the subarray with the maximum sum.

Input:
8 5 2
1 2 3 4 5 6 7 8

output:
21

Input:
3 4 2
9 4 3

output:
18

Input:
12 6 4
8 4 6 12 59 4 6 1 2 3 4 5

output:
118

Input:
1 0 1
5

output:
-5

Solution:
"""
from math import floor, sqrt
try: 
    long
except NameError: 
    long = int
 
def fac(n):
    step = lambda x: 1 + (x<<2) - ((x>>1)<<1)
    maxq = long(floor(sqrt(n)))
    d = 1
    q = n % 2 == 0 and 2 or 3 
    while q <= maxq and n % q != 0:
        q = step(d)
        d += 1
    return q <= maxq and [q] + fac(n//q) or [n]
n,k,s=map(int,input().split())
a=list(map(int,input().split()))
di={}
l=[]
m=0
ans=0
su=0
for i in a:
    su+=i
    bb=list(set(fac(i)))
    for j in bb:
        try:
            di[j]+=1
        except KeyError:
            m+=1
            di[j]=1
    zz=su*(k-m*s)
    l.append(zz)
    if zz<0:
        m=0
        di={}
        su=0
print(max(l))
