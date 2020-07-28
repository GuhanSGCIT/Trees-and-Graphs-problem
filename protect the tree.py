"""
 Ramarajan has been very busy with his pongal preparations and he doesn't have time to look after ramu and samu.
To keep them busy, Ramarajan has given them an array A of size N. He has asked them to plant trees at the points with Cartesian
coordinates (A[ i ], A[ j ]), such that i < j.

There are a lot of cows nearby. To save the trees from the cows, they decide to build a fence around the trees.
Moreover, they want to use the minimum length of fencing for this task. Find the value equal to twice the area covered by
the fence using the minimum length of fencing.

Timing:1.7sec
level:6

Input Description:
The first line contains T, the number of test cases to follow.
The first line of each test case contains an integer N, the size of the array.
The second line of the test case contains N space-separated integers.

Output Description:
For each test case, output the value equal to two times the area, rounded to the nearest integer, surrounded by the fence
when using the minimum length of net to surround all the trees.

Constraints:
    1 ≤ T ≤ 40000
    2 ≤ N ≤ 105
    1 ≤ Value of the array elements ≤ 108
    1 ≤ Sum of N over all cases ≤ 2*105

Input:
2
3
2 4 1
4
2 4 1 3

Output:
6
13

Explanation:
Example case 1.
Covered portion is a right angled triangle with vertices (2,4), (2,1) and (4,1).
Area = (1/2)*2*3 = 3.
Example case 2.
A, B, C, D, E, and F denote the trees.
The above image denotes the situation.
Area of the figure = 6.5
2*(Area of Triangle ABC + Area of Triangle BFE + Area of Square EFCD) is the answer.
Area of Triangle ABC = 1.5
Area of Triangle BFE = 1
Area of Square EFCD = 2*2 = 4

Input:
3
3
1 1 1
5
1 5 9 6 3
9
1 2 3 4 5 6 7 8 9

Output:
0
84
49

Input:
1
12
21 54 87 54 21 32 54 98 48 25 21 11

Output:
12848

Input:
2
2
1 2
3
3 2 1

Output:
0
1

Input:
1
5
1 0 1 0 1

Output:
2

Solution:
"""
from sys import stdin, stdout


class Point:
    __slots__ = 'x', 'y'

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return '(' + str(self.x) + ', ' + str(self.y) + ')'

    def __str__(self):
        return self.__repr__()

    def __lt__(self, other):
        if self.x < other.x:
            return True
        elif self.x == other.x and self.y < other.y:
            return True

        return False


def vec(a, b):
    return Point(b.x - a.x, b.y - a.y)


def cross(u, v):
    return u.x*v.y - u.y*v.x


def orient(o, a, b):
    return cross(vec(o, a), vec(o, b))


def sign(x):
    return -1 if x < 0 else (1 if x > 0 else 0)


def getConvexHull(points):
    lower = []
    for p in points:
        while len(lower) >= 2 and sign(orient(lower[-2], lower[-1], p)) <= 0:
            lower.pop()
        lower.append(p)

    upper = []
    for p in reversed(points):
        while len(upper) >= 2 and sign(orient(upper[-2], upper[-1], p)) <= 0:
            upper.pop()
        upper.append(p)

    return lower[:-1] + upper[:-1]


def doublePolygonArea(polygon_vertices):
    area = 0
    last_vertex = polygon_vertices[-1]
    for vertex in polygon_vertices:
        area += (last_vertex.x + vertex.x)*(vertex.y - last_vertex.y)
        last_vertex = vertex

    return area


no_of_test_cases = int(stdin.readline())
for _ in range(no_of_test_cases):
    n = int(stdin.readline())
    A = [int(x) for x in stdin.readline().split()]
    min_y = A[n - 1]
    max_y = A[n - 1]
    trees = []
    #trees = [Point(A[n - 2], min_y), Point(A[n - 2], min_y)]
    for i in range(n - 1, 0, -1):
        a = A[i]
        if a < min_y:
            min_y = a
        elif a > max_y:
            max_y = a
        trees.append(Point(A[i - 1], min_y))
        trees.append(Point(A[i - 1], max_y))
    trees = sorted(trees)
    fence = getConvexHull(trees)
    double_area = doublePolygonArea(fence)
    stdout.write(str(double_area) + '\n')
