/*
Rahul and Rashi are bored of playing the game of Nim all day. More so, Rahul has been losing all the games. Actually, the array of stone piles for a game is always selected by Rashi from a huge N-length array A. This selected array is always a subarray of A.

Rahul, now frustrated by his losing streak, insists that he would play the next game only if she chooses a game array of length m.

Can you find the number of such subarrays that Rashi can choose so that Rahul still loses? Moreover, since the value of m is decided by Rahul, can you do this for all possible values of m?

Please note that Rahul is always the first player.

Input:
The first line contains an integer T, the number of test cases to follow. 
In each of the test cases, the first line contains a single integer N, and the next line contains N integers, representing the array A.

Output:
Output the results of each test case on a new line. For each test case, output the results for all values of m, that is, m = 1, m = 2 ... m = N, separated by a single space.

Constraints:
    1 ≤ T ≤ 3
    1 ≤ N ≤ 10^5
    0 ≤ A[i] ≤ 10^9
    1 ≤ m ≤ N

Sample Input:
2
6
1 2 3 2 1 3
4
1 1 1 1

Sample Output:
0 0 3 0 0 1
0 3 0 1

Explanation
For the first test case and m = 3, required sub-arrays are [1,2,3], [3,2,1] and [2,1,3].

input:
1
7
1 2 3 4 5 6 7

output:
0 0 1 2 0 0 1 

input:
2
4
2 4 6 8
3
5 6 4

output:
0 0 1 0 
0 0 0

input:
3
2
2 4
6
5 1 8 6 7 9
2 
12 32


output:
0 0 
0 0 0 1 0 0 
0 0 

input:
1
5
6 5 4 2 3

output:
0 0 0 1 0 

hint:
It can be claimed using Nim Game 3 theory that second player will win the game if XOR of the selected subarray is 0. We can find XOR of any subarray in O(1) time by creating a prefix XOR array.

*/
#include <bits/stdc++.h>
using namespace std;

using cd = complex<double>;
const double PI = acos(-1);
const int N = 100050;
int arr[N], answer[N];
bool f[N];
vector<int> vc[N];
map<int, int> mp;

void fft(vector<cd> &a, bool invert)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    for (int len = 2; len <= n; len <<= 1)
    {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len)
        {
            cd w(1);
            for (int j = 0; j < len / 2; j++)
            {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if (invert)
    {
        for (cd &x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main()
{
    int t, n, k;
    scanf("%d", &t);
    while (t--)
    {
        mp[0] = 1;
        vc[1].push_back(0);
        k = 1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            arr[i] = arr[i - 1] ^ arr[i];
            if (!mp[arr[i]])
                mp[arr[i]] = ++k;
            vc[mp[arr[i]]].push_back(i);
        }
        for (int i = 1; i <= k; i++)
        {
            if (vc[i].size() <= 1200)
            {
                for (int x = 0; x < vc[i].size(); x++)
                {
                    for (int y = x + 1; y < vc[i].size(); y++)
                    {
                        answer[vc[i][y] - vc[i][x]]++;
                    }
                }
            }
            else
            {
                memset(f, 0, sizeof f);
                int limit = n;
                for (int x = 0; x < vc[i].size(); x++)
                {
                    f[vc[i][x]] = 1;
                }
                vector<int> a, b, res;
                for (int x = 0; x <= limit; x++)
                {
                    a.push_back(f[x]);
                }
                for (int x = limit; x >= 0; x--)
                {
                    b.push_back(f[x]);
                }
                res = multiply(a, b);
                for (int x = limit + 1; x < res.size(); x++)
                {
                    answer[x - limit] += res[x];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d ", answer[i]);
        }
        printf("\n");

        mp.clear();
        for (int i = 0; i < N; i++)
        {
            answer[i] = 0;
            vc[i].clear();
        }
    }
}