"""
Kuldeep has a string S of length N, consisting of only characters a and b for banana and P points to spend.

Now Kuldeep wants to replace and/or re-arrange characters of this given string to get the lexicographically smallest string possible.
For this, he can perform the following two operations any number of times.

1) Swap any two characters in the string. This operation costs 1 point. (any two, need not be adjacent)

2) Replace a character in the string with any other lower case english letter. This operation costs 2 points.

Help kuldeep in obtaining the lexicographically smallest string possible, by using at most P points.


Input Description:-
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains two lines of input, first-line containing two integers N, P.
The second line contains a string Sconsisting of N characters.

Ouput Description:-
For each testcase, output in a single containing the lexicographically smallest string obtained.

Testcases:
Input:
1
3 3
bba
Output:
aab

Explanation:

We swap S[0] and S[2], to get abb. With the 2 remaining points, we replace S[1] to obtain
aab which is the lexicographically smallest string possible for this case.

Input:
2
3 3
aaa
3 2
bba
Output:
aaa
aba

Input:
1
6 2
banana
Output:
aaaabb

Input:
3
4 2
bbbb
2 1
aa
5 4
ababa
Output:
abbb
aa
aaaaa

Solution:-

"""
for _ in range(int(input())):
    n, p = map(int,input().split());s = list(input());a=s.count('a'); b=s.count('b'); swap = 0;arr = [i for i in s]
    for i in range(a):
        if s[i] == 'b':swap += 1
    if p <= swap:
        i=0; tmp=p
        while p>0 and i<n:
            if arr[i]=='b':arr[i]='a';p -= 1
            i += 1
        p = tmp; i = n-1
        while p>0 and i>0:
            if arr[i] == 'a':arr[i] = 'b';p -= 1
            i -= 1
        print(''.join(arr))
    else:
        for j in range(n):
            if j < a:arr[j] = 'a'
            else:arr[j] = 'b'
        p -= swap
        for k in range(n):
            if arr[k] == 'b':
                if s[k] == 'b' and p >= 2:p -= 2;arr[k] = 'a'
                if s[k] == 'a' and p >= 1:p -= 1;arr[k] = 'a'
        print(''.join(arr))
