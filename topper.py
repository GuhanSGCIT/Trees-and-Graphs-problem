"""
Given two arrays A1 has student reg numbers of toppers and A2 has student
reg numbers of players,the task is that we find students can be only topper who
are present in first array,but not present in the second array.

in des
First line contain space separated integers a1,a2,which denotes the size of two arrays.
Second line contain a1 space separated integers,which denotes topper's reg number.
Third line contain a2 space separated integers,which denotes player's reg number.

Out des
Print the students in single line

Ex
From sample
4 and 10 are present in first array, but
not in second array.

Hint
Print the element which not present in second array.

In
5 4
3 5 4 6 7
9 0 8 55 4

Ot
3 5 4 6 7

In
1 1
1
2

Ot
1

In
1 2
1
3 2

Ot
1

In
4 5
1 3 2 4
4 6 7 8 0

Ot
1 3 2

In
5 5
1 2 3 4 5
1 22 3 44 5

Ot
2 4 5
T 1000

"""

def findMissing(a, b, n, m): 

	for i in range(n): 
		for j in range(m): 
			if (a[i] == b[j]): 
				break

		if (j == m - 1): 
			print(a[i], end = " ") 


	
a1,a2= map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
n = len(a) 
m = len(b) 
findMissing(a, b, n, m) 
