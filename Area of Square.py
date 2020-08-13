"""
Varun and varun's friend are playing a game.

Varun's friend gave him a grid of infinite dots and each dot is equidistant from the dot above it, below it, left to it
and right to it (uniformly spaced, the distance being one unit).

Varun is given a number N.He was told to draw a square whose area was N. The sides of the squares can only be drawn by
joining any 4 dots as long as the connected figure is a square with area N.

Given N, can you help Varun determine if it is possible to draw a square of the given area?

timing:5sec
level:5

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, one integer N.

Output:
For each testcase, output in a single line answer "Yes"
(without quotes) if area N is possible otherwise "No"(without quotes).

Constraints
1≤T≤1000
2≤N≤10^5

Sample Input:
3
4
3
20

Sample Output:
Yes
No
Yes

input:
4
8
74
2632
315465

output:
Yes
Yes
No
No

input:
6
1
1002153
3216351
3216
32165
215132121

output:
Yes
No
No
No
No
Yes

input:
2
12124
3333342

output:
No
No

input:
3
4
2
6

output:
Yes
Yes
No

hint:
Area of N is possible only if the area is the sum of two squared integers.
N = a2a^2a2 + b2b^2b2 , where a and b are whole numbers.
"""
from math import sqrt,floor
def is_root(n):
    return sqrt(n)==int(sqrt(n))
for a0 in range(int(input())):
    n=int(input())
    for i in range(floor(sqrt(n))+1):
        if is_root(n-pow(i,2)):
            
            print("Yes")
            break
    else:
        print("No")
        
