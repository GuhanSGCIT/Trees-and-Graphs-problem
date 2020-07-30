"""
 Given an integer, N. Convert this integer to binary and then if the Kth bit is not set then set the Kth bit otherwise leave
it as it is. Then convert this binary to decimal M.

Timing:1sec
level:4

Input Description:
    The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
    The first and only line of each test case contains two space seperated integer N and K

Output Description:
    For each test case, output a single line containing the new number M

Constraints

    1 ≤ T ≤ 105
    0 ≤ N ≤ 105
    0 ≤ K ≤ 31
    All values are unsigned integer type

Input:
2
2 0
5 0
Output:
3
5

Explanation:
Example case 1.N = 2 which can be represented by 10 in binary, now if we set 0th bit then it becomes 11 which is equal to 3
in decimal

Input:
3
2 4
4 6
6 8

Output:
18
68
262

Input:
2
0 1
0 6

Output:
2
64

Input:
4
1 2
2 3
3 4
4 5

Output:
5
10
19
36

Input:
1
102 201

Output:
1048678

Solution:
"""
t=int(input())
i=1 
while(i<=t):
    n,k=map(int,input().split())
    ans=n|(1<<k)
    print(ans)
    i+=1 
    
