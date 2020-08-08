"""
You're organising Bachelor's party today. You're expecting 'n' Bachelor and you've already arranged 'm' beer cans.
You want to distribute all the beers among your juniors in such a way that each Bachelor receives the same number of beer cans.
Note you cannot divide a beer can into halves. Find the minimum number of additional beer cans you must buy so that each Bachelor
receives same number of beer cans.

timing:1sec
level:4

Input
First line denotes 'T' number of test cases
It will be followed by 'T' lines containing two space separated integers describing the respective values of n and m

Output
Print 'T' lines containing single integer denoting the number of additional beer cans to be bought

Constraints
    1 ≤ T ≤ 100
    1 ≤ n, m ≤ 10^9

Input:
1
5 3

Output:
2

Explanation
There are n=5 Bachelor coming to Bachelor's party and you've m=3 beer cans already. So, you need 2 additional beer cans
so that everyone will have same number of beer cans.


input:
2
4 6
7 9

output:
2
5

input:
4
1 9
4 6
7 8
2 8

output:
0
2
6
0

input:
6
1 2
2 3
4 5
7 8
8 9
5 6

output:
0
1
3
6
7
4

input:
3
45 89
65 32
78 45

output:
1
33
33

hint:
There are n Bachelor and m beer cans. Then each Bachelor will get m/n number of beer cans.
Now this fraction needs to be a whole number so we calculate the ceiling of m/n i.e. ceil(m/n).
Total number of beer cans expected for n Bachelors will be ceil(m/n) x n.
Subtracting the m beer cans which is already given, we get (ceil(m/n) x n) – m.
"""
import math
a = int(input())
i=1
while i<=a:
  li = input().split()
  n = int(li[0])
  m = int(li[1])
  r= int(math.ceil(m/n)*n-m)
  print(r)
  i=i+1
