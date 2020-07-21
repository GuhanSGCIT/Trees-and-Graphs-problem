"""
Question:-
 A college student name ravi is sitting in a very boring lecture, waiting for it to end. He has recently asked his friend about the time,
and instead of the straightforward answer, his friend, told him the absolute value of angle between hour and minute hands.

 But that is obviously not what he wanted to know, so he asks you to help him, by writing down all valid values of time
(in hours and minutes, both non-negative integers) from midnight (inclusive) to noon (not inclusive) which satisfy the information
ravi's friend has provided. Keep in mind that a time value is considered valid if the angle between the clock's hands for
that value and the angle ravi's friend has described differ by less than 1/120 degrees.

Note:
    The movement of the minute hand influences the hour hand. That is, every minute, it moves by 1/60th of the angular
distance between two consecutive hour marks.

Input Description:
The first line of the input contains an integer T denoting the number of test cases.
The only line of each test case contain a single real number A in decimal notation,
denoting the angle between minute and hour hands. The fractional part won't contain more than 4 digits.

Output Description:
For each test case print all valid values of time as described in the statement in the format "hh:mm" (without quotes),
where hh means number of hours, and mm the number of minutes. Times should be printed in chronological order.

Testcases:
Input:
2
0
30

Output:
00:00
01:00
11:00

Input:
3
15
25
45

Output:
05:30
06:30
01:10
10:50
04:30
07:30

Input:
1
59
Output:

Input:
5
12
10
5
35
0
Output:
05:38
06:22

Input:
3
55
35
6
Output:
00:10
11:50
03:10
08:50
02:12
09:48

Solution:-
"""
t = int(input())

dct = {}

for i in range(0,12):
    for j in range(0,60):
        hrang = (i*60.0 + j)/2.0
        mnang = j*6.0
        diff = abs(mnang-hrang)*1.0
        diff = min(diff,360-diff)
        if int(diff) in dct:
            dct[int(diff)].append([i,j,diff,360.0-diff])
        else:
            dct[int(diff)] = [[i,j,diff,360.0-diff]]

for _ in range(t):
    ang = float(input())
    artmp = dct[int(ang)]
    for tmp in artmp:
        if abs(tmp[2]-ang)<=(1.0/120.0) or abs(tmp[3]-ang)<=(1.0/120.0):
            print("%02d:%02d"%(tmp[0],tmp[1]))
