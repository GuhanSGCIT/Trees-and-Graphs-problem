"""
There are N watchtowers built in a row. Each watchtower can only accommodate one person. Some of them are already occupied by
members of the Night's Watch. Since the members of the Night's Watch do not get along, no two consecutive towers can be occupied at
any moment.
Arya heard that the wildlings are planning an attack. She is not satisfied by the current security, so she plans to place more
members of the Night's Watch in the empty towers. What is the maximum number of people she can place in the towers such that no two
consecutive towers are occupied afterwards? Note that Arya may not remove anyone from already occupied towers.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The next line contains a single string S with length N. For each valid i, the i-th character of this string is '1' if the i -th watchtower is initially occupied or '0' if it is empty.

Output
For each test case, print a single line containing one integer — the maximum number of people Arya can place in the towers.
Constraints
1≤T≤1,000
1≤N≤10^6
S contains only characters '0' and '1'
initially, no two consecutive towers are occupied the sum of N,over all test cases does not exceed 10^6

Input:
2
6
010001
11
00101010000

Output:
1
3

input:
3
4
0100
4
1010
10
0101010111

output:
1
0
0

input:
1
12
100011100010

output:
2

input:
2
5
10100
4
1111

output:
1
0

input:
1
7
1010011

output:
0

hint:
For each maximal substring consisting of only '0’s, find out its contribution to the answer.
"""
for i in range(int(input())):
    n = int(input())
    s ='0'+input()+'0'
    s = [len(i) for i in s.split('1') if len(i) > 0]
    count = 0
    for x in s:
        if x%2 == 0:
            count += (x-2)//2
        else:
            count +=x//2
    print(count)