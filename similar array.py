"""
You are given two arrays(A and B) each of size N.

In one step you can choose any two index l and r such that 1≤l≤r≤N and increment B[i] by 1 for l≤i≤r.
Find the minimum number of steps required to make both are similar.

timing:1
level:5

Input Description:
First line will contain N, size of each array.
Second line contains N space separated integers, ith number denotes the value of A[i].
Third line contains N space separated integers, ith number denotes the value of B[i].

Output Description:
Print the minimum number of steps required to make both arrays similar.

Constraints
1≤N≤100000
0≤B[i]≤A[i]≤10^9

Sample Input:
5
1 2 3 4 5
1 1 1 4 1

Sample Output:
6

EXPLANATION:
We can select the following ranges : [2,3] once, [3,3] once and [5,5] four times.

Input:
2
1 8
1 7

output:
1

Input:
4
1 1 2 2
1 1 2 2

output:
0

Input:
5
1 2 5 4 3
1 2 3 4 5

output:
2

Input:
9
1 5 9 6 3 2 1 1 7
1 1 2 5 9 6 5 9 6
output:
18

Solution:

"""
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
s=[]
for i in range(0,n):
    s.append(a[i]-b[i])
steps=s[0]
for i in range(1,n):
    if(s[i]<=s[i-1]):
        continue
    else:
        steps+=s[i]-s[i-1]
print(steps)
