/*
Given a string consisting of some numbers, not separated by any separator. The numbers are positive integers and the sequence increases by one at each number except the missing number. The task is to complete the function missingNumber which return's the missing number. The numbers will have no more than six digits. Print -1 if input sequence is not valid.

Note: Its is guaranteed that if the string is valid, then it is sure that atleast one number would be missing from the string.

Input:
The first line of input contains an integer T denoting the no of test cases. Then T test cases follow. Each test case contains an string s representing a number.

Output:
For each test case in a new line output will be the missing number. Output will be -1 if the input is invalid.

Constraints:
1<=T<=100
1<=Length of string<=100

Input:
2
9899100102
1112141519

Output:
101
-1

input:
3
2165655665
321651
33565

output:
-1
-1
-1

input:
2
16565565
9899100102

output:
-1
101

input:
1
99101102

output:
100

input:
3
596597598600601602
909192939495969798100101
89101113

output:
599
99
12

hint:
Try all lengths from 1 to 6. For every length we try, we check if the current length satisfies the property of all consecutive numbers and one missing.
An interesting thing is number of digits may change as we increment numbers.

*/
#include<bits/stdc++.h> 
using namespace std; 
const int MAX_DIGITS = 6; 
int getValue(const string& str, int i, int m) 
{ 
    if (i + m > str.length()) 
        return -1; 
    int value = 0; 
    for (int j = 0; j < m; j++) 
    { 
        int c = str[i + j] - '0'; 
        if (c < 0 || c > 9) 
            return -1; 
        value = value * 10 + c; 
    } 
    return value; 
} 
int findMissingNumber(const string& str) 
{ 
    // Try all lengths for first number 
    for (int m=1; m<=MAX_DIGITS; ++m) 
    { 
        // Get value of first number with current 
        // length/ 
        int n = getValue(str, 0, m); 
        if (n == -1) 
           break; 
        int missingNo = -1; 
        bool fail = false; 
        for (int i=m; i!=str.length(); i += 1 + log10l(n)) 
        { 
            if ((missingNo == -1) && 
                (getValue(str, i, 1+log10l(n+2)) == n+2)) 
            { 
                missingNo = n + 1; 
                n += 2; 
            } 
            else if (getValue(str, i, 1+log10l(n+1)) == n+1) 
                n++; 
  
            else
            { 
                fail = true; 
                break; 
            } 
        } 
  
        if (!fail) 
          return missingNo; 
    } 
    return -1; // not found or no missing number 
} 
  
// Driver code 
int main() 
{
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>n;
        cout << findMissingNumber(n);
        }
    return 0; 
} 
