/*
In chennai, there are M types of cookies, numbered 1 through M. There is an infinite supply of cookies of each type.

Each morning, the Master cuisinier of chennai prepares a menu — a sequence of cookies. There may be multiple cookies with identical types in a menu. Two menus are considered different if the total number of cookies in one menu is different from their total number in the other menu or there is a valid index x
such that the type of the x-th cookie in one menu is different from the type of the x-th cookie in the other menu. For example, menus (1,2,1), (1,2,1,2) are different, and (1,1,2,3), (1,2,1,3) are also different.

To make things interesting, each morning, Master cuisinier receives three integers L, R and K. To prepare a menu on that morning, he may use a cookie of type x only if L≤x≤R and he may not use more than K cookies in total in this menu. For example, when L=3, R=5 and K=4, then (5,4,3,5) and (3,5,5) are possible menus, while (5,4,3,5,4) and (3,5,6) are not.

Moreover, a menu becomes special only if there is no integer x>1 that divides the type of each cookie in the menu, i.e. a menu S=(s1,s2,…,sn) is special if gcd(s1,s2,…,sn)=1.

You should process Q queries. In each query, you are given the parameters L, R and K for one morning. Master cuisinier wonders how many different special menus are possible. Can you help him calculate the number of possible special menus on each morning modulo 230 ?

Input
The first line of the input contains two space-separated integers M and Q.
Each of the next Q lines contains three space-separated integers L, R and K describing a query.

Output
For each query, print a single line containing one integer — the number of possible special menus modulo 230.

Constraints
1≤M≤10^5
1≤Q≤10,000
1≤L≤R≤M
1≤K≤10^9

Example Input
5 3
3 4 3
2 2 7
3 5 7

Example Output
8   
0   
3258

Explanation:
The eight possible menus for the first morning (first query) are (3,4), (4,3), (3,3,4), (3,4,3), (3,4,4), (4,3,4), (4,3,3), (4,4,3)

input:
10 2
5 10 15
7 8 9

output:
485869478
1004

input:
100 1
12 14 104

output:
421357386

input:
5 3
2 2 7
2 3 7
3 3 4


output:
0
240
0

input:
3 2
1 1 1
2 2 2

output:
1
0

hint:
calculate the number of ways to select K elements such that their gcd is one using g(d). Let’s define f(d) as the number of ways to select K elements in the range [L,R] such that their gcd is d. We want to calculate f(1) as expression of g(x) only.

*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 100005
#define MOD (1LL << 30)
#define ll long long int

ll Cum[MAX];
int mobius[MAX];

void Init()
{
    mobius[1] = 1;
    for (int i = 1; i < MAX; i++)
    {
        for (int j = i + i; j < MAX; j += i)
        {
            mobius[j] -= mobius[i];
        }
    }
    for (int i = 1; i < MAX; i++)
        Cum[i] = Cum[i - 1] + mobius[i];
}

ll GeoSum(ll a, int n)
{
    ll sz = 0;
    ll ret = 0;
    ll mul = 1;
    int MSB = 31 - __builtin_clz(n);

    while (MSB >= 0)
    {
        ret = ret * (1 + mul);
        sz <<= 1;
        mul = (mul * mul) % MOD;
        if ((n >> MSB) & 1)
            mul = (mul * a) % MOD, ret += mul;
        ret %= MOD;
        MSB--;
    }
    return ret;
}

ll Solve(ll b, ll d, ll k)
{
    vector<ll> vec;
    for (int i = 1; i * i <= b; i++)
    {
        vec.push_back(i);
        vec.push_back(b / i);
    }

    for (int i = 1; i * i <= d; i++)
    {
        vec.push_back(i);
        vec.push_back(d / i);
    }

    vec.push_back(0);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    ll Sum = 0;
    for (int i = 1; i < vec.size(); i++)
    {
        ll Curr = Cum[vec[i]] - Cum[vec[i - 1]];
        if (Curr < 0)
            Curr += MOD;
        ll Now = d / vec[i] - b / vec[i];
        Sum += (Curr * GeoSum(Now, k)) % MOD;
        if (Sum >= MOD)
            Sum -= MOD;
    }
    return Sum;
}

int main()
{
    Init();

    int m, q;
    scanf("%d %d", &m, &q);

    assert(1 <= m && m <= 100000);
    assert(1 <= q && q <= 10000);

    for (int cs = 1; cs <= q; cs++)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        assert(1 <= l && l <= r && r <= m);
        assert(1 <= k && k <= 1000000000);

        ll Ans = Solve(l - 1, r, k);
        printf("%lld\n", Ans);
    }
}