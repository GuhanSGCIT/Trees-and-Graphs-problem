"""
Varun want to book Ola Cab,he have to take ride from point one (xi,yi) to second point (xj,yj),Ola cost N rupees per unit,
Varun have R rupees in his pocket, You have to help Chef to find Whether he have suffiecient amount of money in his pocket
for paying to ola,

if yes print "yes"(without quotes) else print "no"(without quotes)

timing:1sec
level:3

Input
The first line contains two integer points xi and yi, i.e.coordinates.
The next line contains two integers xj and yj coordinates
The next line contain integer n i.e.charges per km)
and next line contain Integer r i.e.amount of money chef have.

Output
Print yes if Varun have sufficient money in his pocket else print no.

Constraints
1<=xi,yi,xj,yj<=10000,
1<=R<=100000,
1<=N<=100

Input:
4 6
1 3
20
80
Output:
no

Explanation
it cost 84.85 rs to chef,but chef have 80 rs,so answer is no


input:
8 1
2 4
5
125

output:
yes

input:
1 8
4 5
30
40

output:
no

input:
1 2
2 4
20
15

output:
no

input:
8 2
6 1
55
40
output:
no

hint:
From the Question,its clear we have to find distance between two points
"""
x1, y1 = [int(x1) for x1 in input().split()] 
x2, y2 = [int(x2) for x2 in input().split()] 
cn=int(input())
an=int(input())

d=( (   (x2-x1)**2  ) +( (y2-y1)**2     )      )**(0.5)
rr=cn*d
#print(rr)
if(int(rr)<=an):
    print("yes")
else:
    print("no")
