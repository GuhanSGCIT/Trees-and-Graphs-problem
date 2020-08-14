"""
A factorial of a non-negative integer is defined as the product of all numbers from 1 to N inclusive.
The factorial of N is denoted by N!. By convention, 0!=1.

For example, 5!=5×4×3×2×1=120.

Your task is simple. You are given N! , where you have to find N . If multiple values exist for a single factorial,
find the largest one. It is guaranteed that a solution exists.

timing:1sec
level:3

Input:
The first line will contain T- number of testcases. Then the testcases follow.
Each testcase consists of a single line of input: one integer N!.

Output:
For each testcase, output in a single line N as explained in the problem statement.

Constraints
1≤T≤30
1≤N!<10^36

Sample Input:
2
1
24

Sample Output:
1
4

EXPLANATION:
For N!=1, multiple solutions exist. N=1 satisfies the conditions.
For N!=24, N=4 because 4×3×2×1=24.

input:
3
10
11
19

output:
3
3
3

input:
7
45
65
556
60
656
1251
8
1

output:
4
4
5
4
5
6
3

input:
1
10000

output:
7

input:
2
10
100

output:
3
4

hint:
First, check if the number is 1. If it is, print 1.
Otherwise, maintain a variable iii and set it to 0. While nnn is not 111, we need to increment i by 1.
We need to change nnn to ni\dfrac{n}{i}in​ (we divide n each time after we increase i). Then print the final i.
Implementation is simple.

"""
for i in range(int(input())):
    a = int(input())
    b = 1
    while a >= 1 :
        a = a//b
        ans = b
        b = b+1 
    print(ans-1)
