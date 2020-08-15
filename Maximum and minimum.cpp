/*
The range of an array is defined as the difference between the maximum and minimum value in it.
Chef comes up with a crazy idea to minimize the range by changing atmost 3 elements in the array.
He wants to check whether the minimum range he gets is right or not.

Please help him in verifying his answer.

timing:1sec
level:6

Input:
First line will contain T , number of testcases. Then the testcases follow.
First line of each test case contains an integer N, the no. of integers in the array.
Second line contains N space separated integers, A0,A1,...,An−1.

Output:
For each testcase, output in a single line, the minimum range.

Constraints
1≤T≤10
3≤N≤10^5
−10^9≤Ai≤10^9

Sample Input:
1
6
3 5 0 2 10 0

Sample Output:
2

EXPLANATION:
Chef changes the elements 3, 5 and 10 to 0, 1 and 2, resulting in the array: [0, 1, 0, 2, 2, 0]. The minimum range is 2−0=2.
There can be multiple ways to change atmost 3 elements to get the answer.

input:
2
7
4 5 10 2 401 201 3
3
7 21 32

output:
3
0

input:
1
11
2 8 31 0 41 2 6  7 8 0 4

output:
8

input:
3
4
5 21 0 8
3
4 0 8
6
4 8 9 0 5 11

output:
0
0
3

input:
2
4
1 0 2 4
4
2 0 2 0

output:
0
0

hint:
Changing at most 333 elements is the same as deleting at most 333 elements because you can set them equal to any of the existing elements in the array. When N=3N = 3N=3, make them all the equal.
So, you can sort the array, and now consider the following cases:
Delete 3 largest elements.
Delete the smallest element and 2 largest elements.
Delete 2 smallest elements and the largest element.
Delete 3 largest elements.
Find the gap between maximum and minimum element in all 4 cases, and take the minimum of those.

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll min_gap(vector<ll>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    if (n == 3) {
        return 0;
    }

    int i = n - 4;
    int j = 0;
    ll res = arr[n - 1] - arr[0];
    int cnt = 0;
    while (cnt < 4) {
        res = min(res, arr[i] - arr[j]);
        ++i;
        ++j;
        ++cnt;
    }
    return res;
}

int main () {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> inp(n);
        for (auto &x: inp) {
            cin >> x;
        }

        cout << min_gap(inp) << endl;
    }
    return 0;
}
