/*
You are given a sequence of integers A1,A2,…,AN. You may change any number of its elements (possibly zero), obtaining a new sequence
of positive integers B1,B2,…,BN. Each element of B must be an integer between 2 and 50 (both inclusive).

Let's define an undirected graph G with N vertices (numbered 1 through N). For each pair of different vertices i and j, there is an
edge between i and j if and only if Bi and Bj are coprime.

You should choose the sequence B in such a way that G is a connected graph. The number of elements which need to be changed to obtain
B from A should be minimum possible. Find one such sequence B and the minimum required number of changes.

It can be proven that a solution always exists — it is always possible to modify sequence A in such a way that G is connected.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output
For each test case, print two lines. The first line should contain a single integer — the minimum required number of changes.
The second line should contain N space-separated integers B1,B2,…,BN — the modified sequence.
If there are multiple solutions, you may print any one.

Constraints
1≤T≤3⋅10^4
1≤N≤50
2≤Ai≤50
for each valid i

Input
2
2
2 3
2
2 4

Output:
0
2 3
1
2 29

Explanation:
Example 1: There is an edge in G between vertices 1 and 2. This graph is connected, so there is no need to change any elements.
Example 2: There is no edge between vertices 1 and 2 since gcd(2,4)≠1. This graph is not connected. We can change element A2=4 to 3 and make this graph connected.

input:
3
2
4 6
3
2 4 6
2
4 5

output:
1
4 29
1
2 4 29
0
4 5

input:
1
2
2 4

output:
1
2 29

input:
2
4
1 2 3 4
3
12 33 44

output:
0
1 2 3 4
1
12 33 29

input:
1
5
5 4 3 2 1

output:
0
5 4 3 2 1

hint:
Use union disjoint sets to check whether the graph is already connected.
If the graph is connected, print the array. Otherwise, It can be proved that changing exactly one element in the array can make the graph connected.
Choose one position in the array, replace it with a prime not used in the array. (Prime not used can be found by the sieve, and are guaranteed to exist since the graph is connected.)


*/
#include <bits/stdc++.h>

using namespace std;

const int MaxN = (int)5e1 + 10;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

int n, a[MaxN];
int who[MaxN];

int getWho(int v) {
	return v == who[v] ? v : who[v] = getWho(who[v]);
}

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		who[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (__gcd(a[i], a[j]) == 1) {
				who[getWho(i)] = getWho(j);
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += getWho(i) == i;
	}
	if (cnt == 1) {
		cout << "0\n";
	} else {
		cout << "1\n";
		bool yeah = false;
		for (int i = 1; i <= n; ++i) {
			if (a[i] != 29) {
				yeah = true;
			}
		}
		if (yeah) {
			a[n] = 29;
		} else {
			a[n] = 31;
		}
	}
	for (int i = 1; i <= n; ++i) {
		who[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (__gcd(a[i], a[j]) == 1) {
				who[getWho(i)] = getWho(j);
			}
		}
	}
	cnt = 0;
	for (int i = 1; i <= n; ++i) {
		cnt += getWho(i) == i;
	}
	assert (cnt == 1);
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << (i == n ? '\n' : ' ');
	}
}

int main() {
//	freopen("input.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t --> 0) {
		solve();
	}
	return 0;
}

