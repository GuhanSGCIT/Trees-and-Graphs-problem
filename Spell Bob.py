"""
Varun likes to play with cards a lot. Today, he's playing a game with three cards. Each card has a letter written on the top face and
another (possibly identical) letter written on the bottom face. Varun can arbitrarily reorder the cards and/or flip any of the cards
in any way he wishes (in particular, he can leave the cards as they were). He wants to do it in such a way that the letters on the
top faces of the cards, read left to right, would spell out the name of his favorite friend Bob.

Determine whether it is possible for Varun to spell "bob" with these cards.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single string with length 3 denoting the characters written on the top faces of the first,second and third card.
The second line contains a single string with length 3 denoting the characters written on the bottom faces of the first,second and third card.

Output
For each test case, print a single line containing the string "yes" (without quotes) if Chef can spell "bob" or "no" (without quotes) if he cannot.

Constraints
1≤T≤20,000
each string contains only lowercase English letters

Example Input
3
bob
rob
dbc
ocb
boc
obc

Example Output
yes
yes
no

Explanation
Example case 1: The top faces of the cards already spell out "bob".
Example case 2: Chef can rearrange the cards in the following way to spell "bob": the second card non-flipped, the first card flipped and the third card flipped.
Example case 3: There is no way for Chef to spell out "bob".

input:
5
kok
obo
kol
bbo
mom
bob
lok
non
bbo
boo

output:
no
yes
yes
no
yes

input:
1
boo
oob

output:
yes

input:
2
ooo
bbb
bob
bob

output:
yes
yes

input:
5
bbb
oob
ooo
bob
obo
obc
abs
abb
boa
ala

output:
yes
yes
no
no
no

hint:
First, fix the letter ooo for the middle card. Now, try the remaining cards and check if both of them contain a “b” on either side of them.

"""
T = int(input())
for _ in range(T):
    s = input()
    t = input()
    ok = False
    for i in range(3):
        if s[i] == 'o' or t[i] == 'o':
            cnt = 0
            for j in range(3):
                if j != i:
                    if s[j] == 'b' or t[j] == 'b':
                        cnt += 1
            if cnt == 2:
                ok = True
    print("yes" if ok else "no");
