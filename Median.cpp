/*
You are given an integer sequence A1,A2,…,AN and integers K and M. For 1≤i≤j≤N, let's define S(i,j) as the number of ways to choose
exactly K elements of the contiguous subsequence Ai,Ai+1,…,Aj in such a way that the median of these K elements is ≥ M.

Find the sum of S(i,j) over all i,j such that 1≤i≤j≤N. Since this sum may be large, calculate it modulo 10^9+7.

Input
The first line of the input contains three space-separated integers N, K and M.
The second line contains N space-separated integers A1,A2,…,AN.

Output:
Print a single line containing one integer — ∑ Ni=1;Nj=i; S(i,j) modulo 10^9+7.

Constraints
1≤N≤10^5
3≤K≤100
K is an odd number
1≤M≤200
1≤Ai≤10^9
for each valid i all elements of A are pairwise distinct

Example Input
4 3 2
1 2 3 4

Example Output
6

Explanation
S(1,1)=S(1,2)=S(2,2)=S(2,3)=S(3,3)=S(3,4)=S(4,4)=0, S(1,3)=S(2,4)=1 and S(1,4)=4.

input:
4 5 6
1 2 3 4

output:
0

input:
4 4 5
2 4 5 7

output:
1

input:
7 4 5
1 2 3 4 5 6 7

output:
50

input:
6 4 5
2 3 4 5 6 1

output:
14


hint:
Let’s replace every element which is less than MMM by 0 and the rest by 1. Now we are currently interested in subsequences where the
number of ones is strictly more than half of K.


*/
#include<bits/stdc++.h>
 
using namespace std;
 
const int MX = (1<<20);
 
typedef long long ll;
 
int n , M , K , arr[MX];
 
int dp[2][105][55];
 
int MOD = 1e9 + 7;
 
int main(){
 
    scanf("%d %d %d",&n,&K,&M);
 
    for(int j = 1 ; j <= n ; j++){
        scanf("%d",&arr[j]);
    }
 
    for(int j = 1 ; j <= n ; j++){
        if(arr[j] >= M) arr[j] = 1;
        else arr[j] = 0;
    }
 
    dp[0][0][0] = 1;
 
    int cur = 1;
 
    long long ans = 0;
 
    int upper = 51;
 
    for(int pos = 1 ; pos <= n ; pos++){
 
        dp[cur][0][0] = dp[cur^1][0][0];
 
        dp[cur][1][0] = dp[cur^1][1][0];
 
        dp[cur][1][1] = dp[cur^1][1][1];
 
        dp[cur][1][arr[pos]] += pos; dp[cur][1][arr[pos]] %= MOD;
 
        for(int take = 2 ; take <= min(pos , K) ; take++){
 
            for(int sum = 0 ; sum < upper ; sum++){
 
                dp[cur][take][sum] = dp[cur^1][take][sum];
 
                dp[cur][take][sum] += dp[cur^1][take - 1][sum - arr[pos]];
 
                dp[cur][take][sum] %= MOD;
            }
 
 
            if(take >= upper){
 
                dp[cur][take][upper] = dp[cur^1][take][upper];
 
 
                dp[cur][take][upper] += dp[cur^1][take - 1][upper];
                dp[cur][take][upper] %= MOD;
 
 
                if(arr[pos] == 1)
                    dp[cur][take][upper] += dp[cur^1][take - 1][upper - arr[pos]];
 
                dp[cur][take][upper] %= MOD;
            }
 
        }
 
 
        for(int take = (K + 1)/2 ; take <= min(K , upper) ; take++){
            long long theta = dp[cur][K][take] - dp[cur^1][K][take];
            theta += MOD; theta %= MOD;
            theta *= (n - pos + 1);
            theta %= MOD;
            ans += theta;
            ans %= MOD;
        }
 
        cur ^= 1;
    }
 
    cout<<ans<<endl;
 
}
