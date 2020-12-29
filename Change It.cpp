/*
You are given a sequence A1,A2,…,AN. You want all the elements of the sequence to be equal. In order to achieve that, you may perform zero or more moves. In each move, you must choose an index i (1≤i≤N), then choose j=i−1 or j=i+1 (it is not allowed to choose j=0 or j=N+1) and change the value of Ai to Aj — in other words, you should replace the value of one element of the sequence by one of its adjacent elements.
What is the minimum number of moves you need to make in order to make all the elements of the sequence equal?

 
Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output
For each test case, print a single line containing one integer — the minimum required number of moves.

Constraints
1≤T≤100
1≤N≤100
1≤Ai≤100
for each valid i

Example Input
3
5
1 1 1 1 1
4
9 8 1 8
2
1 9

Example Output
0
2
1

Explanation:
Example case 1: No moves are needed since all the elements are already equal.
Example case 3: We can perform one move on either A1 or A2.

input:
1
5
2 1 2 4 6

output:
3

input:
3
2
1 2
4
5 8 7 9
3
6 5 7 8

output:
1
3
2

input:
4
5 
8 4 9 6 1
5
21 54 65 98 55
1
23
7
2 5 8 7 4 6 3

output:
4
4
0
6

input:
2
5
2 4 8 5 1
6
8 9 5 4 1 2

output:
4
5

hint:
For each element of the array, we will use at most one operation on it.
All the elements of the array that are left unchanged (no operation is used on them), should be equal.
As a conclusion of the above observations, we should make all the elements equal to the number that has the most occurrences in order to minimize the number of operations.

*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    scanf("%d", &q);
    for (; q; q--)
    {
        int n, a, Mx = 0;
        scanf("%d", &n);
        map<int, int> MP;
        for (int i = 0; i < n; i++)
            scanf("%d", &a), MP[a]++;
        for (auto X : MP)
            Mx = max(Mx, X.second);
        printf("%d\n", n - Mx);
    }
    return 0;
}