"""
 You are a poor person in ChocoLand. Here, people eat chocolates daily instead of normal food. There is only one shop near
your home; this shop is closed on Sunday, but open on all other days of the week. You may buy at most one box of N chocolates
from this shop on each day when it is open.

Currently, it's Monday, and you need to survive for the next S days (including the current day). You have to eat K
chocolates everyday (including the current day) to survive. Do note that you are allowed to buy the a chocolate box and
eat from it on the same day.

Compute the minimum number of days on which you need to buy from the shop so that you can survive the next S days,
or determine that it isn't possible to survive.

Hard level: 3
Timing:0.01sec

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains 3 positive integers N, K and S denoting the number of chocolates in a box,
the number of chocolates you have to eat everyday to survive and the number of days you need to survive.

Output Description:
For each test case, print a single line containing one integer — the minimum number of days on which you need to buy
from the shop to survive, or -1 if you will not be able to survive S days.

Constraints:
    1 ≤ T ≤ 100
    1 ≤ N ≤ 100
    1 ≤ K ≤ 100
    1 ≤ S ≤ 1000

Input:
2
16 2 10
50 48 7

Output:
2
-1

Explanation:
Example case 1: One possible solution is to buy a box on day 1 (Monday); it's sufficient to eat from this box up to day 8
(Monday) inclusive. Now, on day 9 (Tuesday), you buy another box and use the chocolates in it to survive days 9 and 10.
Example case 2: You will not be able to survive even if you buy from the shop everyday except every 7-th day.

Input:
3
1 2 3
4 5 6
7 8 9
output:
-1
-1
-1

Input:
1
29854 4654 5565
Output:
868

Input:
8
122 55 4996
11 545 68
546 9 55
456 66 1
55 21 45
22 1 6
78 9 68
21 12 33

Output:
2253
-1
1
1
18
1
8
19

Input:
2
1 45 66
0 1 26
Output:
-1
-1

Solution:
"""
from math import ceil
for i in range(int(input())):
    n, k, d=map(int, input().split())
    buydays=d-(d//7)
    if((buydays*n)>=(k*d)):
        print(ceil((k*d)/n))
    else:
        print("-1")
