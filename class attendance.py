"""
Question:-
    In your class,Class advisor will take attendance before each period,i.e. call out the names of students one by one
and mark which students are present. Each student has a first name and a last name. In order to save time,
advisor wants to call out only the first names of students. However, whenever there are multiple students with the same first name,
advisor has to call out the full names (both first and last names) of all these students.For each student that does not
share the first name with any other student, Staff may still call out only this student's first name.

    There are N students attending the course, numbered 1 through N.Help the staff decide, for each student,
whether he will call out this student's full name or only the first name.

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.N lines follow. For each valid i, the i-th of the following N lines
contains two space-separated strings denoting the first and last name of student i.

Output Description:
For each test case, print N lines. For each valid i, the i-th of these lines should describe how staff calls out
the i-th student's name ― it should contain either the first name or the first and last name separated by a space.

Testcases:
Input:
1
4
Arun kumar
Prem Anand
Arun mozhivarman
Mohan ram

Output:
Arun kumar
Prem
Arun mozhivarman
Mohan

Input:
1
7
Mohan Ram
Ram Mohan
Prem k
Naveen kumar
Ram charan
Keerthi vasan
karan raj

Output:
Mohan
Ram Mohan
Prem
Naveen
Ram charan
Keerthi
karan

Input:
1
4
arun kumar
perm k
arul anand
arul kumar

Output:
arun
perm
arul anand
arul kumar

Input:
1
4
hasan jaddouh
farhod khakimiyon
kerim kochekov
hasan khateeb

Output:
hasan jaddouh
farhod
kerim
hasan khateeb

Input:
1
3
1234 26563
1234 3516
35 12
Output:
1234 26563
1234 3516
35

Solution:
"""
def main():
    t = int(input())
    for _ in range(t):
        n = int(input())
        dic ={}
        arr =[]
        for _ in range(n):
            first, last = input().split()
            arr.append([first,last])
            dic[first] = dic.get(first,0)+1
        for first, last in arr:
            if dic[first] > 1:
                print(first,last,sep = " ")
            else:
                print(first)


if __name__ == "__main__":
    main()
