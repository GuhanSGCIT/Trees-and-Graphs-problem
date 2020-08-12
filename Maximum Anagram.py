"""
Beware! You might lose time on this. Try others and jump back here.
So the deal is, you need to find the lexicographically maximum anagram of the given string. Can you do this?

timing:1sec
level:3

Input
First line contains T, the number of test cases.
Next T lines contain a string S.

Output
Print the lexicographically maximum anagram of S.

Constraints
    1 <= T <= 100
    1 <= |S| <= 100000


Input:
2
cabnrc
bjprss

Output:
rnccba
ssrpjb

input:
3
vbhjghgvgv
jhhmbjhbhh
jhbjj

output:
vvvjhhgggb
mjjhhhhhbb
jjjhb

input:
2
guvi
geek

output:
vuig
kgee

input:
3
adobe
forty five
evil

output:
oedba
yvtroiffe 
vlie

input:
1
I am a weakish speller

output:
wssrpmllkiheeeaaaI

hint:
Two strings are anagrams if the frequency of each character is same in both strings. In question, lexicographically maximum substring is asked. It will be the reverse of the given string after sorting.
"""
t = int(input())
a = " "
for i in range(t) :
    n = str(input())
    a = "".join(sorted(n))
    a = a[::-1]
    print(a)
