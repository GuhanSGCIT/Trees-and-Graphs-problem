"""
In international standards, when writing a number, a comma is placed after every three digits starting from the right. For example, 1000000 is written as 1,000,000.
Whereas in India and few other countries, a comma is placed after the first three digits from the right, after that a comma is placed after every two digits. For example, 1000000 is written as 10,00,000.
Given two numbers, one in international format (W) and another in Indian format (I), print if they are equal or not.

Input:
First line contains T no. of test cases
For every test case, a line W and I separated by space

Output:
For every test case, print equal or different on a new line.

Constraints
1≤T≤1000
1≤len(W),len(I)≤50

Sample Input:
2
1,359,479 13,59,479
4,750 43,140

Sample Output:
equal
different

EXPLANATION:
Self-explanatory.


input:
3
12 120
15,000 15,000
1 1

output:
different
equal
equal

input:
1
159,151,065 1,65,51,265

output:
different

input:
3
1,111,111 1,11,11,111
15,000 01,50,000
1 10

output:
different
different
different

input:
2
11,000 11,100
1,111 1,111

output:
different
equal

hint:
Just remove the commas from the numbers,
and check if W == I, if yes, then print equal,
otherwise, print different
"""
T = int(input())
for z in range(T):
    international_number, indian_number = input().split()
    international_number = international_number.replace(",","")
    indian_number = indian_number.replace(",","")
    #print(indian_number, international_number)
    if indian_number == international_number:
        print("equal")
    else:
        print("different")
