"""
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

    An egg that survives a fall can be used again.
    A broken egg must be discarded.
    The effect of a fall is the same for all eggs.
    If the egg doesn't break at a certain floor, it will not break at any floor below.
    If the eggs breaks at a certain floor, it will break at any floor above.

timing:1.5sec
level:6

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3

input:
3
1 5
2 16
2 8

output
5
6
4

input:
2
1 6
3 15

output
6
5

input:
1
2 8
output
4

input:
4
1 5
2 7
2 9
1 9

output
5
4
4
9

hint:
calculate the minimum number of droppings needed in the worst case. The floor which gives the minimum value in the worst case is going to be part of the solution.
In the following solutions, we return the minimum number of trials in the worst case; these solutions can be easily modified to print floor numbers of every trial also.

"""
import sys  
def eggDrop(n, k): 
    if (k == 1 or k == 0): 
        return k 
    if (n == 1): 
        return k 
  
    min = sys.maxsize 
    for x in range(1, k + 1): 
  
        res = max(eggDrop(n - 1, x - 1),  
                  eggDrop(n, k - x)) 
        if (res < min): 
            min = res 
  
    return min + 1
if __name__ == "__main__": 
  
    for i in range(int(input())):
        n,k=map(int,input().split())
        print(eggDrop(n, k)) 
