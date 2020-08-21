"""
Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].

Input:
The first line contains an integer T, depicting total number of test cases.  Then T test case follows.
First line of each test case contains an integer N denoting the size of the array.
Next line contains N space separated integeres denoting the elements of the array.

Output:
Print the maximum difference of the indexes i and j in a separtate line.

Constraints:
1 ≤ T ≤ 1000
1 ≤ N ≤ 10^3
0 ≤ A[i] ≤ 10^18

Example:
Input:
1
9
34 8 10 3 2 80 30 33 1

Output:
6

Explanation:
In the given array A[1] < A[7] satisfying the required condition(A[i] <= A[j]) thus giving the maximum difference of j - i which is 6(7-1).

input:
2
4
35 4 21 8
8
15 9 59 32 4 5 1 4

output:
2
3

input:
1
12
1 5 4 54 22 34 8 6 212 1 12 2

output:
11

input:
3
3
1 54 2
15
1 5 4 0 10 152 655 215 2 5 2 1 123 2 50
4
1 2 0 1

output:
2
14
1

input:
1
11
1 2 0 12 89 1 0 2 5 6 21
output:
10

hint:
Run two loops. In the outer loop, pick elements one by one from left. In the inner loop, compare the picked element with the
elements starting from right side. Stop the inner loop when you see an element greater than the picked element and keep updating
the maximum j-i so far.

"""
def maxIndexDiff(arr, n): 
    maxDiff = -1
    for i in range(0, n): 
        j = n - 1
        while(j > i): 
            if arr[j] > arr[i] and maxDiff < (j - i): 
                maxDiff = j - i; 
            j -= 1
      
    return maxDiff 
  
# driver code 
for i in range(int(input())):
    n = int(input())
    arr = [int(v) for v in input().split()] 
    maxDiff = maxIndexDiff(arr, n) 
    print(maxDiff) 
