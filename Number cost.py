"""
The task is simple! You have to form a given number n using following two operations.

    Append a digit d to current number. The cost of this operation is d (0<=d<=9)
    Append any "substring of current number" to the current number. The cost of this operation is zero

You start the process with an empty number and repeat one of the above 2 operations until you get the desired number.
Print the minimum cost to form the given number.

timing:1sec
level:4

Input
First line will contain T (the number of test cases).
For each test case input is the number to be formed by the given operations.(The number can be very large).

Output
Print the minimum cost needed to form the given number using the given two operations.

Constraints
    1 ≤ T ≤ 10
    1 ≤ n ≤ 1010000

Input:
2
123
1212

Explanation:
first string has distint number are 1+2+3=6,
Similarlly,1+2=3.

Output:
6
3

input:
3
1212148
54854232
1256465

output:
15
22
18

input:
1
216565216521653

output:
17

input:
2
12121
7845874587

output:
3
24

input:
1
123321

output:
6

hint:
You can observe that once a digit is appended to your string it can be appended any number of times with a cost of 0
as it will be a sub-string of the current string.
So the total cost is just the sum of distinct digits present in the string.
"""
test = int(input())
while test > 0:
    l = []
    string = input()
    for value in string:
        if value not in l:
            l.append(value)
    cost = sum(list(map(int, l)))
    print(cost)
    test -= 1
