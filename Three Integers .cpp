/*
You are given three integers A, B and C. You may perform the following operation an arbitrary number of times: choose one of the numbers A, B, C and either add 1 to it or subtract 1 from it.

Find the minimum number of operations required to make the sequence A, B, C an arithmetic progression, i.e. a sequence which satisfies B - A = C - B.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers A, B and C.

Output
For each test case, print a single line containing one integer — the minimum required number of operations.

Constraints
    1 ≤ T ≤ 10,000
    -109 ≤ A, B, C ≤ 10^9


Input:
5
-5 0 5
-5 7 6
-10 -100 20
1 -1 1
51 23 10

Output:
0
7
105
2
8

Explanation
Example case 1: No operations are needed because 0-(-5) = 5-0.
Example case 2: We can obtain an arithmetic progression in seven operations by adding 1 to A = -5 and subtracting 1 six times from B = 7.
Example case 3: We should add 1 to B 105 times.

Input:
2
151 35215 -1135
16365 -6465 51656

output:
35707
40476

Input:
5
1 -1 100
165 263 1
1 1 1
808 80 8008
1 2 3

output:
52
180
0
4328
0

Input:
1
125 126 134

output:
4

Input:
1
102000 33222 36321

output:
35939


hint:
For A,B,C to be in arithmetic progression, they must satisfy 2B=A+C. We need to make both side of the expression equal. Observe that in right hand side, you need to do the same type of operation on A,C. You can’t add 1 on A and subtract −1 from C because it will only increase the number of operations
*/
#include <bits/stdc++.h>

using namespace std;

const int MaxN = (int)1e6 + 10;
const int INF = 1e9;

int solve(int a, int b, int c) {
	if (a > c) {
		swap(a, c);
	}
	if (b > a && b > c) {
		a = -a;
		b = -b;
		c = -c;
		swap(a, c);
	}
	if (a <= b && b <= c) {
		int x = b - a;
		int y = c - b;
		if (x > y) {
			swap(x, y);
		}
		return (y - x + 1) / 2;
	}
	// a >= b && c >= b
	return a - b + (c - a + 1) / 2;
}

int rnd(int l, int r) {
	return (1LL * RAND_MAX * rand() + rand()) % (r - l + 1) + l;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
/*	freopen("input.txt", "w", stdout);
	printf("%d\n", 10000);
	for (int i = 1; i <= 10000; ++i) {
		if (i <= 1000) {
			printf("%d %d %d\n", rnd(-10, +10), rnd(-10, +10), rnd(-10, +10));
		} else {
			printf("%d %d %d\n", rnd(-INF, INF), rnd(-INF, INF), rnd(-INF, INF));
		}
	}*/
	int t;
	cin >> t;
	while (t --> 0) {
		int a, b, c;
		cin >> a >> b >> c;
		cout << solve(a, b, c) << '\n';
	}
	return 0;
}
