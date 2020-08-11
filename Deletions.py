"""
The greatest common divisor (GCD) of a sequence is the greatest positive integer which divides each element of this sequence.

You are given a sequence A of positive integers with size N. You are allowed to delete up to N−1 elements from this sequence.
(I.e., you may delete any number of elements, including zero, as long as the resulting sequence is non-empty.)

Please find the minimum number of elements which have to be deleted so that the GCD of the resulting sequence would be equal to 1,
or determine that it is impossible.

timing:1sec
level:6

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The second line contains N space-separated integers A1,A2,…,AN.

Output
For each test case, print a single line containing one integer — the minimum number of elements to delete, or −1
if it is impossible to make the GCD equal to 1.

Constraints
1≤T≤100
2≤N≤1,000
1≤Ai≤50,000
for each valid i

Input
2
2
2 3
2
2 4

Output:
0
-1

Explanation
Example case 1: The GCD is already equal to 1, so the answer is 0.
Example case 2: It is impossible to make the GCD equal to 1, so the answer is −1.

input:
3
3
5 7 9
2
4 6
4
2 4 6 8

output:
0
-1
-1

input:
1
3
5 8 9

output:
0

input:
1
2
8 9

output:
0

input:
3
2
2 5
2
8 4
3
1 3 5

output:
0
-1
0

hint:
It makes no sense to remove any elements, since any such operation doesn’t decrease the GCD and increase the number of deletions.
Therefore the answer is 0 if the GCD of the original array is 1, −1 otherwise.

"""
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=min(a)
    if b==1:
        count=-1
    for i in range(2,(b+1)):
        count=0
        for j in range(n):
            if a[j]%i!=0:
                count=-1
                break
        if count==0:
            break
    if count==0:
        print(-1)
    else:
        print(0)
                
