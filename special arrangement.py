"""
An operation on an array of size n shifts each of the array's elements 1 unit to the left. 

Given an array of n integers and a number, d, perform d operations on the array. Then print the updated array as a single
line of space-separated integers.

timng:1sec
level:4

Input Format:
The first line contains two space-separated integers denoting the respective values of n (the number of integers) and d
(the number of operations you must perform).
The second line contains n space-separated integers describing the respective elements of the array's initial state.

Constraints:
1≤n≤105
1≤d≤n
1≤ai≤106
where ai is the ith element of array

Output Format:
Print a single line of n space-separated integers denoting the final state of the array after performing d operations.

Sample Input:
5 4
1 2 3 4 5

Sample Output:
5 1 2 3 4

Explanation:
When we perform d=4 operations, the array undergoes the following sequence of changes:
[1,2,3,4,5]→[2,3,4,5,1]→[3,4,5,1,2]→[4,5,1,2,3]→[5,1,2,3,4]
Thus, we print the array's final state as a single line of space-separated values, which is 5 1 2 3 4.

Input:
6 3
19 4 6 5 2 1

output:
5 2 1 19 4 6

Input:
9 8
8 4 6 5 1 2 3 7 9

output:
9 8 4 6 5 1 2 3 7

Input:
4 2
5 8 6 1

output:
6 1 5 8

Input:
5 2
8 5 2 6 3

output:
2 6 3 8 5

hint:
Instead of shifting the elements one by one, we first print elements from index ddd to index n−1.
Then from 0 to index d−1.
"""
n,k = map(int,input().split())
arr = list(map(int,input().split()))
if len(arr) == n:
	arr = arr[k:] + arr[:k]
	for i in arr:
		print(i,end=" ")
print()
				
