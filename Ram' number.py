"""
Ram has N dishes of different types arranged in a row: A1,A2,…,AN, where Ai denotes the type of the ith dish. He wants to choose
as many dishes as possible from the given list but while satisfying two conditions:
    He can choose only one type of dish.
    No two chosen dishes should be adjacent to each other.
Ram wants to know which type of dish he should choose from, so that he can pick the maximum number of dishes.

timing:1sec
level:6

Input:
The first line contains T, the number of test cases. Then the test cases follow.
For each test case, the first line contains a single integer N.
The second line contains N integers A1,A2,…,AN.

Output:
For each test case, print a single line containing one integer ― the type of the dish that Ram should choose from.
If there are multiple answers, print the smallest one.

Constraints
1≤T≤10^3
1≤N≤10^3
1≤Ai≤10^3
Sum of N over all test cases doesn't exceed 10^4

Sample Input:
3
5
1 2 2 1 2
6
1 1 1 1 1 1
8
1 2 2 2 3 4 2 1

Sample Output:
1
1
2

Explanation:
Test case 1:
For both type 1 and type 2, Ram can pick at most two dishes. In the case of multiple answers, we pick the smallest one.
Hence the answer will be 1.
Test case 2:
There are only dishes of type 1. So the answer is 1.
Test case 3:
For type 1, Ram can choose at most two dishes. For type 2, he can choose three dishes. For type 3 and type 4, Ram can
choose the only dish available. Hence the maximum is in type 2 and so the answer is 2.

input:
2
3
1 2 1
4
1 2 3 4

output:
1
1

input:
3
1
2
3
5 2 66
4
120 121 201 102

output:
2
2
102

input:
1
9
4 5 6 1 5 9 6 3 2

output:
5

input:
1
4
5 8 9 9

output:
5

hint:
As Ai​ is almost 1000. So, for each iii from 1 to 1000, we can find the largest valid subsequence is possible with i as it’s an element. If there are many valid i for which length of the valid subsequence is the same then the answer is minimum possible iii.
"""
from collections import Counter
for j in range(int(input())):
    a=input()
    b=list(input().split())
    l=[int(b[0])]
    for i in range(1,len(b)):
        if b[i]!=b[i-1]:
            l.append(int(b[i]))
        else:
            b[i]=0
    for k,_ in Counter(sorted(l)).most_common(1):
        print(k)