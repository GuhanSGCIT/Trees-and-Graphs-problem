"""
For a permutation P = (p1, p2, ..., pN) of numbers [1, 2, ..., N], we define the function
f(P) = max(p1, p2) + max(p2, p3) + ... + max(pN-1, pN).

You are given N and an integer K. Find and report a permutation P of [1, 2, ..., N] such that f(P) = K,
if such a permutation exists.Note f([1]) = 0.

Input Description:
    The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
    The only line of each test case consists of two space-separated integers N, K respectively.

Output Description:
For each test case, if a permutation satisfying the condition exists, output a single line containing N
space-separated integers which denotes any such permutation. If no such permutation exists, output a single integer -1 instead.
Use fast I/O methods since the size of the output is large.

Constraints
    1 ≤ T ≤ 40
    1 ≤ N ≤ 10^5
    Sum of N over all test cases in each file ≤ 10^6
    0 ≤ K ≤ 2 * 10^10

Input:
3
4 12
2 2
5 14

Output:
-1
1 2
5 4 3 2 1

Explanation:
Example 1. There doesn't exist any permutation of numbers [1, 2, 3, 4] that can have its f value equal to 4. Hence answer is -1.
Example 2. The permutations [1, 2] and [2, 1] both have their f values equal to 2. You can print any of these two permutations.
Example 3. The permutation [5, 4, 3, 2, 1] has f value = max(5, 4) + max(4, 3) + max(3, 2) + max(2, 1) = 5 + 4 + 3 + 2 = 14.

Input:
4
2 50
1 4
5 15
15 44

Output:
-1
-1
1 2 3 5 4 
-1

Input:
3
2 2
10 28
25 225

Output:
1 2 
-1
-1

Input:
3
2 15
2 2
11 121

Output:
-1
1 2 
-1

Input:
3
2 2
3 2
4 2

Output:
1 2
-1
-1

code:
"""
for i in range(int(input())):
    n,k=[int(i) for i in input().split()]
    if(n%2==0):
        if(k<(n*(n+1))//2 - 1  or  k>3*((n//2)**2) - 1):
            print(-1)
        elif(k==(n*(n+1))//2 - 1):
            for i in range(1,n+1):
                print(i,'',end='')
            print()
        else:
            k=k-(n*(n+1))//2 + 1
            count=0 
            p=0
            while(k>0):
                p+=2 
                k=k-n+p 
                count+=1
            l=[0 for i in range(n)]
            x=1 
            for i in range(n,n-count+1,-1):
                l[x]=i 
                x+=2
            k=-k 
            l[2*count - 1 +k]=n-count+1 
            p=1 
            for i in range(n):
                if(l[i]==0):
                    l[i]=p 
                    p+=1 
            for i in l:
                print(i,'',end='')
            print()
    else:
        if(n==1):
            if(k==0):
                print(1)
            else:
                print(-1)
        elif(k<(n*(n+1))//2 - 1  or k>3*(n//2)*(n//2 + 1)):
            print(-1)
        elif(k==(n*(n+1))//2 - 1):
            for i in range(1,n+1):
                print(i,'',end='')
            print()
        else:
            k=k-(n*(n+1))//2 + 1
            count=0 
            p=0
            while(k>0):
                p+=2 
                k=k-n+p 
                count+=1
            l=[0 for i in range(n)]
            x=1 
            for i in range(n,n-count+1,-1):
                l[x]=i  
                x+=2 
            k=-k 
            l[2*count - 1 +k]=n-count+1 
            p=1 
            for i in range(n):
                if(l[i]==0):
                    l[i]=p 
                    p+=1 
            for i in l:
                print(i,'',end='')
            print()
            
