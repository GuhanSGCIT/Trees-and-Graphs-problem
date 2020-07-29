"""
Given an array of n integers : A1,A2,...,An, find the longest size subsequence which satisfies the following property:
The xor of adjacent integers in the subsequence must be non-decreasing.

Timing:1sec
level:5

Input Description:
First line contains an integer n, denoting the length of the array.
Second line will contain n space separated integers, denoting the elements of the array.

Output Description:
Output a single integer denoting the longest size of subsequence with the given property.

Constraints
    1≤n≤103
    0≤Ai≤1018

Input:
8
1 200 3 0 400 4 1 7

Output:
6

EXPLANATION:
The subsequence of maximum length is {1, 3, 0, 4, 1, 7} with Xor of adjacent indexes as {2,3,4,5,6} (non-decreasing)

Input:
4
1 20 4 45
Output:

Input:
7
45 1 87 2 54 2 1
Output:

Input:
9
1 22 4 0 45 2 0 2 3 7
Output:

Input:
3
1 10 2
Output:

Solution:
"""
n=int(input())
l=list(map(int,input().split()))
a=[]
for i in range(0,n):
	for j in range(i+1,n):
		a.append((l[i]^l[j],(i,j)))

a.sort()
dp=[0]*n
for i in range(0,len(a)):
	x=a[i][0]
	left,right=a[i][1][0],a[i][1][1]
	dp[right]=max(dp[left]+1,dp[right])

print(max(dp)+1)
