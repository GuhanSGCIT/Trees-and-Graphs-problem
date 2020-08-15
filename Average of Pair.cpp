/*
You are given an integer sequence A with length N.
Find the number of (unordered) pairs of elements such that the average of these two elements is also present in the sequence.
Formally, find the number of pairs (i,j) such that 1≤i<j≤N and there is an index k (1≤k≤N) for which 2Ak=Ai+Aj holds.

timing:2sec
level:6

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output
For each test case, print a single line containing one integer —the number of valid pairs (i,j).

Constraints
1≤T≤10
1≤N≤10^5
|Ai|≤10^3
for each valid i

Example Input
3
2
2 2
3
2 1 3
6
4 2 5 1 3 5

Example Output
1
1
7

Explanation
Example case 1: We can take k for Ak to be either 1 or 2, since Ak=2 either way. Since the problem asks for unordered pairs,
(1,2) is the only possible valid pair (the same as (2,1)). Hence, the answer is 1.

Example case 2: We see that A1=2=(1+3)/2. No other valid pair exists.

input:
4
2
1 5
6
1 8 6 3 2 4
8
1 5 4 9 6 5 5 4
4
12 24 36 46

output:
0
4
7
1

input:
1
6
1 2 3 4 5 6

output:
6

input:
3
1
2
2
14 18
3
108 801 401

output:
0
0
0

input:
2
1
213
5
4 5 9 8 7

output:
0
2

hint:
We immediately see the low constraints for value of Ai​. We can make a frequency array to record frequency of each array element.
The only problem is, Ai​ can be negative as well. This is easily solved by adding a constant KKK (preferably 1000) to all array
elements. With all elements positive, we iterate over all possible pair of values of array elements, i.e. we check all pairs of
(a,b) where 0≤a,b≤20000. We check if a, b and their average exists in array and update answer accordingly.

*/
#include <bits/stdc++.h>
// loops
#define rep(i, n) for(int i=0; i<n; i++)
#define repA(i, a, n) for(int i=a; i<n; i++)
#define repD(i, a, n) for(int i=a; i>=n; i--)
#define trav(it, ctr) for(auto it=ctr.begin(); it!=ctr.end(); it++)
#define travR(it, ctr) for(auto it=ctr.rbegin(); it!=ctr.rend(); it++)

// I/O
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define p(x) cout<<x<<"\n"
#define pp(x, y) cout<<x<<" "<<y<<"\n"
#define lbr cout<<"\n"

// container and contants
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define hell (int)1e9

// namespaces
using namespace std;

// typedefs
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long int ll;
typedef map<int, int> mii;
typedef unsigned long long ull;
typedef priority_queue<int> pq;

// global constants
const int mod=1e9+7;

int main()
{
    FIO;
    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x, neg[1001], pos[1001];
        memset(pos, 0, sizeof pos);
        memset(neg, 0, sizeof neg);
        rep(i, n){
            cin>>x;
            if(x<0)
                neg[abs(x)]++;
            else
                pos[abs(x)]++;
        }
        ll ans=0, tmp;
        for(int i=-1000; i<=1000; i++){
            tmp=0;
            if(i<0){
                if(neg[abs(i)])
                    tmp=neg[abs(i)];
            }
            else{
                if(pos[abs(i)])
                    tmp=pos[abs(i)];
            }
            tmp*=tmp-1;
            tmp/=2;
            ans+=tmp;
            for(int j=i+1; j<=1000; j++){
                if(i<0)
                    tmp=neg[abs(i)];
                else
                    tmp=pos[abs(i)];
                if(j<0)
                    tmp*=neg[abs(j)];
                else
                    tmp*=pos[abs(j)];
                x=i+j;
                if(x%2)continue;
                x/=2;
                if(x<0){
                    if(neg[abs(x)])
                        ans+=tmp;
                }
                else{
                    // if(i==1 and j==3)
                    //     pp("HII", pos[x]);
                    if(pos[x]){
                        ans+=tmp;
                        // p("HII");
                    }
                }
            }
        }
        p(ans);
    }
    return 0;
}
