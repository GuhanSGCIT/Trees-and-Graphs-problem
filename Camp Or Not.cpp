/*
The Ram camp takes place in about one month. Jafar wants to participate in the camp, but guess what? His coach is kapil dev.

kapil dev is a legendary coach, famous in the history of competitive programming. However, he is only willing to send to the camp students who solve really hard problems on Timus. He started a marathon at the beginning of December. Initially, he said that people who solve 200 or more problems by the 31-st of December may go to the camp. Jafar made a schedule for the next month. For each day, he knows how many problems he is going to solve.

The problem is that kapil dev is a really moody coach — he may wake up tomorrow and change his decision about the deadline and the number of problems that must be solved by this deadline to qualify for the camp. Jafar has Q

such scenarios. Now he wants to know: in each scenario, if he does not change his problem solving schedule, will he go to the camp or not?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer D - the number of days in Jafar's schedule.
D lines follow. For each i (1≤i≤D), the i-th of these lines contains two space-separated integers di and pi denoting that Jafar will solve pi problems on day di.
The next line contains a single integer Q denoting the number of scenarios Jafar considers.
Q lines follow. For each i (1≤i≤Q), the i-th of these lines contains two space-separated integers deadi and reqi denoting a scenario where Yalaovichik decides that students who solve reqi problems by day deadi(inclusive) will go to the camp.

Output
For each scenario, print a single line containing the string "Go Camp" if Jafar is going to the camp or "Go Sleep" otherwise (without quotes).

Example Input
1
3
10 5
14 4
31 1
2
9 2
15 7

Example Output
Go Sleep
Go Camp

Explanation
Example case 1:By the end of day 9 , Jafar will not have any problem solved.
By the end of day 15 , Jafar will have 9 problems solved, which is enough to go to the camp, since he needs at least 7 problems.

input:
1
4
12 4
23 8
6 2
10 2
3
23 7
12 6
3 1

output:
Go Camp
Go Camp
Go Sleep

input:
2
1
41 12
2
21 4
54 32
1
21 6
2
12 6
24 5

output:
Go Sleep
Go Sleep
Go Sleep
Go Camp

input:
1
4
4 2
6 2
2 1
3 2
2
12 6
6 3

output:
Go Camp
Go Camp

input:
1
1
2 1
1
2 2

output:
Go Sleep

hint:
for each query, we can iterate through all the problem-solving events. If the day corresponding to some event is the deadline day (or someday before) we can assume that we are gonna solve the number of problems planned for that day. We sum up all the problems amounts of these days.

*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv)
{

    int T;
    cin >> T;
    while (T--)
    {

        int D;
        cin >> D;

        vector<pair<int, int>> ev;

        for (int i = 0; i < D; i++)
        {
            int di, pi;
            cin >> di >> pi;
            ev.push_back({di, pi});
        }

        int Q;
        cin >> Q;

        for (int i = 0; i < Q; i++)
        {
            int deadi, reqi, tot = 0;
            cin >> deadi >> reqi;
            for (auto e : ev)
            {
                if (e.first <= deadi)
                    tot += e.second;
            }
            if (tot >= reqi)
                puts("Go Camp");
            else
                puts("Go Sleep");
        }
    }
}