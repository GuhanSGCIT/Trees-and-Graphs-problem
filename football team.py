"""
Question:=
Igor Štimac is the FootBall coach of the TN Football Team.

There are N players (enumerated 1 through N) placed in a line. The i-th player has an experience of i years.

Štimac is training The players in the following tactic:
1.)Initially the leftmost player has the ball.
2.)The player that has the ball passes the ball to the nearest player to the right that is more experience than him.
3.)The previous step continues until the ball reaches the mostest experienced player, then he throws the ball and scores a goal!

Help Štimac reordering the players in such a way that the ball is passed from player to player exactly K times.

For example, if there are 5 players ordered as [3 4 5 1 2], then the ball goes 3→4→5→goal, and the ball was passed two times.

Input Description:
First line will contain T, number of testcases.
Each test case consist of a line with two space separated integers N,K.

Output Description:
For each testcase, output in a single line conaining N integers representing one possible ordering in which the player can be placed.

Testcases:
Input:
1
5 2
Output:
3 4 5 1 2 

Input:
2
6 3
5 1
Output:
3 4 5 6 1 2 
4 5 1 2 3

Input:
3
3 1
6 4
1 1
Output:
2 3 1 
2 3 4 5 6 1 
0 1

Input:
1
11 2
Output:
9 10 11 1 2 3 4 5 6 7 8

Input:
1
2 10
Output:
-8 -7 -6 -5 -4 -3 -2 -1 0 1 2

Solution:-
"""
for i in range(int(input())):
    N, K = list(map(int, input().split()))
    sequence = []
    c = N - K
    for j in range(c, N+1):
        sequence.append(j)
    for j in range(1, c):
        sequence.append(j)
    for j in sequence:
        print(j, end=" ")
    print()
