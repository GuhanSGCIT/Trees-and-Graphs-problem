"""
Given an array A[] of n numbers,which denotes person and another number x,
determine whether or not there exist two person in A is friend of x,if sum of 2 person
gives axactly x they are friends print yes,else no.

in des
First line contain N,size of array.
Second line contain N space separated integers,which denotes person.
Third line contain integer X,which also denotes person.

Ot des
Print yes or no

Ex
From sample
If we calculate the sum of the output,
1 + (-3) = -2

hINT
Check the pairs possibility of 2 and Print the two element in array which's sum
is equal to X

In
5
0 -1 2 -3 1
-2

Out
yes

In
5
1 -2 1 0 5
0

Out
no

In
5
1 2 3 4 5
9

Out
yes

In
3
-1 -2 2
0

Out
yes

In
2
1 -2
1

Out
no
T 1000
""" 

def hasArrayTwoCandidates(A, arr_size, sum): 
	quickSort(A, 0, arr_size-1) 
	l = 0
	r = arr_size-1
	 
	while l<r: 
		if (A[l] + A[r] == sum): 
			return 1
		elif (A[l] + A[r] < sum): 
			l += 1
		else: 
			r -= 1
	return 0
 
def quickSort(A, si, ei): 
	if si < ei: 
		pi = partition(A, si, ei) 
		quickSort(A, si, pi-1) 
		quickSort(A, pi + 1, ei) 

def partition(A, si, ei): 
	x = A[ei] 
	i = (si-1) 
	for j in range(si, ei): 
		if A[j] <= x: 
			i += 1
			
			
			A[i], A[j] = A[j], A[i] 

		A[i + 1], A[ei] = A[ei], A[i + 1] 
		
	return i + 1
N=int(input()) 
A = list(map(int,input().split())) 
n = int(input())
if (hasArrayTwoCandidates(A, len(A), n)): 
	print("yes") 
else: 
	print("no") 