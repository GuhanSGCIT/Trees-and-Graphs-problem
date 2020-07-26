"""
Question:
  Ethan Hunt is U.S. government operative agent and his mentor Jim Phelps sent a secret message to the ethan,but he couldn't
able to encode the message code ,he need some help to encode message.He need your help.

Hints:
If the string is of odd length, in odd step add the characters from the back in the resultant string, else add from the front.
If the string is of even length, in odd step add characters from the front and add characters from back in even step.
The reverse of the resultant string thus obtained is the original string which was encrypted.

Input Discription:-
Input consists of single string without spaces.

Output Discription:-
Print the encoded string without spaces.

Testcases:

Input:
YourProjectisJim

Output:
isteoPuYorrjciJm

Input:
QuitTheMission
Output:
osieTiQuthMsin

Input:
JoinWithLutherStickell
Output:
lkiSetLtWiJonihuhrtcels

input:
EthanMatthewHuntisafictionalcharacterandtheprotagonistoftheMission:Impossiblefilmseries
output:
siemiebsom:osietosngtretnrtaacaotiainHetanhEtaMthwutsfcinlhrceadhpoaoitfhMsinIpsilflsre

Input:
NoMessage
output:
easMNoesg

Solution:
"""
def encrypted_string(strg): 
    EncryptedString = [strg[0]] 
    for t in range(1,len(strg)): 
        if (t%2 == 1): 
            EncryptedString.append(strg[t]) #At odd position, append the next character 
        else: 
            EncryptedString.insert(0,strg[t]) #At Even position, prepend the next character  
    #print the resultant string 
    return (''.join(EncryptedString))
if __name__== '__main__': 
      
    print (encrypted_string(input())) 
