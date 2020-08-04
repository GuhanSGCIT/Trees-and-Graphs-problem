"""
Varun has two integers A and B. He can perform the following operation on A an arbitrary number of times (including zero):
    write A as a binary number with an arbitrary number of leading zeroes (possibly without any)
    shuffle the binary digits of A in an arbitrary way, obtaining a number s
    replace A by s+1

Varu is wondering about the minimum number of operations he has to perform on A in order to obtain B. Compute this number
or determine that it is impossible.

timing:1sec
level:6

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains two space-separated integers A and B.

Output Description:
For each test case, print a single line containing one integer — the minimum number of operations or −1 if it is impossible
to obtain B from A.

Constraints
    1≤T≤10^5
    0≤A,B≤10^18

Input
2
2 4
1 5

Output
2
1

Explanation:
Example case 1: One optimal solution is to not shuffle anything, so Chef just adds 1 twice.
Example case 2: We can obtain 5 from 1 in one operation.

Input:
3
1 2
2 5
8 9

Output:
1
1
1

Input:
4
11 12
4 45
1 6
5 9

Output:
1
3
2
2

Input:
2
1 1
5 4

Output:
0
1

Input:
1
1 0

Output:
-1

Solution:
"""
def count_ones(a):
    return bin(a)[2:].count('1')
def count_opts(a,b):
    if a==b:
        return 0
    elif b==0:
        return -1
    elif b==1:
        if(a==0):
            return 1
        else:
            return -1
    opts=count_ones(b-1)-count_ones(a)+1
    if opts>0:
        return opts
    else:
        return 2

#main
for _ in range(int(input())):
    a,b=map(int,input().split())
    print (count_opts(a,b))
