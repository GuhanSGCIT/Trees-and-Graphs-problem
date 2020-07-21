"""
Question:-
    Farmer murugan has three fields banana tree planted in them. He harvested x hand of banana from the first field, y hand of banana
from the second field and is yet to harvest hand of banana from the third field. Murugan is very superstitious and believes that
if the sum of hands of banana he harvests from the three fields is a prime number,he'll make a huge profit.

    Please help him by calculating for him the minimum number of hands of banana that if harvested from the third field will
make the sum of hands of banana prime. At least one hand of banana should be harvested from the third field.

Input Description:
The first line of the input contains an integer T denoting the number of test cases.
Each of the next T lines contain 2 integers separated by single space: x and y.

Output Description:
For each test case, output a single line containing the answer.

Testcases:
Input:
2
1 3
4 3
Output:
1
4

Explanation:
In example case 1: the farmer harvested a hand of banana from the first field and 3 hands of banana from the second field.
The sum is 4. If he is able to harvest a hand of banana from the third field, that will make the sum 5, which is prime.
Hence the answer is 1(he needs one more potato to make the sum of harvested potatoes prime.)

Input:
5
1 2
5 4
2 3
8 5
9 8
Output:
2
2
2
4
2

Input:
1
0 1
Output:
1

Input:
2
29565 265165
3213565321 32562154
Output:
1
26

Input:
4
1 1
52 85
55 11
25 48
Output:
1
2
1
6

Solution:-
"""

import math

def is_prime(num):
     sq_root = int(math.sqrt(num))
     for i in range(2, sq_root+1):
             if num%i == 0:
                     return 0
     return 1
 
test_case = int(input())

for i in range(test_case):
     x,y = map(int,input().split())
     sum0 = x + y
     num = sum0
          
     while (1):
        num =num + 1
        if is_prime(num) == 1:
            break
     
     print(num - sum0) 

