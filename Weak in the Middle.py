"""
Question:-
You are given an array A with length N. On each day, the following process was performed:
    1.)a new array R is created; this array contains all elements Ai such that i=1,i=N or min(Ai−1,Ai+1)≤Ai (2≤i<N),
in the original order.
    2.)A is replaced by R and N is replaced by the length of R.
In other words, all elements of A that are between two bigger elements disappear.
For each element of the original array, calculate the number of the day on which it disappeared (the process starts with day 1),
or determine that it never disappeared.

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output Description:
For each test case, print a single line containing N space-separated integers.
For each valid i, the i-th of these integers should be the number of the day on
which the i-th element of the original array disappeared, or 0 if it never disappeared.

Testcases:
Input:
1
6
3 2 5 4 1 7
Output:
0 1 0 2 1 0

Input:
2
3
5 4 6
8
32546 2565 55 5 2 4 1 9
Output:
0 1 0
0 0 0 3 1 2 1 0

Input:
1
6
5 1 2 8 4 6
Output:
0 1 2 0 1 0

Input:
1
4
8 5 4 3
Output:
0 0 0 0

Input:
3
3
-1 -2 -3
4
3 2 1 0
9
-9 8 -7 6 -5 4 -3 2 -1
Output:
0 0 0
0 0 0 0
0 0 1 0 1 0 1 0 0

Solution:-
"""
T = int(input())
for test in range(T):
    N = int(input())
    A = [int(v) for v in input().split()]

    rem = [(A[0],0)]
    count = 0
    prev = 0
    res = [0]*N
    for i in range(1,N):
        v = A[i]
        while (len(rem) > 1) and (rem[-1][0] < min(rem[-2][0],v)):
            _,old_count,ind = rem.pop()
            count = max(count,old_count)+1
            res[ind] = count
        else:
            rem.append((v,count,i))
            count = 0
            back = 0
    print(" ".join([str(v) for v in res]))
