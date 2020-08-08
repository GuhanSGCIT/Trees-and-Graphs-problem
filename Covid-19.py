"""
There are N number of patients standing in a queue to withdraw money from atm. There are fewer masks available in our area.
we cant provide a mask to everyone in the queue. if a person is not wearing a mask there is a possibility of transferring
corona-virus to the person in front of him and behind him. For eg-If the second person is wearing a mask then there is no
possibility of passing any disease from First to the Second person in the queue and so on. As we don't know who has Corona disease.
we have to find the minimum number of mask required for not spreading diseases from one person to another person standing
one behind others in the queue.

timing:1sec
level:2

Input:
First-line will contain T, number of test cases. Then the test cases follow.
Each test case contains a single line of input, one integer N.

Output:
For each test case, output in a single line answer given by printing the minimum number of mask required

Constraints
1≤T≤10
0≤N≤1000000

Sample Input:
1
1

Sample Output:
0

EXPLANATION:
There is no neighbour to the only person. Hence, no mask is required. Hence the answer is 0

input:
9
1
2
5
3
8
7
9
6
4

Ouput:
0
1
2
1
4
3
4
3
2

input:
4
125
150
40
45

Output:
62
75
20
22

input:
5
45
56
54
78
98

Output:
22
28
27
39
49

input:
2
15684
654

Output:
7842
327

Hint:
The number of minimum mask required for not spreading coronavirus is n/2.
If the alternate person will wear the mask then no corona will spread from one to another.
in case, of single or no person in a queue there is no need of mask as corona cant spread to anyone further.
"""
for __ in range(int(input())):
    n = int(input())
    print(n // 2)
