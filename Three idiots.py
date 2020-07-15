"""
Question:-
There are three friends; let's call them A, B, C. They made the following statements:
A: "I have x rupees more than B."
B: "I have y rupees more than C."
C: "I have z rupees more than A."

You do not know the exact values of x,y,z.Instead, you are given their absolute values, i.e. X=|x|, Y=|y| and Z=|z|.
Note that x, y, z may be negative; "having −r rupees more" is the same as "having r rupees less".

Find out if there is some way to assign amounts of money to A, B, C such that all of their statements are true.

Input Description:-
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers X, Y and Z.

Output Description:-
For each test case, print a single line containing the string "yes" if the presented scenario is possible or "no"
otherwise (without quotes).

Testcases:-
Input:
2
1 2 1
1 1 1
Output:
yes
no

Explanation
One possible way to satisfy all conditions is: A has 10 rupees,
B has 9 rupees and C has 11 rupees. Therefore, we have x=1, y=−2, z=1.

Input:
3
1 1 0
0 1 1
1 0 1
Ouput:
yes
yes
yes

Input:
1
0 0 0
Output:
yes

Input:
4
4545 100 45
1 2 1
753 357 159
2 8 9
Ouput:
no
yes
no
no

Input:
2
45 75 45
12 24 12
Output:
no
yes
"""
t=int(input())
for _ in range(t):
    x,y,z=list(map(int,input().split()))
    x=abs(x)
    y=abs(y)
    z=abs(z)
    if x+y+z==2*max(x,y,z):
        print('yes')
    else:print('no')
