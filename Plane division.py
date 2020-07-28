"""
Ram is working with lines on a 2-D plane.
He knows that every line on a plane can be clearly defined by three coefficients A, B and C: any point (x, y) lies on the line
if and only if A * x + B * y + C = 0.

Let's call a set of lines to be perfect if there does not exist a point that belongs to two or more distinct lines of the set.

He has a set of lines on a plane and he wants to find out the size of the largest perfect subset of this set.

Timing:1sec
level:5

Input Description:
The first line of input contains one integers T denoting the number of test cases.
Each test case consists of one integer N denoting number of lines.
Next N lines contain 3 space-separated integers each denoting coefficients A, B and C respectively.

Output Description:
For each test case output the cardinality of the largest perfect subset in a single line.

Constraints:
    1 ≤ N ≤ Nmax
    Sum over all N for all test cases ≤ NSmax
    |A|, |B|, |C| ≤ 109
    For a line with coefficients A, B and C either A or B is not zero.

Input:
1
5
1 0 0
1 2 3
3 4 5
30 40 0
30 40 50

Output:
2

Explanation:
Lines 3*x + 4*y + 5 = 0 and 30*x + 40*y + 0 = 0 form a biggest perfect subset.

Input:
2
3
55 4 23
1 55 0
1 5 1
5
1 2 3
5 4 3
0 1 0
2 55 0
44 40 41

Output:
1
1

Input:
1
2
5 2 1
6 8 4

Output:
1

Input:
1
6
1 2 3
4 5 6
7 8 9
12 32 45
65 78 98
124 256 632

Output:
1

Input:
1
1
30 40 50

Output:
1

Solution:
"""
from collections import defaultdict
from math import gcd
def res():
    for _ in range(int(input())):
        n=int(input())
        s=defaultdict(set)
        for i in range(n):
            a,b,c=map(int,input().split())
            g=gcd(a,b)
            h=gcd(g,c)
            s[a/g,b/g].add((a/h,b/h,c/h))
        print(max(map(len,s.values())))
res()
