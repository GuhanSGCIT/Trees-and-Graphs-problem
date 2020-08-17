"""
Given a natural number, calculate sum of all its proper divisors. A proper divisor of a natural number is the divisor that
is strictly less than the number. For example, number 20 has 5 proper divisors: 1, 2, 4, 5, 10, and
the divisor summation is: 1 + 2 + 4 + 5 + 10 = 22.

timing:1sec
level:4

Input
The first line contains number of test cases T. Each line of test case contain a number N

Output
For each test case, output is sum of divisors.

 
Constraints
    1 ≤ T ≤ 100
    1 ≤ A≤ 10^6

Input:
2
20
5

Output:
22
1

input:
3
45
89
15

output:
33
1
9

input:
2
120
458

output:
240
232

input:
4
1
2
34
56

output:
0
1
20
64

input:
1
1111135165

output:
412707395

hint:
This problem has very simple solution, we all know that for any number ‘num’ all its divisors are always less than and equal
to ‘num/2’ and all prime factors are always less than and equal to sqrt(num). So we iterate through ‘i’ till i<=sqrt(num)
and for any ‘i’ if it divides ‘num’ , then we get two divisors ‘i’ and ‘num/i’ , continuously add these divisors but for some
numbers divisors ‘i’ and ‘num/i’ will same in this case just add only one divisor

"""
import math  
def printDivisors(n) : 
    s = 0
    i = 1
    while i <= math.sqrt(n): 
        if (n % i == 0) : 
            if (n // i == i) : 
                s = s + i 
            else : 
                s = s + i + n//i             
        i = i + 1
    return s
    
for _ in range(int(input())) :
    n = int(input())
    ans = printDivisors(n)
    print(ans-n)
