"""
You are given two numbers A and B. Write a program to count number of bits needed to be flipped to convert A to B.

timing:1sec
level:5
Input:
The first line of input contains an integer T denoting the number of test cases. T testcases follow. The first line of each test case is A and B separated by a space.

Output:
For each testcase, in a new line, print the number of bits needed to be flipped.

Constraints:
1 ≤ T ≤ 100
1 ≤ A, B ≤ 103

Example:
Input:
1
10 20
Output:
4

Explanation:
Testcase1:
A  = 01010
B  = 10100
Number of bits need to flipped = 4

input:
2
20 30
15 25

output:
2
3

input:
3
12 24
23 32
40 60

output:
2
5
2

input:
1
50 100

output:
4

input:
1
22 33

output:
5

hint:
Calculate XOR of A and B,a_xor_b = A ^ B ;
Count the set bits in the above calculated XOR result.
countSetBits(a_xor_b)
"""
def countSetBits( n ): 
    count = 0
    while n: 
        count += 1
        n &= (n-1) 
    return count 
def FlippedCount(a , b): 
    return countSetBits(a^b) 
  
# Driver code 
for i in  range(int(input())):
    a,b=map(int,input().split())
    print(FlippedCount(a, b)) 
