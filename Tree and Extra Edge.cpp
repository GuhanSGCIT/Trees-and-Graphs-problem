/*
You have a rooted tree consisting of n vertices. There are some weights on each edge of the tree denoted by Wi. The tree root is a
vertex with number 1.

In this problem, you need to answer Q queries. Each query is described by three values u, v, and x. It is guaranteed that subtrees of
node u and node v are disjoint. You are allowed to add at most one edge of weight x between any node in the subtree of u and any node
in the subtree of v. Find the maximum weighted path between u and v given that each node can occur only once in a path.

A subtree of some vertex is a subgraph containing that vertex and all its descendants.

timing:3sec
level:7

Input:
First line will contain T , number of testcases. Then the testcases follow.
First line of each testcase will contain N and Q, number of nodes and queries respectively.
Next N− 1 lines contain three integers u, v and Wi representing an edge between nodes u and v of weight Wi.
The next Q lines contain three integers u, v and x as explained in the problem statement.

Output:
For each query, output in a single line the maximum weighted path.

Constraints:
1≤T≤5
1≤n,q≤2∗10^5
1≤u,v≤n
1≤abs(Wi),x≤10^9

Input:
1
7 3
1 2 1
1 3 -2
2 4 3
2 5 -4
5 7 5
3 6 6
2 3 1
5 4 2
5 6 0

Output:
10
7
5

Explanation:
Query 1 : Its optimal to add a edge between nodes 4 and 6 making a path 2 -> 4 -> 6 -> 3 with a weight of 3 + 1 + 6 = 10.

input:
1
3 2
1 2 2
1 3 -1
2 1 3
5 4 2

output:
5
2

input:
1
3 3
2 3 -1
3 4 2
5 4 1
2 6 3
2 5 8

output:
1
3
8

input:
1
4 3
1 2 -1
2 3 1
2 4 -2
9 8 4
6 2 4
1 4 7

output:
4
5
7

input:
1
2 3
1 2 -1
2 4 6
8 9 5
4 7 8

output:
6
5
8

hint:
We will compare the weights of exactly two paths. 1) From u to LCA of (u,v) and from this LCA to v. 2) From the bottom-most node in the maximum weight subtree of u, connect an edge of weight x to the bottom-most node in the maximum weight subtree of v. The maximum of these two is the answer.

*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using ll = long long ;
using ld = long double;
using vll = vector<ll>;
using vvll = vector< vector<ll> > ;
using namespace __gnu_pbds;

#define fastio(); ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

const int MAX = 25;
const int maxS = 2e5+7;
vector<pair<ll, ll>> TREE[maxS];
bool visit[maxS];
ll H[maxS];
ll SAVE[maxS];
ll P[MAX][maxS];
ll H1[maxS];
void DFS(ll node, ll h , ll parent) {
    H[node] = h;
    SAVE[node] = 0;
    P[0][node] = parent;
    for(auto child: TREE[node]) {
        if(child.first != parent) {
            H1[child.first] = H1[node] + child.second;
            DFS(child.first, h+1, node);
            SAVE[node] = max(SAVE[node], SAVE[child.first] + child.second);
        }
    }
    return ;
}

void LCA_SETUP(int N) {
    for(int i = 1;i < MAX;i ++) {
        for(int j = 1;j <= N;j ++) {
            if(P[i-1][j] != 0) {
                P[i][j] = P[i-1][P[i-1][j]];
            }
        }
    }
}

int getLCA(int x, int y) {
    if(H[x] < H[y]) {
        swap(x, y);
    }
    for(int i = MAX-1;i >= 0;i --) {
        if(H[x]-(1<<i) >= H[y]) {
            x = P[i][x];
        }
    }
    if(x == y) {
        return x;
    }
    for(int i = MAX-1;i >= 0;i --) {
        if(P[i][x] != 0 && P[i][y] != 0 && P[i][x] != P[i][y]) {
            x = P[i][x];
            y = P[i][y];
        }
    }
    return P[0][x];
}

int main() {
    fastio();
 
    int T;
    cin >> T;
    while(T --) {
        int N, Q, u, v, x;
        cin >> N >> Q;
        for(int i = 0;i <= N;i ++) {
            TREE[i].clear();
            visit[i] = false;
            H[i] = 0;
            H1[i] = 0;
            SAVE[i] = 0;
        }
        for(int i = 0;i < MAX;i ++) {
            for(int j = 0;j < maxS;j ++) {
                P[i][j] = 0;
            }
        }
        for(int i = 0;i < N-1;i ++) {
            cin >> u >> v >> x;
            TREE[u].push_back({v, x});
            TREE[v].push_back({u, x});
        }
        DFS(1, 1, 0);
        LCA_SETUP(N);
        ll a, b, lca;
        while(Q --) {
            cin >> u >> v >> x;
            a = SAVE[u] + SAVE[v] + x;
            lca = getLCA(u, v);
            b = H1[u] + H1[v] - 2*H1[lca];
            cout << max(a, b) << "\n";
        }
    }
}
