/*
Rehan is interested to solve series problems. Rehan wants to solve a series problem but he can't solve it till now.Can you help Rehan to solve the series problem?

    In series problem, the series goes as follows 1,9,31,73,141 . . . . . . . .

Your task is to find the Nth term of series. For larger value of N answer becomes very large, So your output should be performed Nth term modulo 1000000007 (10^9+7).

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single integer N.

Output:
For each testcase, output in a single line answer i.e. The N th term of series modulo 1000000007.

Constraints
1≤T≤10^5
1≤N≤10^9

Sample Input:
2
8
10

Sample Output:
561
1081

input:
4
5
12
45
2

output:
141
1849
93061
9

input:
2
121
21

output:
1785961
9661

input:
3
122
7
1555555

output:
1830489
379
132414772

input:
4
12323
99999
11111
212

output:
477360854
992900150
824383134
9572649

hint:
Nth term of the series = ((N-1)^2 + N^3). For larger value of N, the Nth term modulo (10^9 + 7).
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i, n) for (ll i = 0; i < n; i++)
#define dfor(i, a, b) for (ll i = (a); i < (b); i++)
#define rfor(i, a, b) for (ll i = (a); i >= (b); i--)
#define pii pair<ll, ll>
#define vi vector<ll>
#define vpii vector<pii>
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
const ll mod = (ll)(1e9 + 7);

int main()
{
    fast
        ll t;
    cin >> t;
    while (t--)
    {
        ll n, ans;
        cin >> n;
        ans = ((n - 1) * (n - 1)) + (n * n * n);
        ans = ans % mod;
        cout << ans << "\n";
    }

    return 0;
}