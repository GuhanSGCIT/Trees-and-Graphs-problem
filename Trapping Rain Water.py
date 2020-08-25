"""
Given an array arr[] of N non-negative integers representing height of blocks at index i as Ai where the width of each block is 1.
Compute how much water can be trapped in between blocks after raining.
Structure is like below:
| |
|_|
We can trap 2 units of water in the middle gap.

Input:
The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains an integer N denoting the size of the array, followed by N space separated numbers to be stored in array.

Output:
Output the total unit of water trapped in between the blocks.

Constraints:
1 <= T <= 100
3 <= N <= 10^7
0 <= Ai <= 10^8

Example:
Input:
2
4
7 4 0 9
3
6 9 9

Output:
10
0

Explanation:
Water trapped by block of height 4 is 3 units, block of height 0 is 7 units. So, total unit of water trapped is 10 units.

input:
3
6
7 2 5 1 5 1
3
4 2 5
6
7 2 5 4 1 1

output:
7
2
3

input:
2
2
5 2
3
4 2 6

output:
0
2

input:
1
3
4 1 4

output:
3

input:
1
3
3 2 3

output:
1

hint:
An element of the array can store water if there are higher bars on left and right. The amount of water to be stored in every
element can be found out by finding the heights of bars on the left and right sides. The idea is to compute the amount of water
that can be stored in every element of the array. 
"""
def maxWater(arr, n) :
    res = 0; 
    for i in range(1, n - 1) : 
        left = arr[i]; 
        for j in range(i) :
            left = max(left, arr[j]); 
        right = arr[i]; 
         
        for j in range(i + 1 , n) : 
            right = max(right, arr[j]);
        res = res + (min(left, right) - arr[i]); 
 
    return res; 
 
# Driver code 
if __name__ == "__main__" :
    for i in range(int(input())):
        n = int(input())
        arr =[int(b) for b in input().split()] 
        print(maxWater(arr, n)); 
