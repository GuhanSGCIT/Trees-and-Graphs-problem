"""
Varun has an array of integers and he starts with an arbitrary initial value X.
He calculates the running sum of X plus array element, from left to right. The running sum never gets below 1.
Find the minimum value of X.

NOTE: X can be equal to Zero.

timing:1sec
level:5

Input:
First line will contain T , number of testcases. Then the testcases follow.
First line of the test case contains the integer N.
Next line contains N space separated integers A0,A1,...,An−1.

Output:
For each testcase, output in a single line, the number X.

Constraints
1≤T≤100
1≤N≤10^5
−10^9≤Ai≤10^9


Sample Input:
2
2
-1 1
5
5 -10 6 7 -12

Sample Output:
2
6

EXPLANATION:
In case 2, if X=6,
The final value is 2, and the running sum has never dropped below 1. The minimum starting value for X is 6.

input:
3
4
4 5 -3 6
3
8 -4 8
7
4 5 6 -7 4 -8 3

output:
-3
-3
-3

input:
1
8
4 6 2 -7 -6 9 6 -5

output:
2

input:
2
2
3 -3
4
1 2 -2 -1

output:
1
1

input:
1
3
109 0 -201

output:
93

hint:
Let’s consider the value at ith index, i.e. X+cumulative_sum[i].
The condition is:
X+cumulative_sum[i]>=1
⟹  X>=1−cumulative_sum[i]
If you consider the condition for all the indices, turns out that the minimum value of X will be the
maximum value of 1−cumulative_sum[i].

"""
t=int(input())
for x in range(t):
    array_count = int(input())
    array = [int(x) for x in input().split()]
    running_sum =0
    minimum = 999999999999999
    flag= False
    for i in array:
        running_sum += i
        if running_sum < minimum:
            minimum = running_sum
    print(1-minimum)
