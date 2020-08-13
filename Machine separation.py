"""
A machine recycles scrap bottles, the size of the bottle is categorised into types. For n number of bottles you have to
calculate the number of bottles in each category type.

Size to category table:-
BOTTLE SIZE: | 1,2 - TYPE 1 | 3,4 - TYPE 2 | 5,6 - TYPE 3

timing:1sec
level:3

Input:
The first line of the input contains a single integer T. T denoting the number of test cases.
The description of T test cases is as follows.
The first line of each testcase will contain the total number of bottles N.
The next line will contain the size of each bottle separated by a space.

Output:
For each test case, print "TYPE # - 5". where # denotes the type of bottle and 5 denotes the total count of it.

Constraints:
1≤T≤1000
1≤N≤10^5
1≤SizeOfBottle≤10^6

Sample Input:
1
11
1 1 2 3 4 5 3 6 2 3 1 

Sample Output:
TYPE 1 - 5
TYPE 2 - 4
TYPE 3 - 2

Explanation:
On comparing the size of the bottles which in this case are 1 1 2 3 4 5 3 6 2 3 1 we can see that
TYPE 1 has 5 bottles (i.e 1 1 2 2 1) TYPE 2 has 4 bottles (i.e 3 4 3 3) TYPE 3 has 2 bottles (i.e 5 6)

input:
1
20
1 2 3 4 5 6 6 5 4 1 2 1 2 13 4 5 4 2 3 5

output:
TYPE 1 - 7
TYPE 2 - 6
TYPE 3 - 6

input:
3
4
2 4 5 4
7
1 5 4 3 2 1 6
8
4 5 6 1 5 2 6 1

output:
TYPE 1 - 1
TYPE 2 - 2
TYPE 3 - 1
TYPE 1 - 3
TYPE 2 - 2
TYPE 3 - 2
TYPE 1 - 3
TYPE 2 - 1
TYPE 3 - 4

input:
1
54
5 2 6 3 1 4 4 5 6 1 2 3 1 1 1 1 1 1 2 2 2 2 2 2 5 5 5 5 5 5 4 5 6 2 5 4 1 2 3 6 5 4 1 4 5 2 6 3 1 4 5 2 6 3 4 4 4 4 4 4

output:
TYPE 1 - 23
TYPE 2 - 18
TYPE 3 - 19

input:
1
2
1 2

output:
TYPE 1 - 2
TYPE 2 - 0
TYPE 3 - 0


hint:
Just count the bottles based the type varient and print as per description.

"""
from sys import stdout, stdin

for _ in range(int(stdin.readline())):
    a = int(stdin.readline())
    arr = [int(x) for x in input().split()]
    stdout.write(f"TYPE 1 - {arr.count(1) + arr.count(2)}\n")
    stdout.write(f"TYPE 2 - {arr.count(3) + arr.count(4)}\n")
    stdout.write(f"TYPE 3 - {arr.count(5) + arr.count(6)}\n")
