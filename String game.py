"""
You are given a uniformly randomly generated string S, consisting of letters from the set {"A", "B"}. Your task is to find a
string T that appears in S as a subsequence exactly twice.

In other words, you need to find such a string T, that there exist exactly two sets of indexes i1, i2, ..., i|T| and
j1, j2, ..., j|T| such that there exists some k, where ik ≠ jk and S{i1...i|T|} = S{j1...j|T|} = T.

Timing:1sec
level:6

Input Description:
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S.
The string S was generated randomly. For a generating string S, we first choose an integer N denoting a length of S. After that every symbol of the string S is chosen randomly from the set {"A", "B"} and the both symbols have equal probability to be chosen. Note that N is not choosen randomly.

Output Description:
For each test case, output a string that occurs exactly twice as a subsequence in S, or output -1 if there is no such string. If there are more than one possible subsequences occurring exactly two times, you can print any one of them.

Constraints
    1 ≤ T ≤ 10


Input:
2
AAAA
BAB

Output:
-1
B

Explanation
Test case #1:
    The string "AAAA" appears once as a subsequence in itself.
    The string "AAA" appears four times as a subsequence in "AAAA"; possible positions: {2, 3, 4}, {1, 3, 4}, {1, 2, 4}, {1, 2, 3}.
    The strings "AA" and "A" also appear in "AAAA" as a subsequence strictly more than twice.
    So, there is no string of "AAAA", which appears exactly twice. Hence answer is -1.

Input:
3
SMVNJ
BABAB
BBAA

output:
-1
A
A

Input:
1
BABABABBA

output:
BABABABA

Input:
3
FSVSV351
ASCW
BABAAB

output:
-1
-1
BABAB

Input:
2
BAAB
AABB

output:
A
A

Solution:
"""
for _ in range(int(input())):
    s=input()
    n=len(s)
    a=s.count('A')
    b=s.count('B')
    c=0
    if (a>2 and b==0) or (b>2 and a==0):
        print(-1)
        c=1
    elif a==2:
        print('A')
        c=1
    elif b==2:
        print('B')
        c=1
    elif n>3:
        for i in range(n-3):
            if i==0 and (s[ :3]=='AAB' or s[ :4]=='BBA'):
                print(s[1: ])
                c=1 
                break
            else:
                p=s[i:i+4]
                if p=='ABBA' or p=='BAAB':
                    print(s[ :i+1]+s[i+2: ])
                    c=1 
                    break
        if c==0 and (s[n-3: ]=='ABB' or s[n-3: ]=='BAA'):
            print(s[ :n-1])
            c=1
    if c==0:
        print(-1)
