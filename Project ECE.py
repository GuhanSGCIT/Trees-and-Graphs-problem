"""
Varun is working on an electronics project. In this project N wires w1, w2,w3 ... wn connect a machine to the power supply,
due to a fault in the wires, wire w1 stops supplying power momentarily after every t1 seconds, wire w2 stops supplying power
momentarily after every t2 seconds, and wire w3 stops supplying power momentarily after every t3 seconds and so on.

The machine keeps working as long as there is power in at least one wire. If the machine stops working, then Varun has to
turn it on manually. Varun also wants to read the books so he cannot monitor the machine all the time otherwise
he will get low marks in the exam. So Varun needs your help to know that After how many seconds does the machine stop working?

Note: all wires connected to power supply at t = 0 seconds. Note: Answer should be with modulo 1000000007.

timing:1.5sec
level:4

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N
The second line of each test case contains N space seperated integers t1,t2,t3...tn where ti denotes the time after which wire wi stops supplying power momentarily

Output
For each test case, output a single line containing the time in seconds after which machine stops working

Constraints
    1 ≤ T ≤ 10^2
    1 ≤ N ≤ 10^3
    1 ≤ ti ≤ 10^5
    Time is given in seconds


Input:
2
2
2 3
3
3 2 7
Output:
6
42

Explanation
At time = 2 seconds w1 stop working momentarily but wire w2 is still working, at time 3 seconds w2 stop working momentarily
but now w1 is working. After 4 seconds again w1 stop working momentarily but w2 is working so the machine is still working.
At time 6 seconds both wires stop working momentarily so machine stops working and now varun has to start the machine again.

input:
3
3
1 2 3
4
1 2 75 4
5
321 651 321 65 6

output:
6
300
9055410

input:
2
4
5 8 4 3
2
21 32

output:
120
672

input:
1
8
4 80 2 1 60 3 5 50

output:
1200

input:
2
1
2
3
102 542 125

output:
2
3455250

hint:
The L.C.M. of the values gives us the minimum time at which all the wires stop working simultaneously.

"""
import math
mod=10**9+7
t=int(input())
while t>0:
    n=int(input())
    l=list(map(int,input().split()))
    a=l[0]
    for i in range(1,n):
        a=((a*l[i])//(math.gcd(a,l[i])))%mod
    print(a)
    t-=1
