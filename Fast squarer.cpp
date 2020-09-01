/*
A squarer is a simple and convenient device. You give it some positive integer X and it calculates its square.

Leha is implementing a module of this device which is responsible for squaring the numbers consisting of multiple repetitions of one
digit. But it turned out that it's not as simple as he thought.

Please help him now!

Let's consider the integer answer Y as a 0-indexed array starting from its leftmost digit. The hash function is calculated as:
p0*Y[0] + p1*Y[1] + ... + pM-1*Y[M-1] modulo 109 + 7
where M is the length of the array representation of Y and p equals 23.

timing:2sec
level:6

Input
The first line contains one integer T denoting the number of testcases. The descriptions of T test cases follow.
Each of the following T lines contain 2 space-separated integers - N and D, respectively. It means that the number X in the
corresponding testcase consists of the digit D repeated N times (in decimal representation).

Output
As the answer can be very large, we ask you to output its hash which is computed in the following way:


Constraints
    1 ≤ T ≤ 20
    1 ≤ D ≤ 9

Input:
3
1 4
3 6
3 5

Output:
139
40079781
32745632

Explanation
In the first test case, X = 4 and Y = 16. Its hash equals 1*1 + 23*6 = 139.

input:
4
5 4
2 5
1 5
9 6

output:
625238233
61896
117
170761649

input:
5
1 2
3 2
4 5
6 2
2 4

output:
4
1217969
322502692
907945689
74797

input:
6
1 2
2 5
4 5
6 3
2 4
8 7

output:
4
61896
322502692
980839395
74797
857607285

input:
3
4 5
6 2
3 1

output:
322502692
907945689
305809

hint:
Since squaring a number is multiplying it by itself, use long multiplication 4, which is sometimes called grade-school multiplication or Standard Algorithm, and speed up the computation using prefix and suffix sums of digits of the intermediate result.

*/
#include <iostream>
using namespace std;

typedef unsigned long long ull;

int sum(int D,int N) {
	int m=1e9+7;
	int n=N*2-1,i,d[2000000+3];
	ull p=1,y=0,c=0,sum=0;
	for(i=0;i<n;i++) {
		y=c+(i<N?(i+1):(2*N-i-1))*D;
		d[i]=y%10; c=y/10;
	}

	if(c) {
		d[n++]=c%10; c/=10;
	}

	for(i=0;i<n;i++) {
		y=c+d[i]*D;
		c=y/10; d[i]=y%10;
	}

	if(c) {
		d[n++]=c%10; c/=10;
	}

	//cout<<"num = ";
	for(i=n-1;i>=0;i--) {
		//cout<<d[i];
		sum=(sum+p*d[i])%m; p=(p*23)%m;
	} //cout<<endl;

	return sum;
}

int main() {
	int T,D,N; cin>>T;

	while(T--) {
		cin>>N>>D;
		cout<<sum(D,N)<<endl;
	}

	return 0;
}
