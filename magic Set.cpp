/*
Katya has a sequence of integers a1,a2,…,an and an integer m.

She defines a good sequence of integers as a non-empty sequence such that the sum of the elements in each of its non-empty subsequences is divisible by m.

Katya wants to know the number of good subsequences of the sequence a. Can you help her?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers n and m.
The second line contains n space-separated integers a1,a2,…,an.

Output
For each test case, print a single line containing one integer — the number of good subsequences.

Constraints
1≤T≤1,000
1≤n≤30
1≤m≤1,000
1≤ai≤1,000
for each valid i

Input
2
2 3
1 2
2 3
1 3

Output
0
1

Explanation
Example case 1: There are no good subsequences.
Example case 2: There is exactly one good subsequence of a: [3].

input:
3
1 2
4
2 2
2 3
3 2
1 2 3

output:
1
1
1

input:
4
5 4
2 5 4 8 6
1 3
2
4 3
5 6 4 8
2 2
1 3

output:
3
0
1
0

input:
1
4 3
2 1 3 4

output:
1

input:
2
2 1
1 3
2 2
1 4

output:
3
1

hint:
Output 2^k−1 where k is number of ai​ divisible by m.
*/
#include <bits/stdc++.h>

using namespace std;

const int MaxN = (int)5e3 + 10;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

void solve()
{
    int n, m, cnt = 0;
    scanf("%d%d", &n, &m);
    assert(1 <= n && n <= 30);
    assert(1 <= m && m <= 1000);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        assert(1 <= x && x <= 1000);
        if (x % m == 0)
        {
            ++cnt;
        }
    }
    printf("%d\n", (1 << cnt) - 1);
}

int main()
{
    //	freopen("input.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    assert(1 <= t && t <= 1e3);
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}
