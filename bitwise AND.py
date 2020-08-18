"""
You are given a sequence of non-negative integers A1,A2,…,AN and Q queries. A sequence is good if the bitwise AND of all its
elements is a perfect square. In each query:
    you are given two parameters L and R
    consider the subsequence B=AL,AL+1,…,AR
    you should find the number of good contiguous subsequences of B

timing:2sec
level:5

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
The second line contains N space-separated integers A1,A2,…,AN.
Each of the following Q lines contains two space-separated integers L and R describing one query.

Output
For each query, print a single line containing one integer — the number of good contiguous subsequences.

Constraints
1≤T≤1,000
1≤N≤10^5
0≤Ai<2^30
for each valid i

Input
1
3 2
1 2 3
2 2
1 3

Output
0
3

Explanation
For the first query, there is only one possible subsequence, [2]. The AND of its elements is equal to its only element 2 ,
which is not a perfect square. For the second query, there are six contiguous subsequences:
    [1]; its AND is 1, a perfect square
    [1,2]; its AND is 0, a perfect square
    [1,2,3]; its AND is 0, a perfect square
    [2]; its AND is 2, not a perfect square
    [2,3]; its AND is 2, not a perfect square
    [3]; its AND is 3, not a perfect square

input:
1
4 2
4 8 6 5
4 2
2 3

output:
0
1

input:
1
3 2
1 2 3
2 3
3 2

output:
0
0

input:
2
2 1
5 6
1 2
1 1
4 5 2
1 1
2 1

output:
1
1

input:
1
3 2
3 4 1
2 1
3 2

output:
0
0

hint:
Pre-process the location of different LogN AND values you can obtain from index i, or preprocess the distance upto which j′th bit of
Ai​ remains same. Both of these can be used for next step, where, while operating over a element, we determine the groups with which
the AND gives perfect square. Range update the corresponding interval, and for answering, we can use range sum query. We need to
sort the queries for this approach.

"""
for _ in range(int(input())):
    n,q=map(int,input().split())
    arr=list(map(int , input().split()))
    for i in range(q):
        l,r=map(int,input().split())
        count=0
        for j in range(l-1,r):
            p=arr[j]
            for k in range(j,r):
                p = p & arr[k]
                if int(p**0.5)**2==int(p):
                    count+=1
        print(count)

