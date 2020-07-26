"""
    There is only little time left until the New Year! For that reason, Pavan decided to make a present for his best friend.
He made a connected and undirected simple graph with N vertices and M edges.

    Since pavan does not like odd numbers and his friend does not like undirected graphs, pavan decided to direct each edge
in one of two possible directions in such a way that the indegrees of all vertices of the resulting graph are even.
The indegree of a vertex is the number of edges directed to that vertex from another vertex. As usual, pavan is busy
in the kitchen, so you need to help him with directing the edges. Find one possible way to direct them or determine
that it is impossible under the given conditions, so that pavan could bake a cake as a present instead.

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
M lines follow. For each i (1≤i≤M), the i-th of these lines contains two space-separated integers ui and vi
denoting an edge between vertices ui and vi.

Timing:1.52sec
level:7

Output Description:
For each test case:
If a valid way to direct the edges does not exist, print a single line containing one integer −1.
Otherwise, print a single line containing M space-separated integers. For each valid i, the i-th of these integers
should be 0 if edge i is directed from ui to vi or 1 if it is directed from vi to ui.

Constraints
1≤T≤5
1≤N,M≤105
1≤ui,vi≤N
for each valid i
the graph on the input is connected, does not contain multiple edges or self-loops

Input:
2
4 4
1 2
1 3
2 4
3 4
3 3
1 2
2 3
1 3

Output:
0 0 1 1
-1

Expalnation:
Direct edges in arbitrary way. Now you may choose any path in initial graph and inverse all edges on this path.
In such way you will change indegrees only of first and last vertices on the path,
thus you may group vertices of odd indegrees in pairs and get rid of them.
Input:
1
5 5
1 2
2 1
2 3
3 4
2 1

Output:
-1

Input:
1
4 4
1 2
2 1
1 2
2 1
 
Output:
0 0 0 0

Input:
1
5 5
1 2
1 4
1 3
2 4
2 3

Output:
-1

Input:
3
3 3
1 2
2 1
0 1
2 1
0 1
4 4
1 2
2 1
1 3
2 3

Output:
-1
-1
0 1 0 0

Solution:
"""
for _ in range(int(input())):
    l=[]
    mp={}
    cr={}
    ans=[]
    n,m=map(int,input().split())
    for i in range(1,n+1):
        mp[i]=0
        cr[i]=False
    for _ in range(m):
        f,t=map(int,input().split())
        l.append((f,t))
        mp[f]+=1
        mp[t]+=1
    if m%2>0:
        print(-1)
        continue
    else:
        for _ in range(m):
            cr[l[_][1]]=not cr[l[_][1]]
            ans.append(0)
        for _ in range(m-1,-1,-1):
            if cr[l[_][1]]==True:
                cr[l[_][1]]=not True
                ans[_]=1
                if cr[l[_][0]]:
                    cr[l[_][0]]=False
                else:
                    cr[l[_][0]]=True
        for i in range(len(ans)):
            print(ans[i],end=' ')
        print()
    
