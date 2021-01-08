
"""
Given coordinates of two pivot points (x0, y0) & (x1, y1) in coordinates plane.
Along with each pivot, two different magnets are tied with the help of a string
of length r1 and r2 respectively. Find the distance between both magnets when they
repelling each other and when they are attracting each other.

Input description
First line has point x0,y0
second line has point x1,y1
Third line has length of string r1,r2 

Output description
Distance while repulsion
Distance while attraction

Explanation
We have two pivots points on coordinates, so distance between these points are D = ((x1-x2)2 +(y1-y2)2 )1/2.
Also, we can conclude that distance between magnet is maximum while repulsion and that too should be the distance between pivots + sum of the length of both strings.
In case of attraction we have two cases to take care of:
Either the minimum distance is the distance between pivots – the sum of the length of both strings
Or minimum distance should be zero in case if the sum of the length of strings is greater than the distance between pivot points.

Input
0 0
5 0
2 2

Output
9
1.0

Input
1 2
2 3
4 5


Output
10
0

input:
1 2
2 3
3 4

output:
8
0

input:
55 66
44 47
5 9

output:
35
7.9544984001001495

input:
2 515
35 556
332 551

output:
935
0

input:
1 1
2 2
3 3

output:
7
0

Hint
As we all know about the properties of magnet that they repel each other when they are facing each other with
the same pole and attract each other when they are facing each other with opposite pole.
Also, the force of attraction, as well as repulsion, always work in a straight line.
"""
import math 
def pivotDis(x0, y0, x1, y1): 

	return math.sqrt((x1 - x0) * (x1 - x0) 
				+ (y1 - y0) * (y1 - y0)) 
def minDis( D, r1, r2): 

	return max((D - r1 - r2), 0) 
def maxDis( D, r1, r2): 

	return D + r1 + r2 
x0,y0 = map(int,input().split())
x1,y1 = map(int,input().split())
r1,r2 = map(int,input().split())
D = pivotDis(x0, y0, x1, y1) 
print(int(maxDis(D, r1, r2))) 
				
print(minDis(D, r1, r2)) 