"""
You are given two strings A, B made up of upper case and lower case letters.You have to check if they are same.
Two strings are same if they satisfy both of the following conditions:
|A|=|B|
Ai=UpperCase(Bi) or Ai=LowerCase(Bi) for every 1≤i≤|A|

If any one of the above conditions is not satisfied then the strings are different. Non-matching indices are those indices which
violate the 2nd condition.

level:5
timing:2sec

Input:
First line will contain T, number of testcases. Then the testcases follow.
First line of each testcase contains string A.
Second line of each testcase contains string B.

Output:
For each testcase, if both strings are same then print same, otherwise print different followed by the first non-matching index,
on a separate line.

Constraints
    1≤T≤100
    1≤|A|,|B|≤10^5
A and B contain upper case and lower case letters only.

Sample Input:
3
Easy
eaSY
One
onePiece
Right
rigid

Sample Output:
same
different 4
different 4

EXPLANATION:
In first case both strings are same.
In second case the strings violate 1st condition so they are different. First 3 indices satisfy 2nd condition but A4 = ′\0′
whereas B4 = ′P′, therefore first non-matching index is 4.
In third case 1st condition is satisfied but 2nd condition is not satisfied. First non-matching index is 4 since A4= ′h′
whereas B4 = ′i′.

Input:
2
Ironman
RODman
superGIRL
supergirl

output:
different 1
same

Input:
3
Guvi
geEK
YOU
your
WIn
Won

output:
different 2
different 4
different 2

Input:
1
HEllo
welcome

output:
different 1

Input:
2
superman
supergirl
qwertyuiopasdfghjklzxcvbnm
qwertyuiopjbjhbjhbbzxcvbnm

output:
different 6
different 11

hint:
Convert both strings AAA and BBB to upper case or lower case and compare them directly.
If A ≠\neq​= BBB, add any end marker (non-alphabet) symbol at the end of smaller string if both stings have different length.
(This ensures that the index will not go out of range before getting different characters in both strings.) Now start with first
index and increment the index till the characters are same. Print the current index.


solution:
"""
for _ in range(int(input())):
	s,t=input().lower(),input().lower()
	if s==t: print('same')
	else:
		if len(s)<len(t): s+='$'
		elif len(s)>len(t): t+='$'
		i=0
		while s[i]==t[i]: i+=1
		print('different',i+1)
