"""
Question:
Ram is class leader,conducting a game,in that game all the students are participating.He need to note the names of the
students to remark the scores,he has no time to cut short names to denote the players.Please help him to cut-short names,
by simply mentioning the initials of a name.

Tags:
String

Input Discription:
Line of string contains the name.

Output Discription:
Print the initials of a name in spaced capital letters.

Testcase 1:
input:
ram
output:
R

Testcase 2:
input:
raveen kumar
output:
N K

Testcase 3:
input:
abhishek kumar singh
output:
A K S

Hint:
Print first character in capital,traverse rest of the string and print every character after space in capital letter.

solution:
"""
def printInitials(name):  
    if(len(name) == 0): 
        return
    print(name[0].upper(),end=" ") 
    for i in range(1, len(name) - 1): 
        if (name[i] == ' '): 
            print (name[i + 1].upper(),end=" ") 
  
def main(): 
    name = input()
    printInitials(name) 
  
if __name__=="__main__": 
    main()  
