"""
Sachin always loves to play with very large number. He spends most of his time in dealing with very large numbers.
One day, he and his friend Harry went to hill station. Even at the hill station, Sachin counts different staffs and power
them with some fixed number. Harry got irritated with his behavior. So he gave him a set of two numbers (a and b) and told him
to find out the number a^b where ^ represents exponentiation operator but since they are at hill station so they don't have any
paper so he just asked him to write the number in his palm after ignoring the first n-1 digits where n is number of digits in
a^b where a and b are very large number.

timing:0.75sec
level:4

Input
First line contains an integer T (the number of testcases).
Then the only line of each test case contains two space separated a and b.

Output
For each case print in a new line the required number.

Constraints
T<=1000
0<=a<=10^501
0<=b<=10^16

Input:
2
2 2
3 2
Output:
4
9

 
Explanation
1st test case, 2^2 is 4 since it is single digit so output is 4.

input:
3
4 6
2 8
19 18

output:
6
6
1

input:
7
4 9
1 8
4 2
7 6
2 4
21 41
22 77

output:
4
1
6
9
6
1
2

input:
2
1 11
108 308

output:
1
6

input:
1
1081 1999

output:
1

hint:
Take last digit in base a.
Now calculate b%4. Here b is very large so we follow this approach to calculate mod of large number.
If b%4==0 that means b is completely divisible by 4, so our exponent now will be exp = 4 because by multiplying number 4 times, we get the last digit according to cycle table in above diagram.
If b%4!=0 that means b is not completely divisible by 4, so our exponent now will be exp=b%4 because by multiplying number exponent times, we get the last digit according to cycle table in above diagram.
Now calculate ldigit = pow( last_digit_in_base, exp ).
Last digit of a^b will be ldigit%10.
"""
for i in range(int(input())):
    a,b=list(map(int,input().split()))
    p=pow(a,b,10)
    print(p)
