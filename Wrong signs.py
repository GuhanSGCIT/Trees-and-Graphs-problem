"""
Instead of writing,a×(b+c)=a×b+a×c,Alex by mistakenly swapped the × and + signs on the left hand side. The equation became,
a+(b×c)=a×b+a×c ?

Alex somehow knew the value of a, but forgot the values of b and c such that the equation is satisfied.
Can you help him find how many ordered pairs (b,c)satisfy the above equation?

If there exists infinite ordered pair, output -1.

Note: a,b,c are integers

Input Description:
Single line containing a single integer a.

Output Description:
Single line containing one integer, denoting the number of ordered set (b,c)

Constraints
|a|≤1018

Input:
2

Output:
4

Explanation:
Possible ordered pairs are (0,1),(1,0),(3,4),(4,3)

Input:
456
Output:
256

Input:
1
Output:
-1
    
Input:
1000
Output:
256

Input:
7889
Output:
320

Solution:
"""
from random import randrange
prime = []

def sieve():
    N = 1000010  # Never change this value
    pr = [True]*N

    pr[0] = pr[1] = False

    for i in range(int(N**0.5)):
        if pr[i]:
            for j in range(2*i,N,i):
                pr[j] = False

    for i in range(N):
        if pr[i]:
            prime.append(i)

    

def miller_rabin(p):
    if p == 2 or p == 3:
        return True

    if p < 3 or p%2 == 0:
        return False

    for i in range(10):
        rand = randrange(2,p-2)
        n = p-1
        while n%2 == 0:
            n //= 2

        mod = pow(rand,n,p)
        if mod == 1 or mod == p-1:
            continue

        flag = 0
        while n != p-1:
            mod = pow(rand,n,p)
            if mod == p-1:
                flag = 1
                break

            n *= 2
        if flag == 0:
            return 0
    return True

sieve()

def fac(n):
    ans = 1
    for p in prime:
        if p*p*p > n:
            break

        count = 1

        while n%p == 0:
            n //= p
            count += 1
            
        ans = ans*count

    if miller_rabin(n):
        ans *= 2
    elif (n**0.5)*(n**0.5) == n and miller_rabin(int(n**0.5)):
        ans *= 3
    elif n != 1:
        ans *= 4
    return ans

a = int(input())

if abs(a) <= 1:
    print(-1)
else:
    print(2*fac(abs(a))*fac(abs(a-1)))
