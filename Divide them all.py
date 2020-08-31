"""
Santa has N truffles and M candies to divide between his two buddy elves such that both have equal amounts of total sweetness.
Each truffle has a sweetness value of X and each candy has a sweetness value of Y.

Note: A unit of truffle or candy cannot be divided further and no item can be left out after division.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, four integers N,M,X,Y.

Output:
For each testcase, print "YES" in a newline if it possible to divide all the candies and truffles into two equal parts of
sweetness values, Else, print "NO" in a newline.

Constraints
1≤T≤10^3
0≤N,M≤10^2
0≤X,Y≤10^5

Input:
3
3 2 2 3
2 0 1 10
1 2 5 4

Output:
YES
YES
NO

EXPLANATION:
In the first test case, all the truffles can be given to one elf and all the candies to another.
Sweetness value with elf1 = 2 + 2 + 2 = 6.
Sweetness value with elf2 = 3 + 3 = 6.
Thus, both have equal amounts. 

input:
2
1 5 8 4
2 6 4 8

output:
NO
YES

input:
5
4 5 6 2
8 4 9 7
2 1 3 4
2 2 1 1

output:
NO
YES
NO
YES

input:
1
1 5 8 9

output:
NO

input:
3
1 2 3 4
4 5 6 7
9 8 7 4

output:
NO
NO
NO


hint:
You can find the answer by running two nested loops.
"""
import bisect
import math as m
from sys import stdin,stdout

for _ in range(int(stdin.readline())):
    t1,t2,s1,s2=map(int,stdin.readline().split())
    total=t1*s1+t2*s2
    if s1==0:
        if t2%2!=0:stdout.write('NO\n')
        else:stdout.write('YES\n')
    elif s2==0:
        if t1 % 2 != 0:stdout.write('NO\n')
        else:stdout.write('YES\n')
    elif total%2==1:stdout.write('NO\n')
    else:
        half=total//2;flag=0
        for x in range(t1+1):
            y=half-(s1*x)
            if y%s2==0 and y//s2 in range(0,t2+1):
                flag=1
                break
        if flag:stdout.write("YES\n")
        else:stdout.write('NO\n')


