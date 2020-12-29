/*
Ram gets N orders. The orders are numbered from 1 to N. He gets order i at Si time, and this order contains Xi number of items. Ram needs to serve each of these Xi items before Di time and for each unit of items he cannot cook before this deadline he needs to pay Pi unit of money as penalty. Given all of the orders, help the Ram to minimize the penalty he will have to pay.

Important Note: Ram can cook at most one item at a unit time and for each item he needs exactly one unit of time to cook. Also Ram can serve an item instantly, when the item is cooked. If Ram wants to serve an item at time t, then the latest he can cook that item is at time time t. In another words, for order i Ram can cook the items at time units Si, Si+1, Si+2, ..., Di-1. Please note, that Ram can not cook items from order i exactly at time unit Di.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case starts with a line containing N the number of orders. Each of the next N lines contains the description of an order.
 Order i is given as a four integers Si, Xi, Di and Pi in a single line separated by a single space.

Output
For each test case, output a single line containing the minimum amount of penalty Ram has to pay.

Constraints
    1 ≤ T ≤ 50
    1 ≤ N ≤ 200
    1 ≤ Si ≤ 10^8
    1 ≤ Xi ≤ 10^8
    1 ≤ Di ≤ 10^8
    1 ≤ Pi ≤ 10^8
    Si+Xi ≤ Di

 
Example

Input:
5
1
1 5 6 10
2
1 5 6 10
1 5 6 10
2
1 5 6 1
1 5 6 10
2
1 5 6 10
6 5 11 10
4
5 8 15 20
11 8 20 21
16 8 25 22
21 8 30 23

Output:
0
50
5
0
147

 
Explanation
Example 1: There is only 1 order and all of the items from this order can be served. So zero penalty
Example 2: There are two orders and you cannot serve 5 items. You can select these 5 items from any order.
Example 3: There are two orders and you cannot serve 5 items. But it is better not to serve these 5 items from the first order.

input:
1
5
1 2 3 4
1 2 3 5
1 2 4 5
1 2 5 4
1 2 3 5

output:
27

input:
2
2
2 5 7 6
2 5 8 9
1
4 8 12 16

output:
24
0

input:
4
1
12 32 45 65
2
21 32 54 65 
54 12 65 23
1
12 3 4 5
2
1 4 7 8
9 5 6 2

output:
0
23
0
10

input:
2
1
1 2 3 5
2
1 12 24 21
1 12 24 2

output:
0
2


hint:
you have time slots on the left and orders on the right. for every order you will have an edge between order and the time slots it is given and the edge cost will be the penalty of the order and capacity 1. Here the no of slots are large. So you can divide total no of slots into ranges of slots such that every range can either be part of a order totally or not. This can be achieved easily and using them as nodes we can run the min-cost flow algorithm.

*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

typedef long long LL;

struct Order{
    int S;
    int X;
    int D;
    int P;
};

struct UnweightedOrder{ 
    int S;
    int X;
    int D;    
};

bool PenaltyOrder(const Order& a, const Order& b){
    return a.P>b.P;
}

bool StartOrder(const UnweightedOrder& a,const UnweightedOrder&b){
    return a.S>b.S;
}

int T;
int N;
Order order[210];

LL Calc(vector<UnweightedOrder> uo){
    int i;
    sort(uo.begin(),uo.end(),StartOrder);
    set<int> s;
    for(i=0;i<uo.size();++i){
        s.insert(uo[i].S);
        s.insert(uo[i].D);
    }
    vector<int> v(s.begin(),s.end());
    int last = 0;
    vector<int> seg;
    for(int i=1;i<v.size();++i){
        seg.push_back(v[i]-v[i-1]);
    }
    int ret = 0;
    for(int i=0;i<uo.size();++i){
        int cur = uo[i].X;
        for(int j=seg.size()-1;j>=0&&cur;--j){
            if(uo[i].S<=v[j]&&uo[i].D>v[j]){
                if(seg[j]<=cur){
                    cur-=seg[j];
                    seg[j] = 0;
                }
                else{
                    seg[j] -= cur;
                    cur = 0;
                }
                
            }
        }
        ret+=cur;
    }
    return ret;
}



int main(){
    int i,j;
    cin>>T;
    while(T--){
        cin>>N;
        for(i=0;i<N;++i){
            cin>>order[i].S>>order[i].X>>order[i].D>>order[i].P;
        }
        sort(order,order+N,PenaltyOrder);
        LL res = 0;
        vector<UnweightedOrder> no;
        UnweightedOrder first = {order[0].S,order[0].X,order[0].D};
        no.push_back(first);
        for(i=1;i<N;++i){
            UnweightedOrder current = {order[i].S,order[i].X,order[i].D};
            vector<UnweightedOrder> to = no;
            to.push_back(current);
            LL temp = Calc(to);
            current.X-=temp;
            res = res + temp*order[i].P;
            no.push_back(current);         
        }
        cout<<res<<endl;
   }
    return 0;
}
