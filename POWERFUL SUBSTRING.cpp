/*
Red Skull likes listening to music and (occasionally) reading. No wonder he is especially interested in texts concerning his favourite music. 
Red Skull calls a string good if it starts with "hail" and ends with "hydra". Finding all good substrings (by substring Red Skull means a subsequence of consecutive characters in a string) in a given text makes our villain especially joyful. Recently he felt an enormous fit of energy while reading a certain text. So he decided to count all good substrings in this text and brag about it all day long. Help him in this difficult task. Two substrings are considered different if they appear at different positions in the text.
For simplicity, let us assume that his text can be represented as a single string.

 
Input
Input contains a single non-empty string consisting of the lowercase Latin alphabet letters.
Length of this string will not be greater than 10^6 characters.

Output
Print exactly one number — the number of powerful substrings of the given string.

 

Sample Input
hailhydraishailhydra


Sample Output
3

input:
hailmfkjbskhydrajsncjbvvvdvdvvhydra

output:
2

input:
asfhklhail

output:
0

input:
hydraprogramminghailwithguvi

output:
0

input:
hailscbhwcbjshydrahbdcjhdvcjsvbhhydra

output:
2

hint:
In this problem one needs to find the number of the substrings in the string S with a given prefix A and given suffix B.
If we mark black all the starting positions of the entries of the string A in S, and white all the starting positions of the entries
of the string B, then we come to the following problem: count the number of pairs . To solve this it is enough to iterate from left
to right counting the number of the passed black positions. Meeting black position we increment this number by one, meeting white
position we add to the answer the number of pairs with this white position, which is exactly our memorized number of the already
passed black positions.

*/
#include <bits/stdc++.h> 
#define ll long long int
using namespace std; 
int count(string s,int n){ 
	int c0=0,c1=0; 
	for (int i=0;i<n;i++) { 
		if (s.substr(i,4)=="hail") 
			c0++; 
		if (s.substr(i,5)=="hydra") 
			c1=c1+c0; 
	} 
	return c1; 
} 
int main(){ 
	string s;
	cin>>s;
	cout<<count(s,s.size())<<endl;
}
