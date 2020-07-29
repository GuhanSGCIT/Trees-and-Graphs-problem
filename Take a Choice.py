"""
Manu and his mother are going for a trip. Manu's world consists of N cities connected by N−1 bidirectional roads such that
each city can be reached from any other city using roads. For each city, we know its age — the number of years
elapsed since the foundation of the city; let's denote the age of city i by Ai.

First of all, Manu and his mother have to decide what city they should visit first. Suppose that Manu chooses a city Cc
and his mother chooses a (not necessarily different) city Cm. The difference of their choices is the number of different bits in
the binary representations of ACc and ACm.

Manu will not argue with his mother if the parity of this difference is not equal to the parity of the length of the shortest
path between cities Cc and Cm (the number of roads on the shortest path between them). Find the number of ways to choose the
cities Cc and Cm such that Manu avoids quarreling with his mother.

timing:2.5sec
level:6

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
Each of the following N−1 lines contains two space-separated integers A and B denoting a road between cities A and B.
The last line contains N space-separated integers a1,a2,…,aN.

Output Description:
For each test case, print a single line containing one integer — the number of valid pairs cc,cm.

Constraints
1≤T≤10
1≤N≤105
1≤A,B≤N
0≤ai≤109
for each valid i

Input:
1
3
1 2
1 3
1 2 3

Output:
2

Explanation:
Example case 1: The two possible choices are Cc=2,Cm=3
(their binary representations differ by one bit, the shortest path has length 2) and Cc=1,Cm=2
(there are two different bits in their binary representations and the shortest path has length 1).

Input:
2
4
1 2
1 3
1 4
1 2 3 4
2
1 2
1 2

Output:
4
1

Input:
1
8
1 4
1 5
1 3
1 2
1 8
1 7
1 6
1 2 3 4 5 6 7 8

Output:
16

Input:
1
2
1 11
1 11

Output:

Input:
1
5
1 2
1 5
1 4
1 3
1 3 2 5 4

Output:
6

Solution:

"""
import sys
sys.setrecursionlimit(10 ** 6)

for t in range(int(input())):
    N = int(input())
    g = [[] for i in range(N + 1)]
    for i in range(N - 1):
        u, v = map(int, input().split())
        g[u].append(v)
        g[v].append(u)
    A = [None] + [bin(int(Ai)).count('1') % 2 for Ai in input().split()]
    cnt = [0] * 4
    def dfs(u, p, d):
        cnt[A[u] << 1 | d] += 1
        for v in g[u]:
            if v != p:
                dfs(v, u, d ^ 1)
    dfs(1, 1, 0)
    ans = 0
    for m in range(16):
        p0, p1, d0, d1 = m & 1, m >> 1 & 1, m >> 2 & 1, m >> 3 & 1
        if p0 ^ p1 ^ d0 ^ d1:
            ans += cnt[p0 << 1 | d0] * cnt[p1 << 1 | d1]
    print(ans // 2)
