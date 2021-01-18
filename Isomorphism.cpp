/*
Let's call two numbers isomorphic if they have same number of digits and set of places having equal digits is same. We consider that all the numbers are in decimal notation and don't have leading zeroes. Consider some examples:
    12321 is isomorphic to 83538 and 45654.
    1232 is not isomorphically equal to 2342 because set of places having equal digits are {{1}, {2, 4}, {3}} and {{1, 4}, {2}, {3}} (digits are numbered from left to right using 1 based indexing). In other words, the digits order has to remain the same.
    12 isomorphic to 10,13,14, 92, but not isomorphic to 1, because their lengths are not equal and not isomorphic to 01, because leading zeroes are not allowed.
Let F(X) denote the smallest integer (without leading zeroes) isomorphic to X where X is a positive integer. For example, F(12) = 10, F(213) = 102.

You are given two integers N and M. Your task is to calculate F(1) % M + F(2) % M + F(3) % M + ... + F(N - 1) % M + F(N) % M.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains a pair of integers N and M. The meaning of these integers is described in the statement.

Output
For each test case, output a single line containing the answer to the problem.

Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 10^11
1 ≤ M ≤ 10^7

Input:
2
15 100
123456789 9876543

Output:
70
102768568246676

Explanation
Example case 1. Numbers 1, 2, 3, ..., 9 are isomorphic to 1. Numbers 10, 12, 13, 14, 15 are isomorphic to 10. Among the numbers from 1 to 15, 11 is isomorphic only to itself. So, we get 1 + 1 + ... + 1 + 10 + 11 + 10 + 10 + 10 + 10 = 70.
Example case 2. This is just a large case so that you can check your solution better. 

input:
3
1 1
10000011 100007
2 3

output:
0
165488232848
2

input:
2
5 8
1 5

output:
5
1

input:
7
1 2
5 9
4 6
123 321
655465 5654
159 159
1 100

output:
1
5
4
3441
1230061098
7104
1

input:
1
1000 100000

output:
94204

hint:
Let’s call a number V viable if there is an n such that F(n)=V. Note that a number V is viable if and only if, after we treat V as a string of digits and after removing every digit that has already appeared in the string, the resulting string of digits is a prefix of 1023456789. For example, 1010212 is viable.

*/
#include <cassert>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int seq[10] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9};

#define dec Dec
#define replace Replace

long long N, ret, M;
int Tn, dec_len, orig_len, was[10], was2[10], it, it2, dec[20], orig[20], replace[10], was1[10], gd[20][20];
int checked[10], assigned[10], used[10];

int grad_decr(int p, int k)
{
    if (k == 0)
        return 1;
    else
        return p * grad_decr(p - 1, k - 1);
}

long long big_part, small_part;

void do_add(long long what)
{
    small_part += what;
    big_part += small_part / 1000000000000000000LL;
    small_part %= 1000000000000000000LL;
}

void process(long long q)
{
    if (dec_len < orig_len)
    {
        long long kol = 9, cways = 9;
        was[1] = ++it;
        for (int i = 2; i <= dec_len; i++)
            if (was[dec[i]] != it)
            {
                was[dec[i]] = it;
                kol *= cways--;
            }
        do_add(q % M * kol);
    }
    else
    {
        long long kol = 0;
        int keq = 0;
        ++it;

        int free = 10;
        for (int i = 0; i < 10; i++)
            assigned[i] = used[i] = -1;

        for (keq = 0; keq < orig_len; keq++)
        {

            if (keq > 0)
            {
                if (assigned[dec[keq]] == -1 && used[orig[keq]] == -1)
                {
                    assigned[dec[keq]] = orig[keq];
                    used[orig[keq]] = dec[keq];
                    --free;
                }
                else if (assigned[dec[keq]] != orig[keq] || used[orig[keq]] != dec[keq])
                    break;
            }

            if (assigned[dec[keq + 1]] != -1 && assigned[dec[keq + 1]] > orig[keq + 1])
                break;
            if (assigned[dec[keq + 1]] != -1 && assigned[dec[keq + 1]] >= orig[keq + 1])
                continue;

            int need_to_assign = 0;
            for (int i = 0; i < 10; i++)
                checked[i] = false;
            for (int i = keq + 1; i <= orig_len; i++)
                if (assigned[dec[i]] == -1 && !checked[dec[i]])
                {
                    checked[dec[i]] = true;
                    ++need_to_assign;
                }

            if (assigned[dec[keq + 1]] == -1)
            {
                int good_for_start = 0;
                for (int i = 0 + (keq == 0); i < orig[keq + 1]; i++)
                    if (used[i] == -1)
                        ++good_for_start;
                kol += good_for_start * gd[free - 1][need_to_assign - 1];
            }
            else
            {
                kol += gd[free][need_to_assign];
            }
        }
        do_add(q % M * kol);
    }
}

