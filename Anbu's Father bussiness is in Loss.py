"""
During the days of Lockdown due to corona virus, Anbu's Father bussiness is in Loss. On Zeroth day of Lockdown the loss was Rs P,
then Rs Q on the First day. Anbu observed loss as a function and wanted to calculate the loss on Nth day of the Lockdown.
He observed that the loss is dependent on the previous days,
i.e. F(n)=F(n−1)+F(n−2)+F(n−1)∗F(n−2)

You are given the loss on Zero th day and the First day of Lockdown. You have to find the loss on N th day.

timing:1sec
level:6

Input desription:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains a single line of input , having three integers P,Q,N.

Output description:
For each testcase, output in a single line answer ,loss on the Nth day. Loss can be large, output it modulo 1000000007 (10^9+7).

Constraints

    1≤T≤105
    0≤P,Q,N≤109

Sample Input:
2
1 2 3
2 3 3

Sample Output:
17
47

EXPLANATION:
For first test case F(0)=1, F(1)=2 , F(2)=1+2+(1∗2)=5 , F(3)=5+2+(5∗2)=17

input:
3
1 4 5
4 8 9
10 12 14

output:
24999
84055858
807242112

input:
1
45 75 89

output:

input:
4
35 36 98
1 2 2
1 1 1
20 302 404
4 5 6

output:
166874861

input:
1
1 0 1
output:
0

hint:
or any k, G(k) = ((a + 1)^( (Kth – 1) fibonaci number)) * ((b + 1)^(Kth fibonaci number)
Now the question reduces to calculate the power of a number
Since the bibonaci number is very large, Even the 100th fibonaci numbe has 21 digits so we cant the the fibonaci number
We have heard about fermat little theorem,
It states that
(a^(p-1) ) % p = 1 where p is a prime number
From quotient remainder theorem:
fib( n ) = k * (p-1) + (fib(n) % (p – 1))
Now using this :
( c^( fib(n) ) ) % p = ( c^((k)*(p-1)) ) % p * ( c ^ (fib(n) % (p – 1))) % p
can be written as : X = Y * Z
Z can be easily calculated as (fib(n) % (p – 1)) can be easily store in int datatype
Y = 1 using fermat therorem
Nth fibo num can be calculated using Matrix Exponentaion.

code:
"""
mod=1000000007
def fib(n): 
    F=[[1, 1],[1, 0]] 
    if (n==0): 
        return 0
    power(F,n-1)
    return F[0][0]
def multiply(F,M):
    x=(F[0][0]*M[0][0]+F[0][1]*M[1][0])%(mod-1)
    y=(F[0][0]*M[0][1]+F[0][1]*M[1][1])%(mod-1)
    z=(F[1][0]*M[0][0]+F[1][1]*M[1][0])%(mod-1)
    w=(F[1][0]*M[0][1]+F[1][1]*M[1][1])%(mod-1)
    F[0][0]=x 
    F[0][1]=y 
    F[1][0]=z 
    F[1][1]=w 
def power(F,n):
    if(n==0 or n==1): 
        return;
    M = [[1, 1], 
         [1, 0]];
    power(F,n//2) 
    multiply(F,F)
    if(n%2!=0): 
        multiply(F,M)
for _ in range(int(input())):
    p,q,n=list(map(int, input().split()))
    if n==0:
        print(p)
        continue
    f1=fib(n)
    f2=fib(n-1)
    ans=pow(p+1,f2,mod)*pow(q+1,f1,mod)
    ans=ans-1
    ans=ans%mod
    print(ans)
