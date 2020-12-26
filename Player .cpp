/*
Ram, mohan and siva are the most influential music critics in Saint-Petersburg. They have recently downloaded their favorite band's new album and going to listen to it. siva claims that the songs of entire album should be listened strictly in the same order as they are given, because there is the secret message from the author in the songs' order. Ram, being chaotic, does not think so, hence he loves listening to songs in a random order. Ram is pretty good in convincing other people, so after a two-hours discussion siva accepted listening in random order(the discussion's duration was like three times longer thatn the album's one). In this context random order means following: There are N songs in the album. In the very beginning random song is chosen(here and further "random song" means that every song has equal probability to be chosen). After some song is over the next one is chosen randomly and independently of what have been played before.
mohan, being the only one who is not going to drop out from the university, wonders, what is the expected number of songs guys have to listen to until every song is played at least once.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer N denoting the number of songs in the album.

Output
For each test case, output a single line containing the expected number of songs the guys will listen to. 
Your answer will be considered as correct if it has an absolute or relative error less than 10−1. More formally if the expected output is A and your output is B, your output will be considered as correct if and only if
|A − B| ≤ 10−1 * max{|A|, |B|, 1}.

Constraints
1 ≤ T ≤ 100
1 ≤ N ≤ 3000

Input:
3
1
2
3


Output:
1
3
5.5


Explanation
Example case 2 After playing the first song there is 1/2 chance to finish the album each time new song is played.
So the expected number of songs is 2/2 + 3/4 + 4/8... = 3 


input:
5
5
4
2
1
6

output:
11.4167
8.33333
3
1
14.7

input:
5
1
2
3
4
5

output:
1
3
5.5
8.33333
11.4167

input:
3
9
7
6

output:
25.4607
18.15
14.7

input:
2
12
21

output:
37.2385
76.5525

hint:
Let’s keep dp[i][j] = what’s probability to have j different elements in the list, such as length of the list is i. We can simulate this solution until the probabilities become small enough. Then, we can either notice the pattern or precalculate the answers in a constant vector.

*/
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <complex>
#include <cassert>
#include <functional>

#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define REPD(i, n) for (int i = (n)-1; i >= 0; i--)
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define FORN(i, a, b) for (int i = a; i < b; i++)
#define FOREACH(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define RESET(c, x) memset(c, x, sizeof(c))

#define PI acos(-1)
#define sqr(x) ((x) * (x))
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Aint(c) (c).begin(), (c).end()
#define SIZE(c) (c).size()

#define DEBUG(x)                          \
    {                                     \
        cerr << #x << " = " << x << endl; \
    }
#define PR(a, n)             \
    {                        \
        cerr << #a << " = "; \
        FOR(_, 1, n)         \
        cerr << a[_] << ' '; \
        cerr << endl;        \
    }
#define PR0(a, n)            \
    {                        \
        cerr << #a << " = "; \
        REP(_, n)            \
        cerr << a[_] << ' '; \
        cerr << endl;        \
    }
#define LL long long

using namespace std;

int nextInt(int l, int r)
{

    int x;
    assert(scanf("%d", &x) == 1);
    assert(l <= x && x <= r);

    return x;
}

double c[3333][3333];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    int t = nextInt(1, 100);

    for (int i = 1; i <= 3000; i++)
    {
        c[i][i] = 0;

        for (int j = i - 1; j >= 0; j--)
            c[i][j] = c[i][j + 1] + 1.0 * i / (i - j);
    }

    while (t--)
    {
        int n = nextInt(1, 3000);
        cout << c[n][0] << endl;
    }

    return 0;
}