/*
The task is simple! You have to form a given number n using following two operations.
Append a digit d to current number. The cost of this operation is d (0<=d<=9),Append any "substring of current number" to the current number. The cost of this operation is zero
You start the process with an empty number and repeat one of the above 2 operations until you get the desired number. Print the minimum cost to form the given number.

     
Input
First line will contain T (the number of test cases).
For each test case input is the number to be formed by the given operations.(The number can be very large).

Output
Print the minimum cost needed to form the given number using the given two operations.

Constraints
1 ≤ T ≤ 10
1 ≤ n ≤ 1010000

Input:
2
123
1212

Output:
6
3

Explanation:
minimum cost needed to form the given number,
1+2+3=6;
1+2=3;


input:
5
12321
54546
111232
22525
121265659852

output:
6
15
6
7
31

input:
1
125451521215

output:
12

input:
2
12425212
216312561

output:
12
17

input:
3
3263651311
31212
3211322345

output:
17
6
15

hint:
You can observe that once a digit is appended to your string it can be appended any number of times with a cost of 0 as it will be a sub-string of the current string.
So the total cost is just the sum of distinct digits present in the string.

*/
#include<bits/stdc++.h>
using namespace std;

// Numeric Constants
#define N 1000000007
#define maxs 200005
#define mins 1005
#define eps 1e-14
#define imax 2000000200
#define llmax 1000000002000000000ll
#define pi 3.141592653589793

// Others
#define ll long long
#define pb push_back
#define gc getchar_unlocked
#define iosbase ios_base::sync_with_stdio(false)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppi pair<pair<int,int>,int>
#define ppl pair<pll,ll>
#define vi vector<int>
#define sc scanf
#define pr printf
#define lld I64d
#define F first
#define S second
#define siter set<int>::iterator
#define p_pq priority_queue
#define ub upper_bound
#define lb lower_bound

int mark[100];
string str;
int main()
{
	iosbase;
	int t,i;
	cin>>t;
	while(t--){
		cin>>str;
		for(i=0;i<10;i++){
			mark[i]=0;
		}
		for(i=0;i<str.size();i++){
			mark[str[i]-'0']=1;
		}
		int ans=0;
		for(i=0;i<=9;i++){
			if(mark[i]){
				ans+=i;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
