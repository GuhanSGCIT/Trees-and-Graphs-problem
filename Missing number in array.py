"""
Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

Input:
The first line of input contains an integer T denoting the number of test cases.
For each test case first line contains N(size of array). The subsequent line contains N-1 array elements.

Output:
Print the missing number in array.

Constraints:
1 ≤ T ≤ 200
1 ≤ N ≤ 10^7
1 ≤ C[i] ≤ 10^7

Example:
Input:
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10

Output:
4
9

Explanation:
Given array : 1 2 3 5. Missing element is 4.

input:
3
4
1 5 6 2
3
4 8 2
5
15 51 55 11 22

output:
-2
-6
-117

input:
1
8
4 5 8 2 1 6 3 7

output:
7

input:
2
9
4 9 3 6 5 2 1 8
6
4 5 6 1 2 3

output:
7
3

input:
1
3
5 8 9

output:
-7

hint:
The length of the array is n-1. So the sum of all n elements, i.e sum of numbers from 1 to n can be calculated using the
formula n*(n+1)/2. Now find the sum of all the elements in the array and subtract it from the sum of first n natural numbers,
it will be the value of the missing element.
"""
def getMissingNo(a, n): 
	i, total = 0, 1

	for i in range(2, n + 2):
		total += i
		total -= a[i - 2]
	return total

# Driver Code
for i in range(int(input())):
    n=int(input())
    arr = [int(v) for v in input().split()]
    print(getMissingNo(arr,n-1))
