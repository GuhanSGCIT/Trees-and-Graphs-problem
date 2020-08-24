"""
Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.

Input:
First line of the input contains no of test cases  T,the T test cases follow.
Each test case consist of 2 space separated integers A and B denoting the size of string str1 and str2 respectively
The next two lines contains the 2 string str1 and str2 .

Output:
For each test case print the length of longest  common subsequence of the two strings .

Constraints:
1<=T<=200
1<=size(str1),size(str2)<=100

Example:
Input:
2
6 6
ABCDGH
AEDFHR
3 2
ABC
AC

Output:
3
2

Explanation
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS of "ABC" and "AC" is "AC" of length 2

input:
3
4 4
knds
kndd
5 4
ABCDE
ABCC
2 3
KK
AKA

output:
3
3
1

input:
1
7 8
ZXCVBNM
ZXCVGHJN

output:
5

input:
2
3 3
KLO
OLK
4 4
HHGN
KHUG

output:
1
2

input:
1
5 5
NHGVJ
KUHVJ

output:
3

hint:
Generate all subsequences of both given sequences and find the longest matching subsequence

"""
def lcs(X, Y, m, n):
    if m == 0 or n == 0:
        return 0;
    elif X[m-1] == Y[n-1]:
        return 1 + lcs(X, Y, m-1, n-1);
    else:
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));

for i in range(int(input())):
    m,n=map(int,input().split())
    X = input()
    Y = input()
    print(lcs(X , Y,m,n))
