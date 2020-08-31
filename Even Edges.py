"""
Varun has a simple undirected graph with N vertices (numbered 1 through N) and M edges. He wants to divide it into K parts
(subgraphs) for some integer K.
First, Varun divides the vertices in the graph into K sets such that each vertex belongs to exactly one set; the subgraphs and sets
are numbered 1 through K such that for each valid i, vertices from the i-th set belong to the i-th subgraph. Then, Varun checks all
the edges in the graph. For an edge connecting vertices u and v, if u and v are both in the i-th set, then this edge belongs to the
i-th subgraph. Otherwise, this edge does not belong to any of these K subgraphs.

At the end, Varun checks these K subgraphs. If each subgraph contains an even number of edges, then Varun thinks that this way of
dividing the graph is delicious.

Varun wants to divide the graph in a delicious way such that K is the smallest possible. Find the minimum K and one such way to divide the graph.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
Each of the next M lines contains two space-separated integers u and v denoting that vertices u and v are connected by an edge.

Output
For each test case, print two lines. The first of these lines should contain a single integer ― the minimum K .
The second line should contain N space-separated integers, where for each valid i, the i-th integer denotes the subgraph that vertex belongs to.
If there are multiple solutions, you may output any one.

Constraints
1≤T≤3,000
1≤M≤100,000
2≤N≤100,000
1≤u≠v≤N
the graph contains no duplicate edges or self-loops the sum of N
over all test cases does not exceed 10^6
the sum of M over all test cases does not exceed 10^6

Input:
1
5 5
1 2
1 3
2 3
2 4
3 4

Output
2
1 2 1 1 1

Explanation
Subgraph 1 contains vertices 1, 3, 4 and edges (1,3) and (3,4). Subgraph 2 contains vertices 2 and 5, but no edges.

input:
1
5 5
1 2
1 3
2 4
3 4
4 5


output:
2
1 1 1 2 1

input:
1
3 3
1 1
2 2
3 3

output:
3
1 1 2

input:
1
2 2
1 2
2 1

output:
1
1 1

input:
1
6 6
1 2
1 3
2 4
2 5
3 4
5 6

output:
1
1 1 1 1 1 1

hint:
If the graph itself has an even number of edges, we can “divide” it into one set;
Otherwise, ∣E∣ must be odd. If the degree of some vertex v is odd, then we partition V into {v} and V−{v};
Otherwise we pick any edge (u,v)∈E, and partition V into {u}, {v} and V−{u,v}.


"""
for step in range(int(input())):
    n,m=map(int,input().split())
    A=[0]*(n+1)
    for i in range(m-1):
        u,v=map(int,input().split())
        A[u]+=1
        A[v]+=1
    u,v=map(int,input().split())
    A[u]+=1
    A[v]+=1
    if m%2==0:
        print(1)
        Ans=""
        for i in range(1,len(A)):
            Ans+="1 "
        print(Ans)
    if m%2!=0:
        flag=0
        for i in range(len(A)):
            if A[i]%2!=0:
                flag=1
                j=i
                break
        if flag==1:
            print(2)
            Ans=""
            for i in range(1,len(A)):
                if i==j:
                    Ans+="2 "
                else:
                    Ans+="1 "
            print(Ans)
        if flag==0:
            print(3)
            Ans=""
            for i in range(1,len(A)):
                if i==u:
                    Ans+="2 "
                elif i==v:
                    Ans+="3 "
                else:
                    Ans+="1 "
            print(Ans)
