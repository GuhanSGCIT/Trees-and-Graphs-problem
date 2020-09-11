/*
 Bharath loves to roam in the campus of NITW and also he is good at problem solving. Pratyush decided to give a problem to Bharath.
Pratyush gives Bharath a list of places inside NITW (each place is represented by some character from 'a' to 'z'). Starting from the beginning, Bharath has to visit all the places in the same order as given in the list.
While roaming Bharath writes the name of a place when he visits it for the first time. At the end of the day Bharat will tell all the distinct places travelled by him during entire day in the order he visited them.

Input
First line will contain T, number of test cases.The description of T test cases follows.
The first and only line of each test case contains a string S (containing only lowercase alphabets).

Output
For each test case print the order of visit of Bharath.

Constraints
    1 <= T <= 10
    1 <= |S| <= 100000


Input:
3
abbcccppf
abaabccba
ccbaacfddhll

Output:
abcpf
abc
cbafdhl

Explanation:
Output the string after removing duplicate occurrences of all characters. Order of characters must be same as input string.

input:
5
ghghjhhjnghbjhbjhbjh
kkhgjhbmtdhbjgfd
mbmnbmhbjhbv
jmjbnjhbjh
kjbjhb

output:
ghjnb
khgjbmtdf
mbnhjv
jmbnh
kjbh

input:
2
qweewqwe
dkvnnk

output:
qwe
dkvn

input:
3
121251565
cvknkjcnvkdj
klkoiko

output:
<empty>...........................................................................
cvknjd
kloi

input:
1
nbmbngjhggnb

output:
nbmgjh

hint:
Keep an array A of size 26 to check if we have already encounter some character or not. Initially all values in A are zero. Now when we start traversing the string and if we encounter some character that has not been visited yet, add it to the result and make it visited in array A (make A[s[i]-‘a’]=1 ).

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

int t;
cin>>t;
while(t--)
{
	string s;
	cin>>s;
	int a[26]={0};
	string res="";
	for(int i=0;i<s.length();i++)
	{
		if(a[s[i]-'a']==0)
		{
			a[s[i]-'a']++;
			res+=s[i];
		}
		
	}
	cout<<res<<endl;
}

}
