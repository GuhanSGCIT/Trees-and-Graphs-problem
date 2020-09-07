"""
Tapan is a CSE guy. He is very lazy to complete his assignment. So he generally manages the assignment from other students.
His teacher is also very smart. This time, He gave a unique problem to each student. So he asked for your help.
The problem is as follows:
“A small child PingPong knows how to count, but how to write numbers, he is just learning. He learned the number digit 1,2,3 and 4.
But he is not yet fully aware that 4 is different  than 1.For ex: 1312=1+3+1+2=7 and 124=1+2+1=4

Now Ping Pong wants to know how many such numbers are possible whose digit's sum is M.Print the answer modulo 10^9 + 7.”

Constraint:
1<=M<=10^18

Input:
The first line of the input contains one integer T (1≤T≤100000) - the number of queries. Then T queries follow.
The Only line in each query contains an integer M.

 
Output:
For each query, Print answer to the query. Don’t Forget to take Modulo by 10^9 + 7 or 1000000007.


Sample Input:
3
1
2
3

Sample Output:
2
5
13


Sample Explanation:
For the First query, two possible numbers are 1 and 4
For the First query, Five possible numbers are 11,14,41,44,2.

input:
5
8
2
6
4
1

output:
1388
5
214
33
2

input:
2
45
32

output:
377404384
368042554


input:
1
15

output:
964666

input:
5
4
8
7
2
1

output:
33
1388
545
5
2

hint:
Let say we have to find the answer to the Query “4”.
1. if we append 1 and 4 at the end of all number having digit’s sum equals 3 then we get digit’s sum as 4.
2. if we append 2 at the end of all number having digit’s sum equals 2 then we get digit’s sum as 4.
3. if we append 3 at the end of all number having digit’s sum equals 1 then we get digit’s sum as 4.
So dp[n]=2*dp[n-1] + dp[n-2] + dp[n-3]
"""
mat=[[2,1,1],[1,0,0],[0,1,0]]
val=[13,5,2]
mod=10**9 + 7

def matmul(a,b):
    row=len(a)
    try:
        col=len(b[0])
    except:
        col=1
    dp=[[0 for i in range(col) ] for j in range(row)]
    for i in range(row):
        for j in range(col):
            ans=0
            for k in range(len(b)):
                ans+=a[i][k]*b[k][j]
                ans%=mod
            dp[i][j]=ans
    return dp


def solve(mat1,m):
    ans=[[1,0,0],[0,1,0],[0,0,1]]

    while m>0:
        if m%2==1:
            ans=matmul(ans,mat1)
        m//=2
        mat1=matmul(mat1,mat1)
    return (ans[0][0]*val[0] + ans[0][1]*val[1] + ans[0][2]*val[2])%mod


import random as r
t=int(input())
for i in range(t):
    n=int(input())
    if n<=3:
        ans=val[-n]
    else:
        ans=solve(mat,n-3)
    print(ans)        
