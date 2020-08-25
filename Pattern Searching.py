"""
Given a text and a pattern. Find whether the pattern exist in the text or not. If it is present print "found" without quotes
else print "not found" without quotes.

Input:
The first line of input contains an integer T denoting the number of test cases.
Each test case consist of a string in 'lowercase' only in a separate line.

Output:
Print "found" or "not found" in a separate line.


Constraints:
1 ≤ T ≤ 30
1 ≤ |s| ≤ 100

Input
1
geeksforgeeks
geeks

Output
found

input:
1
guvigeek
geekcoin

output:
not found

input:
2
ironman
iron
google
go

output:
found
found

input:
1
goodgod
god

output:
not found

input:
1
bxnxnj
bxbx

output:
not found

hint:
Slide the pattern over text one by one and check for a match. If a match is found, then slides by 1 again to check for subsequent matches.

"""

def search(pat, txt): 
    M = len(pat) 
    N = len(txt) 
  
    # A loop to slide pat[] one by one */ 
    for i in range(N - M + 1): 
        j = 0
          
        # For current index i, check  
        # for pattern match */ 
        while(j < M): 
            if (txt[i + j] != pat[j]): 
                break
            j += 1
  
        if (j == M):  
            print("found")
            break
        else:
            print("not found")
            break
# Driver Code 
if __name__ == '__main__':
    for i in range(int(input())):
        txt =input()
        pat =input()
        search(pat, txt) 
