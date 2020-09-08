/*
Varun has a rooted tree with N vertices (numbered 1 through N); vertex 1 is the root of the tree. Initially, there are some bacteria
in its vertices. Let's denote the number of sons of vertex v by sv; a leaf is a vertex without sons. During each second, the following
events happen:
    1.)For each non-leaf vertex v, if there are x bacteria in this vertex at the start of this second, they divide into sv⋅x bacteria.
At the end of this second, x of these bacteria instantly move to each of its sons (none of them stay in vertex v). The original x
bacteria do not exist any more.
    2.)Zero or more bacteria appear in one vertex. These bacteria do not divide or move at this second.

Initially, we are at the start of second 0. You should process Q queries ― one query during each of the seconds 0 through Q−1.
There are two types of queries:
    1.)+ v k: During this second, k bacteria appear in vertex v.
    2.)? v: Find the number of bacteria in vertex v at the end of this second ― after the divided bacteria have moved.

Input
The first line of the input contains two space-separated integers N and Q.
Each of the next N−1 lines contains two space-separated integers x and y denoting that vertices x and y are connected by an edge.
The next line contains N space-separated integers a1,a2,…,aN denoting the initial numbers of bacteria in vertices 1 through N.
Q lines follow. Each of these lines describes a query in the format + v k or ? v.

Output
For each query of the second type, print a single line containing one integer ― the number of bacteria in the given vertex.

Constraints
1≤N,Q≤5⋅10^5
1≤ai≤10^9
for each valid i
1≤x,y≤N
the graph described on the input is a tree
1≤v≤N
1≤k≤10^9

Input
5 8
4 3
3 1
5 2
1 2
1 10 4 9 4
+ 1 6
? 3
+ 3 5
? 3
+ 2 2
+ 5 10
? 5
? 4

Output
6
0
33
25

Explanation
The numbers of bacteria in all vertices at the end of each second are:
0-th second: 6,1,1,13,14
1-st second: 0,6,6,14,15
2-nd second: 0,0,5,20,21
3-rd second: 0,0,0,25,21
4-th second: 0,2,0,25,21
5-th second: 0,0,0,25,33
6-th second: 0,0,0,25,33
7-th second: 0,0,0,25,33

input:
4 3
2 3
2 4
3 5
5 2 3 4
+ 1 1
? 2
+ 2 3
 

output:
0

input:
7 5
1 3
1 2
3 4
2 5
4 6
4 7
5 2 6 3 1 4 7
+ 1 2
+ 4 5
? 3
+ 3 2
? 4

output:
0
2

input:
8 4
4 5
1 2
3 6
7 5
5 2
1 2
5 6
1 2 3 4 5 6 7 8
+ 2 3
? 3
+ 4 5
? 5

output:
14
0

input:
4 3
2 3
2 1
3 4
2 3 4 5
+ 4 3
? 2
+ 1 2

output:
0

hint:
First, we need to compute the DFS order of a tree. The DFS order is the order of nodes that we encounter during a Depth-first search,
and it can be computed by the following pseudocode:
DFS(x)
  push vertex x to the DFS order
  for (v in children of x)
    DFS(v)


*/
#include<bits/stdc++.h>
#define put(x) cout<<#x<<" = "<<x<<endl;
using namespace std;
const int maxn=2e6+10,maxq=4e6+10;
const char addQuery='+',askQuery='?';

struct Query{
	int id,time,v,k;
	long long answer;
	char type;
	Query(){}
	Query(int _id,char _type,int _time,int _v,int _k=0,long long _answer=0){
		id=_id;
		type=_type;
		time=_time;
		v=_v;
		k=_k;
		answer=_answer;
	}
};

int n,q,H[maxn];
int qsize=0,startingTime[maxn],finishingTime[maxn],curTime=0;
long long A[maxn];
bool isLeaf[maxn];
vector<int> G[maxn];
Query Q[maxq];
int Qper[maxq];

void dfs(int a,int par=-1){
	startingTime[a]=curTime++;
	for(int b:G[a]){
		if(b!=par){
			H[b]=H[a]+1;
			dfs(b,a);
		}
	}
	if(int(G[a].size())-(par!=-1)==0){
		isLeaf[a]=1;
	}
	finishingTime[a]=curTime;
}

struct FenwickTree{
	long long s[maxn];
	bool mark[maxn];
	int history[maxn],historySize=0;
	void add(int x,long long value){
		x+=5;
		if(!mark[x]){
			mark[x]=1;
			history[historySize++]=x;
		}
		for(int i=x;i<maxn;i+=i&-i){
			s[i]+=value;
		}
	}

	// [L,R)
	void add(int L,int R,long long value){
		add(L,+value);
		add(R,-value);
	}

	long long ask(int x){
		x+=5;
		long long ans=0;
		for(int i=x;i>0;i-=i&-i){
			ans+=s[i];
		}
		return ans;
	}

	void clear(){
		for(int i=0;i<historySize;i++){
			int a=history[i];
			mark[a]=0;
			for(int j=a;j<maxn;j+=j&-j){
				s[j]=0;
			}
		}
		historySize=0;
	}
}fenwick[2];


int32_t main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs(0);
	for(int i=0;i<n;i++){
		scanf("%d",A+i);
		// this query doesn't need to have a valid id
		Q[qsize++]=Query(maxq,addQuery,-H[i],i,A[i]);
	}
	for(int i=1;i<=q;i++){
		Q[qsize].id=i;
		scanf(" %c",&Q[qsize].type);
		if(Q[qsize].type==askQuery){
			scanf("%d",&Q[qsize].v);
			Q[qsize].v--;
			Q[qsize].time=i-H[Q[qsize].v];
		}else if(Q[qsize].type==addQuery){
			scanf("%d%d",&Q[qsize].v,&Q[qsize].k);
			Q[qsize].v--;
			Q[qsize].time=i-H[Q[qsize].v];
		}else{
			assert(0);
		}
		qsize++;
	}
	for(int i=0;i<qsize;i++){
		Qper[i]=i;
	}
	sort(Qper,Qper+qsize,[](int a,int b){
		if(Q[a].time!=Q[b].time){
			return Q[a].time<Q[b].time;
		}
		// For queries with the same time, addQuery has more priority
		return Q[a].type=='+' && Q[b].type=='?';
	});
	for(int i=0;i<qsize;i++){
		if(i>0 && Q[Qper[i-1]].time!=Q[Qper[i]].time){
			fenwick[1].clear();
		}
		if(Q[Qper[i]].type==addQuery){
			fenwick[0].add(startingTime[Q[Qper[i]].v],finishingTime[Q[Qper[i]].v],Q[Qper[i]].k);
			fenwick[1].add(startingTime[Q[Qper[i]].v],finishingTime[Q[Qper[i]].v],Q[Qper[i]].k);
		}
		if(Q[Qper[i]].type==askQuery){
			int fenwickId=1;
			if(isLeaf[Q[Qper[i]].v]){
				fenwickId=0;
			}
			Q[Qper[i]].answer=fenwick[fenwickId].ask(startingTime[Q[Qper[i]].v]);
		}
	}
	for(int i=0;i<qsize;i++){
		if(Q[i].type==askQuery){
			printf("%lld\n",Q[i].answer);
		}
	}
}
