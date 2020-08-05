"""
You are given a string containing N lower case letters. So you will be thinking what to do with that? Huh, well here’s
what you need to do, you need to count occurrences of each character and then print characters having higher frequency all the way
to the letter having lower frequency. For more simplicity as we are friends, print the characters alphabetically if they are having
same frequencies in the string.

timing:1sec
level:5

Input Description:
First and only line a string with lower case N letters.

Output description:
Output a single line of letters ranked according to their frequency in descending order !

Constraints

    2≤N≤1000

Sample Input:
aabaabba

Sample Output:
ab

EXPLANATION:
Here letter 'a' occurs 5 times and letter 'b' occurs 3 times so answer will be 'ab'

input:
adadqcascfs

Output:
acds
fq

input:
aaaaaaaa

Output:
a

input:
ababbajimkmc

Output:
abm
cijk

input:
12151635121

Output:
125
36

code:
"""
import sys
import heapq

input = sys.stdin.readline()
letters = {}
for letter in input:
    if letter in letters:
        letters[letter] += 1
    else:
        letters[letter] = 1

pq = []

for key in letters:
    heapq.heappush(pq, (-letters[key], key))
    
output = ''
while len(pq) > 0:
    count,letter = heapq.heappop(pq)
    output += letter
    
print(output)
