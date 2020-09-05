"""
Raju has created a program to find the square root of a number. But his program can store only integers. Being a newbie, he didn't
know about rounding the numbers. Hence his program returns the absolute value of the result if possible.
For example, sqrt(3) = 1.73205080757……. His program will return 1 Given a number N, and it's integral square root S, His instructor
will consider the answer correct if Difference between N and the square of S is within less than or equal to X% of N.

Input:
First line contains T no. of test cases and X separated by space
For every test case, a line contains an integer N

Output:
For every test case, print yes if his programs return square root and (N-(S^2)) <= 0.01XN . For everything else, print no on a new line


Sample Input:
2 20
5
3

Sample Output:
yes
no

EXPLANATION:
In #1, sqrt(5) = 2.2360679775. Taking integral value, S = 2.
S2 = 4. Difference=1 which is within 20% of 5
In #1, sqrt(3) = 1.73205080757. Taking integral value, S = 1.
S2 = 1. Difference=2 which is not within 20% of 3


input:
3 40
2
5
6

output:
no
yes
yes

input:
6 45
5
4
8
9
5
2

output:
yes
yes
no
yes
yes
no


input:
4 10
2
1
4
5

output:
no
yes
yes
no


input:
5 45
1
2
3
4
5

output:
yes
no
no
yes
yes

hint:
Negative numbers can not have a real square root!.
Hence, when N is negative, print no
Otherwise, calculate difference D = N−S^2
if D ≤ X∗N/100​, print yes,else print no
"""
import math
T, X = map(int, input().split())
for z in range(T):
    N = int(input())
    if N < 0:
        print("no")
        continue
    S = int(math.sqrt(N))
    if N - (S ** 2) <= 0.01 * X * N:
        print("yes")
    else:
        print("no")
