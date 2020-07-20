"""
Question:-

In Beach Volleyball tournament , there are usually three people in a team. For each person in the team, you know
their scores in three skills - Passing,Setter,Serving.

You want to check whether it is possible to order these people (assign them numbers from 1 to 3) in such a way
that for each 1 ≤ i ≤ 2, i+1-th person is stricly better than the i-th person.

A person x is said to be better than another person y if x doesn't score less than y in any of the skills and scores
more than y in at least one skill.

Determine whether such an ordering exists.

Input Description:
The first line fo the input contains an integer T denoting the number of test cases.
Each test consists of three lines. Each of these lines contains three space separated integers s1, s2 and s3
denoting the scores of one member of the team in each of the three skills, in the given order.

Output Description:
For each test case, output a single line containing "yes" if such an ordering exists or "no" if doesn't exist (without quotes).

Testcases:
Input:
3
1 2 3
2 3 4
2 3 5
1 2 3
2 3 4
2 3 4
5 6 5
1 2 3
2 3 4
Output:
yes
no
yes

Explanation:
Test Case 1: We can order them as (3, 2, 1). Person 3 is better than Person 2 because his scores in the first two skills
are not lesser than Person 2's. And in skill 3, Person 3 scores higher.Similarly, Person 2 is better than Person 1.
He scores more than Person 1 in every skill, in fact.

Input:
1
1 1 1
2 2 2
3 3 3
Output:
yes

Input:
2
0 1 2
2 3 3
3 3 3
3 3 3
1 2 1
1 1 1
Output:
yes
yes

Input:
3
1 1 1
3 2 1
2 1 3
2 0 1
2 2 2
3 3 3
0 0 1
2 3 0
2 2 1
Output:
no
yes
no

Input:
1
0 0 1
0 1 0
0 0 0
Output:
no

Solution:-
"""
t=int(input())
ans=[]
def comp(a,b):
    ch=0;ch1=0
    for i in range(3):
        if a[i]>b[i]:ch+=1
        if a[i]==b[i]:ch1+=1
        if a[i]<b[i]:return False
    return True if ch>=1 and (ch+ch1)==3 else False
for i in range(0,t):
    s=[list(map(int,input().split())) for i in range(3)]
    s.sort(key=sum)
    if comp(s[1],s[0]) and comp(s[2],s[1]) and comp(s[2],s[0]):ans.append('yes');continue
    ans.append('no')
for i in ans:print(i)
