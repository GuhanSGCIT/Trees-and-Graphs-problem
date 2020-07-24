"""
Question:

A person X wanted to publises his website. To do so, he decided to create a post on a social networking site and share it.
Every share costed RS 1 and X had only RS 1 remaining. When X shared the post on a friend F's profile, the post could be viewed
on the profiles of all F's friends ( except X himself ), friends of his friends, friends of friends of friends, and so on.
X wanted maximum number of people to view the post.With which friend should he share the post?

Input Description:
First line contains X the name of the person.
Second line contains an integer K which denotes the total number of lines which follow K lines follow, each of the K lines
contain the input in the format:
A B, which denotes that A and B are friends.
    Note that A and B are names (ie. strings).
    Name of each person will be unique.
    A person can have multiple friends.
    If A is a friend of B, then B is a friend of A.

Output Description:
First line should contain the name of the friend with whom X should share the post.
The second line should contain the number of people who will then see the post.
If there are multiple answers possible, print the lexicographically smallest one.

Testcases:
Input:
A
4
A B
A C
C D
C E

Output:
C
3

Explanation:
    A
   / \
  B   C
      /\
     D  E

If A shares the post with B, only B will view the post.
If A shares the post with C, the post will be viewed by C, D and E.
Hence, A should share the post with C.

Input:
x
6
x y
x c
y z
z a
z b
a b

output:
y
4

Input:
admin
12
admin m1
m1 m2
m1 m3
m1 m4
m3 m5
m3 m6
m4 m7
m6 m8
m6 m9
m6 m10
m8 m11
m8 m12
m12 you

output:
m1
12

Input:
a
3
a b
a c
a v

output:
b
1

Input:
i
5
i u
u he
u she
he her
her them

output:
u
5

Solution:-
"""
from collections import defaultdict

adj = defaultdict(list)
visited = defaultdict(bool)

ans = 0

def dfs(u):
    stack = []
    stack.append(u)
    count = 0

    while len(stack):
        s = stack.pop()

        if not visited[s]:
            count += 1
            visited[s] = True

        for i in adj[s]:
            if not visited[i]:
                stack.append(i)

    return count
        

    
s = input().strip()

n = int(input().strip())

for i in range(n):
    u,v = input().strip().split(" ")
    adj[u].append(v)
    adj[v].append(u)

adj[s].sort()

maxi = 0
ch = "A"

visited[s] = True

for i in adj[s]:
    if not visited[i]:
        ans = dfs(i)
        if ans > maxi:
            maxi = ans
            ch = i


print(ch)
print(maxi)
