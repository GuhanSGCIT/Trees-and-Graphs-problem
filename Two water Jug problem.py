"""
You are at the side of a river. You are given a m litre jug and a n litre jug where 0 < m < n. Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water where d < n. Determine the minimum no of operations to be performed to obtain d litres of water in one of jug.
The operations you can perform are:
    Empty a Jug
    Fill a Jug
    Pour water from one jug to the other until one of the jugs is either empty or full.

Input:
First line consists of T test cases. Only line of every test case consists of 3 spaced integers denoting m , n, and d respectively. 

Output:
Single line output, print the minimum number of operations.

Constraints:
1<=T<=100
1<=N,D<=100
1<=M<=N

Example:
Input:
2
8 56 46
3 5 4
Output:
-1
6


input:
3
1 5 4
3 2 1

output:
2
2

input:
1
3 5 4

output:
6

Explanation:
(0,0)->(3,0)->(0,3)->(3,3)->(1,5)->(1,0)->(0,1)->(3,1)->(0,4)
Hence the no of operations you need to perform are 8.

input:
2
5 2 1
10 4 3

output:
4
-1

input:
1
10 2 1

output:
-1

hint:
Fill the m litre jug and empty it into n liter jug.Whenever the m liter jug becomes empty fill it.Whenever the n liter jug becomes full empty it.
Repeat steps 1,2,3 till either n liter jug or the m liter jug contains d litres of water.


"""
def gcd(a, b): 
    if b==0: 
        return a 
    return gcd(b, a%b) 
def Pour(toJugCap, fromJugCap, d): 
    fromJug = fromJugCap 
    toJug  = 0
    step = 1
    while ((fromJug  is not d) and (toJug is not d)): 
        # poured 
        temp = min(fromJug, toJugCap-toJug) 
        toJug = toJug + temp 
        fromJug = fromJug - temp 
  
        step =  step + 1
        if ((fromJug == d) or (toJug == d)): 
            break
        if fromJug == 0: 
            fromJug = fromJugCap 
            step =  step + 1
        if toJug == toJugCap: 
            toJug = 0
            step =  step + 1
              
    return step 
  
def minSteps(n, m, d): 
    if m> n: 
        temp = m 
        m = n 
        n = temp 
          
    if (d%(gcd(n,m)) is not 0): 
        return -1
      
    return(min(Pour(n,m,d), Pour(m,n,d))) 
  
# Driver code 
if __name__ == '__main__':
    for i in range(int(input())):
        n,m,d=map(int,input().split())      
        print(minSteps(n, m, d)) 
