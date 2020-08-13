"""
There are N trains running on M tracks. The i-th train currently has its ends at distances li and ri from the starting of
occupied track. Find the minimum value of M such that no two trains intersect or touch each other.

timing:1sec
level:5

Input:
First line will contain T, number of testcases. Then the testcases follow.
First line each testcase contains a single line integer N.
Then N lines follow.
Each line contains two integers li,ri.

Output:
For each testcase, output in a single line the minimum value of M.

Constraints
1≤T≤50
1≤N≤10^5
0≤li≤ri≤10^9

Sample Input:
2
3
1 2
3 4
5 6
4
2 3
0 1
2 3
5 6

Sample Output:
1
2

EXPLANATION:
Case 1: All trains can be placed on same track without intersection.
Case 2: First and Third train will intersect if placed on same track.Hence minimum 2 tracks are required.

input:
1
4
4 5
1 2
6 3
1 1

output:
2

input:
2
2
4 5
2 6
3
1 5
4 2
6 2

output:
2
1

input:
1
5
4 5
7 8
9 6
1 2
2 3

output:
2

input:
1
3
246546565 6544
6565 6651165
33524635 32244654

output:
0

hint:
We will simply find the point where there is intersection of maximum trains i.e. the point common to maximum number of trains.
Thus the minimum number of track required will be the max value found.
To do this we will take the input of intervals and the sort them in nlogn, after that traverse them to find out
the point of maximum intersection witch will take n time.
"""
for _ in range(int(input())):
	c,a={},[]
	for _ in range(int(input())):
		l,r=map(int,input().split())
		if l in c: c[l]+=1
		else: c[l]=1;a.append(l)
		if r+1 in c: c[r+1]-=1
		else: c[r+1]=-1;a.append(r+1)
	x,ans,a=0,0,sorted(a)
	for i in a:
		x+=c[i]
		ans=max(ans,x)
	print(ans)
