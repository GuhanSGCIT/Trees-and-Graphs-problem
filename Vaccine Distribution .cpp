/*
Finally, a COVID vaccine is out on the market and the india government has asked you to form a plan to distribute it to the public as soon as possible. There are a total of N people with ages a1,a2,…,aN.
There is only one hospital where vaccination is done and it is only possible to vaccinate up to D people per day. Anyone whose age is ≥80 or ≤9 is considered to be at risk. On each day, you may not vaccinate both a person who is at risk and a person who is not at risk. Find the smallest number of days needed to vaccinate everyone.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and D.
The second line contains N space-separated integers a1,a2,…,aN.

Output
For each test case, print a single line containing one integer ― the smallest required number of days.

Constraints
1≤T≤10
1≤N≤10^4
1≤D≤10^5
1≤ai≤100
for each valid i

Input
2
10 1
10 20 30 40 50 60 90 80 100 1
5 2
9 80 27 72 79

Example Output
10
3

Explanatio
Example case 1: We do not need to worry about how the people are grouped, since only one person can be vaccinated in a single day. We require as many days as there are people.
Example case 2: There are two people at risk and three people who are not at risk. One optimal strategy is to vaccinate the two people at risk on day 1
and the remaining three on the next 2 days.

input:
1
10 5
1 2 3 4 5 6 7 8 9 10

output:
3

input:
2
4 2
5 8 4 9
5 2
1 5 4 7

output:
2
3

input:
3
4 2
10 20 30 40
3 1
55 66 77
6 2
12 15 16 17 18 19

output:
2
3
3

input:
1
5 2
12 24 48 56 96

output:
3

hint:
First find the minimum numbers of days to vaccinate all the people who are at risk, then find the same for all the people who are not at risk and add the results to get the required answer.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int risk = 0, not_risk = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= 80 || a[i] <= 9)
                risk++;
            else
                not_risk++;
        }

        int ans = (risk / d) + (risk % d > 0) + (not_risk / d) + (not_risk % d > 0);
        cout << ans << endl;
    }
    return 0;
}