/*
Given a long sentence, reverse the first word of the sentence individually in the sentence itself.
For example, if the sentence is- "Guvi geek", the output should be-"ivuG geek".

timming:1sec
level:4

Input:
The only line of input contains the sentence s, upon which the above-mentioned operation is to be performed.

Output:
Output the modified sentence.

Constraints
1≤Length of s≤1000
Modify the first word only, leaving rest of the sentence unchanged.

Sample Input:
College of Engineering Chennai

Sample Output:

egelloC of Engineering Chennai

EXPLANATION:
The first word of the given sentence is- "College". So we simply reverse it leaving rest of the sentence unchanged,
i.e. "egelloC of Engineering Chennai".

input:
reverse the word

output:
esrever the word

input:
Iron man

output:
nori man

input:
jbnj,hnbj,hnbjbj  kjbjhj nbjhb

output:
jbjbnh,jbnh,jnbn kjbjhj nbjhb

input:
Learn and Practice Programming

output:
nrael and Practice Programming

hint:
find the index of the last character of the first word. Once we have the index, we can simply reverse that much part of the sentence and display it.
*/
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    string s;
    getline(cin,s);
    cin.ignore();
    //cout<<s<<endl;
    int i,cnt=0;
    vector<char> v;
    
    for(i=0;i<s.size();i++)
    {
        if(s[i]==' ')
         break;
        else
        {
         v.push_back(s[i]);
         cnt++;
        }
    }
    
    for(i=v.size()-1;i>=0;i--)
        cout<<v[i];
    for(i=cnt;i<s.size();i++)
	    cout<<s[i];
	cout<<endl;
	return 0;
}
