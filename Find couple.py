"""
In a party everyone is in couple except one. People who are in couple have same numbers. Find out the person who is not in couple.

In des
The first line contains an integer 'N' denoting the size of array.
The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array. (N is always odd)

Ot des
Print number of the person not in couple.

5
1 2 3 2 1

3

3
1 1 4

4

7
1 1 2 2 5 7 7

5

15
1 2 3 4 5 6 7 8 7 6 5 4 3 2 1

8

1
1

1

5
12 44 17 12 44

17

Exp
From sample: element 3 has no pair.

Hint
Find the element present once in array.
H 4
T 2000

"""
N=int(input())
L=list(map(int,input().split()))
for i in range(N):
    if(L.count(L[i])==1):
        print(L[i])
        