/*
Kupan and alex are participating in a contest. There are N problems in this contest; each problem has a unique problem code
between 1 and N inclusive. Kupan and alex decided to split the problems to solve between them ― Kupan should solve the problems
whose problem codes are divisible by A but not divisible by B, and alex should solve the problems whose problem codes are
divisible by B but not divisible by A (they decided to not solve the problems whose codes are divisible by both A and B).

To win, it is necessary to solve at least K problems. You have to tell kupan whether they are going to win or lose.

timing:0.6sec
level:4

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers N, A, B and K.

Output
For each test case, print a single line containing the string "Win" if they can solve at least K problems
or "Lose" otherwise (without quotes).

Constraints
1≤T≤15
1≤K≤N≤10^18
1≤A,B≤10^9

Input
1
6 2 3 3

Output
Win

Explanation
Example case 1: Kupan is solving the problems with codes 2 and 4, alex is solving the problem with code 3.
Nobody is solving problem 6, since 6 is divisible by both 2 and 3. Therefore, they can solve 3 problems and win.

input:
1
8 5 6 4

output:
Lose

input:
2
4 8 6 5
2 6 4 7

output:
Lose
Lose

input:
3
7 8 9 4
5 6 1 2
3 2 1 4

output:
Lose
Win
Lose

input:
2
1 2 1 2
2 1 2 1

output:
Lose
Win

hint:
Number of problems solved by Appy is N/A−N/lcm(A,B).
Number of problems solved by Chef is N/B−N/lcm(A,B).
Total number of problems solved become N/A+N/B−2∗N/lcm(A,B).
We can simply check if it is at least K or not.
*/
#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;



int main(){

int t;cin>>t;
while(t--){
    ll n,a,b,k;cin>>n>>a>>b>>k;


        ll __lcm = (a*b)/__gcd(a,b);
        ll cnt = 0;
        cnt = n/a + n/b -  2*(n/__lcm);
        if(cnt>=k){
            cout<<"Win"<<endl;
        }
        else{
            cout<<"Lose"<<endl;
        }
    }




return 0;
}
