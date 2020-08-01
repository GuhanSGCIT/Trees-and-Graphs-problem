"""
You are given a sequence of N powers of an integer k; let's denote the i-th of these powers by kAi.
You should partition this sequence into two non-empty contiguous subsequences; each element of the original
sequence should appear in exactly one of these subsequences. In addition, the product of (the sum of elements
of the left subsequence) and (the sum of elements of the right subsequence) should be maximum possible.

Find the smallest position at which you should split this sequence in such a way that this product is maximized.

timing:1sec
level:6

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and k.
The second line contains N space-separated integers A1,A2,…,AN.

Output Description:
For each test case, print a single line containing one integer — the size of the left subsequence.
If there is more than one possible answer, print the smallest possible one.

Constraints
1≤T≤10
2≤N≤10^5
2≤k≤10^9
0≤Ai≤10^5
for each valid i

Example Input
1
5 2
1 1 3 3 5

Example Output
4

Explanation
Example case 1: The actual sequence of powers is [21,21,23,23,25]=[2,2,8,8,32].
The maximum product is 20⋅32=640. In the optimal solution, the sequence is partitioned into [2,2,8,8] and [32].

Input:
2
6 2
5 8 4 6 2 3
4 1
5 4 8 6

Output:
2
1

Input:
1
8 3
55 66 44 8 11 22 99 33

Output:
6

Input:
1
3 1
3 2 1

Output:
1

Input:
1
7 3
6 4 3 2 1 7 8

Output:
6

Code:
"""
t = int(input())  # read a line with a single integer
for numtest in range(1, t + 1):
    n,k=[int(kk) for kk in input().strip().split(" ")]
    a=[int(kk) for kk in input().strip().split(" ")]
    sm=max(a)+50
    ts=[0]*(sm+1)
    ts[sm]=1
    for i in range(n):
        ts[a[i]]+=1
        ii=a[i]
        while ts[ii]==k:
            ts[ii]=0
            ii+=1
            ts[ii]+=1
    tts=ts[:]
    poss=[]
    for i in range(n):
        tts[a[i]]-=2
        ii=a[i]
        while tts[ii]<0:
            tts[ii]+=k
            ii+=1
            tts[ii]-=1
            if ii==sm:
                poss+=[i]
                if i:
                    poss+=[i-1]
                    ptts=tts[:]
                    ptts[a[i]]+=1
                    jj=a[i]
                    while ptts[jj]>=k:
                         ptts[jj]-=k
                         jj+=1
                         ptts[jj]+=1
                    if ptts[sm] and max(ptts[:sm]):
                        print( i+1)
                    else:
                        print (i)
                else:
                    print (i+1)
       # print i,tts
        if len(poss):
            break
    

