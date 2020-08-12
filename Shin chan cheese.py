"""
Shin chan is a health-conscious mouse who loves eating cheese. He likes cheese so much that he will eat all the available cheeses.
Currently, he has N cheese with distinct calorie value a1,a2,...,an. Shin chan wants his total calorie intake to be K. To achieve his
calorie diet, he can steal at most 1 cheese such that:
    its calorie value should lie between the minimum and maximum calorie value of cheese he already has
    its calorie value should not coincide with any available cheese calorie value
Help Shin chan decide if he can achieve a total calorie diet of K.

timing:1sec
level:4

Input:
First line of input contains 2 space-separated integers, N and K
Second line contains N space-separated integer, a1,a2,...,an

Output:
Print YES,if Shin chan can have a total calorie diet of K with at most 1 stolen cheese, otherwise print NO

Constraints
1≤N≤100
1≤k≤10^5
1≤ai≤1000(i=1,2,...,N)
Every ai is distinct

Input:
3 10
1 2 4

Output:
YES

Input:
3 10
2 3 4

Output:
NO

input:
6 3
5 6 10 11 20 21

output:
NO

input:
7 4
1 5 9 8 4 3 2

output:
NO

input:
4 10
1 2 3 5

output:
NO

hint:
First, sum all the N elements and let it be S, if S > K then it is not possible to achieve as we can add only positive integers.
if S == K then answer is YES.
if S < K then answer is YES if and only if,K-S < maximum of N elements;K-S > minimum of N elements;K-S is not equal to any value from given N integer.;

"""
n,k=map(int,input().split())
a=list(map(int,input().split()))
if(sum(a)==k):
    print("YES")
elif(sum(a)>k):
    print("NO")
else:
    d=k-sum(a)
    if(d>min(a) and d<max(a) and (d not in a)):
        print("YES")
    else:
        print("NO")
