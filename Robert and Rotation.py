"""
Robert has a sequence A1,A2,…,AN. For a positive integer M, sequence B is defined as B=A∗M that is, appending A exactly M times.
For example, If A=[1,2] and M=3, then B=A∗M=[1,2,1,2,1,2]
You have to help him to find out the minimum value of M such that the length of the longest strictly increasing subsequence
is maximum possible.

timing:2sec
level:6s

Input:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output:
For each test case, print a single line containing one integer ― the minimum value of M.

Constraints
1≤T≤500
1≤N≤2∗10^5
1≤Ai≤10^9

Input:
3
2
2 1
2
1 2
5
1 3 2 1 2

Output:
2
1
2

Explanation:
In the first test case, Choosing M=2 gives B=[2,1,2,1] which has a longest strictly increasing sequence of length 2 which is the maximum possible.
In the second test case, Choosing M=1 gives B=[1,2] which has a longest strictly increasing sequence of length 2 which is the maximum possible.


input:
4
3
1 2 3
4
1 2 3 4
5
1 2 3 4 5
6
1 2 3 4 5 6

output:
1
1
1
1

input:
3
1
111
2
111 111
3
111 111 111

output:
1
1
1

input:
3
4
4 8 6 5
2
1 5
3
4 5 8

output:
3
1
1

input:
1
7
45 88 66 22 45 45 21

output:
4

hint:
If the given sequence contains the D distinct elements and let’s represent by them S={d1,d2,…,dD}
Step1:Find the valid prefix of S. A prefix is said to be valid if it is also the subsequence of the given sequence and length is
maximum possible. If the length of the valid prefix is equal to S then stop else remove the valid prefix from the S and
go back to Step1.

"""
from sys import stdin, stdout

def makedict(n,a):
    d={}
    for i in range(n):
        if a[i] not in d:
            d[a[i]]=[i]
        else:
            d[a[i]]+=[i]
    return solve(n,d)

def solve(n,d):
    l=sorted(d.keys())
    prev=-1
    c=1
    for i in range(len(l)):
        new=True
        for j in d[l[i]]:
            if j>prev:
                prev=j
                new=False
                break
        if new:    
            c+=1
            prev=d[l[i]][0]
    return c

for tc_ in range(int(stdin.readline())):
    n=int(stdin.readline())
    a=list(map(int,stdin.readline().split()))
    stdout.write(f"{makedict(n,a)}\n")
