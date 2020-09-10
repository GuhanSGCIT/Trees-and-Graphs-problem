/*
Varun decided to make a big picnic. He chose a beautiful place for this special event. Then, Varun placed N picnic baskets on the
ground at some points. The only thing remaining is placing some picnic blankets underneath the baskets in such a way that each basket
lies on at least one blanket (the blankets are allowed to overlap and each basket may lie on more than one blanket).

Each picnic blanket can be represented as an axis-aligned square. Varun may place any number of blankets on the ground, arbitrarily
and independently choosing the side length of each blanket. However, for each blanket, there must be at least three baskets lying on it.

Your task is to help Varun with the preparations by minimizing the size of the largest blanket.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of baskets.
Each of the following N lines contains two space-separated integers X and Y denoting the coordinates of one basket.

Output
For each test case, print a single line containing one integer — the minimum possible side length of the largest blanket (the blanket with the maximum side length).

Constraints
1≤T≤5
3≤N≤10^4
0≤X,Y≤10^9

Example Input
2
4 
1 1 
1 2 
2 2 
3 5
3 
1 1 
11 1
1 43

Example Output
3
42

Explanation
Example case 1: Chef can place two picnic blankets on the ground. The first blanket has two opposite corners at points (1,1)
and (2,2), the second blanket at points (1,2) and (4,5). Then, the largest blanket (blanket 2) has side length 3.

input:
3
3
2 5
3 6
1 2
2
1 2
2 3
3
1 1
2 2
3 3

output:
4
1000000000
2

input:
1
3
1 2
2 3
4 5

output:
3

input:
1
2
1 1
2 2

output:
1000000000

input:
1
5
1 2
3 6
5 4
7 8
8 9

output:
5

hint:
Let’s binary search the answer, let the current proposed answer is DDD. Imagine you placed all the possible squares with side equal to DDD, how to check that they cover all the points?
The main observation is that any intersection of three squares contains at least one corner of some square inside it.

*/
#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mt make_tuple
#define f first
#define s second

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())

#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { if (b < a) { a = b; return 1; } return 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

// const int INF = (int)2e9;
const int maxn = 2e4 + 5, inf = 2e9;

int n;

int x[maxn], y[maxn];

vector<int> tmp;
int szh(int y) {
    return lower_bound(all(tmp), y) - tmp.begin();
}

vector<pair<int, int> > ev;
vector<pair<int, int> > ev2;
int res[maxn];

int t[maxn];
void add(int pos, int val) {
    for (int i = pos + 1; i < maxn; i += i & -i)
        t[i] += val;
}
int get(int r) {
    int ans = 0;
    for (int i = r + 1; i > 0; i -= i & -i)
        ans += t[i];
    return ans;
}

int l[maxn], r[maxn];

bool can(int d) {
    ev.clear();
    tmp.clear();
    ev2.clear();

    for (int i = 0; i < n; i++) {
        tmp.pb(y[i]);
        tmp.pb(y[i] - d);
    }
    sort(all(tmp));
    tmp.resize(unique(all(tmp)) - tmp.begin());
    for (int i = 0; i < n; i++) {
        l[i] = szh(y[i] - d);
        r[i] = szh(y[i]);

        ev.eb(x[i] - d, i);
        ev.eb(x[i] + 1, -i - 1);

        ev.eb(x[i] - d, inf + i);
        ev.eb(x[i],     inf + i);

        ev2.eb(x[i] - d - 1, - i - 1);
        ev2.eb(x[i], i);
    }

    sort(all(ev));
    memset(t,0,sizeof(t));
    for(auto e:ev) {
        int x = e.f;
        int k = e.s;

        if (k >= inf) {
            int i = k - inf;

            int cur = get(l[i]);
            if (cur >= 3) {
                ev2.eb(x, -inf - l[i]);
            }

                cur = get(r[i]);
            if (cur >= 3) {
                ev2.eb(x, -inf - r[i]);
            }
        } else if (k >= 0) {
            add(l[k], 1);
            add(r[k] + 1, -1);
        } else {
            k = -k - 1;
            add(l[k], -1);
            add(r[k] + 1, +1);
        }
    }

    sort(all(ev2));
    memset(t,0,sizeof(t));
    memset(res, 0, sizeof(res));
    for (auto e:ev2){
        int x = e.f;
        int k = e.s;

        if (k <= -inf) {
            int ps = -k-inf;
            add(ps, 1);
        } else if (k >= 0) {
            res[k] += get(r[k]) - get(l[k] - 1);
        } else {
            k = -k-1;
            res[k] -= get(r[k]) - get(l[k] - 1);
        }
    }

    bool ok = 1;
    rep(i, 0, n) {
        if (res[i] == 0)
            ok = 0;
    }
    return ok;
}

void gen() {
    ofstream cout("input.txt");
    int n = rand() % 1 + 5;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() % 10 << ' ' << rand() % 10 << endl;
    }
}

void solve() {
	cin >> n;

    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    
    int l = 0, r = (int)1e9;
    while (r - l > 0) {
        int m = (l + r) >> 1;
        if (can(m))
            r = m;
        else
            l = m + 1;
    }

    cout << l << endl;
}

int main() {
    srand(time(0));
    // gen();

    // freopen("input.txt", "r", stdin);
    // freopen("out2.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--)
    	solve();
    return 0;
}
