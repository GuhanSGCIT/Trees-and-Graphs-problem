/*
Chef has a sequence A containing N integers A1, A2, ..., AN.
Chef is playing a game with this sequence. In this game, he may perform the following operation any number of times (including zero): Choose an arbitrary pair of elements from the sequence such that their sum is even, delete these two elements from the sequence and insert their sum into the sequence instead.
The goal of the game is to minimise the number of elements in the sequence.

Help Chef to play the game and find the minimum possible size of the sequence at the end of the game!

timming:2sec
level:5

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1, A2, ..., AN.

Output
For each test case, print a single line containing one integer — the minimum possible final size of the sequence.

Constraints
    1 ≤ T ≤ 100
    1 ≤ N ≤ 100
    1 ≤ Ai ≤ 1,000 for each valid i

Input:
2
2
1 2
5
7 4 3 2 6

Output:
2
1

Example
case 1: There is no pair of elements with an even sum. Thus, the sequence must remain the same and the answer is 2.
case 2: Chef can choose elements 7 and 3 in the first step, delete them and insert 10 in the sequence. Now all its elements are even and Chef can choose any two elements on each of the following steps of the game until the sequence contains only one element.

input:
3
4
1 2 3 4
5
4 8 2 5 6
3
1 1 2

output:
1
2
1

input:
7
3
1 1 1 
5
4 5 6 1 3
2
1 2
1
1
5
1 4 5 2 3
4
2 5 8 9
6
5 8 7 4 9 9

output:
2
2
2
2
2
1
1

input:
1
9
1 5 9 3 8 9 5 6 3

output:
2

input:
1
11
1 11 111 2 22 5 4 6 7 8 9

output:
1

hint:
Minimum number of elements in final array will always be 1 or 2.Sum of two numbers of same parity is even.
Which means that our operation will always be applied on two odd or two even numbers, but never on one odd and one even number.
This problem can be solved even using two booleans, without storing the elements, though it isn’t necessary to solve the problem. Frequency of odd and even number serve the purpose.

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
cin>>n;int cnte=0,cnto=0,temp;

for(int i=0;i<n;i++){
cin>>temp;
if(temp%2==0)
cnte++;
else
cnto++;}

if(cnte%2!=0&&cnto%2!=0){
cout<<"2\n";
}

if(cnte%2!=0&&cnto%2==0){
cout<<"1\n";
}

if(cnte%2==0&&cnto%2!=0){
cout<<"2\n";

}

if(cnte%2==0&&cnto%2==0)
cout<<"1\n";

}
return 0;
}


