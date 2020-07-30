"""
A student is frustrated with boring classes. Professor X agreed to give him some questions;
if the student answers all questions correctly, then minimum attendance criteria will not apply to him.

Professor X chooses a sequence A1,A2,…,AN and asks Q queries. In each query, the student is given an integer P;
he has to construct a sequence B1,B2,…,BN, where P⊕Ai=Bi for each valid i (⊕ denotes bitwise XOR), and then he has
to find the number of elements of this sequence which have an even number of 1-s in the binary representation and the
number of elements with an odd number of 1-s in the binary representation. Help him answer the queries.

Timing:1 sec
level: 5

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and Q.
The second line contains N space-separated integers A1,A2,…,AN.
Q lines follow. Each of these lines contains a single integer P describing a query.

Output Description:
For each query, print a single line containing two space-separated integers ― the number of elements with an even number of 1-s
and the number of elements with an odd number of 1-s in the binary representation.

Constraints
1≤T≤100
1≤N,Q≤105
T⋅(N+Q)≤4⋅106
1≤Ai≤108 for each valid i
1≤P≤105

The input/output is quite large, please use fast reading and writing methods.

Input:
1
6 1
4 2 15 9 8 8
3

Output:
2 4

Explanation:
Example case 1: The elements of the sequence B are P⊕4=7, P⊕2=1, P⊕15=12, P⊕9=10, P⊕8=11 and P⊕8=11.
The elements which have an even number of 1-s in the binary representation are 12 and 10, while the elements
with an odd number of 1-s are 7, 1, 11 and 11.

Input:
1
7 3
455 6546 54 6 55 2 0
5
44
2

output:
5 2
2 5
2 5

Input:
1
5 4
1 2 3 4 5
1
2
3
4

output:
3 2
3 2
2 3
3 2

Input:
1
9 1
9 8 7 4 5 6 1 2 3
2

output:
5 4

Input:
1
3 1
45 75 59
5

output:
2 1

Solution:
"""
import sys
from sys import stdin, stdout
for z in range(0,int(input())):
	eve = 0
	odd = 0
	N,Q = map(int,sys.stdin.readline().split())
	A = map(int,sys.stdin.readline().split())
	for i in A:
		if bin(i).count('1')%2==0:
			eve = eve+1
		else:
			odd = odd +1
	for q in range (0,Q):
		P=int(stdin.readline())
		x = bin(P).count('1')
		#print(x)
		if x%2 !=0:
			sys.stdout.write(f'{odd} {eve}\n')
		else:
			sys.stdout.write(f'{eve} {odd}\n')
