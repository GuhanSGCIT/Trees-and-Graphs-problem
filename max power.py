"""
Given a binary number (of N bits) X. Find the highest power of 2 that divides this number.
Note: If the binary number is "100" then the highest power of 2 that divides it is 2 (as 22 = 4)

Input Descriptoin:
    The first line contains N the number of bits in the number
    The next line contains a binary number of N bits

Output:
    The first and only line contains the max power of 2 that divides the given number

Constraints:
    1≤N≤105
    1≤X

Input:
5
10100

Output:
2

Input:
4
1110

Output:
1

Input:
12
111111000101

Output:
0

Input:
5
00010

Output:
1

Input:
3
101

Output:
0

Solution:
"""
n=int(input())
a=input()
a=a[::-1]
for i in range(n):
 if(a[i]=='1'):
  print(i)
  break
