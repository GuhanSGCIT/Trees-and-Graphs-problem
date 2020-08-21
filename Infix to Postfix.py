"""
Given an infix expression in the form of a string str. Conver this infix expression to postfix expression.
    Infix expression: The expression of the form a op b. When an operator is in-between every pair of operands.
    Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.

Input:
The first line of input contains an integer T denoting the number of test cases.
The next T lines contains an infix expression.The expression contains all characters and ^,*,/,+,-.

Output:
For each testcase, in a new line, output the infix expression to postfix expression.

Constraints:
1 <= T <= 100
1 <= length of str <= 10^3

Example:
Input:
2
a+b*(c^d-e)^(f+g*h)-i
A*(B+C)/D

Output:
abcd^e-fgh*+^*+i-
ABC+*D/


input:
3
A*(B+C)/D
A*B+C/D
A*(B+C/D)

output:
ABC+*D/
AB*CD/+
ABCD/+*

input:
2
((A*B)+(C/D))
((A*(B+C))/D)

output:
AB*CD/+
ABC+*D/

input:
1
(A*(B+(C/D)))

output:
ABCD/+*

input:
1
a+b*c-(d/e+f*g*h)

output:
abc*+de/fg*h*+-

hint:
The compiler first scans the expression to evaluate the expression,The repeated scanning makes it very in-efficient.
It is better to convert the expression to postfix(or prefix) form before evaluation. The postfix expressions can be evaluated
easily using a stack. We will cover postfix expression evaluation in a separate post.


"""
class Conversion: 
    def __init__(self, capacity): 
        self.top = -1 
        self.capacity = capacity 
        # This array is used a stack  
        self.array = [] 
        # Precedence setting 
        self.output = [] 
        self.precedence = {'+':1, '-':1, '*':2, '/':2, '^':3} 
      
    # check if the stack is empty 
    def isEmpty(self): 
        return True if self.top == -1 else False
      
    # Return the value of the top of the stack 
    def peek(self): 
        return self.array[-1] 
      
    # Pop the element from the stack 
    def pop(self): 
        if not self.isEmpty(): 
            self.top -= 1
            return self.array.pop() 
        else: 
            return "$"
      
    # Push the element to the stack 
    def push(self, op): 
        self.top += 1
        self.array.append(op)  
    def isOperand(self, ch): 
        return ch.isalpha() 
    def notGreater(self, i): 
        try: 
            a = self.precedence[i] 
            b = self.precedence[self.peek()] 
            return True if a  <= b else False
        except KeyError:  
            return False
              
    def infixToPostfix(self, exp): 
          
        # Iterate over the expression for conversion 
        for i in exp: 
            if self.isOperand(i): 
                self.output.append(i) 
              
            # If the character is an '(', push it to stack 
            elif i  == '(': 
                self.push(i) 
  
            elif i == ')': 
                while( (not self.isEmpty()) and self.peek() != '('): 
                    a = self.pop() 
                    self.output.append(a) 
                if (not self.isEmpty() and self.peek() != '('): 
                    return -1
                else: 
                    self.pop() 
  
            # An operator is encountered 
            else: 
                while(not self.isEmpty() and self.notGreater(i)): 
                    self.output.append(self.pop()) 
                self.push(i) 
  
        # pop all the operator from the stack 
        while not self.isEmpty(): 
            self.output.append(self.pop()) 
  
        print( "".join(self.output)) 
  
for i in range(int(input())):
    exp = input()
    obj = Conversion(len(exp)) 
    obj.infixToPostfix(exp) 
