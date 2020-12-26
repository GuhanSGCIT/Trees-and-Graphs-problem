/*
The teacher in ram's class is teaching concepts of a bouncing ball. The rubber ball that she is using has the property that if the ball is dropped from height H then, it bounces back to maximum height H/F. So after first bounce it rises up to maximum height H/F, after second bounce to maximum height H/F2, after third bounce to maximum height H/F3, and so on.
The class has N children, and the teacher wants to select two children such that when the taller child drops the ball from his height, ball reaches a maximum height equal to the height of the shorter child after some (possibly zero) number of bounces. Note that zero bounces mean heights of the two children will be same. Given the heights of the children in the class Height[i], can you tell how many ways are there for the teacher to select two children for the demonstration? Note that when heights are same, the pair is only counted once (See first example for further clarification).

Input
First line contains T, number of testcases. Then 2*T lines follow, 2 per testcase.
First line of each testcase consists of two space-separated intergers N and F.
Second line of each testcase contains N space-separated integers representing the array Height.

Output
For each testcase, print a single line containing the answer to the problem.

Constraints
 For 40 points: 1 ≤ T ≤ 100, 1 ≤ N ≤ 10^3, 2 ≤ F ≤ 10^9, 1 ≤ Height[i] ≤ 10^9
 For 60 points: 1 ≤ T ≤ 100, 1 ≤ N ≤ 10^4, 2 ≤ F ≤ 10^9, 1 ≤ Height[i] ≤ 10^9

Input:
2
3 2
2 2 2
3 2
2 1 4

Output:
3
3

Explanation:
In the first case, the three pairs are (child 1, child 2), (child 2, child 3) and (child 1, child 3).
For the second case also, the three pairs are (child 1, child 2), (child 2, child 3) and (child 1, child 3).

input:
2
4 5
4 5 2 1 4
2 2
2 4

output:
1
6

input:
1
4 3
5 4 8 2

output:
0

input:
1
8 5
4 8 5 2 6 8 4 1

output:
3

input:
2
4 4
2 1 3 4 
3 2
1 2 3

output:
1
1

hint:
You can sort array h in ascending order and then iterate over the array. For each element h[i] you divide it by F^0, F^1, … while F^k <= h[i] and for each of these divisions if its result is an integer, you use binary search to determine the number elements in h equal to the result.

*/
#include <bits/stdc++.h>
using namespace std;

#define mx 100005
int h[mx];
int n, f;

bool power_of(int a, int f)
{
    while (a % f == 0)
        a /= f;
    if (a == 1)
        return true;
    else
        return false;
}

void solve_small()
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (h[i] % h[j] == 0)
            {
                if (power_of(h[i] / h[j], f))
                    ans++;
            }
            else if (h[j] % h[i] == 0)
            {
                if (power_of(h[j] / h[i], f))
                    ans++;
            }
        }
    }
    printf("%d\n", ans);
}

map<int, int> mp;
void solve_large()
{
    mp.clear();
    for (int i = 0; i < n; i++)
    {
        int base = h[i];
        while (base % f == 0)
        {

            base /= f;
        }
        mp[base]++;
    }

    int ans = 0;
    for (map<int, int>::iterator itr = mp.begin(); itr != mp.end(); itr++)
    {
        int e = itr->second;
        ans += (e * (e - 1)) / 2;
    }
    printf("%d\n", ans);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &f);
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);
        solve_large();
    }
}