/*
Varun is trying to develop a program for a very simple microcontroller. It makes readings from various sensors over time,
and these readings must happen at specific regular times. Unfortunately, if two of these readings occur at the same time,
the microcontroller freezes and must be reset.

There are N different sensors that read data on a regular basis. For each i from 1 to N, the reading from sensor i will occur
every Ai milliseconds with the first reading occurring exactly Ai milliseconds after the microcontroller is powered up.
Each reading takes precisely one millisecond on Varun's microcontroller.

Varun wants to know when the microcontroller will freeze after he turns it on.

timing:2.5sec
level:6
    
Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line contains single integer N denoting the number of sensors.
The second line contains N space-separated integers A1, A2, ..., AN denoting frequency of measurements.
Namely, sensor i will be read every Ai milliseconds with the first reading occurring Ai milliseconds after the microcontroller is first turned on.

Output
For each test case, output a single line containing the number of milliseconds until the microcontroller freezes.

 
Constraints
    1 ≤ T ≤ 10
    2 ≤ N ≤ 500
    1 ≤ Ai ≤ 10^9

Input:
3
3
2 3 5
4
1 8 7 11
4
4 4 5 6

Output:
6
7
4

 
Explanation
Case 1: in 6 milliseconds, the third reading will be attempted from the 1st sensor and the second reading will be attempted from the 2nd sensor.
Case 2: in 7 milliseconds the seventh reading will be attempted from the 1st sensor and the first reading will be attempted from the 3rd sensor.
Case 3: in 4 milliseconds, the first readings from the first two sensors will be attempted.

input:
4
3
5 4 6
7
1 5 9 8 7 4 2
2
5 4
3
102 201 45

output:
12
2
20
1530

input:
1
5
100 120 130 110 140

output:
600

input:
2
6
1 2 3 4 5 6
7
7 6 5 4 3 2 1

output:
2
2

input:
1
4
101 1021 1551 4511

output:
103121

hint:
A very straight forward way to solve this problem is to check for every millisection starting from the first millisecond whether
at least two events will occur on that millisecond or not, we stop at the first millisecond in which at least 2 events occured at
this millisecond and this will be the answer.

*/
#include<iostream>

using namespace std;

const int N = 503;
int n;
int t;
long long a[N];
long long ans;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    else return gcd(b,a % b);
}

long long lca(long long a,long long b){
    return (a * b) / gcd(a,b);
}

int main(){
    //freopen("2.in.txt","r",stdin);
    //freopen("2.out.txt","w",stdout);

    cin >> t;

    while(t --> 0){

        cin >> n;

        ans = 1e18;
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                ans = min(ans,lca(a[i], a[j]));
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
