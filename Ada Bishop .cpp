/*
Ada has the biggest chessboard in wasteLand. It has N rows (numbered 1 through N) and M columns (numbered 1 through M), where M≥2N. As training for her upcoming world chess championship match, she placed one bishop at row r and column c of her board. The remaining squares of the board are empty. Now, she is calculating the number of squares that can be reached by the bishop in at most K
moves. Help Ada verify her answers.

Remember that in one move, a bishop at row r and column c can move to another square at row r′ and column c′ if and only if either r+c=r′+c′ or r−c=r′−c.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains five space-separated integers N, M, r, c and K.

Output
For each test case, print a single line containing one integer — the number of reachable squares.

Constraints
1≤T≤5⋅10^5
1≤N,K≤10^9
2N≤M≤10^9
1≤r≤N
1≤c≤M

Example Input
1
3 7 1 1 2

Example Output
7

Explanation:
Given starting position (r,c)(r,c)(r,c) of the bishop in a N∗M chessboard, Find the number of distinct squares that can be visited within KKK moves.

input:
1
5 2 6 5 4

output:
5

input:
2
5 7 4 3 1
3 2 5 7 4

output:
8
1

input:
1
7 4 1 1 2

output:
14

input:
1
7 4 5 4 1

output:

hint:
Just divide the board into two parts of the same height, one with first C columns while other with M−C+1 columns. We see that Number of reachable positions in the original board is just number of reachable positions in both new boards less number of reachable positions in Cth column since it gets included in both.

*/
#include<bits/stdc++.h>

using namespace std;
long long n,m,r,c,k;
long long n1,m1,r1,c1,k1;
int d[200][200];

const int inf =50000;
queue<pair<int,int>> q;

void bfs(int x, int y)
{
    q.push({x,y});
    d[x][y]=0;

    while(!q.empty())
    {
        pair<int,int> node = q.front();
        q.pop();

        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            if (d[i][j]==inf && (i+j==node.first+node.second || i-j==node.first-node.second))
            {
                d[i][j]=d[node.first][node.second]+1;
                q.push({i,j});
            }
    }
  return ;
}


long long parnih(long long x, long long y, long long n, long long m)
{
    long long tot=n*m;
    if (tot%2==0) return tot/2;
    if ((x&1)==(y&1)) return tot-tot/2; else return tot/2;
}

long long sum(long long l, long long r)
{
    return (r*(r+1))/2-(l*(l+1))/2;
}
long long dijagonala(long long ima, long long duzina)
{
   long long ans=0;

   if (ima&1)
   {
       ans=(ima+1)/2;
       duzina--;
       ans+=2*sum(ima/2 - duzina/2,ima/2);
       if (duzina&1) ans+=ima/2-duzina/2;
   }
   else
   {
       ans+=2*sum(ima/2-duzina/2,ima/2);
       if (duzina&1)
        ans+=ima/2-duzina/2;
   }

   return ans;
}
long long resi(long long n, long long m, long long r, long long k)
{
    long long g=r;
    long long d=n-r+1;

    long long side=d+g-2;
    if (side*(k-1)>=m) return parnih(r+1,2,n,m);

    long long ans=0;

    long long prvi=parnih(r+1,2,n,side);
    long long drugi=parnih(side+1+n-r,1+side,n,side);

    ans=prvi*(k/2) +drugi*((k-1)/2);

    if (k%2==0) {
        r=n-r+1;
        swap(g,d);
    }

    m-=(k-1)*side;

    long long dole=n-r+1;
    long long gore=r;

    g=min(r,m);
    d=min(n-r+1,m);

    ans+=dijagonala(dole,d);
    ans+=dijagonala(gore,g);
    ans--;
    return ans;
}

long long resi1(long long n, long long m, long long r, long  long c, long long k)
{

    if (r==n) r=1;
    if (c==m) c=1;

    if ((k-1)*(n-1)>=m) return parnih(2,2,n,m);

    long long ans=(k-1)*n*(n-1)/2;
    m-=(k-1)*(n-1);
    long long d=min(n,m);
    ans+=dijagonala(n,d);
    return ans;
}
long long  solve()
{

    scanf("%lld%lld%lld%lld%lld",&n,&m,&r,&c,&k);
//    n=rand()%50+1;
//    m=rand()%n+2*n;
//    r=rand()%n+1;
//    c=rand()%n+1;
//    k=rand()%30+1;

    n1=n;
    m1=m;
    r1=r;
    c1=c;
    k1=k;

    if (k==1)
    {
       long long rez=min(n-r+1,m-c+1);
       rez+=min(r,c);
       rez+=min(n-r+1,c);
       rez+=min(r,m-c+1);
       rez-=3;
       return rez;
    }

    if ((r==1 || r==n) && (c==1 || c==m))
        return resi1(n,m,r,c,k);

     long long ans=0;

     if (c>=n)
     ans+=resi(n,c,r,k);
    else
    ans+=parnih(c+r,2,n,c);

     if (m-c+1>=n)
     ans+=resi(n,m-c+1,r,k);
    else
    ans+=parnih(c+r,1+c,n,m-c+1);
    if (r&1) ans-=(n+1)/2; else ans-=n/2;

   return ans;
}

long long do_it()
{
    n=n1;
    m=m1;
    r=r1;
    c=c1;
    k=k1;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            d[i][j]=inf;

    bfs(r,c);

    long long  ans=0;

    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        if (d[i][j]<=k) ans++;

   return ans;
}
int main()
{
    int t;
   scanf("%d",&t);

   while(t--){
    long long ans=solve();
    //long long ans1=do_it();

     printf("%lld\n",ans);
    // cout<<ans<<" "<<ans1<<endl;
    //if (ans!=ans1) printf("Greksa %lld %lld %lld %lld %lld\n",n1,m1,r1,c1,k1);
   }
}
