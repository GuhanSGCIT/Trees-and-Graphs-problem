"""
A number is called palindromic if its decimal representation is a palindrome. You are given a range, described by a pair
of integers L and R. Find the sum of all palindromic numbers lying in the range [L, R], inclusive of both the extrema.

timing:1sec
level:6

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a pair of space separated integers L and R denoting the range for which you are
required to find the sum of the palindromic numbers.

Output
For each test case, output a single line containing the sum of all the palindromic numbers in the given range.

Constraints
    1 ≤ T ≤ 100
    1 ≤ L ≤ R ≤ 10^3
    1 ≤ L ≤ R ≤ 10^5

Input:
2
1 10
123 150

Output:
45
272

Explanation
Example case 1. The palindromic numbers between 1 and 10 are all numbers except the number 10. Their sum is 45.
Example case 2. The palindromic numbers between 123 and 150 are 131 and 141 and their sum is 272.

hint:
Precompute the sum of palindromic number not greater than K, for 1≤K≤10^5, and store these values
in an array. Provide an answer for a single test case [L,R][L, R][L,R] using precomputed sums for R and L−1.

input:
3
12 23
1023 4025
1 1

output:
22
77913
1

input:
1
121 131

output:
252

input:
2
46 47
1 11

output:
0
56

input:
3
1 2
2 3
4 5

output:
3
5
9

code:
"""
l1 = list(range(1,10))
l2 = list(range(11,100,11))
l3 = []
for i in l1+[0]:
    for j in range(1,10):
        l3.append(10*i + 101*j)
l4 = []
for i in l2+[0]:
    for j in range(1,10):
        l4.append(i*10 + 1001*j)
l5 = []
for i in [k*10 for k in l1]+l3+[0]:
    for j in range(1,10):
        l5.append(i*10 + 10001*j)

pals = l1+l2+l3+l4+l5
pals.sort()

sums = [0]
s = 0

for p in pals:
    s += p
    sums.append(s)
    
from bisect import *

for t in range(int(input())):

    l,r = [int(i) for i in input().split()]
    bl = bisect_left(pals,l)
    br = bisect_right(pals,r)

    print(sums[br]-sums[bl])
    
