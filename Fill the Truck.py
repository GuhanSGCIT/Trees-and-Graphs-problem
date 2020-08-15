"""
Varun is moving soon, and he wants to choose a truck that can hold a certain amount of weight. He knows the weights of all the
items he is putting on the truck. Can you help him determine the maximum number of items that he can put on a truck of any given
weight?

You are given an array a of n integers, the weights of the items. Then, you are given q queries, each of which is a possible
weight of a truck. You must print the number of items that can fit on the truck, each item with weight a[i].

timing:1sec
level:6

Input:
The first line contains two integers n and q. n is the number of items, and q is the number of weight queries.
The next line contains an array a of n integers, the weights of each item.
The next q lines contain one integer each, the weight of the truck.

Output:
There should be q lines of output, the answer to each query.

Constraints
1≤n≤10^5
1≤a[i]≤10^9
1≤q≤10^5
0≤q[i]≤10^18

Sample Input:
10 2
1 1 8 2 5 1 6 6 1 2
3
8

Sample Output:
3
6

EXPLANATION:
In the first query, only 3 items can be taken for a truck with weight 3. These items all have weights 1, 1, and 1.
In the second query, 6 items can be taken for a truck with weight 8. These items have weights 1, 2, 1, 2, 1, and 1.

input:
7 3
4 8 5 6 2 3 2
1
2
3

output:
0
1
1

input:
3 1
5 5 5
2

output:
0

input:
8 2
2 4 6 8 10 12 14 16
3
5

output:
1
1

input:
5 3
1 3 5 7 9
2
4
6

output:
1
2
2

hint:
We can construct a sum array, and then use binary searches for each query.

"""
import bisect
num=list(map(int,input().split()))
wt=list(map(int,input().split()))
wt.sort()
q=[]
for i in range(num[1]):
    q.append(int(input()))

presum = []
presum.append(wt[0])
for i in wt[1:]:
    presum.append(presum[-1] + i)

for i in q[0:]:
    print(bisect.bisect(presum,i))
