/*
People in Ooty love apples. They are also very generous. Due to a famine, they now have only a limited supply of apples. Each person has an amount of apples, of which he eats one apple per day. As the people are very generous, they give apples to those in need. If a person runs out of apples, he can receive one apple from anyone on that day. If a person runs out of apples and no one can give him an apple, then that person starves to death. Find the day on which the last person dies. 

Input
First line has T, the number of test cases. T test cases follow.
First line of each test case has N, the population of Ooty.
Second line of each test case has an array of N integers applei, the amount of apple each person has.

Output
For each test case, print one line that denotes the day on which the last person dies. 

Constraints
    1 ≤ T ≤ 10
    0 ≤ N ≤ 100
    0 ≤ applei ≤ 1000

Input:
2
4
2 1 1 4
3
4 0 0

Output:
2
2

 
Explanation
Example case 1. On each day, each person eats one apple. On the first day (2 1 1 4) becomes (1 0 0 3) but the person with 3 apples shares with others so (1 0 0 3) becomes (1 1 1 1). On the second day (1 1 1 1) becomes (0 0 0 0) and everyone dies on second day.
Example case 2. On the first day the person with 4 apples shares with others so (4 0 0) becomes (2 1 1) and by the end of the day it becomes (1 0 0) and 2 people die. On second day (1 0 0) becomes (0 0 0) and the last person dies on second day.

input:
3
2
1 2
4
1 2 3 4
5
1 2 3 4 5

output:
2
3
3

input:
1
7
1 5 8 44 22 66 77

output:
32

input:
1
9
1 2 5 8 9 6 3 4 7

output:
5

input:
1
11
1 2 3 4 5 6 7 8 9 10 11

output:
6

hint:
The apples can be shared with anyone. Instead of giving an apple to someone only when he needs, we can split the apples equally among all the people at the beginning.
This can be done by finding the total number of apples and dividing by N, to find the average number of apples each person should have
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long a[n], sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		long long ans = ceil(sum / double(n));
		cout << ans << endl;
	}
}
