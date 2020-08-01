/*
Question:(Encapsulation)
ATMs of SBI is arranged so that they can not give any amount of money requested by the user. Due to the limited size of the bill dispenser 
(the device that is directly giving money from an ATM) and some peculiarities of the ATM structure, you can get at most k bills from it,
and the bills may be of at most two distinct denominations.

For example, if a country uses bills with denominations 10, 50, 100, 500, 1000 and 5000, then at k = 20 such ATM can give sums 100000
and 96000, but it cannot give sums 99 000 and 101000.

Let's suppose that the country uses bills of n distinct denominations, and the ATM that you are using has an unlimited number of bills of each type. 
You know that during the day you will need to withdraw a certain amount of cash q times. You know that when the ATM has multiple ways to give money, 
it chooses the one which requires the minimum number of bills, or displays an error message if it cannot be done. Determine the result of each of the q 
of requests for cash withdrawal.

Input Description:
The first line contains two integers n, k (1 ≤ n ≤ 5000, 1 ≤ k ≤ 20).
The next line contains n space-separated integers a i (1 ≤ a i ≤ 10^7) — the denominations of the bills that are used in the country.
Numbers a i follow in the strictly increasing order.
The next line contains integer q (1 ≤ q ≤ 20) — the number of requests for cash withdrawal that you will make.
The next q lines contain numbers x i (1 ≤ x i ≤ 2·10^8) — the sums of money in burles that you are going to withdraw from the ATM.

Output Desciption:
For each request for cash withdrawal print on a single line the minimum number of bills it can be done, or print  - 1, 
if it is impossible to get the corresponding sum.

Input:
6 20
10 50 100 500 1000 5000
8
4200
100000
95000
96000
99000
10100
2015
9950

Output:
6
20
19
20
-1
3
-1
-1

Input:
5 2
1 2 3 5 8
8
1
3
5
7
9
11
13
15

Output:
1
1
1
2
2
2
2
-1

Input:
9 40
1 2 5 10 20 50 100 500 2000
5
400
360
10
1
4568

Output:
4
6
1
1
-1

Input:
4 50
200 500 1000 2000
6
10000
55000
10
128
35498
1500

Output:
5
28
-1
-1
-1
2

Input:
3 5
1 2 5 10
6
3546
35
656
777
99
3534856

Output:
2
-1
-1
-1
-1
-1
-1
-1
-1
-1

Hint:
Put the denomination of the banknote in the map, enumerate the type and quantity of the first type of banknote, if it happens to be x, update the answer,
otherwise enumerate the number of the second type of banknote, then the denomination of the second type of banknote is determined, from map to find whether 
this denomination exists, if it exists, update the answer.

Code:
*/ 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
#define maxn 5555
map<ll,int>m;
int n,k,a[maxn],q;
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        m.clear();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),m[a[i]]=1;
        scanf("%d",&q);
        while(q--)
        {
            int ans=-1;
            ll x;
            scanf("%I64d",&x);
            for(int i=1;i<=n;i++)
                for(int j=1;j<=k&&1ll*a[i]*j<=x;j++)
                {
                    ll t=x-1ll*a[i]*j;
                    if(t==0)
                    {
                        if(ans==-1)ans=j;
                        else ans=min(ans,j);
                    }
                    else
                    {
                        for(int l=1;l+j<=k;l++)
                            if(t%l==0&&m.find(t/l)!=m.end())
                            {
                                if(ans==-1)ans=j+l;
                                else ans=min(ans,j+l);
                            }
                    }
                }
            printf("%d\n",ans);
        }
    }
    return 0;
}