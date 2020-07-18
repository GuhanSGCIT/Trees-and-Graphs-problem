"""
    Tom has N jerry. Each jerry has two characteristics: power a and endurance b. Tom thinks that a non-empty
set of jerry {m1,m2,…,mk} with characteristics (am1,bm1),(am2,bm2),…,(amk,bmk) is good if the mean endurance
of this set doesn't exceed the minimum power in it, i.e. if min(am1,am2,…,amk) ≥ (bm1+bm2+⋯+bmk)/k.

    Tom would like to choose a good subset of her jerry and give these jerry to Mark. Your task is to calculate the
maximum number of jerry.Tom can give to Mark.

Input Description:
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains a single integer N.
The following N lines describe jerry. Each of these lines contains two space-separated integers a and b denoting
the power and endurance of one jerry.

Output Description:
For each test case, print a single line containing one number — the size of the largest good set of jerry,
or 0 if no such set exists.

Tag: Segment Tree

Testcases:
Input:
2
3
1 4
3 3
2 1
2
3 5
1 4
Output:
2
0


Explanation:
Example case 1: The set of jerry {2,3} is good, since min(3,2)≥(3+1)/2.
Example case 2: There is no non-empty good subset of jerry.

Input:
2
1
1 2
3
2 5
2 5
5 2
Output:
0
1

Input:
1
6
25 785
4 55
4545 665
2456 55
6 5
1 0
65 55

Output:
2

Input:
5
3
1 4
3 3
2 1
2
3 5
1 4
1
1 1
1
1 2
5
5 1
5 2
5 3
5 4
5 5
Output:
2
0
1
0
5

Input:
2
5
1 2
1 5
1 6
1 4
1 8
3
5 2
5 4
5 3
Output:
0
3

Solution:
"""
T = int(input())
for _ in range(T):
    N = int(input())
    mas_p = []
    for i in range(N):
        a, b = [int(s) for s in input().split()]
        mas_p.append((a, b, i))
    mas_e = [el for el in mas_p]
    mas_e.sort(key=lambda el: el[1])
    mas_p.sort(key=lambda el: (el[0], -el[1]))

    ans = 0
    b = -1
    cur_p_i = 0
    processed_p = set()
    processed_num = 0
    e = 0
    for cur_p_i in range(N):
        p = mas_p[cur_p_i][0]
        while b < N - 1:
            if mas_e[b + 1][2] in processed_p:
                b += 1
                processed_num += 1
                continue
            if p * (b + 1 + 1 - processed_num) >= e + mas_e[b + 1][1]:
                b += 1
                e += mas_e[b][1]
                processed_p.add(mas_e[b][2])
                continue
            else:
                break
        if mas_p[cur_p_i][2] in processed_p:
            ans = max(ans, b + 1 - processed_num)
            e -= mas_p[cur_p_i][1]
            processed_num += 1
        else:
            processed_p.add(mas_p[cur_p_i][2])

    print(ans)
