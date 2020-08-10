"""
Varun Purchased an array A having N Integer values,After Playing it for while,he got bored of it and decided to update value
of its element.In one second he can increase value of each array element by 1.He wants each array element’s value to become
greater than or equal to K,

Please Help Varun to find out the minimum amount of time it will take,for him to do so.

timing:1sec
level:3

Input:
First line consists of two space separated integers denoting N and K.
Second line of N space separated integers denoting the array A.

output:
Print the minimum time in which all array elements will become greater than or equal to K

Constraints
1<=T<=5
1<=N<=10^5
1<=A[i],k<=10^6

Input:
3 4
1 2 5 

output:
3

Input:
5 6
1 2 3 4 5

output:
5

Input:
7 6
4 5 2 7 6 4 1

output:
5

Input:
2 1
1 2

output:
0

Input:
7 8
4 6 11 2 12 7 15

output:
6

hint:
Since we can only increase all the elements by 1, the minimum element will take most step to reach K.
So we have to find the minimum element in array A and answer will difference between K and minimum element.

"""
N=[int(nsk) for nsk in input().split()]
A=list()
A=[int(x) for x in input().split()]
m=1000000
for j in range(N[0]):
    if A[j]<m:
        m=A[j]
print(N[1]-m)
