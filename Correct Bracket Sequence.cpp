/*
A string consisting only of parentheses ('(' and ')') is called a bracket sequence. Some bracket sequence are called correct bracket sequences(CBS). More formally:
    Empty string is a CBS.
    If S is a CBS, then (S) is also a CBS.
    If S and T are CBS, then ST (concatenation of S and T) is also a CBS.

A 'good' CBS is a sequence where the first (N/2) characters are '(' and the next (N/2) characters are ')',where N is the length of sequence.
You are given two numbers N and K. Find the probability that a N length CBS can be converted into a 'good' CBS by at most K 'good' swaps. A swap is 'good' if the sequence after the swap is a CBS.

If the answer is of the form P/Q where P and Q are coprime, print (P*Q-1) modulo 1000000007.

timing:3sec
level:6

Input Format:
The first line contains an integer T, the number of test cases.
Next T lines contains two space separated integers N, K.

Output Format:
For each test case, output the corresponding answer in a separate line.

Constraints:
    1<=T<=20
    1<=N<=100000
    0<=K<=100000
    N is even.

Sample Input:
1
8 1

Sample Output:
714285720

Explanation:
Correct Bracket sequences for n = 8:
1. (((())))
2. ((()()))
3. (()(()))
4. ()((()))
5. ((())())
6. (()()())
7. ()(()())
8. (())(())
9. ()()(())
10. ((()))()
11. (()())()
12. ()(())()
13. (())()()
14. ()()()()
In 3, the 3rd and 5th characters can be swapped to form a good CBS since it is a good swap.
Similarly 1,2,4,5,6,7,10,11,12 can also be converted to good CBS.
Thus the probability is 10/14. 

input:
2
4 8
9 18

output:
1
1

input:
1
9 5

output:
1

input:
2
6 1
1 7

output:
1
1

input:
3
4 8
9 1
2 7

output:
1
714285720
1

hint:
The number of closing bracket sequences in the first half of the sequence be x. Those paths will pass through (n-x,x).
Therefore the number of such paths is equal to (C(n,x)-C(n,x-1))^2 where 0<=x<=min(k,n/2).So the probability turns out to be
summation(i=0 to min(n/2,k))(C(n,i)-C(n,i-1)))/(C(2n,n)-C(2n,n-1)).
 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int md = 1e9+7;
const int N =  100005;
int fact[N],ifact[N];

int power(int a,int b)
{
	int ans = 1;
	while(b)
	{
		if(b&1)
			ans=((ll)ans*a)%md;
		a = ((ll)a*a)%md;
		b>>=1;
	}
	return ans;
}
int nCr(int n,int k)
{
	if(n<k || k<0)
		return 0;
	int ans = fact[n];
	ans = ((ll)ans*ifact[n-k])%md;
	ans = ((ll)ans*ifact[k])%md;
	return ans;
}
int main()
{
	fact[0] = 1;
	ifact[0] = 1;
	for(int i=1;i<N;i++)
		fact[i] = ((ll)fact[i-1]*i)%md;
	ifact[N-1] = power(fact[N-1],md-2);
	for(int i = N-2;i>=0;i--)
		ifact[i] = ((ll)ifact[i+1]*(i+1))%md;
	int t;
	scanf("%d",&t);
	while(t--)
	{
	int n,k;
	scanf("%d %d",&n,&k);
	n>>=1;
	int ans = 0;
	for(int i=0;i<=min(n/2,k);i++)
	{
		int val = (nCr(n,i)-nCr(n,i-1))%md;
		ans = (ans + ((ll)val*val)%md)%md;
	}
	ans = ((ll)ans*power(nCr(2*n,n),md-2))%md;
	ans = ((ll)ans*(n+1))%md;
	printf("%d\n",ans);
	}
	return 0;
}
