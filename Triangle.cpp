/*
Ram always loves to solve triangle problem.But due to his illness Ram is not able to solve his triangle problem. Can you help Ram to solve this problem?
Your task is to print "YES" if triangle is possible and find out the area of the triangle. Otherwise print "NO"(if not possible).

For every test case given inputs a, b, and c,three sides of triangle.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, three integers a,b,c.

Output:
For each testcase, output in a single line answer "YES"(if triangle possible) and area of triangle correct upto five decimal places space separated. Otherwise "NO".

Constraints
1≤T≤10^5
1≤a,b,c≤10^7

Sample Input:
2
3 4 5
2 4 7

Sample Output:
YES 6.00000
NO

EXPLANATION:
For 1st test case Triangle is possible. And area is 6.00000
And for 2nd test case triangle is not possible.

input:
3
1 2 3
4 6 2
7 8 9

output:
NO
NO
YES 26.83282

input:
1
6 7 8

output:
YES 15.49193

input:
4
1 3 1
2 1 2
5 1 4
2 4 5

output:
NO
YES 0.00000
NO
YES 0.00000

input:
1
0 1 0

output:
NO

hint:
Whether triangle is possible or not, check ( larger side of triangle < sum of other two sides ) then triangle is possible otherwise not.
For find out the area of triangle, first find out semi perimeter (s=(a+b+c)/2), then sqrt of (s*(s-a)(s-b)(s-c)); Where a,b,c are three sides of triangle.

*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, ar[3];
        cin >> a >> b >> c;
        long double s, ans, p;
        ar[0] = a;
        ar[1] = b;
        ar[2] = c;
        sort(ar, ar + 3);
        if (ar[0] + ar[1] <= ar[2])
            cout << "NO\n";
        else
        {
            s = (a + b + c) / 2;
            p = 1.00;
            p *= sqrt(s);
            p *= sqrt(s - a);
            p *= sqrt(s - b);
            p *= sqrt(s - c);
            ans = p;
            cout << "YES " << fixed << setprecision(5) << (ans) << "\n";
        }
    }
    return 0;
}