"""
Mr. Das is a teacher teaching for several years in a school. He is not computer savvy. Due to lockdown, now he has to take classes
online. Recently he took an online exam for students of different classes. Now, he will call parents of all the students who scored
lower than average marks for the class. He has requested you to give the name X, parent's phone number P, and marks obtained M to him.

Input:
First line contains T no. of test cases for every test case,
first line contains an integer N , no. of students of his class
Next N lines contain X, P , and M separated by space

Output:
For every test case, find details of the students who scored below average, then print X,P,M separated by space on a new line as per the increasing order of their marks. In case there are multiple students with the same marks, print them as per the order of their occurrence in the input

Constraints
1≤T≤20
X contains characters between a-z and A-Z with a maximum length of 20
1≤N≤100
P is 10 digits
0≤M≤100

Sample Input:
2  
3
Rahul 1345964789 47
Rupendra 1457856987 58
Priya 1478569820 45
2
Tanuja 4310779415 97
Akash 3689781245 43

Sample Output:
Priya 1478569820 45
Rahul 1345964789 47
Akash 3689781245 43

EXPLANATION:
In #1, Priya and Rahul's number was lower than average. In #2, Akash's number was lower than average



input:
1
5
ram 4567891232 89
priya 4958612370 90
rakul 4589671231 99
gowtham 7894563212 55
kavin 1234567891 45

output:
kavin 1234567891 45
gowtham 7894563212 55

input:
1
3
guha 4569871235 65
gova 458791263 61
ganesh 7418529632 61

output:
gova 458791263 61
ganesh 7418529632 61

input:
1
3
priya 4512326598 11
ganesh 4598653212 12
ram 4584765981 11

output:
priya 4512326598 11
ram 4584765981 11

input:
1
1
guhan 4587986521 22

output:
<empty>

hint:
For a class with N number of students, Let name, parents phone number and marks obtained by ithi^{th}ith student be, name_i​, P_i​, and M_i​.
To calculate average, we take the sum of MiM_iMi​ and divide it by N.
avg=(∑i=1->N;Mi)/N
Then we iterate through all students, We filter out students whose M_i < avg
Then we sort the students as per the increasing order of their marks and print them.
"""
T = int(input())
for z in range(T):
    N = int(input())
    details = []
    for i in range(N):
        name, phone, marks = input().split()
        details.append((name, phone, int(marks)))
    # Find sum of marks
    total = sum(elem[2] for elem in details)
    avg = total / N

    details.sort(key=lambda x: x[2])  # Sort by score
    for student in details:
        if student[2] < avg:
            print(student[0], student[1], student[2])
