/*
Roy protected his confidential information by encrypting it using a secret method. He rotates the alphabet in the following manner:
Original string - abcdefghijklmnopqrstuvwxyz
Rotation by 3 - defghijklmnopqrstuvwxyzabc


Input:
The first line contains the integer, n, the length of the unencrypted string.
The second line contains the unencrypted string, s.
The third line contains k, the number of letters to rotate the alphabet by.

Output:
Print the encoded string.

Constraints
1≤n≤100
0≤k≤100
s is a valid ASCII string without any spaces.

Sample Input:
11
middle-Outz
2

Sample Output:
okffng-Qwvb

EXPLANATION:
Original alphabet: abcdefghijklmnopqrstuvwxyz
Alphabet rotated +2: cdefghijklmnopqrstuvwxyzab
m -> o
i -> k
d -> f
d -> f
l -> n
e -> g
 - -
O -> Q
u -> w
t -> v
z -> b

input:
5
guvi-g
7

output:
nbcp-g

input:
6
g-u-vi
3

output:
j-x-yl

input:
9
theprogra
5

output:
ymjuwtlwf

input:
5
gu+vi
12

output:
sg+hu


hint:
First of all, we need to extract the ASCII value of each character in the string sss. After that, we add k to the ASCII value and
take modulus by 26 so that ASCII value doesn’t exceed the range of alphabets.


*/
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n,k;char s[100];
    cin>>n>>s>>k;
    
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            int t=s[i]-'a';
            t+=k;
            t=t%26;
            s[i]=t+'a';
        }
        
          if(s[i]>='A' && s[i]<='Z')
           {
            int t=s[i]-'A';
            t+=k;
            t=t%26;
            s[i]=t+'A';
           }
        
        
    }
    cout<<s;
}
