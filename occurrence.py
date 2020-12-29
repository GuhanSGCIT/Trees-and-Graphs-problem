"""
Question
A string consists of char or num denotes the bus,your task is to find the last trip of a given bus
k.The last trip is the last occurrence of k in string.If not have trip print 0.

Input description
First line has string
Second line has a char k

Output description
print the value integer

Explanation
Input : str = "geeks", x = 'e'
Output :3
Last index of 'e' in "geeks" is: 3

Input
123451

Output
6

Input
1222
2

Output
4

Input
12345
6

Output
0

Input
1
1

Output
1

Input
gre23sjyyytree442r
r

Output
18

Solution:"""
def findLastIndex(str, x): 
	index = -1
	for i in range(0, len(str)): 
		if str[i] == x: 
			index = i 
	return index+1
 
str = input()

x = input()

index = findLastIndex(str, x) 

if index == -1: 
	print("-1") 
else: 
	print(index) 
