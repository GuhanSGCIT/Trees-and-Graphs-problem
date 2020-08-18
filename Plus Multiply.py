"""
Varun has a sequence A1,A2,…,AN. He needs to find the number of pairs (i,j) (1≤i<j≤N) such that Ai+Aj=Ai⋅Aj. However, he is busy,
so he asks for your help.

timing:1sec
level:6

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output
For each test case, print a single line containing one integer ― the desired number of pairs.

Constraints
1≤T≤20
1≤N≤40,000
0≤Ai≤10^9
for each valid i

Input
2
3
2 4 2
3
0 2 3

Output
1
0

Explanation
Example case 1: The only valid pair is (1,3).
Example case 2: We can see that no valid pair exists.

input:
3
4
12 0 5 55
6
4 8 1 0 2 5
9
5 4 1 1 4 5 8 4

output:
0
0
0

input:
2
3
4 5 2
4
2 4 0 2

output:
0
1

input:
4
2
1 0
6
1 8 5 2 0 2
5
8 5 4 23 1
4
1 1 2 0

output:
0
1
0
0

input:
2
8
1 0 2 1 5 0 2 2
3
1 0 2

output:
4
0

hint:
We may rewrite it as Ai=Aj(Ai−1), or Aj=Ai / (Ai−1)​. Since Aj​ is integer it’s only possible when either Ai=Aj=2 or Ai=Aj=0,
so we just have to calculate amount of occurences of 0's and 2's in the sequence.

"""
t = int(input())
for _ in range(t):
    n = int(input())
    A = input().split()

    two = A.count('2')
    zero = A.count('0')

    twoPair = two * (two - 1) / 2
    zeroPair = zero * (zero - 1) / 2

    if twoPair < 0:
        twoPair = 0
    if zeroPair < 0:
        zeroPair = 0

    total = twoPair + zeroPair

    print(int(total))
