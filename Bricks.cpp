/*
For him next karate demonstration, Chan will break some bricks.
Chan stacked three bricks on top of each other. Initially, their widths (from top to bottom) are W1,W2,W3.
Chan's strength is S . Whenever he hits a stack of bricks, consider the largest k≥0 such that the sum of widths of the topmost k bricks does not exceed S; the topmost k bricks break and are removed from the stack. Before each hit, Chan may also decide to reverse the current stack of bricks, with no cost.

Find the minimum number of hits Chan needs in order to break all bricks if he performs the reversals optimally. You are not required to minimise the number of reversals.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains four space-separated integers S , W1, W2 and W3.

Output
For each test case, print a single line containing one integer ― the minimum required number of hits.

Constraints
1≤T≤64
1≤S≤8
1≤Wi≤2
for each valid i
it is guaranteed that Chan can break all bricks

Example Input
3
3 1 2 2
2 1 1 1
3 2 2 1

Example Output
2
2
2

Explanation
Example case 1: Chan can reverse the stack and then hit it two times. Before the first hit, the widths of bricks in the stack (from top to bottom) are (2,2,1) . After the first hit, the topmost brick breaks and the stack becomes (2,1). The second hit breaks both remaining bricks.
In this particular case, it is also possible to hit the stack two times without reversing. Before the first hit, it is (1,2,2) . The first hit breaks the two bricks at the top (so the stack becomes (2)) and the second hit breaks the last brick.

input:
4
1 2 3 4
1 1 2 2
2 2 1 1
1 2 1 2

output:
3
3
2
3

input:
1
1 2 4 2

output:
3

input:
3
7 4 8 6
4 4 8 3
2 5 8 1

output:
3
3
3

input:
2
1 2 2 1
5 1 1 6

output:
3
2


hint:
Realize that if S ≥ W1+W2+W3 then only 1 hit suffices.
If 1 hit doesnt suffices, we need either 2 or 3 hits.
If S ≥ W1+W2​ then we can break 2 bricks in 1 hit and last one in another hit - a total of 2 hits.
If above doesn’t happen, we can reverse the stack and see if S ≥ W3+W2​ or not. If it is so, again 2 hits suffice.
If neither of above holds, we NEED 3 hits.

*/

#include <iostream>
#include <stdio.h>
using namespace std;

int t;

int main()
{
    int test;
    int i, j;

    scanf("%d", &t);

    for (test = 1; test <= t; test++)
    {
        int s, w1, w2, w3;

        scanf("%d %d %d %d", &s, &w1, &w2, &w3);

        if (s >= w1 + w2 + w3)
            printf("1\n");
        else if (s >= w1 + w2 || s >= w2 + w3)
            printf("2\n");
        else
            printf("3\n");
    }

    return 0;
}
