"""
Rajesh is a very brilliant student. He likes sequences a lot specially the fibonacci sequence.
The fibonacci sequence is shown below
1 1 2 3 5 8 ...
Today Rajesh friend Saket gave him a problem on fibonacci sequences.

The problem is to find the N'th fibonacci number given N.
As this number can be very very large, Saket just need the n'th fibonacci number MOD 1000000007.

Since Rajesh is a genious at fibonacci sequences, he considers this as a pretty easy problem and asks you to solve it as
he is feeling sleepy.Can you solve the problem before Rajesh wakes up.

Hint: Recall the matrix form of the fibonacci numbers.

timing:2.5sec
level:5

Input:
First line of the input contains an integer T, denoting the number of inputs.
T lines follow each containing an integer N

Output:
Output the N'th fibonacci number MOD 1000000007 in a newline

Input:
3
3
4
5

Output:
2
3
5

Explanation
The fibonacci numbers corresponding to the 2nd, 3rd, 4th term is 1, 2, 3 respectively

input:
7
2
14
23
1
8
8
6

output:
1
377
28657
1
21
21
8

input:
3
12
24
11

output:
144
46368
89

input:
1
1000

output:
517691607

input:
1
999999

output:
616309404

hint:
It is a 2x2 matrix A with A[0][0]=1, A[0][1]=1, A[1][0]=1, A[1][1]=0. With this matrix form one can calculate the nth
Fibonacci just by raising the matrix to the power n. A[0][1] will give you the nth Fibonacci number.
"""
def mat_exp(A,n):
    res=[[1,0],[0,1]] 
    while n:
        if n%2:
            res=mat_mult(res,A) 
        A=mat_mult(A,A) 
        n//=2 
    return res
def mat_mult(A,B,mod=10**9+7): 
    C=[[1,1],[1,1]] 
    C[0][0]=((A[0][0]*B[0][0])%mod+(A[0][1]*B[1][0])%mod)%mod
    C[0][1]=((A[0][0]*B[0][1])%mod+(A[0][1]*B[1][1])%mod)%mod
    C[1][0]=((A[1][0]*B[0][0])%mod+(A[1][1]*B[1][0])%mod)%mod
    C[1][1]=((A[1][0]*B[0][1])%mod+(A[1][1]*B[1][1])%mod)%mod
    return C
def fib(n,mod=10**9+7):
    if n<=2:
        print(1)
        return  
    A=[[1,1],[1,0]] 
    exp=mat_exp(A,n)
    print(exp[0][1]%mod)
for _ in range(int(input())):
    n=int(input()) 
    fib(n) 
