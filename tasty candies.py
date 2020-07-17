"""
Question:
    There are two friends raja and shiva. They have a packet of n candies. They want to split the candies between them,
and to do so, they kept them all in a single line. The ith candy in the line has a sweetness value of 'a'.
They decided to take turns in picking the candies. Raja has the first turn. In a person's turn,they either eat
the leftmost candy or the rightmost candy with equal probability.

Can you find the expected value of sum of sweetness of the candies eaten by raja?

Input Description:
The first line will contain T, number of testcases. Then the testcases follow.
First line of each testcase contains a single integer n denoting the number of candies.
Second line of each testcase contains n space separated integers representing a1,a2,a3,...an respectively.

Output Description:
For each testcase, output the expected value of sum of sweetness of the candies which Raja eats.

Testcases:
Input:
2
2
1 2
3
1 2 3
Output:
1.5
4.0

EXPLANATION:
In the first sample, raja eats either the first or the second candy with equal probability. Hence, expected value is (1+2)/2=1.5
For the second sample, expected value is 4.

Input:
2
6
7 5 2 6 9 4
3
6 5 8
Output:
16.40625
13.0

Input:
1
12
1 2 3 4 5 6 7 8 9 10 11 12
output:
39.0

Input:
3
2
10 0
4
1 0 1 0
3
1 2 3
Output:
5.0
1.0
4.0

Solution:
"""
def recSolve(a, dp, l, r):
    if(l>r):
        return 0
    if dp[l][r] != 0.0:
        return dp[l][r]
    x = a[l]+ (recSolve(a, dp, l+2, r) + recSolve(a, dp, l+1, r-1))*0.5
    y = a[r]+ (recSolve(a, dp, l+1, r-1) + recSolve(a, dp, l, r-2))*0.5
    dp[l][r] = (x+y)*0.5
    return dp[l][r]
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    dp = [[0.0]*(n+1) for i in range(n+1)]
    res = recSolve(a, dp, 0, n-1)
    print(res)
