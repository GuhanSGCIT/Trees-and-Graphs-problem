"""
Question:
In the School prayer ,students are standing in the line,but they are standing in irregular manner (based on height).
Time is getting late for the prayer,Staff want sort atlest few students(X).help the staff to sort the students.

Tags:
Linked list

Input Discription:
First line consists of a number of students N,
Second line consists of  N no of students as list,
Thrid line consists of height of students should be sorted X.

Output Discription:
Print the sorted students line list.

Testcase 1:
input:
6
1 4 3 2 5 2 3
3
output:
1 2 2 3 3 4 5

Testcase 2:
input:
4
1 4 2 10
3
output:
1 2 4 10

Testcase 3:
input:
5
10 4 20 10 3
4
output:
3 4 10 20 10

Hint:
Sort the students height less than or equal to X, other remains same.

solution:

"""class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    def printLinkedList(self):
        temp = self.head
        while temp is not None:
            if temp.next is not None:
                print(temp.data, end = " ")
            else:
                print(temp.data, end = "")
        temp = temp.next
def partition( head, x) : 
	smallerHead = None
	smallerLast = None
	greaterLast = None
	greaterHead = None
	equalHead = None
	equalLast = None
	while (head != None) : 
		if (head.data == x): 
		
			if (equalHead == None): 
				equalHead = equalLast = head 
			else: 
			
				equalLast.next = head 
				equalLast = equalLast.next
		elif (head.data < x): 
		
			if (smallerHead == None): 
				smallerLast = smallerHead = head 
			else: 
			
				smallerLast.next = head 
				smallerLast = head 
		
		else : 
		# Append to the list of greater values 
		
			if (greaterHead == None) : 
				greaterLast = greaterHead = head 
			else: 
			
				greaterLast.next = head 
				greaterLast = head 
			
		head = head.next
	if (greaterLast != None) : 
		greaterLast.next = None
	if (smallerHead == None) : 
	
		if (equalHead == None) : 
			return greaterHead 
		equalLast.next = greaterHead 
		return equalHead 
	if (equalHead == None) : 
	
		smallerLast.next = greaterHead 
		return smallerHead 
	smallerLast.next = equalHead 
	equalLast.next = greaterHead 
	return smallerHead 



def createLinkedList(lst, n):
    ll = LinkedList()
    temp = ll.head
    for i in range(n):
        new_node = Node(lst[i])
        if ll.head is None:
            ll.head = new_node
            temp = new_node
        else:
            temp.next = new_node
            temp = new_node
    return ll

# Function to print linked list 
def printList(head) : 

	temp = head 
	while (temp != None): 
	
		print(temp.data ,end= " ") 
		temp = temp.next
	

# Driver code 

# Start with the empty list 
n = int(input())
lst = [int(x) for x in input().split()]
ll = createLinkedList(lst,n)
x = int(input())
head = partition(ll.head, x) 
printList(head)
