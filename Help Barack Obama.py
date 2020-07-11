"""
Questions:-
    Barack Obama was giving a test and he encounter one question in exam,he wants your help,help him to solve the
question,
    A name is consider as a Subname of a another name if it can be formed by characters present in other name.
Given two names of equal length,what's the longest name that can be constructed such that it is a Subname of both?

    For example,ABCD and ABDC have two Subnames with maximum length 3, ABC and ABD.They can be formed by eliminating
either the D or C from both names.Note that we will not consider ABCD as a common Subname because we can't rearrange
characters and ABCD != ABDC.

Input Format:-
There is one line with two space-separated names, s1 and s2.

Constraints:-
1 <= |s1| , |s2| <=5000
All characters are upper case in the range ascii[A-Z].

Output Format:-
Print the length of the longest name s, such that s is a Subname of both s1 and s2.

Sample Input:
DBATU
DATUE
Sample Output:
4

Explanation:
The longest name that can be formed by deleting zero or more characters from DBATU and DATUE is DATU, whose length is 4.

Testcases:

Input:
HARRY
SALLY
Output:
2

Input:
AA
BB
Ouput:
0

Input:
DBATU
DATUE
Output:
4

Input:
SHINCHAN
NOHARAAA
Output:
3



Solution:-
"""
from __future__ import division
from sys import stdin
from collections import defaultdict

def lcs(s1, s2):
    prev = defaultdict(int)
    for i in range(len(s1)):
        cur = defaultdict(int)
        for j in range(len(s2)):
            cur[j] = prev[j - 1] + 1 if s1[i] == s2[j] else max(cur[j - 1], prev[j])
        prev = cur
    return prev[len(s2)-1]
                
def main():
    s=input()
    t=input()
    print(lcs(s, t))

main()
