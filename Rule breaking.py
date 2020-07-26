"""
Mohammed is playing with an expression which consists of integer operands and the following binary Bitwise operators - AND, OR and
XOR.He is trying to figure out that what could be the Maximum possible answer of the expression, given that he can perform the
operation in any order i.e not necessarily follow the rule of Precedence of operators while evaluating the expression.

After some time of consistent work mohammed starts feeling exhausted and wants you to automate this process for him.
Can you help him out? The expression has Bitwise operators in symbol format:

    & stands for AND
    | stands for OR
    ^ stands for XOR

NOTE : It is guaranteed that the expression will always be valid, also each OPERATOR will always be preceded and succeeded
by an OPERAND.

Input Description:
The first line of input contains a single integer T denoting the number of test cases.
The only line of input for each test case is a string which is the mohammed's expression to evaluate.

Output Description:
For each test case print a single integer i.e the maximum possible value of Mohammed's expression.

Constraints
1≤T≤100.
The number of OPERATORS in the expression will be atleast 1 and atmost 10.
Each OPERAND may range from 0 to 10^9.

Timing:1.13sec
level: 6

Input:
2
3^40|10^2
92^95|56&2&3

Output:
43
95

EXPLANATION:
If we first compute (56 & 2), the expression becomes 92^95|0&3, since (56 & 2) yields 0.
Now on computing (95 | 0), the expression becomes 92^95&3.
Further on computing (95 & 3), the expression becomes 92^3.
Finally (92 ^ 3) yields 95, which is the maximum value of the expression.

Input:
3
4|45^89&2&65
54^265
1&3|4|6

Output:
45
319
7

Input:
1
123^321|45&5&5

Output:
319

Input:
2
1|2|3&5^9
1&2&3|2

Output:
11
2

Input:
1
21^30

Output:
11

Solution:

"""
def extract(s):
	arr = []
	news = ''
	for x in s:
		try:
			x = int(x)
			news += str(x)
		except:
			arr += [news]
			news = ''
			arr += [x]
	arr += [news]
	return arr

t = int(input())
for _ in range(t):
	s = input()
	arr = extract(s)
	n = len(arr)//2 + 1
	dp = [[0]*n for j in range(n)]
	for i in range(n):
		dp[i][i] = [int(arr[2*i])]

	n = len(arr)
	for i in range(3, n+1, 2):
		for j in range(0, n-i+1, 2):
			ans = []
			for k in range(j+2, i+j+1, 2):
				for x in dp[j//2][(k-1)//2]:
					for y in dp[k//2][(i+j)//2]:
						if arr[k-1] == '&':
							ans += [x & y]
						if arr[k-1] == '|':
							ans += [x | y]
						if arr[k-1] == '^':
							ans += [x ^ y]
			if i != n:
				dp[j//2][k//2] = ans[:]
			else:
				print(max(ans))
