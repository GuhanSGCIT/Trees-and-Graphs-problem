/*
You are given a sequence of N powers of an integer k; let's denote the i-th of these powers by kAi . You should partition this sequence into two non-empty contiguous subsequences; each element of the original sequence should appear in exactly one of these subsequences. In addition, the product of (the sum of elements of the left subsequence) and (the sum of elements of the right subsequence) should be maximum possible.
Find the smallest position at which you should split this sequence in such a way that this product is maximized.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and k.
The second line contains N space-separated integers A1,A2,…,AN.

Output
For each test case, print a single line containing one integer — the size of the left subsequence. If there is more than one possible answer, print the smallest possible one.

Constraints
1≤T≤10
2≤N≤10^5
2≤k≤10^9
0≤Ai≤10^5
for each valid i

Example Input
1
5 2
1 1 3 3 5

Example Output
4

Explanation
The actual sequence of powers is [21,21,23,23,25]=[2,2,8,8,32]. The maximum product is 20⋅32=640. In the optimal solution, the sequence is partitioned into [2,2,8,8] and [32].

input:
1
7 4
5 6 12 47 56 78 102

output:
6

input:
1
4 2
5 4 12 33

output:
3

input:
1
8 4
2 3 11 7 9 5 3 1

output:
3

input:
1
7 3
1 2 3 4 5 6 7

output:
6

hint:
Let’s suppose we have a number N and we want to split it into a,b such that a+b=N and a × b is maximum. The cut point would be exactly N/2. This can be proved by solving the quadratic equation N(N-x)* or deriving the function.


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
#define MAX 100100
#define double long double
#define pb push_back
int inf = pow(10,9);
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out
int freq[MAX] = {};
int fir[MAX] = {}; // the left part
int sec[MAX] = {}; // right part
int arr[MAX] = {};
void init(){
	fori(MAX)
		freq[i] = 0, fir[i] = 0, sec[i] = 0;
} 
bool great(bool equal_case){ // returns if first sum > (or >= if equal_case==1) second sum, and reinitilizes first and second arrays to 0
	int gr = -1;
	for(int i=MAX-1; i>-1; i--){
		if(gr==-1){
			if(fir[i] > sec[i])
				gr = 1;
			else if(sec[i] > fir[i])
				gr = 0;
		}
		fir[i]=0, sec[i]=0;
	}
	if(equal_case)
		return (gr!=0);
	return (gr==1);
}
void deal(){
	int t;
	cin>>t;
	assert(t<=10);
	forl(t){
		init();
		int n,k;
		cin>>n>>k;
		assert(n<=pow(10,5));
		assert(k>=2);
		fori(n){
			cin>>arr[i];
			assert(arr[i]<=pow(10,5));
			assert(arr[i]>=0);
			freq[arr[i]]++;
		}
		int a = 0, b= n-1;
		while(a<b){	// returns first index where sum1 > sum2
			int c = (a+b)/2;
		//	cout<<a<<" "<<b<<endl;
			fori(c+1)
				fir[arr[i]]++;
			sec[0] = freq[0] - fir[0];
			fori(MAX-1){
				sec[i+1] = freq[i+1] - fir[i+1];
				sec[i+1] += sec[i]/k, sec[i]%=k;
				fir[i+1] += fir[i]/k, fir[i]%=k;
			}
			if(great(0))
				b=c;
			else
				a=c+1;
		}
		if(a==0){
			cout<<a+1<<'\n';
			continue;
		}
		if(a==n-1){
			cout<<a<<'\n';
			continue;
		}
		// find out if (left part >= right part) without a, if yes than output left (as if in a-1), otherwise right(as if in a) 
		fori(a)
			fir[arr[i]]++;
		sec[arr[a]]--;
		sec[0] = freq[0] - fir[0];
		fori(MAX-1){
			sec[i+1] += freq[i+1] - fir[i+1];
			sec[i+1] += sec[i]/k, sec[i]%=k;
			fir[i+1] += fir[i]/k, fir[i]%=k;
		}
		if(great(1))
			cout<<a<<'\n';
		else
			cout<<a+1<<'\n';
	}
}
int main(){
//	freopen("i_test.txt", "r", stdin);
//	freopen("o5.txt", "wb", stdout);
	deal();
} 
