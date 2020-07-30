"""
 Guna has a string (S), which is initially empty. In one operation, he can select a lowercase character (a-z) uniformly at random
and appends it to S. He then evaluates whether S is a palindrome or not; if it is, he gets 1 point.

Given that Guna performs N operations in total, find the expected no. of points Bob gets. It is guaranteed that the answer
can always be represented as a rational number ab. You must print this number modulo 1000000007.
By this we mean that you must print, a×b−1 modulo 1000000007 where b−1 denotes the modulo inverse of b with respect to 1000000007.

Also observe that 1000000007 is a prime number.

Timnig:1 sec
level:6

Input Description:
First line of the input will contain T denoting the number of test-cases.For every test case, first line will contain N.

Output Description:
For every test case, print the required answer in a separate line % 10^9+7.

Constraints
    1 ≤ T ≤ 30
    1 ≤ N ≤ 1000000000

Input:
3
2
3
4

Output:
576923082
153846156
214497044

Explanation
For n = 2, the answer is 27/26 points.  
We have to print this number modulo 1000000007 which equals 27 * 26 −1 % 1000000007 = 576923082.

Input:
4
5
2
4
7

Output:
275147932
576923082
214497044
125967230

Input:
6
1
11
111
1111
11111
111111

Output:
1
519417116
184048898
515799774
85191740
863088480

Input:
2
6546
65465

Output:
825389001
552334093

Input:
4
4
8
9
2

Output:
214497044
315406064
504844898
576923082

Solution:
"""
t=int(input())
e=10**9+7
for _ in range(t):
    n=int(input())
    if(n==1):
        print(1)
    else:
        c=n//2
        x=0
        k=pow(26,c*(e-2),e)
        if n%2==0:
            
            b=pow(25,e-2,e)
            a=(pow(26,c,e)*27)%e
            a-=27
            a=(a*b)%e
            a=a*k
            print(a%e)
        else:

            b=pow(25,e-2,e)
            a=(pow(26,c,e)*27)%e
            a-=2
            a=(a*b)%e
            a=a*k
            print(a%e)
