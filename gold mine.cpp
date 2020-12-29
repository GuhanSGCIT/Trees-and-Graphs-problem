/*
Ram belongs to a very rich family which owns many gold mines. Today, he brought N gold coins and decided to form a triangle using these coins. Isn't it strange?
Ram has a unusual way of forming a triangle using gold coins, which is described as follows:
    He puts 1 coin in the 1st row.
    then puts 2 coins in the 2nd row.
    then puts 3 coins in the 3rd row.
    and so on as shown in the given figure.

Ram is interested in forming a triangle with maximum possible height using at most N coins. Can you tell him the maximum possible height of the triangle?

Input
The first line of input contains a single integer T denoting the number of test cases.
The first and the only line of each test case contains an integer N denoting the number of gold coins Ram has.

Output
For each test case, output a single line containing an integer corresponding to the maximum possible height of the triangle that Ram can get.

Constraints
    1 ≤ T ≤ 100
    1 ≤ N ≤ 10^9

Input
3
3
5
7

Output
2
2
3

Explanation
Test 1: Ram can't form a triangle with height > 2 as it requires atleast 6 gold coins.
Test 2: Ram can't form a triangle with height > 2 as it requires atleast 6 gold coins.
Test 3: Ram can't form a triangle with height > 3 as it requires atleast 10 gold coins.

input:
4
120
144
1
135165

ouput:
15
16
1
519

input:
10
122
999999
1656
6596
654
9885
3524
2
12
1

ouput:
15
1413
57
114
35
140
83
1
4
1

input:
1
99999999

ouput:
14141

input:
3
1
2
3

ouput:
1
1
2

hint:
Maximum possible height of the triangle is the maximum possible value of HHH such that (H×(H+1))/2 ≤ N.

*/
#include <bits/stdc++.h>
// #include "testlib.h"
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define all(x) x.begin(), x.end()

#define ll long long int
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pii pair<int, int>
#define plii pair<pair<ll, int>, int>
#define piii pair<pii, int>
#define viii vector<pair<pii, int>>
#define vl vector<ll>
#define vll vector<pair<ll, ll>>
#define pll pair<ll, ll>
#define pli pair<ll, int>
#define mp make_pair
#define ms(x, v) memset(x, v, sizeof x)

#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)

#define scll1(x) scanf("%lld", &x)
#define scll2(x, y) scanf("%lld%lld", &x, &y)
#define scll3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)

#define pr1(x) printf("%d\n", x)
#define pr2(x, y) printf("%d %d\n", x, y)
#define pr3(x, y, z) printf("%d %d %d\n", x, y, z)

#define prll1(x) printf("%lld\n", x)
#define prll2(x, y) printf("%lld %lld\n", x, y)
#define prll3(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define pr_vec(v)                      \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";

#define f_in(st) freopen(st, "r", stdin)
#define f_out(st) freopen(st, "w", stdout)

#define fr(i, a, b) for (i = a; i <= b; i++)
#define fb(i, a, b) for (i = a; i >= b; i--)
#define ASST(x, l, r) assert(x <= r && x >= l)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const int mod = 1e9 + 7;

int ADD(int a, int b, int m = mod)
{
    int s = a;
    s += b;
    if (s >= m)
        s -= m;
    return s;
}

int MUL(int a, int b, int m = mod)
{
    return (1LL * a * b % m);
}

int power(int a, int b, int m = mod)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

ll nC2(ll x)
{
    return (x * (x - 1) / 2);
}

ll sum(ll x)
{
    return (x * (x + 1) / 2);
}

const int maxn = 1e5 + 5;

void solve()
{
    int t;
    sc1(t);
    while (t--)
    {
        int n;
        sc1(n);
        int ans = 0;
        while (sum(ans) <= n)
            ans++;
        cout << ans - 1 << "\n";
    }
}

int main()
{
    solve();
    return 0;
}