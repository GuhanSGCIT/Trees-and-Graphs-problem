"""
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock so that in between those days your profit is maximum.

Input: 
First line contains number of test cases T. First line of each test case contains an integer value N denoting the number of days, followed by an array of stock prices of N days. 

Output:
For each testcase, output all the days with profit in a single line. And if there is no profit then print "No Profit".

Constraints:
1 <= T <= 100
2 <= N <= 103
0 <= Ai <= 104

Example
Input:
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67

Output:
(0 3) (4 6)
No Profit
(1 4) (5 9)

Explanation:
We can buy stock on day 0, and sell it on 3rd day, which will give us maximum profit.

input:
1
8
654 565 651 535 335 355 352 456

output:
( 1 2 ) ( 4 5 ) ( 6 7 )

input:
2
4
123 452 451 245
6
159 458 789 542 632 254

output:
( 0 1 ) No Profit 
( 0 2 ) ( 3 4 )

input:
3
4
2 5 6 4
3
12 21 24
5
1 2 3 4 5

output:
( 0 2 ) 
( 0 2 ) 
( 0 4 )

input:
1
12
4 5 2 58 2 5 25 23 12 10 45 22

output:
( 0 1 ) ( 2 3 ) ( 4 6 ) ( 9 10 )

hint:
Find the local minima and store it as starting index. If not exists, return.Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
Update the solution (Increment count of buy sell pairs),Repeat the above steps if end is not reached.

"""
def stockBuySell(price, n): 
    if (n == 1): 
        return
    i = 0
    while (i < (n - 1)): 
        while ((i < (n - 1)) and 
                (price[i + 1] <= price[i])): 
            i += 1
          
        if (i == n - 1):
            print("No Profit",end=" ")
            break
          
        buy = i 
        i += 1
          
        while ((i < n) and (price[i] >= price[i - 1])): 
            i += 1
              
        sell = i - 1
          
        print("(",buy,sell,")",end=" ")
    print()
          
for i in range(int(input())):
    n=int(input())
    price = [int(v) for v in input().split()];
    stockBuySell(price, n) 

    
