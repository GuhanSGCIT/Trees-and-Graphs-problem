/*
Now its time for the final battle between Eon and Codezilla. There are N weapons available numbered from 1 to N.
The cost of weapon i is C[i] (1<=i<=N). There will be M attacks. In each attack Eon will choose K weapons from the range
of weapons numbered between L and R (both inclusive). All weapons have the same damage power. Eon wants to spend the minimum
amount possible for each attack .Tell Eon the amount that he will need to spend for each attack.

timing:0.196262 secs
level:5

Input Description:
First line of the input contains an integer N. The next line contains N space separated integers representing the array C
representing the cost of the weapons. Next line contains an integer M. Each of the next M lines contains three integers L, R and K.

Output Description:
Output should consists of M lines. The i'th line should contain the minimum amount that Eon needs to spend for the i'th attack.
Since the answer can be large, output the answer modulo 10^9+7.

Constraints
    1 ≤ N ≤ 20000
    1 ≤ M ≤ 20000
    1 ≤ L ≤ R ≤ N
    1 ≤ K ≤ R-L+1
    1 ≤ C[i] ≤ 10^9

Input:
5
9 3 5 3 1
2
1 3 2
2 5 3

Output:
8
7

Explanation
Example case 1. Eon will choose the weapons 2 and 3. So the answer is 3+5=8.
Example case 2. Eon will choose the weapons 2, 4 and 5. So the answer is 1+3+3=7.

Input:
4
5 4 6 2
3
4 5 6
7 5 3
1 5 9

Output:
999999992
0
0

Input:
8
1 2 3 4 5 6 7 8
5
1 5 9
7 8 9
6 5 2
2 5 8
1 4 7

Output:
15
15
0
14
10

Input:
5
9 8 7 4 5
1
5 8 1

Output:
999999979

Input:
2
1 4
2
1 5 4
9 5 4

Output:
0
0

code:
*/
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MOD 1000000007

struct node
{
    int n,l,r;
    long long sum;
} buf[400000];    

int N,i,j,T,Q,pos[20000+10],roots[20000+10],num;
vector<pair<int,int> > a;
int insert(int id,int l,int r,int v);
long long query(int lr,int rr,int l,int r,int k);

int main()
{
    scanf("%d",&N);
    for(i = 0; i < N; i++)
    {
        scanf("%d",&j);
        a.pb(mp(j,i+1));
    }
    sort(all(a));
    for(i = 0; i < N; i++)
        pos[a[i].second] = i+1;
    roots[0] = 0;
    for(i = 1; i <= N; i++)
        roots[i] = insert(roots[i-1],1,N,pos[i]);
    scanf("%d",&Q);
    while(Q--)
    {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        printf("%lld\n",query(roots[l-1],roots[r],1,N,k));
    }
    
    return 0;
}

int insert(int id,int l,int r,int v)
{
    int idx = ++num;
    buf[idx] = buf[id];
    if(l == r)
    {
        buf[idx].sum = a[l-1].first;
        buf[idx].n = 1;
        return idx;
    }
    int mid = (l + r) / 2;
    if(v <= mid) buf[idx].l = insert(buf[idx].l,l,mid,v);
    else         buf[idx].r = insert(buf[idx].r,mid+1,r,v);
    buf[idx].sum = (buf[buf[idx].l].sum + buf[buf[idx].r].sum) % MOD;
    buf[idx].n = buf[buf[idx].l].n + buf[buf[idx].r].n;
    return idx;
}

long long query(int lr,int rr,int l,int r,int k)
{
    if(l == r)
        return buf[rr].sum - buf[lr].sum;
    int mid = (l + r) / 2;
    int left = buf[buf[rr].l].n - buf[buf[lr].l].n;
    if(left >= k)
        return query(buf[lr].l,buf[rr].l,l,mid,k);
    else
        return (buf[buf[rr].l].sum - buf[buf[lr].l].sum + MOD + query(buf[lr].r,buf[rr].r,mid+1,r,k-left)) % MOD;
}
