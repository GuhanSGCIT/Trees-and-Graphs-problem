/*
You visit a doctor on a date given in the format yyyy:mm:dd. Your doctor suggests you to take pills every alternate day starting from that day. You being a forgetful person are pretty sure won’t be able to remember the last day you took the medicine and would end up in taking the medicines on wrong days.
So you come up with the idea of taking medicine on the dates whose day is odd or even depending on whether dd is odd or even. Calculate the number of pills you took on right time before messing up for the first time.

Input:
First line will contain T, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, in the format yyyy:mm:dd

Output:
For each testcase, output in a single line the required answer.

Constraints
1≤T≤1000
1900≤yyyy≤ 2038
yyyy:mm:dd is a valid date

Sample Input:
1
2019:03:31

Sample Output:
1

EXPLANATION:
You can take pill on the right day only on 31st March. Next you will take it on 1st April which is not on the alternate day.

input:
2
2020:12:31
2021:01:01

output:
1
16

input:
3
1999:12:21
1945:10:10
1998:11:06

output:
6
11
28

input:
1
1884:01:26

output:
3


input:
2
1888:02:27
1919:21:08

output:
2
27

hint:
Every year that is exactly divisible by four is a leap year, except for years that are exactly divisible by 100; the centurial years that are exactly divisible by 400 are still leap years. For example, the year 1900 is not a leap year; the year 2000 is a leap year.


*/
#include <stdio.h>

int main(void)
{
    // your code goes here
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int m, y, d, c = 0;
        scanf("%d:%d:%d", &y, &m, &d);
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            c = ((31 - d) / 2) + 1;
        }
        else if (m == 2)
        {
            if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
            {
                c = ((29 - d) / 2) + 1;
            }
            else
            {
                c = ((59 - d) / 2) + 1;
            }
        }
        else
        {
            c = ((61 - d) / 2) + 1;
        }
        printf("%d\n", c);
    }
    return 0;
}
