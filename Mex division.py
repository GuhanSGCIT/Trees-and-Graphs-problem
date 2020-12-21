"""
Given an array A of n non-negative integers. Find the number of ways to partition/divide the array into subarrays, such that mex in each subarray is not more than k. For example, mex of the arrays [1, 2] will be 0, and that of [0, 2] will be 1, and that of [0, 1, 2] will be 3. Due to the fact that the answer can turn out to be quite large, calculate it modulo 109 + 7.

Input
The first line of the input contains two integers n, k denoting the number of elements and limit of mex.
The second line contains n space-separated integers A1, A2, ... , An .

Output
Output a single integer corresponding to the answer of the problem.

Constraints
1 ≤ n ≤ 5 * 10^5
0 ≤ k, A[i] ≤ 10^9

Example

Input:
3 1
0 1 2

Output:
2


Explanation
The valid ways of partitioning will be [[0], [1, 2]] (mex of first subarray is 1, while that of the second is zero), and [[0], [1], [2]] (mex of first subarray is 1, and that of others is 0). There is no other way to partition the array such that mex is less than or equal to 1. For example, [[0, 1], [2]] is not a valid partitioning as mex of first subarray is 2 which is more than 1.

Input:
10 3
0 1 2 3 4 0 1 2 5 3

Output:
379

input:
7 3
4 8 5 2 6 3 0

output:
64

input:
3 1
1 1 0

output:
2

input:
11 2
1 5 8 9 6 3 2 11 8 9 1

output:
1024

"""
n,k=[int(i) for i in input().split()]
l=[int(i) for i in input().split()]
cons=int(5e5+1)
mod=10**9+7
tpa=[1 for i in range(cons)]
tpa[0]=1
for i in range(1,cons):
    tpa[i]=(tpa[i-1]*2)%mod
if k>n:
    print(tpa[n-1])
else:
    il=[[]for i in range(k+1)]
    for i in range(n):
        if l[i]<=k:
            il[l[i]].append(i)
    for i in range(k+1):
        if len(il[i])==0:
            print(tpa[n-1])
            break
    else:
        pi=-1
        dp=[-1 for i in range(n)]
        dp[0]=1
        si=max(il,key=lambda x:x[0])[0]
        s=1
        for i in range(1,si):
            dp[i]=tpa[i]
            s=(s+dp[i])%mod
        ci=[0 for i in range(k+1)]
        j=si
        i=0
        while j<n:
            if l[i]>k :
                s=(s-dp[i])%mod
                i+=1
            elif ci[l[i]]+1<len(il[l[i]]) and il[l[i]][ci[l[i]]+1]<=j:
                s=(s-dp[i])%mod
                ci[l[i]]+=1
                i+=1
            else:
                dp[j]=s
                pi=i
                s=(s+dp[j])%mod
                j+=1
        print(dp[n-1])