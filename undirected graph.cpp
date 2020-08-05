/*
You are given an undirected graph G = (V, E) containing N nodes and M edges. The nodes are numbered from 1 to N.
A subset C of V is a vertex cover if for every edge (u, v) ∈ E, at least one of u and v belong to C. Note that C = V is
always a vertex cover.

Consider a partition of V into two sets A and B. It is said to be a valid partition, if the following two conditions
are satisfied: A should be a vertex cover. And for each i such that 1 ≤ i ≤ n/2, nodes 2*i and 2*i - 1 don't belong to the
same set (i.e. one belongs to set A and the other to set B).

Determine if a valid partition exists. If it exists, provide an example of one valid partition.

timing:0.75sec
level:6
Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M denoting the number of nodes and number of edges
in the graph respectively.
Each of the following M lines contains two space-separated integers u and v denoting an edge between nodes u and v.

Output Description:
For each test case, print a line containing the string "possible" (without quotes) if a solution exists or "impossible" otherwise.
If a solution exists, print a second line containing a binary string. The i-th character of this string should be '0'
if vertex i is in set B or '1' if it is in set A.

Constraints
    1 ≤ T ≤ 10^5
    1 ≤ N ≤ 2·10^5
    0 ≤ M ≤ 2·10^5
    1 ≤ u, v ≤ N
    1 ≤ sum of N over all test cases ≤ 1066
    1 ≤ sum of M over all test cases ≤ 10^6

Input:
2
3 2
1 2
2 3
4 5
1 3
2 4
1 4 
1 2
2 3

Output:
possible
011
impossible

Explanation
Example case 1: We can put nodes numbered 2 and 3 in set A and node 1 in set B. Note that this is a valid partition
because set A is a vertex cover; also, nodes numbered 1 and 2 belong to different sets.
Example case 2: There exists no partition which satisfies the conditions.

Input:
1
5 5
1 2
2 4
2 3
3 5
3 4

output:
possible
01101

Input:
2
3 2
2 3
3 4
6 5
2 3
2 4
3 1
4 5
1 2

output:
possible
101
possible
011010

Input:
1
6 6
1 2
1 3
2 4
3 5
4 6
6 7

output:
possible
011001

Input:
1
2 2
1 3
3 4

output:
possible
10

code:
*/
#include<bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d", &x)
#define scll(x) scanf("%lld", &x)
#define ll long long 
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define sync std::ios::sync_with_stdio(false)
#define INF 0x3f3f3f3f
#define frein freopen("in.txt", "r", stdin)
#define freout freopen("out.txt", "w", stdout)
const int MAXN = 400010;
const int MAXM = 800010;
struct Edge {
    int to, nxt;
}edge[MAXM];
int head[MAXN], tot;
void init(int n) {
    tot = 0;
    for (int i = 0; i < n; i++) head[i] = -1;
}
void add(int u, int v) {
    edge[tot].to = v;
    edge[tot].nxt = head[u];
    head[u] = tot++;
}
bool vis[MAXN];
int s[MAXN], top;
bool dfs(int u) {
    if (vis[u^1]) return false;
    if (vis[u]) return true;
    vis[u] = true;
    s[top++] = u;
    for (int i = head[u]; i != -1; i = edge[i].nxt)
        if (!dfs(edge[i].to)) return false;
    return true;
}
bool twosat(int n) {
    for (int i = 0; i < n; i++) vis[i] = false;
    for (int i = 0; i < n; i += 2) {
        if (vis[i] || vis[i^1]) continue;
        top = 0;
        if (!dfs(i)) {
            while (top) vis[s[--top]] = false;
            if (!dfs(i^1)) return false;
        }
    }
    return true;
}
bool isok(int u, int v) {
    if (u == v + 1) {
        if (u % 2 == 0) return true;
    }
    if (v == u + 1) {
        if (v % 2 == 0) return true;
    }
    return false;
}
int main() {
    //sync;
    //frein;
    //freout;
    int t;
    sc(t);
    int n, m;
    while (t--) {
        sc(n), sc(m);
        init(2 * n);
        int u, v;
        for (int i = 0; i < m; i++) {
            sc(u), sc(v);
            u--;
            u *= 2;
            v--;
            v *= 2;
            add(u ^ 1, v);
            add(v ^ 1, u);
        }
        for (int i = 1; i <= n / 2; i++) {
            u = 2 * i;
            v = 2 * i - 1;
            u--;
            u *= 2;
            v--;
            v *= 2;
            add(u, v ^ 1);
            add(v, u ^ 1);
        }
        if (twosat(2 * n)) {
            printf("possible\n");
            for (int i = 0; i < 2 * n; i += 2) {
                if (vis[i]) printf("1");
                else printf("0");
            }
            printf("\n");
        }
        else printf("impossible\n");
    }
    return 0;
}
