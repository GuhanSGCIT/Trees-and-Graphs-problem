/*
For a string S consisting of characters S1, S2, ..., SN,
S[i, j] denotes the substring of characters Si, Si + 1, ..., Sj.
LCP(S1, S2) is defined as the length of the longest common prefix of strings S1 and S2.

Given positive integers N, K and M, count how many binary strings S of length N exist such that there exist more than M
indices i such that LCP(S[1, i], S[i + 1, N]) ≥ K and 1 ≤ i < N.

timing:1sec
level:5

Input Description:
    The first line of the input contains an integer T denoting the number of test cases.
    The first line of each test case contains three integers denoting N, K and M. 

Output Description:
For each test case, output the required number modulo 10^9 + 7.

Constraints
    1 ≤ T ≤ 5
    1 ≤ N ≤ 50
    0 ≤ M ≤ N - 1
    0 ≤ K ≤ min(10, N)

Input:
1
3 1 1
Output:
2

Explanation
The two strings which satisfy the conditions are "000" and "111".

Input:
2
3 1 0
2 5 8

Output:
6
0

Input:
3
8 4 6
2 1 5
1 1 1

Output:
0
0
0

Input:
2
4 2 0
2 1 0
4 2 0

Output:
4
2

Input:
5
50 48 0
4 2 0
15 14 0
8 4 0
45 2 4

Output:
0
4
0
16
818878460

Code:
*/
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
inline int getint() {
	register char ch;
	while(!isdigit(ch=getchar()));
	register int x=ch^'0';
	while(isdigit(ch=getchar())) x=(((x<<2)+x)<<1)+(ch^'0');
	return x;
}
typedef long long int64;
const int N=51,K=11,M=1024,mod=1e9+7;
int f[2][N][K],g[M][K];
inline void upd(int &a,const int &b) {
	(a+=b)%=mod;
}
int main() {
	for(register int T=getint();T;T--) {
		const int n=getint(),k=getint(),m=getint();
		if(k==0) {
			printf("%lld\n",(1ll<<n)%mod);
			continue;
		}
		if(m+1==n||k*2>n) {
			puts("0");
			continue;
		}
		const int all=(1<<k)-1;
		int ans=0;
		for(register int s=0;s<=all/2;s++) {
			int p[k+1];
			for(register int i=0,t=s;i<=k;i++) {
				p[k-i]=t;
				t>>=1;
			}
			memset(f[0],0,sizeof f[0]);
			for(register int t=0;t<=all;t++) {
				for(register int i=1;i<=k;i++) {
					int l;
					for(l=i;l;l--) {
						if(p[l]==(t&((1<<l)-1))) break;
					}
					g[t][i]=l;
				}
				f[0][t==s][g[t][k]]++;
			}
			for(register int i=k*2+1;i<=n;i++) {
				const bool cur=i&1;
				memset(f[cur],0,sizeof f[cur]);
				for(register int j=0;j<=i;j++) {
					for(register int i=0;i<=k;i++) {
						for(register int b=0;b<2;b++) {
							const int t=((p[i]<<1)|b)&all;
							const int l=g[t][std::min(i+1,k)];
							upd(f[cur][j+(l==k)][l],f[!cur][j][i]);
						}
					}
				}
			}
			for(register int j=m+1;j<=n;j++) {
				for(register int i=0;i<=k;i++) {
					(ans+=f[n&1][j][i])%=mod;
				}
			}
		}
		printf("%d\n",(ans<<1)%mod);
	}
	return 0;
}
