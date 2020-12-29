/*
Increasing COVID cases have created panic amongst the people of India, so the government is starting to push for production of a vaccine. It has to report to the media about the exact date when vaccines will be available.
There are two companies which are producing vaccines for COVID. Company A starts producing vaccines on day D1 and it can produce V1 vaccines per day. Company B starts producing vaccines on day D2 and it can produce V2 vaccines per day. Currently, we are on day 1.
We need a total of P vaccines. How many days are required to produce enough vaccines? Formally, find the smallest integer d such that we have enough vaccines at the end of the day d.

Input
The first and only line of the input contains five space-separated integers D1, V1, D2, V2 and P.

Output
Print a single line containing one integer ― the smallest required number of days.

Constraints:
1≤D1,V1,D2,V2≤100
1≤P≤1,000

Example Input
1 2 1 3 14

Example Output
3

Explanation
Since D1=D2=1, we can produce V1+V2=5 vaccines per day. In 3 days, we produce 15 vaccines, which satisfies our requirement of 14 vaccines.

Example Input
5 4 2 10 100

Example Output
9

input:
1 2 12 24 55

output:
13

input:
8 16 21 42 105

output:
14

input:
3 6 14 26 100

output:
15

hint:
Without loss of generality assume D1<D2. Let the required answer be d. Check two cases:
D1≤d<D2
d≥D2
Form mathematical expressions accordingly and find the minimum value of d.

*/
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int D1, V1, D2, V2, P;
    cin >> D1 >> V1 >> D2 >> V2 >> P;

    if (D1 > D2)
    {
        swap(D1, D2);
        swap(V1, V2);
    }

    int d = (P / V1) + (P % V1 > 0) + D1 - 1;

    if (d < D2)
        cout << d << endl;
    else
    {
        int num = P + (D1 - 1) * V1 + (D2 - 1) * V2;
        int den = V1 + V2;
        d = (num / den) + (num % den > 0);
        cout << d << endl;
    }

    return 0;
}