""" 
Question:
  You are given a rooted tree consisting of N nodes. The nodes are numbered from 1 to N, and node 1 is the root. At each node of the tree,
you can put zero or one coin such that the following property is satisfied for the tree:
    For each node of the tree, starting from the original configuration, we should be able to get two coins on the node by applying at most two operations of the 
following kind:
    Take a coin from a node and move it to an adjacent node.
    While trying to get to a particular node, if the same coin is moved in two operations, both those operations should either be towards the root,
or both of them should be away from the root. That is, you cannot move a coin to its parent in one operation and then take it to another child of the parent
in the second operation.

Find the minimum total number of coins which can be used to get a valid configuration.

timing:3 sec
level:7

Input Description:
The first line of the input contains an integer T.
For each test case, the first line contains an integer N.
Each of the next N - 1 lines, contains two space separated integers u, v, denoting that there is an edge between node u and node v of the tree.

Output description:
For each test case, output a single integer corresponding to the minimum number of coins that can be used. If it's not possible to achieve this, output -1.

Testcases:
Input:
2
3
1 2
1 3
5
1 2
1 3
3 4
3 5

Output:
3
4


Input:
1
4
1 3
1 4
3 4

Ouput:
2

Input:
1
9
1 5 
1 6
1 3
1 2
2 4
4 8
3 4
4 7

output:
7

INput:
2
2
1 1
5
1 2 
1 3
1 4
2 3

Output:
1
3

Input:
1
6
1 5
2 3
4 5
2 5
4 6

Output:
4

Solution:
"""
import sys
sys.setrecursionlimit(100010)
 
def dfs(start):
    global totsum, visit
    visit[start] = True
    if num[start] == 1 and start != 1:
        totsum = totsum + 1
        return [af(1,0), af(0,0),af(1,0)]
    flexibleRequirements = af(0,0)
    hardRequirements = af(0,0)
    canHelp = af(0,0)
    z1 = 0
    z2 = 0
    y1 = 0
    y2 = 0
    x1 = 0
    x2 = 0
    for child in tree[start]:
        if visit[child]:
            continue
        result = dfs(child)
        z1 = z1 + result[0].oneLevel
        z2 = z2 + result[0].twoLevel
        y1 = y1 + result[1].oneLevel
        y2 = y2 + result[1].twoLevel
        x1 = x1 + result[2].oneLevel
        x2 = x2 + result[2].twoLevel
 
    if start == 1:
        if z1 != 0 or z2!= 0 or y1 != 0 or y2 != 0:
            totsum = totsum + 1
        elif x1 < 2:
            totsum = totsum + 1
        return
    else:
        if z2> 0 or y1 > 0 or y2 > 0:
            totsum = totsum + 1
            if x1 == 0 and x2 == 0:
                return [af(1,0), af(0,0), af(1,0)]
            else:
                return [af(0,0), af(0,0), af(1,x1)]
        elif z1 > 0:
            if x1 == 0:
                totsum = totsum + 1
                if x2 == 0:
                    return [af(1,0), af(0,0), af(1,x1)]
                else:
                    return [af(0,0), af(0,0), af(1,x1)]
            elif x1 == 1:
                return [af(0,0), af(1,0), af(0,x1)]
            else:
                return [af(0,0), af(0,z1), af(0,x1)]
        else:
            if x1 == 0:
                totsum = totsum + 1
                if x2 == 0:
                    return [af(1,0), af(0,0), af(1,x1)]
                else:
                    return [af(0,0), af(0,0), af(1,x1)]
            elif x1 == 1:
                return [af(0,0), af(1,0), af(0,x1)]
            else:
                return [af(0,0), af(0,0), af(0,x1)]

class af(object):
    def __init__(self, oneLevel, twoLevel):
        self.oneLevel = oneLevel
        self.twoLevel = twoLevel

t = int(input())
for i in range(0,t):
    n = int(input())
    if n == 1:
        print -1
        continue
    tree = {}
    for j in range(0, n-1):
        a,b =  map(int,input().split())
        if a not in tree:
            tree[a] = [b]
        else:
            tree[a].append(b)
        if b not in tree:
            tree[b] = [a]
        else:
            tree[b].append(a)
 
    num = {}
    for o in tree:
        num[o] = len(tree[o])
 
    totsum = 0
    visit = []
    for i in range(0, n+1):
        visit.append(False)
    dfs(1)
    print( totsum)
