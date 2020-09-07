/*
Keeping in mind the situation of coronavirus pandemic. Pappu decided to distribute presents to bring some positivity . But,
this time he has with him a limited amount of gifts to give away. So, not everyone is lucky to get them but only the smart ones.
He asks a simple question and who gets to the answer receives the present.He has N bags with him, each of them containing K identical
lower case English alphabets. No two bags contain same character. He wants to arrange all the N∗K characters into a segment such that there exists at least 1 sub-segment of length K
having characters picked from the same bag. Now, He is curious to know in how many ways he can do such arrangements.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two integers N,K.

Output:
For each testcase, output your answer to Santa modulo 10^9+7 in a new line.

Constraints
1≤T≤10^5
1≤N≤26
1≤K≤10^4

Sample Input:
1
2 2

Sample Output
4

EXPLANATION:
Let 1 of the bag contain 2a′s and the other 2b′s. The possible arrangements will be
[a,a,b,b]
[a,b,b,a]
[b,a,a,b]
[b,b,a,a]

input:
3
7 14
8 16
2 4

output:
108269155
405689655
8

input:
2
24 48
1 11

output:
199757874
1

input:
1
2 3

output:
6

input:
3
1 1
2 5
6 4

output:
1
10
489678530

hint:
We can solve this problem simply by using inclusion exclusion principle. let Ai be the event denoting that character
from ith bag should remain together. So clearly SnS_{n}Sn​ =∣A1⋃A2⋃A3...⋃An∣ will be the required answer.
*/
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define sz(x) (int)x.size()
#define mex 500005

inline ll binex(ll a,ll b)
{
 ll ans=1,temp=a%mod;
 while(b!=0){
     if(b&1) ans=(ans*temp)%mod;
     temp=(temp*temp)%mod;
     b=b>>1;
 }
 return ans;
 }

 int main()
 {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL); cout.tie(NULL);
      ll fact[mex],inv[mex];
      fact[0]=1; inv[0]=1;
      for(int i=1;i<mex;i++){
        fact[i]=(i*fact[i-1])%mod;
       inv[i]=binex(fact[i],mod-2);
    }    
     int t; cin>>t;
     assert(t>=1 && t<=100000);
    while(t--){
         int n,k; cin>>n>>k;
    assert(n>=1 && n<=26);
    assert(k>=1 && k<=10000);
    ll ans=0;
    int temp=1;
    for(int i=1;i<=n;i++){
        ll x=(((fact[n]*inv[i])%mod)*inv[n-i])%mod;
        ll y=(fact[i+k*(n-i)]*binex(inv[k],n-i))%mod;
        x=(temp*x*y)%mod; 
        x=(x+mod)%mod;
        ans=(ans+x)%mod;
        temp*=-1;
    }
    cout<<ans<<endl;
}
} 
