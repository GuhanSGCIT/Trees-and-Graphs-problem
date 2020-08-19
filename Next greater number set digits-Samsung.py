"""
Given a number n, find the smallest number that has same set of digits as n and is greater than n. If x is the greatest possible number with its set of digits, then print “not possible”.

timing:1sec
level:6

Input:

The first line of input contains an integer T denoting the number of test cases.
The first line of each test case is n,n is the number.

Output:

Print the greater number than n with same set of digits and if not possible then print "not possible" without double quote.

Constraints:

1 ≤ T ≤ 100
1 ≤ n ≤ 100000

Example:

Input
2
143
431

Output
314
not possible

input:
3
326321
32165
12

output:
331226
32516
21
    
input:
1
123

output:
132

input:
1
999999

output:
not possible

input:
2
1212
1000

output:
1221
not possible

hint:
Traverse the given number from rightmost digit, keep traversing till you find a digit which is smaller than the previously traversed digit.
Now search the right side of above found digit ‘d’ for the smallest digit greater than ‘d’. Swap the above found two digits, Now sort all digits from position next to ‘d’ to the end of number. The number that we get after sorting is the output

"""
def findNext(number,n): 
     for i in range(n-1,0,-1): 
         if number[i] > number[i-1]: 
             break
     if i == 1 and number[i] <= number[i-1]: 
         print ("not possible")
         return
     x = number[i-1] 
     smallest = i 
     for j in range(i+1,n): 
         if number[j] > x and number[j] < number[smallest]: 
             smallest = j 
     number[smallest],number[i-1] = number[i-1], number[smallest] 
       
     x = 0
     for j in range(i): 
         x = x * 10 + number[j] 
     number = sorted(number[i:]) 
     # converting the remaining sorted digits into number 
     for j in range(n-i): 
         x = x * 10 + number[j] 
       
     print(x) 
  
for i in range(int(input())):
    digits = input()
    n=len(digits)
    number = int(input()) 
    findNext(number,n) 
