"""
The college has to give some gifts to the students on the occasion of the tech fest. But as college does not want to spend
much money on it, it is intended to give gifts to as few students as possible. But it has to give gift to at least one student,
it cannot give gift to none. But students has strong love for their friends and for a pair of students A and B, a student
A will only accept gift if college also gives gift to student B but not vice versa. Each gift costs K rupees. There are N
students in the college and there are M pair of friends in them. Find the minimum amount of money, college needs to spend
to distribute the gifts.

timing:1sec
level:7
tag:dfs,graph

Input
The first line of input consists of three integers N, M, K as stated in the problem statement.
In the next M lines, each line contains two distinct elements A and B as stated in the problem.

Output
Print a single integer which is answer to the corresponding input.

Constraints
2<=N<=1000
1<=M<=100000
1<=A, B<=N

Input:
3 3 100
1 2
2 3
3 1
Output:
300

Input
4 2 50
1 2
2 3
Output
50
 
Explanation
In example 1, Student 1 will only accept gift if college gives gift to student 2 and for this it has to give gift to student 3
and student 3 will only accept gift if college gives gift to student 1. So college has to give gifts to all three students and
cost of one gift is 100 rupees. So total cost is 300 rupees.

input:
4 3 75
1 5
5 3
3 4

output:
75

input:
5 5 125
1 3
1 2
3 4
2 5
5 6

output:
125

input:
2 2 25
1 2
2 1

output:
50

input:
2 1 5
1 2

output:
5

hint:
Let us define a Directed Graph whose vertices are students. A directed edge connecting Student A to Student B would mean that
Student B is a friend of Student A i.e. Student A will accept a gift only if Student B is given a gift too.

Therefore, by induction, a connected component on this graph will mean that either all of the connected students (vertices)
would get a gift or none would. Since the college wants to give the minimum possible number of gifts (but not zero), we have
to find the component with the minimum number of vertices. Our answer will be K times the size of this minimum component.

"""
from collections import defaultdict

def dfs(node,hash,bool):


    bool[node] = True

    for i in hash[node]:
        if bool[i] == False:

            dfs(i,hash,bool)


    stack.append(node)

def dfs2(node,hash,bool,conn):


    bool[node] = True
    conn.add(node)
    for i in hash[node]:
        if bool[i] == False:

            dfs2(i,hash,bool,conn)









hash1= defaultdict(list)
hash2= defaultdict(list)

n,m,k = map(int,input().split())

for i in range(m):
    a,b = map(int,input().split())
    hash1[a].append(b)
    hash2[b].append(a)



flag = 0
for i in range(1,n+1):

    if i not in hash1 or hash1[i] == []:

        print(k)
        flag = 1
        break

bool1 = [False]*(n+1)
bool2 = [False]*(n+1)

ans = []
stack = []
mini = 10**18
if flag!=1:
 for i in range(1,n+1):
    conn = set()

    dfs2(i,hash1,bool1,conn)
    mini = min(mini,len(conn)*k)
    bool1 = [False]*(n+1)


 print(mini)





