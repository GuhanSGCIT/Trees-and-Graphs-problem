/*
There are N friends in a group. Each of them have Ai candies. Can they share all of these candies among themselves such that each one of them have equal no. of candies.

timing:2sec
level:7

Input:
First line will contain T, number of testcases. Then the testcases follow.
First line of each testcase contains of a single line of input, an integer N denoting no. of friends in the group.
Next line contains N space separated integers Ai denoting the no. candies ith friend has.

Output:
For each testcase, output "Yes",if it is possible to share equally else "No"(without " ").

Constraints
1≤T≤10
1≤N≤100
0≤Ai≤1000

Sample Input:
1
3
1 2 3

Sample Output:
Yes

EXPLANATION:
Each of them have 2 candies after sharing.

input:
2
4
5 9 4 6
5
1 5 8 7 4

output:
Yes
Yes

input:
3
7
4 8 5 9 6 4 7
8
4 8 5 6 9 7 4 1
2
4 8

output:
No
No
Yes

input:
2
4
5 1 2 3
3
7 4 5

output:
No
No

input:
1
9
4 5 8 6 9 7 1 2 3

output:
Yes

hint:
The idea is check out whether the total no. of candies is divisible by N , or not. If it is divisible by N then it can be equally distributed among N friends else it is not possible to do so.

*/
#include <iostream>
using namespace std;
 
int main() {
	int t,n,i,s,r;
	cin>>t;
	while(t--)
	{
		cin>>n;
		s=0;
		for(i=0;i<n;i++)
		{
			cin>>r;
			s+=r;
		}
		if(s%n==0)
		cout<<"Yes\n";
		else
		cout<<"No\n";
	}
	return 0;
} 
