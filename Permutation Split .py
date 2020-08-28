"""
Flippy the bird has a permutation p of length n while Fluffy the squirrel has a permutation q of length n. Flippy the bird wants
his permutation to be the same as Fluffy's permutation. He can cut the permutation into several parts, and rearrange those parts
so that the resulting permutation is equal to q. He wants to cut the permutation into the minimum possible number of pieces.
Can you help him determine the minimum number of pieces he needs to cut the permutation into?

 
Input
The first line contains a single integer n, the length of the sequence.
The next line contains n space-seperated integers, p1, p2, ..., pn.
It is guaranteed that these numbers are a permutation of 1, 2, ..., n.
The next line contains n space-seperated integers, q1, q2, ..., qn.
It is guaranteed that these numbers are a permutation of 1, 2, ..., n

 
Output

Output a single integer, the minimum number of pieces that Flippy needs to cut to form Fluffy's permutation.
(Note that if Flippy doesn't cut, the number of pieces is 1)

 
Constraints
1 ≤ n ≤ 300000


Input:
5
3 2 1 4 5
2 3 1 4 5
Output:
3

 
Explanation
One can cut the permutation p into 3 parts, [3], [2], [1, 4, 5], and then rearrange it into [2], [3], [1, 4, 5], which is the permutation q.

input:
6
1 2 5 2 3 4
1 4 5 6 4 3
 
output:
6

input:
4
1 2 1 4
3 3 1 4
 
output:
3

 input:
4
1 1 1 2
2 2 2 1
 
output:
4

 input:
8
4 8 5 1 1 2 2 3
1 1 2 2 3 3 4 4
 
output:
7

 hint:
 Just iterate from left to right and split whenever the difference between two adjacent numbers is not 111 (and the one to the right should be larger)
"""
n = int(input())
l = list(map(int,input().split()))
l1 = list(map(int,input().split()))
count = 0
l2 = [0]*(n)
l3 = [0]*(n)
for i in range(n):
    l2[l1[i]-1] = i 
for i in range(n):
    a = l[i] - 1
    l3[i] = l2[l[i] - 1]
for i in range(n):
    if i == 0:
        count += 1
    elif l3[i] - l3[i - 1] != 1:
        count += 1
print(count)
