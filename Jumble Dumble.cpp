/*
Rishabh is playing a game of jumbled words with his friends.The game comprises of a set of N distinct letters.The player is given
the number, a set of distinct letters and a letter from the set.The player has to identify the position of the first and the last
word that will be formed if the words formed from all the letters were arranged in a dictionary order and putting given letter at
first position.The player has to find those words as well.Help Rishabh win the game.

Input
The first line consists of value of N i.e. total number of distinct letters.
The second line consists of the set of distinct letters.And the third lines consists of the letter whose words you need to find out.

Output
Please output the first and the last words formed from the letter as well as their positions.

Constraints
    1 ≤ N ≤ 26

Input:
10
b a c z j t y q i p
t

Output:
2540161 tabcijpqyz
2903040 tzyqpjicba


Explanation:
First line says that there is 10 distinct alphabets and second line contain that 10 distinct alphabets.
Now third line has that character that needed to put at first position.

Now if we put 't' at first position then first word form will be 'tabcijpqyz' and its position will be 2540161 
and similarly last word will be 'tzyqpjicba' and its position will be  2903040 

input:
11
d v s d x c f q a s a
a

output:
1 aacddfqssvx
3628800 axvssqfddca

input:
9
d e a s d l x e r
d

output:
40321 dadeelrsx
80640 dxsrleeda

input:
4
e a t u
u

output:
19 uaet
24 utea

input:
8
g e e k g u v i
g

output:
10081 geegikuv
15120 gvukigee

hint:
The programmer is required to place a letter out of the given letters, at the start of the string, and then find out dictionary position of the first and the last word formed with that letter at the beginning.

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long int fact(long int n)
{
    if(n<=1)
        return 1;
    return (n*(fact(n-1)));
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n;
    cin>>n;
    string str;
    for(long int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        str+=c;
    }
    char k;
    cin>>k;
   // cout<<str;
    sort(str.begin(),str.end());
    string temp="";
    bool flag = true;
    long int c=0;
    for(long int i=0;i<n;i++)
    {
        if(flag && str[i]==k)
        {
            flag = false;
            continue;
        }
        else if(flag)
        {
            c++;
        }
        temp+=str[i];
    }
    unsigned long long int a=fact(n-1),ans;
    ans=a*c;
    cout<<(ans+1)<<" "<<k<<temp<<endl;
    reverse(temp.begin(),temp.end());
    cout<<(ans+a)<<" "<<k<<temp<<endl;
    
    return 0;
}
