"""
Aunty got a box of chocolates for Christmas. In fact, he discovered that the box contained several identical smaller boxes,
and they could contain even smaller boxes, and so on. Formally, we say that chocolates are boxes of level 0, and for 1 ≤ i ≤ n,
a level i box contains ai boxes of level i - 1. The largest box has level n. Aunty realized that it can take quite a long time
to open all the boxes before he actually gets to eat some chocolates, so he put the box aside in frustration.

But today being his birthday, some friends came to visit Aunty, and Aunty decided to share some chocolates with them.
In order to do that, he must open some of the boxes. Naturally, Aunty can not open a box that is still inside an unopened box.
If Aunty wants to retrieve X chocolates, what is the least number of boxes he must open? You must help him answer many such queries.
Each query is independent.

Timing:2.5sec

level:6

Input Description:
The first line contains two integers n and m, which refer to the level of the largest box, and the number of queries respectively.
The second line contains n integers a1, ..., an.
The third line contains m integers X1, ..., Xm.

Output Description:
Print m integers each in a new line, ith of them equal to the smallest number of boxes Aunty must open in order to retrieve
at least Xi chocolates.

Constraints
1 ≤ n,m ≤ 300000
1 ≤ ai ≤ 109
1 ≤ Xi ≤ 1012
It is guaranteed that the total number of chocolates is at least Xi for all i

Input:
5 1
1 1 1 1 1
1

Output:
5

Input:
3 3
3 3 3
2 8 13

Output:
3
5
8

Explanation:
Testcase 1: The only chocolate is contained in five levels of boxes.
Testcase 2: In the third query, for 13 candies, Andy should open the largest box, two level-2 boxes, and finally five of
six available level-1 boxes. Each of those boxes will contain 3 level-0 boxes (which are candies). So he'll have 15 chocolates
in total, but he needs only 13 of them.

Input:
2 2
1 8
9 44

Output:
11
50

Input:
4 5
1 8 5 6
8 4 6 55 44

Output:
11
7
9
65
53

Input:
2 1
5 2
44

Output:
14

Solution:
"""
n,m = map(int,input().split())
box = list(map(int,input().split()))
mularr = []
queries = list(map(int,input().split()))
qm = max(queries)
cnt = 0
mularr.append([box[0],1])
candy = box[0]
for b in box[1:]:
	if b == 1:
		mularr[-1][1] +=1
	else:
		candy *= b
		mularr.append([candy,1])
	if qm <= candy:
		break
#print(mularr)
for query in queries:
	cnt = n
	test = query
	test-=1
	for k,v in mularr:
		#print (mularr[m],test)
		add = (test//k)*v
		cnt+=add
	print(cnt)
