"""
Question:
    Consider an ordered tree with N vertices. Your task is to calculate the desired value of the number of vertices having
exactly one child in such tree assuming that it is uniformly chosen from the set of all ordered trees of size N.

Input Description:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each testcase contains a single integer N for which you should calculate the answer.

Output Description:
For each test case, output a single line containing two integers, which are explained below.
Consider the answer to be a proper fraction P/Q, where gcd(P, Q) = 1. Then your task is to output
two integers PQ^-1 mod 10^9 + 7 and PQ^-1 mod 10^9 + 9.

Testcase:
Input:
4
1
2
3
4

Output:
0 0
1 1
1 1
400000004 200000003

Explanation:
You can see every possible tree with 1, 2, 3 or 4 vertices,
From this result you can see that answers for these inputs are 0/1 = 0, 1/1 = 1, (2+0)/2 = 1 and (3+1+1+1+0)/5 = 6/5 correspondingly.

Input:
5
4
5
6
1
2

Output:
400000004 200000003
428571433 571428578
666666673 333333338
0 0
1 1

Input:
3
1
4
7

Output:
0 0
400000004 200000003
181818185 636363644

Input:
7
1
2
3
4
5
6
7

Output:
0 0
1 1
1 1
400000004 200000003
428571433 571428578
666666673 333333338
181818185 636363644

Input:
5
9
5
1
7
3

Output:
800000008 400000006
428571433 571428578
0 0
181818185 636363644
1 1

Solution:-
"""
def modInverse(a, m) :
    m0 = m
    y = 0
    x = 1
 
    if (m == 1) :
        return 0
 
    while (a > 1) :
        q = a // m
 
        t = m
        m = a % m
        a = t
        t = y
 
        # Update x and y
        y = x - q * y
        x = t
 
 
    # Make x positive
    if (x < 0) :
        x = x + m0
 
    return x
m1=int(1e9+7)
m2=int(1e9+9)
for _ in range(int(input())):
    n=int(input())
    p=n*(n-1)//2
    q=2*n-3
    mi=modInverse(q,m1)
    mi2=modInverse(q,m2)
    print(p*mi%m1,p*mi2%m2)
