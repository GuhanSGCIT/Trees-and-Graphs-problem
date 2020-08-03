"""
You are given a string containing characters A and B only. Your task is to change it into a string such that there are no matching
adjacent characters. To do this, you are allowed to delete zero or more characters in the string.Your task is to find the minimum
number of required deletions.
For example, given the string s=AABAAB, remove an A at positions 0 and 3 to make s=ABAB in 2 deletions.

timing:1
level:3

Input Description:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a string s.

Output:
For each testcase, print the minimum number of deletions required on a new line.

Constraints
1≤T≤10
1≤|s|≤10^5
Each string s will consist only of characters A and B.

Sample Input:
5
AAAA
BBBBB
ABABABAB
BABABA
AAABBB

Sample Output:
3
4
0
0
4

EXPLANATION:
    Delete 3 A's.
    Delete 4 B's.
    0 deletions required.
    0 deletions required.
    Delete 2 A's and 2 B's.

Input:
3
kyjgyj
sjchNN
KJjjbKJJB

Ouput:
0
1
2

Input:
4
WEarePROGRAMMERS
AAABBBBBBBBBAAA
AlLtHeBeSt
GuVi

Output:
1
12
0
0

Input:
1
ABABBABABBABABBBBBAB

Ouput:
6

Input:
2
jhsdbjhbefskjdbfsjzfvbhksjdfhvbs
NKCJABDCJAHBDJAZHNADLKDAJVNALKJDUBHKABCDBJKVH

Output:
0
0

code:
"""
t=int(input())
for i in range(t):
    s=input()
    n=len(s)
    cnt=0 
    for i in range(1,n):
        if s[i]==s[i-1]: 
            cnt+=1 
    print(cnt)
