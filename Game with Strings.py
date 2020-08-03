"""
Guvi is taking a cryptography class and finding anagrams to be very useful. We consider two strings to be anagrams of each other
if the first string's letters can be rearranged to form the second string. In other words, both strings must contain the same exact
letters in the same exact frequency For example, bacdc and dcbac are anagrams, but bacdc and dcbad are not.

Guvi decides on an encryption scheme involving two large strings where encryption is dependent on the minimum number of character
deletions required to make the two strings anagrams. Can you help her find this number?

Given two strings, a and b, that may or may not be of the same length, determine the minimum number of character deletions
required to make a and b anagrams. Any characters can be deleted from either of the strings.

timing:1sec
level:6

Input Description:
The first line contains a single string, a.
The second line contains a single string, b.

Output Description:
Print a single integer denoting the number of characters you must delete to make the two strings anagrams of each other.

Constraints
    1≤Length of a and b≤1000
The strings a and b consist of lowercase English alphabetic letters ascii[a-z].

Sample Input:
cde
abc

Sample Output:
4

EXPLANATION:
We delete the following characters from our two strings to turn them into anagrams of each other:
    Remove d and e from cde to get c.
    Remove a and b from abc to get c.
We must delete 4 characters to make both strings anagrams, so we print 4 on a new line.

Input:
aaa
bbb

Output:
6

Input:
Guvi
Geeks

Output:
7

Input:
good
bad

Output:
5

Input:
sdsdmcjhdu
kddjkah

Output:
9

code:
"""
from collections import Counter
def deletionsNum(a,b):
    a=Counter(a)
    b=Counter(b)
    total=0
    for char in a:
        if char in b:
            total+=abs(a[char]-b[char])
        else:
            total+=a[char]
    for char in b:
        if char not in a:
            total+=b[char]
    return total

import fileinput
input=fileinput.input()
print(deletionsNum(input[0].strip(),input[1].strip()))
