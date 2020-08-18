/*
Varun Two and Varun Ten are playing a game with a number X. In one turn, they can multiply X by 2. The goal of the game is to make
X divisible by 10.

Help the Varun's find the smallest number of turns necessary to win the game (it may be possible to win in zero turns) or
determine that it is impossible.

timing:3sec
level:4
    
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a single integer denoting the initial value of X.

Output
For each test case, print a single line containing one integer — the minimum required number of turns or −1
if there is no way to win the game.

Constraints
1≤T≤1000
0≤X≤10^9

Input
3
10
25
1

Output
0
1
-1

input
4
12
20
45
24

output
-1
0
1
-1

input
6
24
82
10
32
55
22

output
-1
-1
0
-1
1
-1

input
5
2
42
60
75
28

output
-1
-1
0
1
-1

input
2
102
402

output
-1
-1

hint:
If the number is already divisible by 10, then the answer is 0.
If the number is divisible by 5, then the answer is 1. It can be proved,
Consider N = K * 5, then if we apply the operation once, it becomes, N = K * 5 * 2 which in turn simpllifies to N = K * 10,thus giving the desired result.
If the number doesn’t fall in previous 2 cases, then it is impossible to achieve the desired result, as for a number to be divisible by 10, it has to be divisble by 5 and 2.

*/
#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	for(int i=1; i<=t; i++){
	    int n; cin>>n;
	    if(n%10==0) cout<<"0"<<endl;
	    else if(n%5==0) cout<<"1"<<endl;
	    else    cout<<"-1"<<endl;
	}
	return 0;
}
