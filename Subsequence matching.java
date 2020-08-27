/*
Given an all upper case string, check if it is a combination of one or more of the following:
1) R
2) RY
3) RYY

Input:

First line contains an integer T denoting the number of test cases. Each of the following T lines will contain an upper case string.

Output:

Print YES if the sequence is correct, NO if not correct.

Constraints:  
1<=T<=100
1<=10^5<= Size of String

Example: 

Input:
3
RY
RWR
RRYY

Output:
YES
NO
YES

input:
2
RYRYYYRYYRYYRYY
RTYRYRTYRTR

output:
NO
NO

input:
4
R
RYRYRR
RRRRY
KJV
RY

output:
YES
YES
YES
NO

input:
1
RYRRYR

output:
YES

input:
3
R
RY
RRYYRY

output:
YES
YES
YES

hint:
Slide the pattern over text one by one and check for a match. If a match is found, then slides by 1 again to check for subsequent matches.

*/
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
public static void main (String[] args) {
Scanner sc=new Scanner(System.in);
int t=sc.nextInt();
while(t!=0){
t--;
String s=new String();
s=sc.next();
s=s.replaceAll("RYY"," ");
s=s.replaceAll("RY"," ");
s=s.replaceAll("R"," ");
s=s.replaceAll(" ","");
if(s.length()==0){
System.out.println("YES");
}
else{
System.out.println("NO");
}
}
}
}
