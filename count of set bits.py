"""
Given a positive integer N, print count of set bits in it. For example, if the given number is 6(binary: 110), output should be 2 as there are two set bits in it.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow.
Each testcase contains single line of input containing the N.

Output:
For each test case, in a new line, print count of set bits in it.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 10^6

Input:
2
6
13

Output:
2
3

Explanation:
Binary representation of 6 is 110 and has 2 set bits,
Binary representation of 13 is 1101 and has 3 set bits.

input:
3
8
15
57

output:
1
4
4

input:
1
102

output:
4

input:
2
2
31

output:
1
5

input:
3
2
12
24

output:
1
2
2

hint:
Loop through all bits in an integer, check if a bit is set and if it is then increment the set bit count.
"""
def countSetBits( n): 
    if (n == 0): 
        return 0
  
    else: 
        return (n & 1) + countSetBits(n >> 1) 
for i in range(int(input())):
    n = int(input())
    print( countSetBits(n))   