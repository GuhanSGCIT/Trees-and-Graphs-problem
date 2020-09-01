/*
There are two people walking along a tree with N nodes (numbered 1 through N), each of them with speed 1 edge per second.

The walk of the first person is described by a sequence of nodes u1,u2,…,uK . This person appears in node u1 at time 0 and walks
to node u2 using the shortest path; then, immediately after reaching u2, walks to node u3 using the shortest path, and so on, until
reaching uK, when this person disappears.

The walk of the second person is described by another sequence v1,v2,…,vL in the same manner.

Count how many times these two people meet — in other words, how many times they reach the same node (including the first and last
nodes of their walks) at the same time.

timing:3sec
level:7

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains three space-separated integers N, K and L.
Each of the next N−1 lines contains two space-separated integers p and q describing an edge between node p and node q.
The following line contains K space-separated integers u1,u2,…,uK.
The last line contains L space-separated integers v1,v2,…,vL.

Output
For each test case, print a single line containing one integer — the number of times the two people meet.

Constraints
1≤T≤1,000
2≤N,K,L≤10^5

Input
1
5 4 3
1 2
2 3
2 4
4 5
1 4 3 5
1 3 5

Output:
3

input:
1
4 5 6
1 2
1 3
2 4
5 1 5 2 4
1 5 2 4 2 3

output:
0

input:
2
2 3 3
1 2
3 2 1
2 4 5
3 4 5
1 2
2 3
4 5 6 1
5 2 1 4 3

output:
2
0

input:
1
2 3 4
1 2
2 1 3
1 5 2 3

output:
0

input:
1
2 2 2
1 3
3 4
2 1

output:
1

hint:
First thing, while splitting paths, we never move to next step for a person, till we complete current step.
Second thing, we have to count vertices systematically. For example, at every step, i counted the vertices at every step, Including target vertex, but excluding start vertex, while tester included first vertex, while excluded last vertex.

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) x.begin(),x.end()
#define finc(i,a,b) for(int _b=b,i=a;i<=_b;++i)
#define fdec(i,a,b) for(int _b=b,i=a;i>=_b;--i)
inline ll read() {ll x=0; bool neg=false; char c=getchar(); while (c!='-'&&(c<'0'||c>'9')) c=getchar(); if (c=='-') neg=true, c=getchar(); while (c>='0'&&c<='9') x=x*10+c-'0', c=getchar(); if (neg) x=-x; return x;}
inline void write(ll x){ if (x<0) { putchar('-'); x=-x; } if (x>9) write(x/10); putchar(x%10+'0'); }
#define read(x) x=read();
#define pb push_back
#define ii pair<int,int>
#define fi first
#define se second
#define _ putchar(' ')
#define __ putchar('\n')

const int           maxn    =   100000;
int                 n,k1,k2,Tin[maxn+1],H[maxn+1],P[maxn+1][17];
vector<int>         G[maxn+1],path1,path2;
void dfs(int u,int dad,int depth){
    H[u]=depth;
    P[u][0]=dad; finc(j,1,16) P[u][j]=P[P[u][j-1]][j-1];
    for(auto &v:G[u]){
        if (v==dad) continue;
        dfs(v,u,depth+1);
    }
}
int lca(int u,int v){
    if (H[u]>H[v]) swap(u,v);
    int diff=H[v]-H[u];
    fdec(j,16,0) if (diff>>j&1) v=P[v][j];
    if (u==v) return u;
    fdec(j,16,0) if (P[u][j]!=P[v][j]) u=P[u][j],v=P[v][j];
    return P[u][0];
}
void readpath(int &k,vector<int> &path){
    path.clear();
    int pre; read(pre); path.pb(pre);
    finc(i,2,k){
        int u; read(u);
        int p=lca(pre,u); if (p!=pre&&p!=u) path.pb(p);
        path.pb(u);
        pre=u;
    }
    k=path.size();
}
int Kpar(int u,int k){
    fdec(j,16,0) if (k>>j&1) u=P[u][j];
    return u;
}
int findK(int u,int v,int k){
    if (H[u]>H[v]) return Kpar(u,k);
              else return Kpar(v,H[v]-H[u]-k);
}
int common(int u1,int v1,int u2,int v2){
    if (H[u1]-H[v1]==H[u2]-H[v2]){
        if (H[u1]!=H[u2]) return 0;
        if (H[u1]<H[v1]) swap(u1,v1),swap(u2,v2);
        return max(0,H[lca(u1,u2)]-H[v1]+1);
    }
    if (H[u1]>H[v1]) swap(u1,v1),swap(u2,v2);
    if (H[u1]>H[u2]) return 0;
    int diff=(H[u2]-H[u1])/2;
    fdec(j,16,0) if (diff>>j&1) u2=P[u2][j];
    if (H[u2]<H[v2]) return 0;
    u1=findK(u1,v1,diff);
    if (u1==u2) return 1;
    return 0;
}
int main(){
    int T; read(T); while (T--){
        read(n); read(k1); read(k2);
        finc(i,1,n) G[i].clear();
        finc(i,1,n-1){
            int u,v; read(u); read(v);
            G[u].pb(v); G[v].pb(u);
        }
        dfs(1,1,1);
        readpath(k1,path1);
        readpath(k2,path2);
        int U=path1[0],V=path2[0];
        if ((H[U]&1)!=(H[V]&1)){
            write(0);__;
            continue;
        }
        ll res=(U==V);
        int ptr1=1,ptr2=1;
        while (ptr1!=k1&&ptr2!=k2){
            int toU=path1[ptr1],
                toV=path2[ptr2];
            int k=min(abs(H[U]-H[toU]),abs(H[V]-H[toV]));
            int nextU=findK(U,toU,k),
                nextV=findK(V,toV,k);
            res+=common(U,nextU,V,nextV)-(U==V);
            U=nextU;V=nextV;
            if (nextU==toU) ++ptr1;
            if (nextV==toV) ++ptr2;
        }
        write(res);__;
    }
    return 0;
}
