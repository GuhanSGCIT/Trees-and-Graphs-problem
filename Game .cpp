/*
You are playing following game: given an array A of N natural numbers. All numbers in the array A are at most M. On every turn you may pick any two different elements Ai and Aj (i≠j), such that Ai, Aj ≤ M, and add K to both. The game ends when you are not able to continue. That is, when there is no pair (i,j) left such that both of them are less than equal to M.
Let's call two arrays different if the sum of all their elements is different. When the game ends, you note down the final array A. How many different final arrays can you have.

Input
The first line contains three integers N, M and K. N elements of the array follow in the next line.

Output
Output single integer - answer for the given problem modulo 10^9+7.

Constraints
    1 ≤ N ≤ 10^5
    1 ≤ M,K ≤ 10^12
    1 ≤ Ai ≤ M 


Input:
3 3 2
1 2 3
Output:
2

Explanation
All possible sums are 14 and 10. You can get them by, for example, these arrays:
A=(5, 4, 5), A=(1, 4, 5)

input:
4 3 2
8 4 6 2

output:
1

input:
3 3 3
5 4 8

output:
1

input:
2 2 1
5 7

output:
1

input:
6 5 5
5 8 7 4 6 3

output:
1


hint:
An array entry Ai can be incremented at most 1 + ⌊ (M-Ai)/K ⌋ times. If it has been incremented fewer times, its value will be at most M, and can still be used in the operation.
If the operation is applied T number of times before the procedure stops, then the final sum is initial sum + 2 T K. Therefore, the game ends with different arrays if and only if the operation is applied different number of times.
When the game ends, at most one entry is less than equal to M. All others must be more than M.


*/
#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define fo(i, n) for (int i = 0; i < n; i++)
#define fin(i, x, n) for (int i = x; i <= n; i++)
#define tr(i, c) for (auto i = (c).begin(); i != (c).end(); i++)
#define deb3(x, y, z) cerr << #x << " : " << x << " , " << #y << " : " << y << " , " << #z << " : " << z << '\n'
#define deb2(x, y) cerr << #x << " : " << x << " , " << #y << " : " << y << '\n'
#define deb(x) cerr << #x << " : " << x << '\n'
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define i64 long long
#define sq(x) ((x) * (x))
#define len size()
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
using namespace std;
i64 n, m, k, r, s, z, mx;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    mx = s = 0;
    cin >> n >> m >> k;
    fo(i, n)
    {
        cin >> z;
        r = (m - z) / k + 1;
        if (mx < r)
            mx = r;
        s += r;
    }
    r = (s - mx) / 2 + (s - mx) % 2;
    mx = s >> 1;
    z = (mx - r + 1) % mod * 1LL;
    cout << z << "\n";
}