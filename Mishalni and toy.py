"""
Mishalni has many toys and she has a weird obsession of arranging all the toys in a line such that their heights are
in non-decreasing order. If the order is messed then she gets angry. You know the number of toys and their current arrangement,
can you tell if she is angry or not?

tags:sorting
timing:0.5sec
level:3

Input:
First line will contain n the number of toys Mishalni has.
Next line contains n integers, denoting the heights of the toys in line.

Output
If Mishalni is angry print "Angry" (without quotes) else print "Happy".

Constraints
    1 ≤ n ≤ 10^5
    1 ≤ Ai ≤ 10^6

Input 1:
5
1 3 5 5 10

Output 1:
Happy

Input 2:
5
1 5 12 7 10

Output 2:
Angry

 
Explanation
All the toys are arranged in non-decreasing order hence Monica is "Happy".

The toys are not arranged in non-decreasing order hence Monica is "Angry".

input:
7
4 5 6 11 5 11 12

Output:
Angry

input:
8
4 5 6 7 7 8 9 12

Output:
Happy

input:
3
1 8 7

Output:
Angry

Hint:
we just need to check if the heights of the toys are arranged in the non-decreasing order or not. That we can do by just checking a number its previous number in the array if it does not follow the desired order (Ai < Ai-1)then print “Angry” else print “Happy”.

"""
def check(l) :
    for i in range(len(l)-1) :
        if(l[i+1] < l[i]) : return False
    return True
n = int(input())
l = list(map(int, input().split()))
print("Happy" if check(l) else "Angry")
