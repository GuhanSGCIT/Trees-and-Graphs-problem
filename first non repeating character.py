"""
Given a string S consisting of lowercase Latin Letters. Find the first non repeating character in S.

Input:
The first line contains T denoting the number of testcases. Then follows description of testcases.
Each case begins with a single integer N denoting the length of string. The next line contains the string S.

Output:
For each testcase, print the first non repeating character present in string. Print -1 if there is no non repeating character.

Constraints:
1 <= T <= 900
1 <= N <= 104

Example:

Input :
3
5  
hello
12
zxvczbtxyzvy
6
xxyyzz

Output :
h
c
z

input:
3
5
vmvmd
7
ggdgbbd
8
tututunk

output:
d
d
n

input:
1
11
ughguhguhgh

output:
h

input:
2
9
helloGuvi
8
GuviGeek

output:
h
-1

input:
1
18
Wearetheprogrammer

output:
W

hint:
First take the count of each character and store it in an array. Also store the index where that particular character occurs. 
After that, check for each character from 'a' to 'z' if the frequency of that character is 1 then check if the position of current
character is less than the position of previously stored character then replace that with current character.
"""
NO_OF_CHARS = 256
def getCharCountArray(string): 
    count = [0] * NO_OF_CHARS 
    for i in string: 
        count[ord(i)]+= 1
    return count 
def firstNonRepeating(string): 
    count = getCharCountArray(string) 
    index = -1
    k = 0
  
    for i in string: 
        if count[ord(i)] == 1: 
            index = k 
            break
        k += 1
  
    return index 
for i in range(int(input())):
    n=int(input())
    string = input()
    index = firstNonRepeating(string) 
    if index == 1: 
        print(-1)
    else: 
        print(string[index]) 