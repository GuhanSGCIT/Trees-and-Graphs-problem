"""
You are given a weighted undirected graph consisting of n nodes and m edges. The nodes are numbered from 1 to n.
The graph does not contain any multiple edges or self loops.

A walk W on the graph is a sequence of vertices (with repetitions of vertices and edges allowed) such that every adjacent
pair of vertices in the sequence is an edge of the graph. We define the cost of a walk W, Cost(W), as the maximum over the weights
of the edges along the walk.

You will be given q queries. In each query, you will be given an integer X.
You have to count the number of different walks W of length 4 such that Cost(W) = X.
Two walks are considered different if they do not represent the same edge sequence.

Timing:0.55sec
level:6

Input Description:
First line contains 2 integers : the number of nodes n and number of edges m.
Next m lines each describe u, v and w, describing an edge between u and v with weight w.
Next line contains q, the number of queries.
Next q lines each describe an integer X- the cost of the walk in the query.

Output Description:
For each query, output in a single line the number of different possible walks.

Constraints
1≤n≤100
1≤m≤n(n−1)2
1≤u,v≤n
1≤w≤100
1≤q≤100
1≤X≤100

Input:
3 3
1 2 1
2 3 2
3 1 3
3
1
2
3

Output:
2
10
36

EXPLANATION:
For X=2, all possible 10 walks are listed below :
1 -> 2 -> 1 -> 2 -> 3
1 -> 2 -> 3 -> 2 -> 1
1 -> 2 -> 3 -> 2 -> 3
2 -> 1 -> 2 -> 3 -> 2
2 -> 3 -> 2 -> 1 -> 2
2 -> 3 -> 2 -> 3 -> 2
3 -> 2 -> 1 -> 2 -> 1
3 -> 2 -> 1 -> 2 -> 3
3 -> 2 -> 3 -> 2 -> 1
3 -> 2 -> 3 -> 2 -> 3

Input:
4 4
1 2 3 4
5 4 2 1
2 4 5 1
6 5 4 1
3
1
2
3

Output:
0
1
2

Input:
3 3
1 2 3
3 2 1
4 5 6
3
1
2
3

Output:
2
0
10

Input:
6 6
7 8 9 4 5 6
1 5 9 6 3 2
7 4 5 3 5 6
5 5 8 6 5 4
5 4 8 6 9 3
8 5 2 1 4 3
5
1
2
3
3
4

Output:
0
1
0
0
0

Input:
4 4
6 3 2 1
9 8 7 4
6 5 4 7
9 6 3 2
3
8
5
6

Output:
0
0
0
0

Solution:
"""
from collections import defaultdict

class sol():
    def __init__(self,n,edges):
        self.n = n
        self.edges = edges
        self.graph = self.create_graph()
        self.precompute()
        
    def create_graph(self):
        graph = defaultdict(list)
        for e in self.edges:
            u = e[0]
            v = e[1]
            w = e[2]
            graph[u].append([v,w])
            graph[v].append([u,w])
        return graph
        
    def precompute(self):
        self.maxiedges = [0]*6
        self.B = [[0 for i in range(101)] for i in range(101)]
        def func(u,v,l):
            if l==2:
                self.B[u][self.maxiedges[l]] += 1
            else:
                for j in self.graph[v]:
                    self.maxiedges[l+1] = max(self.maxiedges[l],j[1])
                    func(u,j[0],l+1)
        for i in range(1,self.n+1):
            func(i,i,0)
            
    def paths(self,X):
        freq = 0
        for u in range(1,self.n+1):
            for x in range(X+1):
                freq += 2*self.B[u][X]*self.B[u][x]
            freq -= self.B[u][X]*self.B[u][X]
        return freq
        
n, m = map(int, input().split())
edges = []
while m:
    uvw = list(map(int, input().split()))
    edges.append(uvw)
    m -= 1
q = int(input())
Graph = sol(n,edges)
while q:
    query = int(input())
    print(Graph.paths(query))
    q -= 1
