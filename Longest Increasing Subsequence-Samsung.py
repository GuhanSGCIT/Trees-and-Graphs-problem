"""
Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in
sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous,
or unique.

Note: Duplicate numbers are not counted as increasing subsequence.

timing:1sec
level:6

Input:
The first line contains an integer T, depicting total number of test cases. Then following T lines contains an integer N
depicting the size of array and next line followed by the value of array.

Output:
For each testcase, in a new line, print the Max length of the subsequence in a separate line.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 1000
0 ≤ A[i] ≤ 300

Example:
Input:
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

Output:
6
3

Explanation:
Longest increasing subsequence is of size 3 with elements (there are many subsequence, but listing one of them): 5 7 9.

input:
3
9
1 2 3 4 2 1 5 0 5
3
1 0 1
9
1 0 12 45 2 0 12 11 42

output:
5
2
4

input:
1
10
1 8 5 0 2 0 4 0 6 3

output:
4

input:
2
4
2 4 1 0
6
1 0 2 0 1 3

output:
2
3

input:
1
7
1 2 3 4 5 6 7

output:
7

hint:
we have set of active lists of varying length. We are adding an element A[i] to these lists. We scan the lists (for end elements)
in decreasing order of their length. We will verify the end elements of all the lists to find a list whose end element is smaller
than A[i] (floor value).

"""
def CeilIndex(A, l, r, key): 
  
    while (r - l > 1): 
      
        m = l + (r - l)//2
        if (A[m] >= key): 
            r = m 
        else: 
            l = m 
    return r 
   
def LongestIncreasingSubsequenceLength(A, size): 
   
    tailTable = [0 for i in range(size + 1)] 
    len = 0 # always points empty slot 
   
    tailTable[0] = A[0] 
    len = 1
    for i in range(1, size): 
      
        if (A[i] < tailTable[0]): 
  
            # new smallest value 
            tailTable[0] = A[i] 
   
        elif (A[i] > tailTable[len-1]): 
            tailTable[len] = A[i] 
            len+= 1
   
        else: 
            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i] 
          
   
    return len

for i in range(int(input())):
    n=int(input())
    A=[int(v) for v in input().split()]
    print(LongestIncreasingSubsequenceLength(A, n)) 