void rec(long long n, int k)
{
    process(n);
    for (int i = 0; i <= k; i++)
        if (n * 10LL + seq[i] <= N)
        {
            dec[++dec_len] = seq[i];
            rec(n * 10LL + seq[i], k);
            --dec_len;
        }
    if (k < 9)
    {
        if (n * 10LL + seq[k + 1] <= N)
        {
            dec[++dec_len] = seq[k + 1];
            rec(n * 10LL + seq[k + 1], k + 1);
            --dec_len;
        }
    }
}

int w[1000], sqn;

long long funct(long long i)
{
    long long kk = i, wn = 0;
    do
    {
        w[++wn] = kk % 10;
        kk /= 10;
    } while (kk != 0);
    reverse(w + 1, w + wn + 1);
    ++it;
    sqn = 0;
    for (int j = 1; j <= wn; j++)
        if (was[w[j]] != it)
        {
            was[w[j]] = it;
            replace[w[j]] = seq[sqn];
            sqn++;
        }
    long long ref = 0;
    for (int j = 1; j <= wn; j++)
        ref = 10LL * ref + replace[w[j]];
    return ref % M;
}

long long brute()
{
    long long ret2 = 0;
    int w[100], sqn;
    for (int i = 1; i <= N; i++)
    {
        int kk = i, wn = 0;
        do
        {
            w[++wn] = kk % 10;
            kk /= 10;
        } while (kk != 0);
        reverse(w + 1, w + wn + 1);
        ++it;
        sqn = 0;
        for (int j = 1; j <= wn; j++)
            if (was[w[j]] != it)
            {
                was[w[j]] = it;
                replace[w[j]] = seq[sqn];
                sqn++;
            }
        int ref = 0;
        for (int j = 1; j <= wn; j++)
            ref = 10 * ref + replace[w[j]];
        ret2 += ref % M;
    }
    return ret2;
}

int main(int argc, char *const argv[])
{
    cin >> Tn;
    assert(1 <= Tn && Tn <= 10);
    while (Tn--)
    {
        big_part = small_part = 0;
        cin >> N >> M;
        assert(1 <= N && N <= 100000000000LL);
        assert(1 <= M && M <= 10000000LL);

        //		cerr << brute() << endl;

        orig_len = 0;
        long long n = N;
        while (n > 0)
        {
            orig[++orig_len] = n % 10;
            n /= 10;
        }
        reverse(orig + 1, orig + orig_len + 1);
        dec[dec_len = 1] = 1;

        for (int i = 0; i <= 10; i++)
            gd[i][0] = 1;
        for (int i = 1; i <= 10; i++)
            for (int j = 1; j <= 10; j++)
                gd[i][j] = i * gd[i - 1][j - 1];

        rec(1, 0);
        do_add(funct(N) % M);
        if (big_part > 0)
        {
            printf("%lld%.18lld\n", big_part, small_part);
        }
        else
            printf("%lld\n", small_part);
    }
    return 0;
}
