"""
Shankar the Artist had two lists that were permutations of one another. He was very proud. Unfortunately, while transporting them
from one exhibition to another, some numbers were lost out of the first list. Can you find the missing numbers?

As an example, the array with some numbers missing, arr=[7,2,5,3,5,3]. The original array of numbers brr=[7,2,5,4,6,3,5,3].
The numbers missing are [4,6].

Notes:
    If a number occurs multiple times in the lists, you must ensure that the frequency of that number in both lists is the same.
If that is not the case, then it is also a missing number.
    You have to print all the missing numbers in ascending order.
    Print each missing number once, even if it is missing multiple times.
    The difference between the maximum and minimum number in the second list is less than or equal to 100.
    arr: the array with missing numbers
    brr: the original array of numbers

timing:2sec
level:6

Input:
There will be four lines of input:
N is the size of the first list, arr.
The next line contains N space-separated integers arr[i].
M is the size of the second list, brr.
The next line contains M space-separated integers brr[i].

Output:
Output the missing numbers in ascending order separated by space.

Constraints
    1≤n,m≤2 X 10^5
    n≤m
    1≤brr[i]≤10^4
    Xmax - Xmin ≤100

Sample Input:
10
203 204 205 206 207 208 203 204 205 206
13
203 204 204 205 206 207 205 208 203 206 205 206 204

Sample Output:
204 205 206

EXPLANATION:
204 is present in both arrays. Its frequency in arr is 2, while its frequency in brr is 3.
Similarly, 205 and 206 occur twice in arr, but three times in brr. The rest of the numbers have the same frequencies in both lists.

input:
12
1 5 6 7 9 11 2 3 6 7 10 11
4
11 20 9 11

output:
20

input:
8
12 23 45 56 13 23 46 47
5
1 3 5 2 4

output:
1 2 3 4 5

input:
6
111 333 555 222 402 302
7
103 204 506 704 204 511 699

output:
704 103 204 506 699 511

input:
3
1 5 2
4
10 20 30 10

output:
10 20 30

hint:
The main task is to find the frequency of numbers in each array. This can be done using count array.
If the frequency of a number is different, then print that number.
we can have two count arrays for each array. Then we need to run a loop for the count array.
While traversing the array if frequencies mismatch, print that number.

"""
from sys import stdin,stdout
n=int(stdin.readline())
d={}
arr=[int(num) for num in stdin.readline().split()]
m=int(stdin.readline())
brr=[int(num) for num in stdin.readline().split()]
if n-m==0:
    print(0)
else:
    for i in set(brr):
        if brr.count(i)!=arr.count(i):
            print(i,end=' ')
