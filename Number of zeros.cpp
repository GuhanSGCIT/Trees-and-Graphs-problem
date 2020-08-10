/*
Determine the number of zeros at the end of X! (X factorial), where X is the input number.

timing:3sec
level:6

input:
Single line of input contains a integer X.

output:
Print the result as a interger.

Constraints
0<=X<=1000

Input :
100

Output :
24

Input
1000

ouput:
249

input:
555

output:
137

input:
701

output:
174

input:
5

output:
1

hint:
To determine the number of zeros at the end of X! ,by ans = ans + n / x;x = x * 5;
*/
#include "bits/stdc++.h"
using namespace std;

long long func(long long n){

	long long ans = 0;
	long long x = 5;
	while(x <= n){

		ans = ans + n / x;
		x = x * 5;
	}
	return ans;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	cout << func(n) << endl;
}
