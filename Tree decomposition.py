"""
Varun has developed a novel decomposition of a tree. He claims that this decomposition solves many difficult problems
related to trees. However, he doesn't know how to find it quickly, so he asks you to help him.

You are given a tree with N vertices numbered 1 through N. Let's denote an edge between vertices u and v by (u,v).
The triple-tree decomposition is a partition of edges of the tree into unordered triples of edges (a,b),(a,c),(a,d)
such that a≠b≠c≠d. Each edge must belong to exactly one triple.

Help Varun with this problem — find a triple-tree decomposition of the given tree or determine that no such decomposition exists.

level:6
tags:bfs dfs
timing:0.5-1sec

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
Each of the following N−1 lines contains two space-separated integers u and v describing an edge between vertices u and v of the tree.

Output Description:
For each test case, print a line containing the string "YES" if a triple-tree decomposition of the given tree exists or "NO"otherwise.
If it exists, print (N−1)/3 more lines describing a decomposition.
Each of these lines should contain four space-separated integers a, b, c and d describing a triple of edges (a,b),(a,c),(a,d).
If more than one triple-tree decomposition exists, you may output any one.

Constraints:
1≤T≤100
2≤N≤2⋅10^5
1≤u,v≤N
the sum of N over all test cases does not exceed 2⋅10^5.

Input:
2
4
1 2
1 3
1 4
7
1 2
2 3
1 4
4 5
1 6
6 7

Output:
YES
1 2 3 4
NO

Input:
3
3
1 2
1 3
6
1 2
1 3
3 4
2 2
3 5
2
1 2

Output:
NO
NO
NO

Input:
2
4
1 2
1 4
1 3
5
1 2
1 4
2 3
4 5

Output:
YES
1 2 4 3
NO

Input:
1
12
1 2
1 5
1 6
1 9
2 4
5 6
9 10
6 7
6 9
7 11
7 6

Output:
NO

Input:
1
3
1 2
2 1

Output:
NO

Hint:
The answer is NO if the number of edges is not divisible by 3. Now, we need to remove edges from the tree of the form as shown
in them. We need to recursively find a node which has three or more children that are leaf nodes,or a node which has exactly
two children which are leaf. Once, we find them, remove these edges marked E1, E2, and E3, and then repeat the process,
until no edges remain. Or print NO if at some stage, there exist no such nodes.


Solution:
"""
def dfs(u, p):
    l = []
    for v in g[u]:
        if v != p:
            r = dfs(v, u)
            if r == 1:
                return 1
            if r == 0:
                l.append(v)
                if len(l) == 3:
                    out.append([u] + l)
                    l = []
    if len(l) == 2:
        out.append([u] + l + [p])
    return len(l)

t=int(input())
for _ in range(t):
    n = int(input())
    g=[[] for _ in range(n + 1)]
    for _ in range(n - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    out = []
    if dfs(1, 0) == 0:
        print('YES')
        for l in out:
            print(*l)
    else:
        print('NO')
        
