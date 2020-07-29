"""
Consider the infinite x axis. There are N impacts on this X-axis at integral points (X1,X2,....XN) (all distinct) .
An impact at a point Xi propagates such that at a point X0, the effect of the impact is K|Xi−X0|. Given the point X0, N and K.
Assume the total impact on X0 is M , find if it is possible to do so.

Note: You are not required to find the set X

Formally print "yes" if this is possible and "no" if not possible.

level:7
timing:1sec

Input Description:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, four integers N,K,M,X0

Output Description:
The output of each test case is either "yes" or "no"

Constraints
1≤T≤1000
1≤N≤100
1≤K≤1000
1≤M≤1018
−109≤X0≤109

Input:
2
4 3 10 10
2 3 10 10

Output:
no
yes

Input:
3
1 2 3 4
10 20 30 40
11 22 33 44

Output:
no
no
no

Input:
1
2 4 8 10

Output:
yes

Input:
2
4 8 16 36
1 2 3 4

Output:
no
no

Input:
1
7 14 21 28

Output:
no

Solution:
"""
from math import log
try:
    for i in range (int(input())):
        a = input().split(" ")
        n,k,x,m = map(int,a)
        ans = "no"
        u = 0
    
        if k != 2 and k != 1:
            if x%k == 0:
                x //= k
                u = -1
            elif x%k == 1:
                n -= 1
                x //= k
                u = -1
    
            if u == -1:     
                while x != 0:
                    if x%k == 0:
                        x //= k
                    elif x%k == 1:
                        x //= k
                        n -= 1
                    elif x%k == 2:
                        x //= k
                        n -= 2
                    else:
                        break
    
            if n == 0 and x == 0:
                ans = "yes"
    
        elif k == 1:
            if x == n:
                ans = "yes"
    
        else:
            lst = []
            p = 0
            N = n
            while x != 0:
                if x%2 == 0:
                    x //= 2
                    p += 1
                elif x%2 == 1:
                    x //= 2
                    n -= 1
                    p += 1
                    lst.append(2**(p-1))
    
            if len(lst) == N:
                ans = "yes"
                
            if len(lst) < N:
                k = 0
                g = len(lst)
                if lst[0] > 2:
                    g += int(log(lst[0])//log(2))-1
                    k = 1
                for i in range(1,len(lst)):
                    if k == 1:
                        g += int(log(lst[i]//lst[i-1],2))
                    elif lst[i] > 2*lst[i-1]:
                        g += int(log(lst[i]//lst[i-1],2))-1
                        k = 1
                    else:
                        k = 0
                if g >= N:
                    ans = "yes"
    
        print(ans)
except EOFError as e : pass
    
