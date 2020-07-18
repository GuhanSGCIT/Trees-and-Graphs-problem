"""
    Today is valentines day and ram and kavitha are visiting a Valentines day special. Upon arriving, they find a
stall with an interesting game.There are N jars having some chocolates in them. To win the game,
one has to select the maximum number of consecutive jars such that the sum of count of chocolates
in maximum and second maximum jar is less than or equal to k in that range.

    Ram wants to win the game so that he can gift the chocolates to kavitha. You are a friend of ram,
help him win the game. There will be at least one possible answer.

Note:
You have to select at least two jars.
Count of chocolates in maximum and second maximum jar among selected consecutive jars may be equal.

Tag:Segment tree

Input  Description:
First line will contain T, number of test cases.
First line of each test case contains two space separated integers N,k.
Second line of each test case contains N space separated integer 'a' denotes number of chocolates in the jar.

Output Description:
For each test case print maximum number of jars.

Testcases:
Input:
1
6 5
1 3 3 1 1 5
Output:
3

EXPLANATION:
You can select 3rd, 4th, and 5th jar as the sum of max and second max is equal to 4 which is less then 5.

Input:
2
5 4
2 2 1 2 3
2 4
1 1
Output:
4
2

Input:
1
10 2
1 1 1 5 8 5 8 2 2 1
Output:
3

Input:
2
12 5
1 4 7 1 4 7 2 5 8 2 5 8
3 1
1 1 1
Output:
2
0

Solution:
"""
from sys import stdin
for _ in range(int(stdin.readline())):
    n,k = map(int,stdin.readline().split())
    l = list(map(int,stdin.readline().split()))
    ans = 0; j = 0
    for i in range(1,n):
        tmp = l[j:i+1]
        tmp.sort()
        if tmp[-1]+tmp[-2]<=k:
            ln = len(tmp)
            if ln>ans:
                ans = ln
        else:
            j += 1
    print(ans)
