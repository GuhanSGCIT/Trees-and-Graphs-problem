/*
Alice likes prime numbers. According to Alice, only those strings are nice whose sum of character values at a prime position is prime. She has a string S. Now, she has to count the number of nice strings which come before string S( including S) in the dictionary and are of the same length as S.
Strings are zero-indexed from left to right. To find the character value she uses the mapping {'a': 0, 'b':1, 'c':2 ……. 'y': 24, 'z':25} .

For example, for string abcde Characters at prime positions are ′c′ and ′d′. c + d = 2 + 3 = 5. Since, 5 is a prime number,
the string is nice.

Since there could be many nice strings print the answer modulo 10^9+7.

timing:3sec
level:8

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, the string S.

Output:
For each testcase, output in a single line number of nice strings modulo 10^9+7.

Constraints
1≤T≤10
2≤|S|≤10^2
String S contains only lowercase letters.

Sample Input:
1
abc

Sample Output:
10

input:
3
asdf
qwert
zxcvbb

output:
3396
2130622
76094858

input:
1
qeeryyui

output:
516317386

input:
1
asdfghjklqwer

output:
15404500

input:
1
123456789

output:
0

hint:
This problem can be solved using Digit DP.However, instead of digits here we are using characters.
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<(b);i++)
#define dfor(i,a,b) for(ll i=(a);i>=(b);i--)
#define mem(u, vis) memset(u, vis, sizeof(u))
#define ll long long
#define ull unsigned long long
#define MOD  1000000007
#define MAX  1e9
#define pb   push_back
#define F    first
#define S    second


ll dp[2000][10000][2];
// smaller ? 0 - no 1: yes
vector<bool> isprime(100000, true);

void prime(int n){
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= n; i++) {
	    if (isprime[i] && (long long)i * i <= n) {
	        for (int j = i * i; j <= n; j += i)
	            isprime[j] = false;
	    }
	}
}

ll calc_dp(string s, ll pos, ll sum, ll smaller){
	if(pos == s.length()){
		if(isprime[sum]){
			return 1;
		}
		return 0;
	}
	if(dp[pos][sum][smaller] != -1){
		return dp[pos][sum][smaller];
	}
	ll limit = 'z' - 'a';
	ll res = 0;
	bool primepos = isprime[pos];

	if(!smaller){
		limit = s[pos] - 'a';
	}

	for(ll i = 0; i <= limit ; ++i){
		ll ns;
		if(i < limit){
			ns = 1;
		}
		else
			ns = smaller;
		if(primepos){
			res = (res   + calc_dp(s, pos + 1, sum + i, ns)%MOD)%MOD;
		}
		else{
			res = (res + calc_dp(s, pos + 1, sum, ns)%MOD)%MOD;
		}
	}

	dp[pos][sum][smaller] = res;
	return res;
}


signed main() {
	ll t=1;
	cin>>t;
	prime(100000);
	while(t--){
		string s;
		cin>>s;
		mem(dp,-1);
		cout<<(calc_dp(s,0,0,0))%MOD<<endl;
	}
	
}
