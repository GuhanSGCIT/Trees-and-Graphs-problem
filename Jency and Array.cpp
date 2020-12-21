/*
Recently jency read about Array and now she is cracking Array's questions. She told about this to his friend Zen .Zen wants to check how much jency know about Array .So, he has given her an array of integers of size N . jency′s task is to find out the sum of all distinct positive integer and distinct negative integers in the given array . As jency is beginner in problem solving so she is looking for your help.

Input:
First line will contain T, the number of testcases.
Each testcase contains of two lines first line contains N
size of array and the second line contains N space-separated integers.

Output:
For each testcase, output in a single line containing S1 and S2 where S1 and S2 are sum of distinct positive integers and sum of distinct negative integers respectively. Sum will not be greater than 10^9 and will not be less than -10^9.

Constraints
1≤T≤100
2≤N≤10^6
−10^6≤A[i]≤10^6

Sample Input:
2
5
-1 1 -1 0 -2
6
4 5 3 3 -1 -2

Sample Output:
1 -3
12 -3

EXPLANATION:
Case 1:- Distinct positive integers are 1,0 and distinct negative integers are -1,-2 sum of positive integers S1 is 1+0=1 and sum of negative integers S2 is (-1+(-2))=-3. So, output is 1 -3.
Case 2:- Distinct positive integers are 4,5,3 and distinct negative integers are -1,-2 sum of positive integers S1 is 4+5+3=12 and sum of negative integers S2 is (-1+ (-2))=-3.So, output is 12 -3.

input:
1
7
5 8 -1 -2 -3 4 6

output:
23 -6

input:
2
3
1 2 -3
4
1 -1 0 2
2
1 -1

output:
3 -3
3 -1

input:
1
11
2 5 8 4 -7 8 -1 -2 2 7 1

output:
27 -10

input:
1
4
1 2 -1 3

output:
6 -1

hint:
 In this problem you just need to find all distinct positive integers and negative integers, you can implement this by using 2 sets ,then at last find the sum of all the elements inside the set.

*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, t, s1, s2, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        long long int k;
        set<long long int> st;
        for (i = 0; i < n; i++)
        {
            cin >> k;
            st.insert(k);
        }
        s1 = 0, s2 = 0;
        for (auto it = st.begin(); it != st.end(); it++)
        {
            if (*it >= 0)
                s1 += (*it);
            else
                s2 += (*it);
        }
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}
