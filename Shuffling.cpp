/*
Ram simulating the next process, imagine that we have an array A = {1, 2, ..., M}. Split it into two arrays with equal size with odd and even indexes from it. After that let's erase in each array numbers on the place [S*X/Y], where S denoting the size of array and merge these arrays(the first element of the second array will be after the last element of the first array), after the first operation A will contain exactly M-2 elements after that, after the second operations M-4 and so on. Ram making this procedure until A has more than 2 elements. In the end he wants to know the value of bitwise XOR elements that remain. He needs your help!

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows. 
The first line of each test case contains three non-negative integers M, X and Y. 

Output
Output in a single line the value of bitwise XOR of two elements that remain in the array A after M/2-1 operations split/merge as described above. 

Constraints
    1 ≤ T ≤ 1000
    1 ≤ M ≤ 10^6
    M is even
    0 ≤ X < Y ≤ 10^6
    Sum of M over all test cases ≤ 5*10^6

Input:
1
6 1 2

Output:
4

Explanation
Initially we have A = {1, 2, 3, 4, 5, 6}. After splitting in two arrays we will have A' = {1, 3, 5} and B' = {2, 4, 6}. Let's erase from 0-indexed A' and B' elements with index = [3*1/2]=1(3 and 4 respectively). After that merge A' and B' -> A = {1, 5, 2, 6}, split A once again in A' = {1, 2} and B' = {5, 6} and erase elements with index = [2*1/2]=1(2 and 6 respectively), merge arrays A' and B' -> A = {1, 5}. Answer is bitwise XOR of 1 and 5 = 4. 

input:
1
1 2 3

output:
3

input:
7
1 5 9
2 6 9
35 54 69
2 4 8
1 2 3
7 4 5
6 7 8

output:
3
3
33
3
3
2
2

input:
1
7 9 12

output:
2

input:
3
2 4 8
1 6 7
1 2 3

output:
3
3
3

hint:
Consider procedure in reverse order. You can trace back positions of remained elements.

*/
#include <bits/stdc++.h>

using namespace std;

int foo(int pos, int size, int x, int y)
{
    int where = 1LL * size * x / y;
    if (pos < where + 1)
    {
        return 2 * pos - 1;
    }
    else if (pos < size)
    {
        return 2 * pos + 1;
    }
    else if (pos < where + size)
    {
        return 2 * (pos - size + 1);
    }
    return 2 * (pos - size + 1) + 2;
}

int main()
{
    //	freopen("input.txt", "rt", stdin);
    //	freopen("output.txt", "wt", stdout);
    int t;
    scanf("%d", &t);
    assert(1 <= t && t <= 1000);
    int em = 0;
    while (t-- > 0)
    {
        int m, x, y;
        scanf("%d%d%d", &m, &x, &y);
        em += m;
        assert(1 <= m && m <= 1000000);
        assert(0 <= x && x < y && y <= 1000000);
        int a = 1, b = 2;
        for (int size = 2; size <= m / 2; ++size)
        {
            a = foo(a, size, x, y);
            b = foo(b, size, x, y);
        }
        printf("%d\n", a ^ b);
    }
    assert(1 <= em && em <= 5000000);
    return 0;
}