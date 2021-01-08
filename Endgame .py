"""
Guardians of the Galaxy were reinstated under Rocket after Thanos killed all the rest. They have set on a new space mission, where they have to destroy 2 galaxies ruled by Discordiana and Hypnotos (siblings of Thanos).The galaxies initially have D and H
number of planets. You are now a guardian and Rocket has ordered you to destroy all the planets in both of the evil galaxies, but he allows you only two guns-

    one destroys exactly one planet from both the galaxies simultaneously (can be done only if possible)
    the other cuts in half each planet from one galaxy of your choice and in effect doubles the number of planets.

You have to find whether it’s possible to destroy both the galaxies, and if yes, the minimum number of gun firings required.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, two integers D,H.

Output:
For each testcase, output a single integer denoting the minimum number of gun firings required. Print −1 if not possible.

Constraints
1≤T≤50
0≤D,H≤10^5

Sample Input:
2
2 9
13 14

Sample Output:
12
15

EXPLANATION:
The following sequence of pair of (D,H) will give:-
(2,9)->(1,8)->(2,8)->(4,8)->(8,8)->(7,7)->(6,6)->(5,5)->(4,4)->(3,3)->(2,2)->(1,1)->(0,0)

input:
3
2 5
6 7
21 23

output:
7 
8 
24

input:
2
123 321
51 56
 
output:
323
57

input:
1
321 35

output:
325

input:
4
44 88
6 12
52 104
1 2

output:
89
13
105
3

hint:
A proposed solution is:-
Double A till you get B> A> =B/2.
Decrease A, B until B=2∗A. It is guaranteed that such a situation will be achieved(Try proving it!).
Double A.Decrease A, B till it becomes 0,0.
Since this solution contains exactly k magnifications and B decrements, we may conclude it is optimal. 
"""
def gun_seq(d, h):
	a = int(d)
	b = int(h)
	if min(a, b) <= 0 and max(a, b) > 0:
		return -1
	else:
		count = 0
		while min(a, b) > 0:
			a, b = min(a, b), max(a, b)
			if a * 2 <= b:
				a *= 2
				count += 1
			else:
				k = 2 * a - b
				a -= k
				b -= k
				count += k
		if a == 0 and b == 0:
			return count
		else:
			return -1

if __name__ == '__main__':
	# = Input Section
	while True:
		n = int(input())
		if (1 <= n <= 50):
			break

	tc = list()

	for i in range(0, n):
		while True:
			d, h  = input().split()
			if (0 <= int(d) <= 100000) and (0 <= int(h) <= 100000):
				break
		tc.append([d, h])

	#= Main Logic
	for a in tc:
		d, h = a
		print(gun_seq(d, h))