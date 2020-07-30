"""
In grassland, there are N cities (numbered 1 through N). Initially, there are no roads between them. The Mayor of grassland has
ordered engineers to build roads across grassland in such a way that each city is reachable from all other cities.

For each pair of distinct cities i and j, the cost of building a road between these cities is equal to (i∧j), where ∧ denotes
the bitwise AND operation. However, leaders of the cities have a weird condition ― they only allow roads with positive costs
to be built from their cities.

Help the Mayor find the minimum cost of building roads in the required way or determine that it is impossible.

Timing:1.5sec
level:6

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N.

Output Description:
For each test case, print a single line containing one integer ― the minimum cost of building the roads or −1,if it is impossible.

Constraints

    1≤T≤2⋅10^5
    2≤N≤10^9

Input
2
3
5

Output
3
8

Explanation
Example case 1: We can connect city 1
with city 3 by a road with cost 1 and city 3 with city 2 by a road with cost 2.

Input:
4
5
6
4
8

Output:
8
10
-1
-1

Input:
5
45
455
4555
45555
1

Output:
140
2123
30807
370915
-1

Input:
3
111
5
100

Output:
399
8
375

Input:
2
101
505

Output:
376
2292

Solution:
"""
from sys import stdin, stdout
from math import ceil


def solve():
    twopow = {}
    for i in range(34):
        twopow[i] = pow(2, i)

    for _ in range(int(input())):
        n = int(stdin.readline())
        ans = (n-1)//2
        if not n & (n - 1):
            print(-1)
            continue

        i = 2
        while i < n:
            ans += ((n - i) // (2 * i) + 1) * i
            i <<= 1
        print(ans)


if __name__ == "__main__":
    solve()
