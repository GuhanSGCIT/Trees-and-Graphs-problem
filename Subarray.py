"""
You are given an integer array( A ) of size N and an integer value K.Find the number of sub-arrays of A,
such that the difference between maximum value and minimum value in the sub array is less than or equal to K.

Sub-array is a contiguous portion of an array and two sub-arrays are different if their starting index or ending index is not same.

Input Description:
First line will contain two integers N and K, size of the array and the difference threshold.
Second line contains N space separated integers, representing the array elements.

Output Description:
Print a single integer, the number of sub-arrays satisfying the above mentioned condition.

Testcases:
Input:
3 2
7 6 14
Output:
4

EXPLANATION:
The sub-arrays which satisfy the condition are [7] difference = 0;[6] difference = 0;[14] difference = 0;[7,6] difference = 1

Input:
5 4
1 2 3 4 5
Output:
15

Input:
12 5
2 4 14 5 6 74 8 4 1 2 5 8
output:
22

Input:
3 1
1 2 3
Output:
5

Input:
6 4
6546516 35613546 5365465 354654 55 44498
output:
6

Solution:
"""
from sys import stdin,stdout
import math
def maxQ(l,r):
    size=int(math.log2(r-l+1))
    return max(sp1[l][size],sp1[r-(1<<size)+1][size])
def minQ(l,r):
    size=int(math.log2(r-l+1))
    return min(sp2[l][size],sp2[r-(1<<size)+1][size])

def build():
    for i in range(n):sp1[i][0]=sp2[i][0]=a[i]
    j=1
    while (1<<j<=n):
        i=0
        while i+(1<<j)-1<n:
            sp1[i][j]=max(sp1[i][j-1],sp1[i+(1<<(j-1))][j-1])
            sp2[i][j]=min(sp2[i][j-1],sp2[i+(1<<(j-1))][j-1])
            i+=1
        j+=1

for _ in range(1):
    n, k = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    sp1 = [[0 for _ in range(31)] for i in range(n)]
    sp2 = [[0 for _ in range(31)] for i in range(n)]
    build();ans=0
    for i in range(n):
        low=i;high=n-1;mx=0
        while low<=high:
            mid=(low+high)>>1
            if maxQ(i,mid)-minQ(i,mid)<=k:
                mx=max(mx,mid)
                low=mid+1
            else:high=mid-1
        ans+=(mx-i+1)
    stdout.write(str(ans)+'\n')
