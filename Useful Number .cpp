/*
You are given an integer sequence A1,A2,…,AN. Let's define the useful number of a subsequence of A as the number of distinct primes p such that p divides each member of the subsequence, multiplied by the length of the subsequence. Find the maximum of useful numbers of all subsequences of A.


Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-seperated integers A1,A2,…,AN.

Output:
Print a single line containing one integer — the maximum useful number.

Constraints
1≤T≤10
1≤N≤10^5
1≤Ai≤10^5
for each valid i

Example Input
1
5
2 2 4 17 8

Example Output
4

Explanation
The subsequence [2,2,4,8] has the maximum useful number. The number of distinct primes that divide each member of the subsequence is 1 (only the prime 2) and the length of the subsequence is 4, so the useful number of this subsequence is 1⋅4=4.

input:
3
5
1 2 3 4 5
5
1 5 3 2 6
2
5 7

output
2
2
1

input:
2
8
5 4 7 6 2 6 1 9
5
2 9 6 4 7

output
4
3

input:
1
9
4 5 6 8 2 1 3 7 9

output
4

input:
1
4
2 5 6 7
output
2

hint:
First of all, Number of distinct prime numbers that divide every number of the subset is equivalent to the number of prime factors of GCD of this subset.


*/
#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(lli j=0; j<v; j++)
#define fork(v) for(lli k=0; k<v; k++)
#define forl(v) for(lli l=0; l<v; l++)
#define fort(v) for(lli t=0; t<v; t++)
#define forz(v) for(lli z=0; z<v; z++)
#define lli long long int
#define MAX 100010
#define double long double
#define pb push_back
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
bool prime[MAX] 	= {};
int  divisors[MAX]	= {};
int  appear[MAX] = {};
void init(){
	fori(MAX)
		appear[i] = 0;
}
void sieve(){
	for(int i=2; i<MAX; i++)
		prime[i] = 1;
	for(int i=2;i<MAX; i++)
		if(prime[i])
			for(int j=i; j<MAX; j+=i)
				prime[j] = 0, divisors[j]++;
}
void deal(){
	sieve();
	int t;
	cin>>t;
	assert(t<=10);
	forl(t){
		init();
		int n;
		cin>>n;
		assert(n<=pow(10,5));
		fori(n){
			int ed;
			cin>>ed, appear[ed]++;
			assert(ed<=pow(10,5));
			assert(ed>=1);
		}
		lli mx = 0;
		for(int i=2; i<MAX; i++){
			int number = 0;
			for(int j=i; j<MAX; j+=i)
				number+=appear[j];
			lli ans = (lli)number*(lli)divisors[i];
			mx = max(mx,ans);
		}
		cout<<mx<<'\n';
	}
}
int main(){
//	freopen("i1.txt", "r", stdin);
//	freopen("o1.txt", "wb", stdout);
	deal();
}
