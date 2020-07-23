"""
You are given a permutation p1,p2,…,pN of the integers 1 through N. You may perform up to K operations of the following type:
1.)Choose three pairwise distinct valid indices i1,i2,i3. Note that these indices do not have to be chosen in increasing order.
2.)Let's denote the values of pi1, pi2 and pi3 before this operation by v1, v2 and v3respectively.
3.)Change pi2 to v1, pi3 to v2 and pi1 to v3. In other words, perform a cyclic right shift on the elements pi1,pi2,pi3 in this order.

Your task is to sort the permutation in increasing order. Note that you do not have to minimise the number of performed operations.

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and K.
The second line contains N space-separated integers p1,p2,…,pN.

Output Description:
For each test case:
If it is impossible to sort the given permutation using at most K operations, print a single line containing the integer −1.
Otherwise, first, print a line containing a single integer M(0 ≤ M ≤ K) ― the number of operations you want to perform.
Then, print M lines describing these operations. For each i (1≤i≤M), the i-th of these lines should contain three space-separated
integers ai, bi and ci (pairwise distinct; 1≤ai,bi,ci≤N) ― the indices on which the i-th operation is performed.

Testcases:
Input:
1
4 2
3 2 4 1
Output:
1
1 3 4

Explanation:
Example case 1: We can sort the permutation by performing one cyclic right shift operation on the indices 1, 3 and 4.

Input:
2
5 2
4 5 1 2 3
6 5
5 6 1 2 3 4
Output:
2
4 2 5
4 3 1
2
5 3 1
6 4 2

Input:
1
5 1
5 4 3 2 1
Output:
-1

Input:
1
3 2
0 0 1
Output:
-1

Input:
2
2 1
1 2
3 1
2 1 3
Output:
0
-1

Solution:
"""
t=int(input())
for _ in range(t):
    n,ops=tuple(map(int,input().split()))
    arr=list(map(int,input().split()))
    arr.insert(0,0)
    visited=[False]*(n+1)
    res=[]
    left=[]
    lsize=0
    for i in range(1,n+1):
        if(visited[i] or arr[i]==i):
            visited[i]=True
            continue
        cycle=[]
        j=i
        size=0
        while(not visited[j]):
            visited[j]=True
            j=arr[j]
            cycle.append(j)
            size+=1
        k=2
        done=0
        while(k<size):
            res.append((cycle[0],cycle[k-1],cycle[k]))
            k+=2
            done+=2
        if(size-done==2):
            left.append(cycle[0])
            left.append(cycle[size-1])
            lsize+=2
        
        if(lsize==4):
            res.append((left[0],left[1],left[2]))
            res.append((left[0],left[3],left[2]))
            left=[]
            lsize=0
    if(lsize==2 or len(res)>ops):
        print(-1)
    else:
        print(len(res))
        for i in res:
            print(i[0],i[1],i[2])
