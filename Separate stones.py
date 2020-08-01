"""
Question:
There are three piles of stones. The first pile contains a stones, the second pile contains b stones and the third pile
contains c stones. You must choose one of the piles and split the stones from it to the other two piles; specifically,
if the chosen pile initially contained s stones, you should choose an integer k (0≤k≤s), move k stones from the chosen
pile onto one of the remaining two piles and s−k stones onto the other remaining pile. Determine if it is possible for
the two remaining piles (in any order) to contain x stones and y stones respectively after performing this action.

timing:0.5sec
level:3

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains five space-separated integers a , b, c, x and y.

Output Dexscription:
For each test case, print a single line containing the string "YES" if it is possible to obtain piles of the given sizes
or "NO" if it is impossible.

Constraints
    1≤T≤100
1≤a,b,c,x,y≤10^9


Example Input
4
1 2 3 2 4
3 2 5 6 5
2 4 2 6 2
6 5 2 12 1

Example Output
YES
NO
YES
NO

Explanation
Example case 1: You can take the two stones on the second pile, put one of them on the first pile and the other one on the third pile.
Example case 2: You do not have enough stones.
Example case 3: You can choose the first pile and put all stones from it on the second pile.

Input:
5
12 54 12 65 45
25 85 6 4 1
1 2 3 4 5
3 2 1 5 4
8 5 2 6 9

output:
NO
NO
NO
NO
YES

Input:
2
1 5 9 4 6
1 2 1 5 8
output:
NO
NO

Input:
1
2 4 2 6 2
output: 
YES

Input:
3
1 5 9 7 4
8 5 2 6 9
1 2 5 4 1

output:
NO
YES
NO

solution:

"""
def piles(a,b,c,x,y):
    state=0
    if(a+b+c!=x+y):
        return 0
    if(state==0):
        state=state+1
        t1=x-b
        if(t1>=0 and t1<=a):
            return 1
        t2=y-b
        if(t2>=0 and t2<=a):
            return 1
    if(state==1):
        state=state+1
        t1=x-a
        if(t1>=0 and t1<=b):
            return 1
        t2=y-a
        if(t2>=0 and t2<=b):
            return 1
    if(state==2):
        state=state+1
        t1=x-a
        if(t1>=0 and t1<=c):
            return 1
        t2=y-a
        if(t2>=0 and t2<=c):
            return 1
    return 0
t=int(input())
for _ in range(t):
    a,b,c,x,y= map(int, input().split())
    if(piles(a,b,c,x,y)==1):
        print('YES')
    else:
        print('NO')
