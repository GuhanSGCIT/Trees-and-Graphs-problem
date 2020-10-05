/*
Olya has written N binary integers (i.e. either zero or one) on a blackboard. She recently learned about XOR operation. Now she wants to erase exactly one integer in the array so that the XOR of the remaining N - 1 numbers is zero. Please help her to calculate the number of ways of doing so.

timing:3sec
level:6

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N denoting the number of numbers that Olya has written on a blackboard.
The second line contains N space-separated integers A1, A2, ..., AN denoting the numbers she had written.

Output
For each test case, output a single line containing the number of ways to erase exactly one integer so that the XOR of the remaining integers is zero. The ways where you erase the same integer but on different places in the given sequence are considered different.

Constraints
    1 ≤ T ≤ 20
    2 ≤ N ≤ 10^5
    0 ≤ Ai ≤ 1

Input:
2
5
1 0 0 0 0
5
1 1 1 1 1

Output:
1
5

Explanation
Example case 1. If you erase the first number on the blackboard, then the XOR of the rest of numbers will be equal to zero.
Example case 2. You can erase any of the given 5 numbers, it will make the XOR of the rest equal to zero.

input:
3
4
1 0 1 0
5
1 1 1 1 0
7
1 0 0 0 0 0 1

output:
2
1
5

input:
2
4
1 1 1 1
5
1 0 0 1 1

output:
0
3

input:
1
9
1 0 1 0 1 0 1 1 1

output:
3

input:
1
5
1 1 1 1 0

output:
1

hint:
The XOR or two bits is 0 if they are equal, and 1 if they are not equal. From this, one can deduce that the XOR of N bits is 1 if there are an odd number of 1 s present, and 0 otherwise. This can be easily seen by noticing that XOR is associative, and that the running XOR 2 changes/flips whenever a 1 is encountered. Since the running XOR starts at 0, we thus want the number of 1 s to be even for the XOR to be 0.

*/
#include <iostream>
#include <cstdio>
#include <cassert>
 
using namespace std;
 
const int MAXN = 100000 + 1;
 
int Tn, a[MAXN], n;
 
int main (int argc, char * const argv[]) {
	ios_base::sync_with_stdio(false);
	cin >> Tn;
	assert(1 <= Tn && Tn <= 20);
	while (Tn--) {
		cin >> n;
		assert(2 <= n && n <= 100000);
		int x = 0;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			assert(0 <= a[i] && a[i] <= 1);
			x ^= a[i];
		}
		int ret = 0;
		for(int i = 0; i < n; i++) 
			if (a[i] == x)
				++ret;
		cout << ret << endl;
	}
    return 0;
}
 
