"""
Question:
    You are given two binary strings A and B, each with length N. You may reorder the characters of A in an arbitrary way and
reorder the characters of B also in an arbitrary (not necessarily the same) way. Then, you should compute the XOR of the
resulting strings.Find the number of distinct values of this XOR which can be obtained, modulo 1,000,000,007 (10^9 + 7).

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains a single string A with length N.
The third line contains a single string B with length N.

Output Description:
For each test case, print a single line containing one integer ― the number of unique XORs modulo 1,000,000,007.

Testcases:
Input:
1
2
00
10

Output:
2

Explanation:
Example case 1: The characters in each string can be reordered in two ways (swap them or do nothing), so there are
four values of their XOR:
"00" XOR "10" is "10"
"00" XOR "01" is "01"
"00" XOR "10" is "10"
"00" XOR "01" is "01" There are only two distinct values.

Input:
2
3
010
101
4
1111
1010

Output:
4
6

Input:
3
5
10101
11100
2
11
01
6
101010
110011

Output:
16
2
32

Input:
2
3
111
000
10
1000110001
0111001110

Output:
1
511

Input:
1
7
1111001

Output:
57

Solution:
"""
from sys import stdin
from collections import Counter

N = 100001
p=1000000007
factorial  = [None] * (N + 1)  
natural  = [None] * (N + 1) 
fact = [None] * (N + 1) 
natural [0] = natural [1] = 1
for i in range(2, N + 1, 1): 
    natural [i] = (natural [p % i] *(p - int(p / i)) % p) 
factorial [0] = factorial [1] = 1
for i in range(2, N + 1, 1): 
    factorial [i] = (natural [i] *factorial [i - 1]) % p 
fact[0] = 1
for i in range(1, N + 1): 
    fact[i] = (fact[i - 1] * i) % p

t = int(stdin.readline())

while t:
    n = int(stdin.readline())
    a = stdin.readline().strip()
    b = stdin.readline().strip()

    c1, c2 = Counter(a), Counter(b)

    max1 = min(c1['0']+c2['0'], c1['1']+c2['1'])
    min1 = abs(c2['1'] - c1['1'])

    
    i = max1
    ans = 0
    while i >= min1:
        ans=(ans+(((fact[n] * factorial [i])% p * factorial [n - i])% p))%p 
        i -= 2

    print(ans)
    t -= 1
