"""You are given with four points c1(n,m),c2(n,m),c3(n,m) and c4(n,m). If this four points forms rectangle shape , print YES ,else NO .

Input size: -1000<n,m<1000

Explanation:
First line consists of number of testcases N, following first four lines are c1,c2,c3,c4 and follows..

HINT: Graph 

Sample test case 1:
Input:
1
1 1
1 2
4 1
4 2
Output:
YES

Sample test case 2:
Input:
2
1 1
1 2
4 1
4 2
1 1
2 2
3 3
4 4
Output:
YES
NO


Sample test case 3:
Input:
1
1 1
1 2
2 2
2 1
Output:
NO

CODE:
"""
import math
def rectangle(l):
    #Distance of the sides
    c2c1= math.sqrt(((l[1][0]-l[0][0])**2)+((l[1][1]-l[0][1])**2))
    c4c3= math.sqrt(((l[3][0]-l[2][0])**2)+((l[3][1]-l[2][1])**2))
    c2c4= math.sqrt(((l[1][0]-l[3][0])**2)+((l[1][1]-l[3][1])**2))
    c1c3= math.sqrt(((l[0][0]-l[2][0])**2)+((l[0][1]-l[2][1])**2))
    #distance of diag
    c4c1= math.sqrt(((l[3][0]-l[0][0])**2)+((l[3][1]-l[0][1])**2))
    
    lst=[c2c1,c4c3,c2c4,c1c3]
    diff=[]
    for i in lst:
        if i not in diff:
            diff.append(i)
    #print(diff)
    #print(c4c1)
    if len(diff)==2 and ((diff[0]**2)+(diff[1]**2))==(c4c1**2):
        print("YES")
    else:
        print("NO")
        
    
N=int(input())
while N>0:
    l=[]
    for i in range(4):
        l.append([int(v) for v in input().split()])
    rectangle(l)
    N-=1





