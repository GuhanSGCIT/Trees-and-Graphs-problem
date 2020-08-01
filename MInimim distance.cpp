/*
Question:(Composition)
You are given two line segments AB and CD in N-dimensional space. Find the minimum distance between them, i.e. the minimum distance |PQ| 
over all points P∈AB and Q∈CD.

Note: Because of large I/O, please use fast I/O methods.

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers a1,a2,…,aN denoting the coordinates of the point A.
The third line contains N space-separated integers b1,b2,…,bN denoting the coordinates of the point B.
The fourth line contains N space-separated integers c1,c2,…,cN denoting the coordinates of the point C.
The fifth line contains N space-separated integers d1,d2,…,dN denoting the coordinates of the point D.

Output Description:
For each query, print a single line containing one real number - the minimum distance between the line segments. 
Your output will be considered correct if the absolute or relative error does not exceed 10−12.

Constraints
1≤T≤10^5
3≤N≤10^5
0≤ai,bi,ci,di≤1,000
for each valid i
the sum of N over all test cases does not exceed 10^6

Example Input
2
3
879 130 645
214 801 973
487 518 681
186 74 684
3
810 702 731
598 325 737
158 871 316
336 999 983

Example Output
146.899739355990
587.980716360221

Input:
1
2
45 85
25 28
65 12
84 63

Output:
43.06902896407313

Input:
1
4
1 2 3 4
5 8 2 6
4 9 6 2
4 8 5 2

Output:
4.69602295340934

Input:
2
3
156 264 894
458 12 121
159 954 623 
78 41 55
2
12 21 
32 23
48 84 
95 59

Output:
354.41347986155603
61.36902330880951

Input:
1
1
100
200
196
65165

Output:
0.00000000000000

code:

*/
#include <bits/stdc++.h>
#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define N 			100005
#define W 			40000
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
int get(int *a,int *b,int *c,int *d){
	int res=0;
	rep(i,0,n) res+=(b[i]-a[i])*(d[i]-c[i]);
	return res;
}
double dis(double *a,double *b){
	double res=0;
	rep(i,0,n) res+=(b[i]-a[i])*(b[i]-a[i]);
	return sqrtl(res);
}
double dis(int *a,int *b){
	double res=0;
	rep(i,0,n) res+=(b[i]-a[i])*(b[i]-a[i]);
	return sqrtl(res);
}
double dis(int *a,double *b){
	double res=0;
	rep(i,0,n) res+=(b[i]-a[i])*(b[i]-a[i]);
	return sqrtl(res);
}
double ptw[N];
double dist(int *c,int *a,int *b){
	int a1=get(a,c,a,b);
	int b1=get(a,b,a,b);
	if(b1==0) return dis(c,a);
	double x=1.0l*a1/b1;
	double ans=dis(c,a);
	ans=min(ans,dis(c,b));
	if(x>=0.0 and x<=1.0){
		rep(i,0,n) ptw[i]=a[i]+x*(b[i]-a[i]);
		ans=min(ans,dis(c,ptw));
	}
	return ans;
}
int a[N],b[N],c[N],d[N];
double ptab[N],ptcd[N];
void solve(){
	double ans=1e18;
	cin>>n;
	rep(i,0,n) cin>>a[i];
	rep(i,0,n) cin>>b[i];
	rep(i,0,n) cin>>c[i];
	rep(i,0,n) cin>>d[i];
	int a1=get(a,c,a,b);
	int b1=get(c,d,a,b);
	int c1=-get(a,b,a,b);
	int a2=get(a,c,c,d);
	int b2=get(c,d,c,d);
	int c2=-get(a,b,c,d);
	double den=(1.0l*b2/W)*c1-(1.0l*b1/W)*c2;
	double numx=(1.0l*a2/W)*b1-(1.0l*a1/W)*b2;
	double numy=(1.0l*a1/W)*c2-(1.0l*a2/W)*c1;
	if(abs(den)>1e-6){
		double x=1.0l*numx/den;
		double y=1.0l*numy/den;
		if(0.0<=x and x<=1.0 and 0.0<=y and y<=1.0){
			rep(i,0,n) ptab[i]=a[i]+x*(b[i]-a[i]);
			rep(i,0,n) ptcd[i]=c[i]+y*(d[i]-c[i]);
			ans=min(ans,dis(ptab,ptcd));
		}
	}
	ans=min(ans,dist(a,c,d));
	ans=min(ans,dist(b,c,d));
	ans=min(ans,dist(c,a,b));
	ans=min(ans,dist(d,a,b));
	cout<<fixed<<setprecision(14)<<ans<<endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}