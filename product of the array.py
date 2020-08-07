"""
 Ramanujan was a kindhearted man, and he wanted to give a cakewalk problem to the coders present, to warm them up.

 Given an array of N integers, print the product of the numbers present in the array.

timing:0.6sec
level:2

Input:
The first line contains T, the number of test cases.
Each test cases consists of two lines, the first line containing N, the number of elements, and the second line containing N integers.

Output
 For each test case, print the required answer in a single line.

Constraints
1 <= T <= 100
1 <= N <= 10
0 <= A[i] <= 15

Input:
1
2
2 2

Output:
4

hint:
simply find the product of the array.

input:
2
32
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 10020 1255 65165 3216 51 32165 165 651 651 524165 66546 321165
6
1 1 1 1 1 1

output:
8239186656315193400588079046598274324095753883761049600000000000
1

input:
1
9
15651 51635 6651651 651651 651651 6651651 2216 5 1

output:
168234504858902407038363182470403665800

input:
4
5
7 8 4 6 5
9
1 2 3 4 5 6 7 8 9
3
9 9 9
4
104 121 232 5965

output:
6720
362880
729
17414745920

input:
2
4
111 10101 1210 0
6
1010101 10101 0

output:
0
0

code:
"""
for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    c=1 
    for i in a:
        c*=i
    print(c)    
    
