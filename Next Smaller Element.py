"""
Given an array, print the Next Smaller Element (NSE) for every element. The Smaller smaller Element for an element
x is the first smaller element on the right side of x in array. Elements for
which no smaller element exist (on right side), consider next smaller element as -1.

input:
First line contain integer N,size of array
Second line contain N space separated integers,denotes array elements.

output:
Print the current value with its next smaller value in each line

Explanation:
Exp
For any array, rightmost element always has next smaller element as -1.
For an array which is sorted in increasing order, all elements have next smaller element as -1.
Element       NSE
   4      -->   2
   8      -->   5
   5      -->   2
   2      -->   -1
   25     -->   -1

input:
4
2 1 4 3

output:
2 -- 1
1 -- -1
4 -- 3
3 -- -1

input:
2
2 3

output:
2 -- -1
3 -- -1

input:
3
1 2 3

output:
1 -- -1
2 -- -1
3 -- -1

input:
5
4 8 5 2 25

output:
4 -- 2
8 -- 5
5 -- 2
2 -- -1
25 -- -1


input:
1
1

output:
1 -- -1

hint:
Use two loops: The outer loop picks all the elements one by one. The inner loop looks for the first smaller element for the element picked by outer loop. If a smaller element is found then that element is printed as next, otherwise -1 is printed.

"""
def printNSE(arr): 

	for i in range(0, len(arr), 1): 

		next = -1
		for j in range(i + 1, len(arr), 1): 
			if arr[i] > arr[j]: 
				next = arr[j] 
				break
			
		print(str(arr[i]) + " -- " + str(next)) 
N = int(input())
arr = list(map(int,input().split())) 
printNSE(arr) 