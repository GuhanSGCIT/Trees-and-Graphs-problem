/*
The Royal Bank of Black Money Island wants to construct ATMs so that the citizens can withdraw black money easily for their day-to-day needs. The capital city can be represented as a number of checkpoints connected by a network of roadways, each of which have ATMs present on them. The capital has somewhat equal distribution of ATMs on the roads. Each roadway has either A ATMs or A + 1 ATMs present on it. The capital city is connected, i.e. there exists a path between every pair of checkpoints.
The Mayor of Black Money Island thinks that the current network of roads and checkpoints is too complicated. He wants to keep only a subset of the roads and shut the rest down. Formally, he wants to select a subset of these roads such that in the resulting network, there is exactly one way to go from any checkpoint to any other. However, due to monetary restrictions (some very weird ones at that), he wants to select a subset of roads such that there is a total of exactly X ATMs on the selected roads. Since the good people at the bank are busy siphoning black money, they have hired you, the local municipal expert, to help them.

Input
The first line of the input contains three space separated integers N, E and A, where N denotes the number of checkpoints, E denotes the number of roads in the city respectively, and A signifies that each road has either A ATMs or A + 1 ATMs.
Each of the next E lines contains three integers U, V and W denoting that there exists a bidirectional road between checkpoints U and V with W ATMs on it. It is guaranteed that U and V are not the same, and that each pair of checkpoints are connected by at most one roadway
The next line contains an integer Q denoting the number of queries.
Each of the next Q lines contains an integer X denoting the required number of ATMs in the selected road network.

Output
For each query, you should output 2 lines. Note that this means that your entire output would be 2 * Q lines.
The first line of output for each query should be 1 if it is possible to find a valid subset of roads satisfying the conditions mentioned above. Otherwise, you should print 0.
If there exists a valid subset, you must print the roads used in that subset in the second line. Formally, you must print a set of distinct integers S. S contains P if the Pth edge (1-indexed as per the input) is in the selected road network. If a valid subset doesn't exist, you must print -1 on the second line.
If there are multiple solutions, you can output any one of them!

Constraints
    2 ≤ N ≤ 10^5
    1 ≤ E ≤ 10^5
    0 ≤ A ≤ 10^9
    1 ≤ U, V ≤ N
    U ≠ V
    A ≤ W ≤ A + 1
    1 ≤ Q ≤ 20
    1 ≤ X ≤ 10^18
    Each pair of checkpoints are connected by at most one roadway.

Input:
5 5 5
1 2 5
1 3 5
3 4 6
3 5 6
4 5 5
2
21
20

Output:
1
3 1 2 5 
0
-1

Explanation:
For the first query, we can take roads 3, 1, 2 and 5. In the resulting network, we can see that there is exactly one path between any 2 checkpoints. The total number of ATMs in this network are 5 + 5 + 6 + 5 = 21. Thus, it satisfies all the requirements. Note that 1, 2, 4 and 5 is also a valid subset of roads.
For the second query, it is impossible to satisfy all requirements. 

input:
7 5 3
1 2 3
2 3 4
2 3 3
2 4 4
4 5 6
3
11
12
13

output:
0
-1
0
-1
0
-1

input:
3 2 3
1 2 1
2 3 2
3
3
12
24

output:
0
-1
0
-1
0
-1

input:
5 5 5
2 3 4
2 4 5
1 2 4
2 5 6
3 5 6
2
12
24

output:
0
-1
0
-1

input:
2 3 2
1 2 5
1 3 5
2 4 6
2
21
20

output:
0
-1
0
-1

hint:
The first step of the solution is to reduce the edge weights to 0 and 1, by subtracting edge weights by A. X can be subtracted by (N−1)∗A.
To construct a valid solution, find E^* i.e. a set of weight 1 edges that must be present in any spanning tree of G. If there exists multiple options for E^*, find any one of them.
Then, simulate Kruskal’s again, but this time start with edges in E^*. Then add more weight 1 edges until your spanning tree has weight X. Finally finish off with weight 0 edges.
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 50;

struct edge {
    int u, v, w;
    int id;
};

int n, e, a, q;
int parent[N];
vector < edge > ones, zero;

inline int root(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        return parent[x] = root(parent[x]);
    }
}

inline void solve(long long target) {
    if (target < 0 || target >= n) {
        cout << "0\n-1\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    vector < edge > necessary_ones;
    for (edge cur : zero) {
        int x = root(cur.u);
        int y = root(cur.v);
        if (x != y) {
            parent[y] = x;
        }
    }
    for (edge cur : ones) {
        int x = root(cur.u);
        int y = root(cur.v);
        if (x != y) {
            necessary_ones.push_back(cur);
            parent[y] = x;
        }
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    int ATMs = 0;
    vector < int > solution;
    for (edge cur : necessary_ones) {
        int x = root(cur.u);
        int y = root(cur.v);
        if (x != y) {
            parent[y] = x;
            ATMs++;
            solution.push_back(cur.id);
        }
    }
    for (edge cur : ones) {
        int x = root(cur.u);
        int y = root(cur.v);
        if ((x != y) && (ATMs < target)) {
            ATMs++;
            parent[y] = x;
            solution.push_back(cur.id);
        }
    }
    for (edge cur : zero) {
        int x = root(cur.u);
        int y = root(cur.v);
        if (x != y) {
            parent[y] = x;
            solution.push_back(cur.id);
        }
    }
    if (ATMs == target) {
        cout << "1\n";
        for (int id : solution) {
            cout << id << " ";
        }
        cout << "\n";
    } else {
        cout << "0\n-1\n";
    }
}

int main() {
    cin >> n >> e >> a;
    for (int i = 1; i <= e; i++) {
        edge cur;
        cin >> cur.u >> cur.v >> cur.w;
        cur.w -= a; cur.id = i;
        if (cur.w == 1) {
            ones.push_back(cur);
        } else {
            zero.push_back(cur);
        }
    }
    cin >> q;
    while (q--) {
        long long x; cin >> x;
        x -= (n - 1) * 1LL * (a);
        solve(x);
    }
}
