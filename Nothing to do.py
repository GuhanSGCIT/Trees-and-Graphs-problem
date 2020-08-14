"""
    Alli has quarreled with Bridal recently. Now she doesn't want to have anything in common with her!
Recently, they've received two collections of positive integers. The Alli's integers were A1, A2, ..., AN,
while Bridal's were B1, B2, ..., BM.

    Now Alli wants to throw away the minimal amount of number from her collection so that their collections would have no
common numbers, i.e. there won't be any number which is present in both collections. Please help Alli to find the minimal
amount of numbers she would need to throw away.

timing:2sec
level:3

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integer numbers N and M denoting the amount of numbers in Alli's
and Bridal's collections respectively.
The second line contains N space-separated integers A1, A2, ..., AN denoting the numbers of Alli.
The third line contains M space-separated integers B1, B2, ..., BM denoting the numbers of Bridal.

Output
For each test case, output a single line containing the minimal amount of numbers Alli needs to throw away from her collection
so that she wouldn't have any numbers in common with Bridal.

Constraints
    1 ≤ Ai, Bi ≤ 10^6
    All numbers are distinct within a single girl's collection.

Input:
2
3 4
1 2 3
3 4 5 6
3 3
1 2 3
4 5 6

Output:
1
0

Explanation
Example case 1. If Alli throws away the number 3 from her collection, she would obtain {1, 2} which is disjoint with {3, 4, 5, 6}.
Example case 2. Girls don't have any number in common initially. So there is no need to throw away any number.

input:
3
4 5
1 2 3 5
7 8 4 5 6
2 3
4 8
2 5 4
1 2
1
3 4

output:
1
1
0

input:
2
6 5
4 5 2 6 3 4
8 5 4 2 6
3 3
4 8 6
4 8 5

output:
4
2

input:
1
9 9
4 5 2 9 3 4 2 6 4
4 5 6 5 8 1 5 3 4

output:
4

input:
4
2 2
4 5
8 4
1 1
1
3
3 3
4 5 6
7 5 4
4 4
4 8 6 2
4 9 3 1

output:
1
0
2
1

hint:
Find the intersection of A and B and return its size.

"""
for i in range(int(input())):
    lens=input().split()
    alist=input().split()
    blist=input().split()
    som=len(list(set(alist).intersection(blist)))
    print(som)
