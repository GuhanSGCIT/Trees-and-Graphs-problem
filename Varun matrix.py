"""
Varun has two matrices A and B, each with N rows (numbered 1 through N) and N columns (numbered 1 through N).

Varun may perform the following operation any number of times (including zero): choose an integer i(1≤i≤N),
then swap row i and column i in matrix A. (Formally, for each valid j, she swaps Ai,j with Aj,i.)

Is it possible to transform matrix A into matrix B?

timing:1sec
level:5

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
N lines follow. For each i (1≤i≤N), the i-th of these lines contains N space-separated integers Ai,1,Ai,2,…,Ai,N.
N more lines follow. For each i (1≤i≤N), the i-th of these lines contains N space-separated integers Bi,1,Bi,2,…,Bi,N.

Output description:
For each test case, print a single line containing the string "Yes" if it is possible to transform A into B or "No"
if it is impossible (without quotes).

Constraints
    1≤T≤105
    1≤N≤210
1≤Ai,j,Bi,j≤10^9
for each valid i,j the sum of N2
over all test cases does not exceed 3⋅10^6

Example Input
1
3
1 2 3
4 5 6
7 8 9
1 2 7
4 5 8
3 6 9

Example Output
Yes

Explanation
Example case 1: We can swap the second row with the second column and in the resulting matrix, swap the first row with the
first column.

input:
1
4
1 2 4 5
7 8 9 4
5 5 4 4
1 5 9 6
1 2 5 4
7 8 4 9
5 5 4 4
1 5 6 9

output:
No

input:
2
2
1 0
0 1
1 1
0 0
1
1
2

output:
No
No

input:
1
5
55 44 48 68 61
3 4 1 8 5
102 15 4 1 2
45 65 23 12 11
1 2 3 4 5
55 44 48 61 68
3 4 1 5 8
102 15 4 2 1
45 65 23 11 12
1 2 3 5 4

output:
No

input:
3
1
1
1
2
1 1
1 1
2 3
4 5
3
1 0 0
0 1 0
0 0 1
1 0 0
0 1 0
0 0 1

output:
Yes
No
Yes

code:
"""
for _ in range(int(input())):
    n, a, b = int(input()), [], []
    for i in range(n):
        a.append(input().split())
    for i in range(n):
        b.append(input().split())
    flag = True
    for i in range(n):
        if a[i][i] != b[i][i]:
            flag = False
            break
    if not flag:
        print('No')
        continue
    flag = False
    for i in range(n):
        for j in range(n):
            if a[i][j] == b[i][j]:
                continue
            if a[i][j] != b[i][j] and a[j][i] == b[i][j]:
                for k in range(n):
                    a[j][k], a[k][j] = a[k][j], a[j][k]
            else:
                flag = True
                break
        if flag:
            break
    if flag:
        print('No')
        continue
    if a == b:
        print('Yes')
    else:
        print('No')
