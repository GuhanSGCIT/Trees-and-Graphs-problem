"""
Question:

Given n and m, calculate 1^1 + 2^2 + 3^3 + ... + n^n modulo m.

Input Description:
The first line contains 1 ≤ t ≤ 10, the number of test cases. Then the test case definitions follow.
Each test case is of the form: 1 ≤ n 1018, 1 ≤ m ≤ 200000

Output Description:
For each test case simply write a single line containing the answer to the problem.

Timing:44.25sec
TYPE:HARD 9

Testcases:
Input:
6
1 100000
2 100000
3 100000
4 100000
5 100000
6 100000

Output:
1
5
32
288
3413
50069

Explanation:
1 + r + r^2 + r^3 + .. + r^k-1
= (1+r) + r^2(1+r) + r^4(1+r) + ... + r^(2[(k-1)/2]) (1+r) + (rk-1 if k is odd)
= (1+r)(1 + r^2 + r^4 + .. + r^2[(k-1)/2]) + (r^k-1 if k is odd)
This has reduced the problem to calculating the sum of a geometric series with half as many terms.
So we can calculate this recursively .

Input:
1
1 20
Output:
1

Input:
5
11 2600
455 1111
202 8448
13 215
1 1000

Output:
1128
640
7509
37
1

Input:
7
9 200
8 200
7 200
6 200
5 200
4 200
3 200

Output:
117
28
12
69
13
88
32

Input:
2
123 321
159 951

Output:
234
582

Input:
1
123 10000

Output:
6616

Solution:
"""
def S(a, n, m):
    if n == -1: return 0
    if n == 0: return 1
    if n == 1: return (1 + a) % m 
    if n % 2 == 1: return ((1 + a) * S(a * a % m, (n - 1)//2, m))%m
    else: return (1 + a * (1 + a) * S(a * a % m, n//2 - 1, m) )%m  
for _ in range(int(input())):
    n,m = map(int,input().split(' '));s=0;e = n//m
    for i in range(1,n%m+1):s += pow(i,e*m + i,m);s = s%m
    for i in range(2,m+1):s += (((S(pow(i,m,m),e-1,m) )%m)*pow(i,i,m))%m;s = s%m
    print((s+e)%m)    
