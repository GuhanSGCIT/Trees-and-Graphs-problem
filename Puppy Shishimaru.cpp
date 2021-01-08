/*
Shishimaru is a little dog. But despite the fact he is still a puppy he already knows about the pretty things that coins are. He knows that for every coin he can get very tasty bone from his master. He believes that some day he will find a treasure and have loads of bones.

And finally he found something interesting. A wooden chest containing N coins! But as you should remember, Shishimaru is just a little dog, and so he can't open it by himself. Actually, the only thing he can really do is barking. He can use his barking to attract nearby people and seek their help. He can set the loudness of his barking very precisely, and therefore you can assume that he can choose to call any number of people, from a minimum of 1, to a maximum of K.

When people come and open the chest they divide all the coins between them in such a way that everyone will get the same amount of coins and this amount is maximal possible. If some coins are not used they will leave it on the ground and Shishimaru will take them after they go away. Since Shishimaru is clearly not a fool, he understands that his profit depends on the number of people he will call. While Shishimaru works on his barking, you have to find the maximum possible number of coins he can get.

Input
The first line of the input contains an integer T denoting the number of test cases. Each of next T lines contains 2 space-separated integers: N and K, for this test case.

Output
For each test case output one integer - the maximum possible number of coins Shishimaru can get.

Constraints
    1 ≤ T ≤ 50
    1 ≤ N, K ≤ 10^5

Input:
2
5 2
11 3

Output:
1
2

Explanation
In the first example he should call two people. Each of them will take 2 coins and they will leave 1 coin for Shishimaru.
In the second example he should call 3 people.

input:
4
321 2211
2 12
2116 21653
23 22

output:
321
2
2116
11

input:
1
3235 -5216

output:
0

input:
2
2 4
1 2

output:
2
1

input:
5
1 1
1321665 22
1 4
125 1236
32 64

output:
0
15
1
125
32

hint:
For each possible number of people, compute the amount of coins which are left after the process. Finally, return the maximum from these values.


*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans = max(ans, n % i);
    }
    cout << ans << endl;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}