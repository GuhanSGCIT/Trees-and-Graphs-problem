/*
You are given a string S. Find the number of ways to choose an unordered pair of non-overlapping non-empty substrings of this string (let's denote them by s1 and s2 in such a way that s2 starts after s1 ends) such that their concatenation s1+s2 is a palindrome.
Two pairs (s1,s2) and (s′1,s′2) are different if s1 is chosen at a different position from s′1 or s2 is chosen at a different position from s′2.

Input
The first and only line of the input contains a single string S.

Output
Print a single line containing one integer — the number of ways to choose a valid pair of substrings.

Constraints
1≤|S|≤1,000
S contains only lowercase English letters

Example Input
abba

Example Output
7

Explanation
The following pairs of substrings can be chosen: ("a", "a"), ("a", "ba"), ("a", "bba"), ("ab", "a"), ("ab", "ba"), ("abb", "a"), ("b", "b").

input:
aaaasssss

output:
50

input:
2212122111

output:
88

input:
aabbab

output:
18

input:
aaabbbb

output:
20

hint:
Iterate pairs (i,j) to split S=AX ∣iBP∣j Xr C. Calculate longest possible ∣X∣ over splits with such (i,j) and multiply this value by number of suffix- and prefix-palindromes of the string BP.
*/
#include<bits/stdc++.h>
using namespace std;
long long dp1[1001][1001], dp2[1001][1001], ans[1001][1001], is_palin[1001][1001];
int main()
{
    //freopen("input14.txt","r",stdin);
    //freopen("output14.txt","w",stdout);
    string t;
    cin >> t;
    string s = '$' + t;
    int n = s.size();
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s.size(); j++)
        {
            dp1[i][j] = dp2[i][j] = ans[i][j] = is_palin[i][j] = 0;
        }
    }
    for(int k = 1; k < n; k++)
    {
        for(int j = k, i = 1; j < n; j++, i++)
        {
            if(s[i] == s[j])
            {
                if(j - i <= 2)
                {
                    is_palin[i][j] = 1;
                }
                else
                {
                    if(is_palin[i + 1][j - 1])
                    {
                        is_palin[i][j] = 1;
                    }
                }
            }
        }
    }
    for(int k = 1; k < n; k++)
    {
        for(int j = k, i = 1; j < n; i++, j++)
        {
            if(is_palin[i][j])
            {
                dp1[i][j] = dp1[i][j - 1] + 1;
            }
            else
            {
                dp1[i][j] = dp1[i][j - 1];
            }
        }
    }
    for(int k = n - 1; k >= 1; k--)
    {
        for(int j = k, i = k; i >= 1; i--)
        {
            if(is_palin[i][j])
            {
                dp2[i][j] = dp2[i + 1][j] + 1;
            }
            else
            {
                dp2[i][j] = dp2[i + 1][j];
            }
        }
    }
    for(int k = 1; k < n; k++)
    {
        for(int j = k, i = 1; j < n; i++, j++)
        {
            if(s[i] == s[j] && i != j)
            {
                if(j - i == 1) ans[i][j] = 1;
                else if(j - i == 2) ans[i][j] = 3;
                else
                {
                    ans[i][j] = 1 + ans[i + 1][j - 1] + dp1[i + 1][j - 2] + dp2[i + 2][j - 1];
                    if(is_palin[i + 1][ j - 1]) ans[i][j] += 2;
                }
            }
        }
    }
    long long result(0);
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            result += ans[i][j];
        }
    }
    cout << result << endl;
}