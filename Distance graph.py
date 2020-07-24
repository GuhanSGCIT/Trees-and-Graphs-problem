"""
Question:
You will be given a tree represented by a matrix. The jth character of ith row will be 1 if there is a path from node i to j.

You will also be given two integers N and F. N is the number of nodes in the tree and F(0 based index) is the node to
which you need to find the distance from the root node. Root node will always be 0. Print the distance of the node F from the root.

Input Description:
First line will contain an integer T, the count of test cases. Each test case will start with
two space separated integers, N and F, in a newline. N lines will follow each of length N.
Each character of these lines will be either 0 or 1.

Output Description:
Output must contain T lines, each having the distance of the node F from root node 0 for each tree.

Testcases:
Input:
2
1 0
0
9 6
011000000
000111000
000000111
000000000
000000000
000000000
000000000
000000000
000000000

Output:
0
2

Explanation:
Example case 1. Since there is only one node which is the root the distance is 0.
Example case 2. Path to node 6 is 0->2->6, thus distance is 2.

Input:
1
5 2
01010
11000
10000
01000
00001

Output:
1

Input:
2
1 1
1
10 5
0000000000
1000000000
0100000000
0000001000
0000000000
0010000000
0000000000
0000000000
1010101010
0000000000

Output:
0
0

Input:
3
1 0
0
2 2
01
11
3 4
001
100
001

Output:
0
1
1

Input:
2
2 1
01
10
3 1
001
111
000

Output:
1
1

Solution:

"""
def bfs(s, e, g):

    visited = [0]*len(g)   
    queue = []
    s = (s, 0)
    queue.append(s)
    while len(queue) > 0 and s[0]!=e:
        s = queue.pop(0)
          
        visited[s[0]] = 1
        for i in range(len(g)):
            if not visited[i] and g[s[0]][i]:
                
                queue.append((i, s[1]+1))
    print(s[1])

t = int(input())
for __ in range(t):
    n, f = map(int, input().split())
    g = [[0 for i in range(n)] for j in range(n)]
    for i in range(n):
        g[i]= list(map(int, list(input())))
    bfs(0, f, g)
    
