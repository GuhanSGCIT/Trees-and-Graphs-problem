"""
You can create a new task by generating some random math statement or modifying some theorems to get something new and build a
new task from that. For example, the conjecture’s statement says: "each even number no less than four can be expressed as the sum
of two primes". Let's modify it to: "each integer no less than 12 can be expressed as the sum of two composite numbers." Not like
the conjecture’s statement, we can prove this theorem.

You are given an integer n no less than 12; express it as a sum of two composite numbers.

Input
The only line contains an integer n(12 ≤ n ≤ 10^6).

Output
Output two composite integers x and y (1 < x, y < n) such that x + y = n .
If there are multiple solutions, you can output any of them.

Sample Inputs
12

Sample Outputs
4 8


Note
In the first example, 12 = 4 + 8 and both 4, 8 are composite numbers. You can output "6 6" or "8 4" as well.

input:
15

output:
6 9

input:
23

output:
8 15

input:
1000000

output:
4 999996

input:
454

output:
4 450

hint:
One way to solve this is by bruteforce: there are O(n) different ways to decompose nnn as sum of two numbers.
If we can check if a number is a prime in O(1) then the whole algorithm can run in O(n). You can use Sieve of
Eratosthenes to do the pre-calculation.
And another way is try to prove this theorem. The solution is simple: if nnn is odd number, then 9 and (n−9) is
an answer (n−9 is an even number at least 4, so a composite number), and if nnn is even number, then 8 and (n−8)
is an answer (n−8 is an even number at least 4, also must be a composite number).

"""
n = int(input())
prime = [1] * (n + 1)
prime[0] = prime[1] = 0
for i in range(4, n + 1):
    if i % 2 == 0:
        prime[i] = 0
for i in range(3, n + 1):
    if prime[i] != 0:
        for j in range(i * i, n + 1, i):
            prime[j] = 0
if n % 2 == 0:
    for i in range(4, n // 2):
        if prime[i] == 0 and prime[n - i] == 0:
            print(i, n - i)
            break
else:
    for i in range(4, (n // 2) + 1):
        if prime[i] == 0 and prime[n - i] == 0:
            print(i, n - i)
            break
