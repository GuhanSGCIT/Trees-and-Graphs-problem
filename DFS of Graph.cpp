/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach.

Input:
The first line of the input contains an integer 'T' denoting the number of test cases. Then 'T' test cases follow.
Each test case consists of two lines. Description of testcases is as follows:
The First line of each test case contains two integers 'N' and 'E'  which denotes the no of vertices and no of edges respectively.
The Second line of each test case contains 'E'  space separated pairs u and v denoting that there is a edge from u to v .

Output:
For each testcase, print the nodes while doing DFS starting from node 0.


Constraints:
1 <= T <= 100
2 <= N <= 104
1 <= E <= (N*(N-1))/2
Graph doesn't contain multiple edges and self loops.

Input:
2
5 4
0 1 0 2 0 3 2 4
4 3
0 1 1 2 0 3

Output:
0 1 2 4 3   
0 1 2 3

Explanation:
Testcase 1:
0 is connected to 1 , 2 , 3
1 is connected to 0
2 is connected to 0 and 4
3 is connected to 0
4 is connected to 2
so starting from 0 , dfs will be 0 1 2 4 3.

input:
1
4 4
0 1 1 0 0 3 1 2

output:
0 1 2 3

input:
2
3 2
2 0 1 2
5 2
1 3 0 1

output:
0 2 1 
0 1 3 2 4

input:
1
5 4
1 2 0 2 0 3 2 4

output:
0 2 1 4 3

input:
1
4 3
0 3 0 2 1 2

output:
0 3 2 1

hint:
Think in terms of going in depth from each node recursively.

*/
void DFSUtil (int i, vector <int> g[], int N, bool vis[], vector <int> &res)
{
    if (vis[i]) return;
    vis[i] = true;
    res.push_back (i);
    
    for (int j : g[i])
    {
        if (!vis[j]) DFSUtil (j, g, N, vis, res);
    }
}

vector <int> dfs(vector<int> g[], int N)
{
    bool vis[N];
    memset (vis, false, sizeof (vis));
    
    vector <int> res;
    for (int i = 0;i < N; i++)
    {
        if (!vis[i])
        {
            DFSUtil (i, g, N, vis, res);
        }
    }
    
    return res;
}

