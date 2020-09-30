"""
Given three positive integers N, L and R, find the number of non-decreasing sequences of size at least 1 and at most N, such that each element of the sequence lies between L and R, both inclusive.
Print the answer modulo 10^6+3.

timing:4sec

Input
First line of input contains T, the number of the test cases.
Each of next T lines contains three space separated integers N, L and R.

Output
For each test case print the answer modulo 106+3 in a single line.

Constraints
    1 ≤ T ≤ 100
    L ≤ R


Input:
2
1 4 5
2 4 5

Output:
2
5

Explanation
1: [4] and [5] are the two sequences.
2: [4], [5], [4, 4], [4, 5] and [5, 5] are the five sequences.

input:
2
1 5 9
2 4 8


output:
5
20

input:
5
22 55 88
152 324 369
4856 1245 6589
2 4 6
1 2 3

output:
535857
208831
687995
9
2

input:
1
5 4 2

output:
0

input:
3
1 1 2
2 2 1
4 5 6

output:
2
0
14

hint:
Number of non-decreasing sequences of size exactly K will be Choose(K + R - L, K). Where Choose(N, R) is number of ways to choose R elements from N distinct elements.
Summation of Choose(K + R - L, K) for all K between 1 and N (inclusive) will be Choose(N + R - L + 1, N) - 1. In the question it is given that the answer should be printed mod (10^6+3) which is a prime number.
"""
import math
from sys import stdin
MOD=10**6+3
#MOD is a prime
fact=[1]
temp=1
for i in range(1,MOD):
    temp*=i
    temp%=MOD
    fact+=[temp]
    
def bino(a,b):
    if b>a:
        return 0
    elif a==0 and b==0:
        return 1
    
    MOD=10**6+3

    temp1=fact[a-b]*fact[b]
    temp1%=MOD
    
    temp1=pow(temp1,MOD-2,MOD)
    
    ans=fact[a]*temp1
    ans%=MOD
    return ans
    

def find(N,L,R):
    T=R-L+1
    #ans=C(N+T,N)
    def findpower(K):
        MOD=10**6+3
        CC=[]
        while(K>0):
            temp=K%MOD
            CC+=[temp]
            K=(K-temp)//MOD
        return CC
    
    A1=findpower(N+T)
    A2=findpower(T)
    #print(A1,A2,'A1,A2')
    A2=A2+[0]*(len(A1)-len(A2))
    
    ans=1
    for i in range(len(A1)):
        ans*=bino(A1[i],A2[i])
        #print(A1[i],A2[i],ans,bino(A1[i],A2[i]),'A1[i],A2[i],ans')
        ans%=MOD
        if ans==0:
            break
    return (ans-1)%MOD        
    
for _ in range(int(input())):
    N,L,R=map(int,stdin.readline().strip().split())
    print(find(N,L,R))
    
    
            
