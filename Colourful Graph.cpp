/*
You are given K colours and a directed graph with N nodes numbered from 1 to N and M edges (there are no self-loops and no multiple edges).

You have to colour the graph in such a manner that if two nodes u and v are linked in such a way that there is a path from u to v
and also from v to u, both nodes should have the same colour. Whereas either any of the two paths or both paths described above does
not exist between u and v , they shouldn't be of the same colour.

You have to find the number of ways in which you can colour the graph following the above-mentioned rules. If it is not possible to colour the graph, return -1.

Input:
The first line will contain T , number of test cases. Then the test cases follow.
The first line of each test case contains a single line of input, three space-separated integers K,N and M (the number of colours available, the number of nodes and the number of edges).
Next M lines contain two space-separated integers, u and v, denoting an edge between the two nodes.

Output:
For each test case, output the number of ways in which you can colour the graph modulo 1000000007.

Constraints
1≤T≤20
1≤K≤500
1≤N≤10^4
1≤M≤5∗10^4

Sample Input:
2
3 3 2
1 2
1 3
2 3 2
1 2
1 3

Sample Output:
6
-1

EXPLANATION:
For test case 1, there are no two nodes which have paths as mentioned in the problem statement, hence they all should be of different colours. So, the number of ways to colour them using 3 colours is 6.
For test case 2, we are in the same situation as test case 1 but now we have only 2 colours. Since we need to colour all the nodes differently, we can't do it in 2 colours. So, the answer is -1.

input:
3
4 4 1
1 3
2 2 4
1 2
1 3
2 5
3 6
1 1 3
1 2
2 3
3 4

output:
24
-1
-1

input:
1
4 5 6
1 2
1 3
2 4
3 5
3 7
4 8

output:
-1

input:
1
2 2 1
2 4

output:
-1

input:
1
1 1 2
1 2
2 3

output:
-1

hint:
Given a graph with N nodes and M - 1 edges. You have also been given K colours and you are required to find the number of ways to
colour the nodes which can be reached from-and-to each other using the same colour, and the ones not reachable in both ways, with
different colours.

*/
#include "bits/stdc++.h"
using namespace std;

#define int long long
#define F first
#define S second
#define rep(i,a,n) for (int i = a; i <= n; ++i)
#define fo(i, n)   for (int i = 1; i <= n; ++i)
#define all(v)  v.begin(), v.end()
#define pb push_back
#define P pair < int, int > 
#define fast  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
#define E cout << '\n'
const int N = 1e4 + 5;
const int mod = 1e9 + 7;
int mul(int x, int y) {
	return (1LL * x * y) % mod;
}
int add(int x, int y) {
	return (x + y) % mod;
}

int po(int x, int n) {
	int res = 1LL;
	while(n) {
		if(n & 1)
			res = mul(res, x);
		x = mul(x, x);
		n >>= 1LL;
	}
	return res;
}
int inv(int x) {
	return po(x, mod - 2);
}
int pre[5*N], vis[N];
vector < int > g[N], revg[N], v;
void pre1() {
	pre[0] = 1, pre[1] = 1;
	int x = 50004;
	for(int i = 1; i < x; ++i)
		pre[i] = mul(pre[i - 1], i);
}
inline void cl(int n) {
	for(int i = 1; i <= n; ++i) {
		g[i].clear();
		revg[i].clear();
		vis[i] = false;		
	}	
}
void dfs(int node) {
	vis[node] = 1;
	for(auto i : g[node])
		if(!vis[i])
			dfs(i);
	v.push_back(node);
}
void revdfs(int node) {
	vis[node] = true;
	for(auto i : revg[node])
		if(!vis[i])
			revdfs(i);
}
inline void solve() {
	int k, n, m, ans(0), l, r;
	cin >> k >> n >> m;
	for(int i = 1; i <= m; ++i) {
		cin >> l >> r;
		g[l].push_back(r);
		revg[r].push_back(l);
	}
	v.clear();
	for(int i = 1; i <= n; ++i) {
		if(!vis[i])
			dfs(i);
	}
	memset(vis, 0, sizeof vis);
	while(!v.empty()) {
		int i = v.back();
		if(!vis[i]) {
			++ans;
			revdfs(i);
		}
		v.pop_back();
	}
	if(ans > k)
		cout << -1 << '\n';
	else
		cout << mul(pre[k], inv(pre[k - ans])) << '\n';
	cl(n);
}
signed main(){  
   fast;
   pre1();
   int t;
   cin >> t;
   while(t--)
   	solve();
   return 0;
}   
