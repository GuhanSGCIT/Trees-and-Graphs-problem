"""
Akash found some electrical motors of X rpm speed. He made a car from this motor with wheels of radius r cm.
The motor is connected to a battery which lasts for t mins. Akshay wants to know how far did the car travel before
the battery exhausted.
Note:- Output the floor value

timing:1sec
level:2

Input:
First-line will contain T, the number of test cases. Then the test case follows.
Each test case contains X,r,t(speed of the motor,radius of the wheel and time respectively)

Output:
For each test case, print the floor value distance(in cm) covered by the car

Constraints
1≤T≤1000
1≤X,r,t≤10^4
1≤r,t≤100
π=3.141

Sample Input:
2
300 4 2
150 5 3

Sample Output:
15076
14134


input:
3
1000 18 3
7500 16 4
6500 16 7

Output:
339227
3015360
4573296

input:
1
8000 18 3

Output:
2713823

input:
4
400 5 5
100 2 1
10 1 100
1000 2 100

Output:
62820
1256
6282
1256400

input:
1
102 6 1230

Output:
4728838

hint:
With the help of the motor speed and the time, one can find the total number of rotation the wheel of the car rotated.
rotation=X*t
In one full rotation, the car can move a distance equal to the circumference of the wheel which is 2πr2\pi r2πr .
distance=rotation*(2*pi*r)

"""
for i in range(int(input())):
    x,r,t=map(int,input().split())
    pi=3.141
    print(int(2*pi*r*t*x))
