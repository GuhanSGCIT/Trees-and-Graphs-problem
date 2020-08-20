"""
Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y co-ordinates
of two points: the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered
overlapping.

Note : It may be assumed that the rectangles are parallel to the coordinate axis.

timing:
level:

Input:
The first integer T denotes the number of testcases. For every test case, there are 2 lines of input.
The first line consists of 4 integers: denoting the co-ordinates of the 2 points of the first rectangle.
The first integer denotes the x co-ordinate and the second integer denotes the y co-ordinate of the left topmost corner of the first rectangle.
The next two integers are the x and y co-ordinates of right bottom corner. Similarly, the second line denotes the cordinates of the two points of the second rectangle in similar fashion.

Output:
For each testcase, output (either 1 or 0) denoting whether the 2 rectangles are overlapping.
1 denotes the rectangles overlap whereas 0 denotes the rectangles do not overlap.

Constraints:
1 <= T <= 10
-10^4 <= x, y <= 10^4


Input:
2
0 10 10 0
5 5 15 0
0 2 1 1
-2 -3 0 2

Output:
1
0

Explanation:
Testcase 1: According to the coordinates given as input ,two rectangles formed overlap with each other and thus answer returns 1.

input:
1
0 100 100 0
50 50 150 0

output:
1

input:
2
1 2 2 1
6 12 12 6
0 1000 -1000 0
-1 -1000 1000 1

output:
0
0

input:
1
1 2 2 1
1 2 2 1

output:
1

input:
2
1000 100 100 1000
1 2 2 1
45 55 55 45
8 64 64 8

output:
0
1

hint:
One solution is to one by one pick all points of one rectangle and see if the point lies inside the other rectangle or not. This can be done using the algorithm discussed here.
Following is a simpler approach. Two rectangles do not overlap if one of the following conditions is true.
One rectangle is above top edge of other rectangle.
One rectangle is on left side of left edge of other rectangle.
"""
class point: 
    def __init__(self, x, y): 
        self.x = x 
        self.y = y 
  
# Returns true if two rectangles(l1, r1)  
# and (l2, r2) overlap 
def doOverlap(l1, r1, l2, r2): 
      
    # If one rectangle is on left side of other 
    if(l1.x >= r2.x or l2.x >= r1.x): 
        return False
  
    # If one rectangle is above other 
    if(l1.y <= r2.y or l2.y <= r1.y): 
        return False
  
    return True
  
# Driver Code 
if __name__ == "__main__":
    for i in  range(int(input())):
        l=[int(x) for x in input().split()]
        ll=[int(v) for v in input().split()]
        l1=point(l[0],l[1])
        r1=point(l[2],l[3])
        l2=point(ll[0],ll[1])
        r2=point(ll[2],ll[3])   
        if(doOverlap(l1, r1, l2, r2)): 
            print(1) 
        else: 
            print(0) 
