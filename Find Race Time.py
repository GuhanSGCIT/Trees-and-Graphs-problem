"""
Varun decided to join car race. Varun wants to finish a round in minimum time possible. For a given car and track,
Braking Point:
    A point on the track from where the racer should apply the brake. From here, the car will decelerate at B m/s2
Acceleration Point:
    A point on the track from where the racer should accelerate. From here, the car will Accelerate at A m/s2
Steady Point:
    A point on the track from where the racer should release both Accelerator and brakes. From this point, the car will decelerate
at G m/s2 due to ground friction.

Note: Ground friction is already considered in braking and Acceleration, DO NOT add subtract G with Acceleration or braking.

Given the G and length L (in meters) and points (1 for braking point, 2 for Acceleration point, 3 for steady point) of a track and A and of the car, find the time required to finish one lap.


Input:
First line contains an integer T no. of test cases
For every test case, first line contains three floats, A , B , and G separated by space
For every test case, second line contains two integers L and Q separated by space
For every Q , a line consists an integer X-type of point and it's distance from starting point D separated by space

Output:
For every test case, print the time required by the car to finish. The result should not differ the actual result by 10^-2.
In case the car is unable to finish, print -1

Constraints
0≤A,B,G≤100.0

10 points:
    1≤T≤10
    1≤L≤5000
    0≤Q≤10

20 points:
    1≤T≤20
    1≤L≤10^4
    1≤Q≤100

70 points:
    1≤T≤50
    1≤L≤10^9
    0≤Q≤10^5

Sample Input:
1
10.0 3.5 0.25
5000 3
1 2000
3 3000
2 4000

Sample Output:
35.65123163210248

EXPLANATION:
Here Accelearation = 10 m/s2
Braking = 3.5m/s2
Ground Friction = 0.25m/s2
Length of track = 5000m
No. of points (braking/acceleartion/steady) = 3

The car will start at point 0 with velocity = 0 and acceleration 10.0m/s2. After some time, when it reaches 2000m, the brake
will be applied. Then the car will decelerate at 3.5m/s2. After going another 1000 m (i.e. 3000 m from start) brake will be released.
From then on, the car will decelerate at 0.25m/s2. After reaching 4000m, the car will accelerate at 10m/s2 until the end of the track
(5000m). The time required to travel the distance is 35.65123163210248

input:
1
10.2 11.2 12.3
1000 5
1 1500
3 3000
5 6000
7 7000
10 10000

output:
-1

input:
1
1.1 2.2 3.3
200 1
2 100

output:
19.06925178491185

input:
1
12.3 121.5 121.6
15000 2
1 10000
3 5000

output:
-1

input:
1
7.1 9.8 11.2
100 3
1 12
2 50
3 18

output:
-1

hint:
Two forumulas should come handy to solve the problem,
v^2 - u^2 = 2as
t=(v−u)/a
Then, the final velocity when reaching Y is, v=sqrt(u∗u+2∗a∗s)
However, what if the car stop while braking or when in steady before reaching the next acceleration point? It means It will never be able to finish the race. Therefore if in any segment
u∗u+2∗a∗s is less than 0, then -1 should be printed.
"""
import math
from math import sqrt



def get_v(u, a, s):
    v_sq = (2 * a * s) + (u ** 2)
    if v_sq < 0:
        return -1
    return math.sqrt(v_sq)


T = int(input())
for z in range(T):
    tym = 0
    last_vel = 0
    acc, breaking, ground = map(float, input().split())
    length, no_of_points = map(int, input().split())
    points = []
    # Add accelearation from starting point
    points.append((2, 0))
    for i in range(no_of_points):
        typ, dist = map(int, input().split())
        points.append((typ, dist))
    # Add end point to calculate time
    points.append((1, length))
    unable_to_finish = False
    for i in range(1, len(points)):
        typ = points[i - 1][0]
        dist = points[i][1] - points[i - 1][1]
        # print(typ, dist)
        a = 0
        if typ == 1:
            a = -breaking
        elif typ == 2:
            a = acc
        else:
            a = -ground

        v = get_v(last_vel, a, dist)
        if v<0:
            unable_to_finish = True
            break
        x = (v - last_vel) / a
        tym += x
        last_vel = v
    if unable_to_finish:
        print(-1)
    else:
        print(tym)
