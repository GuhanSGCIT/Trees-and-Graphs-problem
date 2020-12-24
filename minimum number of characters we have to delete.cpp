/*
We say that a binary string (a string containing only characters '0' and '1') is pure if it does not contain either of the strings "0101" or "1010" as a subsequence.
Recall that string T is a subsequence of string S if we can delete some of the letters of S (possibly none) such that the resulting string will become T.
You are given a binary string S with length N. We want to make this string pure by deleting some (possibly zero) characters from it. What is the minimum number of characters we have to delete?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single string S with length N.

Output
For each test case, print a single line containing one integer — the minimum number of characters we have to delete from S.

Constraints
1≤T≤40
1≤N≤1,000
S contains only characters '0' and '1'

Example Input
4
010111101
1011100001011101
0110
111111

Example Output
2
3
0
0

Explanation:
Example case 1: We can delete the first and third character of our string. There is no way to make the string pure by deleting only one character.
Example case 3: The given string is already pure, so the answer is zero.

input:
3
10101111010
1111111
000000001

output:
3
0
0

input:
4
101000101
1000000001
1011111011010110101000
111001111011111100000

output:
2
0
6
3

input:
1
01101

output:
1

\input:
5
1
0
100001001100
11101011
111111

output:
0
0
2
1
0

hint:
A string is pure if and only if there are at most 333 maximal blocks of consecutive equal characters in the string.
We can calculate the number of 000's and 111's of an interval using partial sum (or dynamic programming).
We can fix the endpoints of the 333 maximal blocks along with their character (000 or 111) and calculate the minimum number of indices which should be deleted in this configuration of blocks using partial sums.

*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int q, n, P[2][N];
char S[N];
int main()
{
    scanf("%d", &q);
    for (; q; q--)
    {
        scanf("%s", &S[1]);
        n = strlen(S + 1);
        for (int i = 1; i <= n; i++)
            for (int w = 0; w <= 1; w++)
                P[w][i] = P[w][i - 1] + (S[i] == w + '0');
        int Mn = n;
        for (int w = 0; w <= 1; w++)
            for (int i = 1; i <= n; i++)
                for (int j = i; j <= n; j++)
                    Mn = min(Mn, P[w][i - 1] + (j - i + 1) - (P[w][j] - P[w][i - 1]) + (P[w][n] - P[w][j]));
        printf("%d\n", Mn);
        memset(S, 0, sizeof(S));
        memset(P, 0, sizeof(P));
    }
    return 0;
}