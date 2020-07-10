"""
Question:
  Ethan Hunt is U.S. government operative agent and his mentor Jim Phelps sent a secret message to the ethan,but he couldn't
understand the message code as it was encrypted ,he need some help to decrypt message.He need your help.

Hints:
1.Start with the first character of the original string.
2.In every odd step, append the next character to it.
3.In every even step, prepend the next character to the encrypted string so far.

Input Discription:-
Input consists of single encrypted string without spaces.

Output Discription:-
Print the decryted string without spaces.

Testcases:

Input:
isteoPuYorrjciJm
Output:
YourProjectisJim

Input:
osieTiQuthMsin
Output:
QuitTheMission

Input:
lkiSetLtWiJonihuhrtcels
Output:
JoinWithLutherStickell

s
Solution:
"""
def decrypted_string(strg): 
    #CHeck the divisibility of length of string by 2 
    if (len(strg)%2!=0): 
        DecryptedString = [strg[0]] 
        for t in range(1,len(strg)): 
            DecryptedString.append(strg[-1*t]) #First add the characters from the back 
            DecryptedString.append(strg[t]) #from the front 
        DecryptedString = DecryptedString[:len(strg)][::-1] #Reverse the final string to get output 
        return (''.join(DecryptedString)) 
    else: 
        reverse_strg = strg[::-1] #In case of even length, reverse the given string first  
        DecryptedString=[reverse_strg[0]] 
  
        #Looping over the reversed string 
        for t in range(1,len(reverse_strg)): 
            DecryptedString.append(reverse_strg[-1*t]) #First add the characters from the back 
            DecryptedString.append(reverse_strg[t]) #and then from the front 
        DecryptedString = DecryptedString[:len(reverse_strg)][::-1] 
        return (''.join(DecryptedString)) 
      
      
#Testing the algorithm with Driver Code 
if __name__== '__main__': 
      
  
    print(decrypted_string(input())) 
   
