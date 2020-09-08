/*
Given a sorted array arr, remove the duplicates from arr such that each element appears only once and display the new array.

Input:
The first line contains T , the number of test cases. Then the T test cases follow.
Each test case contains 2 lines of input:
The first line contains n, the size of array arr.
The second line contains n space separated elements of array arr.

Output:
For each test case, output in a single line, the new array. The elements of the array should be separated by space. Your output format should match with that given in the sample output.

Constraints
1≤T≤1000
1≤n≤10^4
−10^5≤arr[i]≤10^5

Sample Input:
2
3
1 1 2
10
0 0 1 1 1 2 2 3 3 4

Sample Output:
1 2
0 1 2 3 4

EXPLANATION:
Given arr= [1,1,2]. Here 1 is repeated, so after deleting 1 the modified array will be [1,2].
Given arr = [0,0,1,1,1,2,2,3,3,4]. After deleting the repeated integers, the modified array will be [0,1,2,3,4].

input:
3
4
1 2 4 3
5
1 1 2 3 3
2
1 1

output:
1 2 4 3 
1 2 3 
1

input:
1
7
1 5 4 2 6 3 1

output:
1 5 4 2 6 3 1

input:
2
9
1 1 2 3 4 5 5 6 7
5
1 1 2 2 2

output:
1 2 3 4 5 6 7 
1 2

input:
1
11
4 5 6 1 2 5 4 6 1 2 1

output:
4 5 6 1 2 5 4 6 1 2 1 

hint:
While traversing the array, if arr[i] matches with arr[i−1], we have to delete it. Instead of deleting it and shifting the elements, we can simply store a large negative value in its place


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
cin>>arr[i];
for(int i=1;i<n;i++)
{
if(arr[i]==arr[i-1])
arr[i-1]=-1000;
}
for(int i=0;i<n;i++)
{
if(arr[i]==-1000)
continue;
cout<<arr[i]<<" ";
}
cout<<endl;
}
} 
