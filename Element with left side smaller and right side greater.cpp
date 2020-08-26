/*
Given an unsorted array of size N. Find the first element in array such that all of its left elements are smaller and all right elements to it are greater than it.

Note: Left and right side elements can be equal to required element. And extreme elements cannot be required element.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated array elements.

Output:
For each test case, in a new line print the required element. If no such element present in array then print -1.

Constraints:
1 <= T <= 100
3 <= N <= 106
1 <= A[i] <= 106

Example:
Input:
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

Output:
5
-1
7
Explanation:
Elements on left of 5 are smaller than 5 and on right of it are greater than 5

input:
4
3
5 4 2
8
4 5 2 9 7 6 1 8
4
7 8 4 2
2
2 1

output:
-1
-1
-1
-1

input:
1
12
1 5 9 6 3 2 4 7 8 10 11 12

output:
10

input:
1
3
11 111 111

output:
111

input:
2
4
1 10 100 1000
5
1 2 3 4 5

output:
10
2

hint:
Traverse left to right and keep track of maximum element till ith index,similarly traverse right to left and keep track of minimum element till ith index.
Use of auxiliary arrays here will be useful to keep track of maximum and minimum element.Finally ttravese the input array and chek if arr[i] > ith maximum in leftmax array and arr[i] < ith minimum in rightmin array.
*/
#include <bits/stdc++.h>
using namespace std;

// Function to return the index of the element which is greater than
// all left elements and smaller than all right elements.
int findElement(int arr[], int n) {
    // leftMax[i] stores maximum of arr[0..i-1]
    int leftMax[n], rightMin[n];
    leftMax[0] = arr[0];
    // Initialize minimum from right
    rightMin[n - 1] = arr[n - 1];

    // Fill leftMax[]1..n-1]
    for (int i = 1; i < n; i++) leftMax[i] = max(leftMax[i - 1], arr[i]);

    // Fill rightMin[]1..n-1]
    for (int i = n - 2; i >= 0; i--) rightMin[i] = min(rightMin[i + 1], arr[i]);

    // Traverse array from right
    for (int i = 1; i < n - 1; i++) {
        // Check if we found a required element
        if (leftMax[i-1] <= arr[i] && rightMin[i + 1] >= arr[i]) return arr[i];
    }

    // If there was no element matching criteria
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
