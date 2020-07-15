"""
Question :-
A name can have at most three parts: first name, middle name and last name. It will have at least one part.
The last name is always present. The rules of formatting a name are very simple:
   1.) Only the first letter of each part of the name should be capital.
   2.) All the parts of the name except the last part should be represented by only two characters.
The first character should be the first letter of the part and should be capitalized. The second character should be ".".

Let us look at some examples of formatting according to these rules:

    chiDambaram-> Chidambaram
    olaganaThan chiDamBaram-> O.Chidambaram
    VallinaYagan olaganaThan chiDamBaram -> V.O.Chidambaram

Input Description:-
The first line of the input contains an integer T denoting the number of test cases.
The only line of each test case contains the space separated parts of the name.

Output Description:-
For each case, output the properly formatted name.

Testcases:
Input:
1
VallinaYagan olaganaThan chiDamBaram
Output
V.O.Chidambaram

Input:
3
gandhi
mahatma gandhI
Mohndas KaramChand gandhi

Output:
Gandhi 
M.Gandhi 
M.K.Gandhi

Input:
2
erode VenKatappa ramasamy
KUMAR
Output:
E.V.Ramasamy
Kumar

Solution:-

"""
for _ in range(int(input())):
    name=list(input().split(' '))
    newname=[]
    for i in range(len(name)-1):
        newname.append(name[i][0].upper()+'.')
    newname.append(name[-1][0].upper()+name[-1][1:].lower())
    newn=''
    print(newn.join(newname))
