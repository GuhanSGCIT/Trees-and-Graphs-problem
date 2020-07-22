"""
Question:
Every time Rami comes up with an idea for a nice problem, his class advisor sundhar rejects it, claiming that it takes a lot of work
to write tests for such a problem. Therefore, Rami spent days thinking about a problem with only three numbers as the input.
Finally, he thought up such a problem and ran happily to his advisor,

shouting:
You are given three integers N, M and K. Find the number of sequences A1,A2,…,AN
such that:
1.)For each valid i, Ai is an integer in the range [0,M−1].
2.)Let's define N prefix sums of A as Si=∑ij=1Aj, where 1≤i≤N. At least K of these prefix sums are divisible by M.

Let's see if you can solve this simple problem! Rami knows that the answer could be really large, so you should compute
it modulo 10^9 + 7.

Input Description: 
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers N, M and K.

Output Description:
For each test case, print a single line containing one integer — the number of valid sequences modulo 10^9 + 7.

Testcases:
Input:
2
3 2 2
3 2 1

Output:
4
7

Explanation:
For N=3
and M=2, there are eight possible sequences satisfying the first condition:
[0,0,0], [0,0,1], [0,1,0], [0,1,1], [1,0,0], [1,0,1], [1,1,0] and [1,1,1].
Their prefix sums are [0,0,0], [0,0,1], [0,1,1], [0,1,2], [1,1,1], [1,1,2], [1,2,2] and [1,2,3] respectively.

Input:
1
1 2 3
Output:
0

Input:
3
4 5 1
7 8 7
1 0 1
Output:
369
1
1

Input:
2
1 5 8
1 9 1
Output:
0
1

Input:
4
1 0 1
0 1 0
110 122 5
9 9 9
Output:
1
1
863631801
1

Solution:
"""
t=int(input())
for you in range(t):
    l=input().split()
    n=int(l[0])
    m=int(l[1])
    k=int(l[2])
    dp=[0 for i in range(n+1)]
    dp[0]=1
    for i in range(1,n+1):
        dp[i]=(dp[i-1]*(n-i+1))*pow(i,1000000005,1000000007)
        dp[i]%=1000000007
    sumi=0
    for i in range(k,n+1):
        sumi=sumi+(dp[i]*pow(m-1,n-i,1000000007))
        sumi%=1000000007
    print(sumi)

