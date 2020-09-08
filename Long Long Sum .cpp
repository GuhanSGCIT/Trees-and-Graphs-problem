/*
Calculate and print the sum of the elements in an array, keeping in mind that some of those integers may be quite large.

timing:.2sec
level:2

Input:
The first line of the input consists of an integer n.
The next line contains n space-separated integers contained in the array arr.

Output:
Print the integer sum of the elements in the array arr.

Constraints
1≤n≤10
0≤arr[i]≤10 x 10^9

Sample Input:
5
1000000001 1000000002 1000000003 1000000004 1000000005

Sample Output:
5000000015

EXPLANATION:
When we add several integer values, the resulting sum might exceed the range of int
datatype. You might need to use long long int in C/C++ or long data type in Java to store such sums.

input:
6
10000101011 101010110000 10101011 999998898998 414105156 11111101010

output:
1122544417186

input:
1
321651651651

output:
321651651651

input:
7
1010000005 100000005 1000010005 100005 10 10111 1

output:
2110120142

input:
5
1 1 1 1 1

output:
5

hint:
The only catch is that the integers may be quite large. For that, we need to use the long long int datatype because the range of int
datatype will get exceeded in the test cases.

*/
#include<bits/stdc++.h>
using namespace std;
long long int temp,s=0;
int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        cin>>temp;
        s+=temp;
    }
    cout<<s;
}
