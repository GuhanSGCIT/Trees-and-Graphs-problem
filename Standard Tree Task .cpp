/*
The company structure of ShareChat can be viewed as a tree with N nodes (numbered 1 through N); node 1 is the root of this tree.
You should choose a (possibly empty) subset of nodes and place one coin in each node from this set. We call the tree proper
if the following condition holds:
    
    Consider two arbitrary disjont subtrees. Let's denote the total number of coins in one subtree by X and the total number of coins in the other subtree by Y.
    If X>0 and Y>0, the greatest common divisior (GCD) of X and Y must be 1.

Please calculate the number of different assignments of coins to nodes (different sets of nodes containing coins) such that the
resulting tree is proper. Since the answer could be very big, compute it modulo 10^9+7.

Note: A subtree is the tree formed by some node v and all (direct or indirect) descendants of v. Two subtrees are disjont if they do not have any common node.

timing:4
level:7

Input
The first line of the input contains a single integer N denoting the number of nodes in the tree.
The second line contains N−1 space-separated integers p2,p3,…,pN, where pi denotes the parent of node i.

Output
Print a single line containing one integer — the number of assignments of coins to nodes which form a proper tree, modulo 10^9+7.

Constraints
1≤N≤70
1≤pi<i
for each valid i

Input
5
1 1 2 3

Output
30

Explanation
There are only two ways to assign coins to nodes such that the resulting tree is not proper. Both contain coins in nodes 2 , 3, 4, 5 and one of them contains a coin in node 1 too

input:
6
2 5 4 1 2

output:
4

input:
7
1 1 2 2 3 3

output:
108

input:
8
4 8 7 5 1 1 6

output:
16

input:
11
4 2 1 5 5 6 3 2 7 9

output:
4
hint:
BitMasking on prime numbers up to $N/2$ is done for building DP states.
Dynamic Programming state is represented as ($u$, $X$, $M$), representing Number of possible ways to place $X$ coins in subtree of node u, such that mask all the subtrees are divisible by primes represented by mask $M$.
DP state is calculated from leaf to root, Every combination of mask is checked and number of ways are added accordingly (involving a number of tricks as explained below).
Final answer is represented as sum of all possible combinations of Number of coins and bitmasks corresponding to root.


*/
#include <bits/stdc++.h>
#define sz(x) ((int)x.size())
#define PB push_back
using namespace std;
const int PW = (1 << 11);
const int N = 75;
const int K = 11;
const int md = int(1e9) + 7;
vector<int> g[N];
bool mrk[N];
int n, res, primes[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int ans[N][N][PW], siz[N], fact[N], f[N][N][PW];
bool ok[N][PW];

int sum(int x, int y){
    x += y;
    if (x >= md)
        x -= md;
    return x;
}

void SUM(int &x, int y){
    x += y;
    if (x >= md)
        x -= md;
}

int mult(int x, int y) { return (1ll * x * y) % md; }

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

#ifdef _LOCAL
    freopen("in.txt","r",stdin);
#endif // _LOCAL

    cin >> n;

    for (int i = 1; i < n; i++){
        int p; cin >> p;
        p--;

        g[p].PB(i);
    }

    for (int i = 2; i <= n; i++)
    for (int j = 0; j < K; j++)
        if (i % primes[j] == 0)
            fact[i] |= (1 << j);

    for (int i = 0; i <= n; i++)
    for (int msk = 0; msk < PW; msk++)
        if ((fact[i] & msk) == 0)
            ok[i][msk] = 1;

    for (int v = n - 1; v >= 0; v--){
        f[v][0][0] = 1;
        f[v][1][0] = 1;

        siz[v] = 1;

        for (int u : g[v]){
            for (int old = siz[v]; old >= 0; old--)
            for (int omk = 0; omk < PW; omk++){
                if (f[v][old][omk] == 0) continue;

                int base = ((PW - 1) ^ omk);

                for (int nw = 1; nw <= siz[u]; nw++) {
                    if (!ok[nw][omk]) continue;

                    for (int mk = base; ; (mk = (mk - 1) & base)){
                        if (ans[u][nw][mk] == 0) {
                            if (mk == 0) break;
                            continue;
                        }

                        SUM(f[v][old + nw][omk | mk], mult(f[v][old][omk], ans[u][nw][mk]));

                        if (mk == 0) break;
                    }
                }
            }

            siz[v] += siz[u];
        }

        for (int cnt = 0; cnt <= siz[v]; cnt++)
        for (int msk = 0; msk < PW; msk++)
            SUM(ans[v][cnt][msk | fact[cnt]], f[v][cnt][msk]);
    }

    for (int cnt = 0; cnt <= n; cnt++)
    for (int msk = 0; msk < PW; msk++)
        res = sum(res, ans[0][cnt][msk]);

    cout << res;

    return 0;
}
