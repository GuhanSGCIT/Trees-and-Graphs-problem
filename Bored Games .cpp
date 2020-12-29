/*
Ram has recently been playing a lot of chess in preparation for the ICCT (International Ram Chess Tournament).
Since putting in long hours is not an easy task, Ram's mind wanders elsewhere. He starts counting the number of squares with odd side length on his chessboard..
However, Ram is not satisfied. He wants to know the number of squares of odd side length on a generic N∗N chessboard.

Input:
The first line will contain a single integer T, the number of test cases.
The next T lines will have a single integer N, the size of the chess board.

Output:
For each test case, print a integer denoting the number of squares with odd length.

Constraints
1≤T≤100
1≤N≤1000

Sample Input:
2
3
8

Sample Output:
10
120

input:
3
12
24
48

output:
364
2600
19600

input:
4
74
1524
6516354
65165465

output:
70300
591096100
-3074114762856317220
-4812725520984107603

input:
7
1
54856
32999
99
16
2
3

output:
1
27513441017656
5989499994500
166650
816
4
10

input:
1
999999

output:
166666666666500000

hint:
we can fit N−i+1 rods of length i in an N×N chessboard horizontally. Similarly, we can fit the same number of rods in the chessboard vertically, since it is a square and is symmetric.
If we consider these rods as the sides of the square of side iii, we have N−i+1 horizontal and vertical choices each. So, the number of squares of length i in a N×N chessboard is (N−i+1)^2.

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define pb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define len(a) int(a.size())
#define sqrt sqrtl

#ifdef ONLINE_JUDGE
#define endl "\n"
#endif

#define int ll
#define vll vector<int>
#define pll pair<int, int>
#define vvll vector<vll>
#define vpll vector<pll>

#define minpqll priority_queue<int, vector<int>, greater<int>>

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#ifndef ONLINE_JUDGE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}

#else
#define trace(...)
#endif // ifndef ONLINE_JUDGE

const double pi = 3.141592653589793238462643383279502884197169399375105820974944;
const double e = 2.71828182845904523536028747135266249775724709369995;
const int mod = 1e9 + 7;
const int inf = 2e18;
const int ninf = -2e18;
const int N5 = 1e5 + 10;
const int N6 = 1e6 + 10;

int power(int x, int y, int mod = inf)
{
    int ans = 1;
    x %= mod;
    while (y)
    {
        if (y & 1)
            ans = (x * ans) % mod;

        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    time_t t1, t2;
    t1 = clock();

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int N = n / 2;
        int t1 = 4 * (N * (N + 1) * (2 * N + 1) / 6);
        int t2 = n * (n + 1) * (2 * n + 1) / 6;

        if (n & 1)
            cout << t2 - t1 << endl;
        else
            cout << t1 << endl;
    }

    t2 = clock();
#ifndef ONLINE_JUDGE
    cerr << endl
         << "time taken: " << t2 - t1 << endl;
#endif // ONLINE_JUDGE

    return 0;
}