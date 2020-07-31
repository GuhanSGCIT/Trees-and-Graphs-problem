"""
Teacher wants to teach a lesson of sharing to the students.

There are N students (numbered from 1 to N from left to right) who are asked to stand in a row. Initially teacher gave "A"
candies to the ith child. In one operation any child can give any number of candies to the child standing to his immediate left
(i.e. ith child can give any amount of candies to the (i−1)th child. In particular 1st child cannot give his candies to anyone).

He asked them to minimize the maximum value of candies a student can possess after performing any number of operations
(possibly zero).Help the students finding such maximum value.

timing:1sec
level:5

Input description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
First line of each test case contains a single integer N denoting the number of students.
Second line contains N space-separated integers A1,A2,..... AN denoting the initial amount of candies chef gave to them.

Output:
For each test case, print a single line containing one integer ― maximum value after sharing.

Constraints
1≤T≤100
1≤N≤10^5
0≤ Ai ≤ 10^9
Sum of N
over all Test Cases does not exceed 10^5

Sample Input:
2 
5 
1 2 3 4 5 
5
5 4 3 2 1

Sample Output:
3 
5  

Explanation:
    For First Test Case: The 5th student will give 2 candies to 4th student and 4th will give 3 candies to 3rd and 3rd will give
3 candies to 2nd and 2nd will give 2 candies to 1st. So finally the number of candies that they will have are [3,3,3,3,3] and
the value of maximum candies is 3.
For Second Test Case: Sharing to the left student will not change the maximum valu
e as 1st cannot share to anyone. So the maximum value will remain 5

input:
3
4
1 5 9 6
3
1 4 7
6
1 2 3 4 5 6

Output:
6
4
4

input:
2
3
1 0 1
5
1 4 5 2 3

Output:
1
4

input:
2
8
5 6 4 1 2 3 7 8
2
1 9

Output:

input:
1
12
4 5 6 8 5 2 1 5 9 3 5 7

Output:
6

Solution:
"""
from math import *
for u in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=sum(l)
    m=s/n
    while(n>1):
        s=s-l.pop()
        n-=1
        m=max(m,s/n)
    print(ceil(m))
