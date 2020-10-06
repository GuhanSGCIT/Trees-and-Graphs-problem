/*
Varun is given a tree of N nodes. Let M denote the number of simple paths with at least two nodes. Notice that M = N * (N - 1) / 2.

There are (M * (M - 1) * (M - 2) / 6) unordered triples of such paths. Your task is to count how many of them are nice. A triple of paths (A, B, C) is nice if and only if either of the following conditions is satisfied:

    The three paths are pairwise disjoint (no two of them share a node).
    Each pair of paths intersect with each other. In other words: paths A and B share at least one node, paths A and C share at least one node, and also paths B and C share at least one node.

Output the number of nice triples of paths modulo (10^9+7).

Input
The first line of the input contains an integer N.
Each of the next N-1 lines contains two integers ai and bi denoting an edge between nodes ai and bi.

Output
Output a single integer, denoting the number of nice triples of paths modulo (10^9+7).

Input 1:
4
1 2
2 3
3 4

Output 1:
16



Explanation
Example test 1. Let (x, y) denote the simple path between nodes x and y. There are 16 nice triples of paths:
    (1, 2), (1, 3), (1, 4)
    (1, 2), (1, 3), (2, 3)
    (1, 2), (1, 3), (2, 4)
    (1, 2), (1, 4), (2, 3)
    (1, 2), (1, 4), (2, 4)
    (1, 2), (2, 3), (2, 4)
    (1, 3), (1, 4), (2, 3)
    (1, 3), (1, 4), (2, 4)
    (1, 3), (1, 4), (3, 4)
    (1, 3), (2, 3), (2, 4)
    (1, 3), (2, 3), (3, 4)
    (1, 3), (2, 4), (3, 4)
    (1, 4), (2, 3), (2, 4)
    (1, 4), (2, 3), (3, 4)
    (1, 4), (2, 4), (3, 4)
    (2, 3), (2, 4), (3, 4)

Input 2:
13
1 2
1 3
1 4
2 5
2 6
3 7
4 8
7 9
9 10
10 11
11 12
12 13

Output 2:
43484

input:
5
12 21
25 52
26 62
48 84

output:
0

input:
7
1 5
1 3
5 6
5 9
6 12
9 88


output:
958

input:
3
1 2
2 3

output:
1

hint:
The approach can be divided into two problems:
Computing the number of triples of paths, where all paths are pairwise intersecting, let’s call them intersecting triples.
Computing the number of triples of paths, where no two paths intersect, let’s call them disjoint triples.


*/
#include <bits/stdc++.h>
using namespace std;

const int nax = 3e5 + 5;
const int mod = 1e9 + 7;
vector<int> edges[nax];
long long dp_empty[nax][4], dp_single[nax][4], dp_doubled[nax][4];
int subtree[nax];
long long answer = 0;
int n;

void add_self(long long & a, long long b) { a = (a + b) % mod; }

// three disjoint paths
void dfs_dp(int a, int par) {
	dp_empty[a][0] = 1;
	for(int b : edges[a]) if(b != par) {
		dfs_dp(b, a);
		for(int s = 3; s >= 0; --s) {
			long long tmp_empty = 0, tmp_single = 0, tmp_doubled = 0;
			for(int i = 0; i <= s; ++i) {
				int j = s - i;
				tmp_empty += dp_empty[a][i] * dp_empty[b][j];
				tmp_single += dp_single[a][i] * dp_empty[b][j]
							+ dp_empty[a][i] * dp_single[b][j];
				tmp_doubled += dp_doubled[a][i] * dp_empty[b][j]
							+ dp_single[a][i] * dp_single[b][j];
			}
			dp_empty[a][s] = tmp_empty % mod;
			dp_single[a][s] = tmp_single % mod;
			dp_doubled[a][s] = tmp_doubled % mod;
		}
	}
	for(int i = 3; i >= 0; --i) {
		// consider this vertex and the LCA of some path:
		if(i != 3)
			add_self(dp_empty[a][i+1], dp_single[a][i] + dp_doubled[a][i]);
		// or start a new path going up:
		add_self(dp_single[a][i], dp_empty[a][i]);
	}
}

// three paths with a common vertex
void dfs_intersect(int a, int par) {
	subtree[a] = 1;
	long long count_paths = 0; // count paths going through this vertex
	for(int b : edges[a]) if(b != par) {
		dfs_intersect(b, a);
		count_paths += (long long) subtree[a] * subtree[b];
		subtree[a] += subtree[b];
	}
	count_paths %= mod;
	long long up = (long long) subtree[a] * (n - subtree[a]) % mod;
	long long all = (count_paths + up) % mod;
	// 'up' is the number of paths that go through vertex 'a' and move up
	// 'all' is the number of all paths going through 'a'
	
	auto choose3 = [&] (long long x) {
		// compute choose(x, 3) = x * (x - 1) * (x - 2) / 6
		vector<long long> list{x, x - 1, x - 2};
		for(int divide : vector<int>{2, 3})
			for(long long & component : list)
				if(component % divide == 0) {
					component /= divide;
					break;
				}
		return list[0] * list[1] % mod * list[2] % mod;
	};
	
	answer += choose3(all) - choose3(up);
	answer = (answer % mod + mod) % mod;
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs_dp(1, -1);
	dfs_intersect(1, -1);
	printf("%lld\n", (answer + dp_empty[1][3]) % mod);
}
