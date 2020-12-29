/*
Ram recently started working at ABC corporation. Let's number weekdays (Monday through Friday) by integers 1 through 5. For each valid i, the number of hours Ram spent working at the office on weekday i was Ai.
Unfortunately, due to the COVID-19 pandemic, Ram started working from home and his productivity decreased by a considerable amount. As per Ram's analysis, 1
hour of work done at the office is equivalent to P hours of work done at home.

Now, in order to complete his work properly, Ram has to spend more hours working from home, possibly at the cost of other things like sleep. However, he does not have to do the same work on each day as he would have in the office ― for each weekday, he can start the work for this day on an earlier day and/or complete it on a later day. The only requirement is that his work does not pile up indefinitely, i.e. he can complete his work for each week during the same week. One day has 24 hours.

If Ram is unable to complete his work for a week during those five weekdays, then he has to work during the weekend too. Ram wishes to know whether he has to work on weekends or if he can complete his work by working only on weekdays. Help him answer that question. (It is possible that Ram would be unable to finish his work even if he worked all the time, but he does not want to know about that.)

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains six space-separated integers A1, A2, A3, A4, A5 and P.

Output
For each test case, print a single line containing the string "Yes" if Ram has to work on weekends or "No" otherwise (without quotes).

Constraints
1≤T≤1,000
0≤Ai≤24
for each valid i
1≤P≤24

Example Input
2
14 10 12 6 18 2
10 10 10 10 10 3

Example Output
No
Yes

Explanation
Example case 1: Here, P=2 , so the number of hours Ram has to work from home to handle his workload for days 1 through 5 is [28,20,24,12,36]. If he works for full 24 hours on each of the five weekdays, he finishes all the work, so he does not have to work on weekends.
Example case 2: No matter what Ram does, he will have to work on weekends

input:
3
4 5 8 2 6 1
12 24 48 72 92 6
1 2 3 4 5 1

output:
No
Yes
No

input:
1
120 140 160 50 75 5

output:
Yes

input:
5
12 23 45 65 78 3
25 36 45 75 95 2
1 2 3 4 5 1
123 456 789 321 654 7
2 6 12 4 8 2


output:
Yes
Yes
No
Yes
No

input:
2
55 100 77 66 25 5
4 8 2 9 1 0

output:
Yes
No

hint:
Total hours of work at home required are (A1+A2+A3+A4+A5)∗P
Total hours available before the weekend are 24∗5=120
If the required hours are strictly greater than available hours, Ram will have to work on weekends.

*/
#include <bits/stdc++.h>
#define endl '\n'

#define SZ(x) ((int)x.size())
#define ALL(V) V.begin(), V.end()
#define L_B lower_bound
#define U_B upper_bound
#define pb push_back

using namespace std;
template<class T, class T1> int chkmin(T &x, const T1 &y) { return x > y ? x = y, 1 : 0; }
template<class T, class T1> int chkmax(T &x, const T1 &y) { return x < y ? x = y, 1 : 0; }
const int MAXN = (1 << 20);

int a[5], p;

void read() {
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> p;
}

void solve() {
	int sum = 0;
	for(int i = 0; i < 5; i++) {
		sum += p * a[i];
	}

	sum -= 24 * 5;

	if(sum > 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while(T--) {
		read();
		solve();
	}

	return 0;
}