/*
Ram has just found a recipe book, where every dish consists of exactly four ingredients. He is going to choose some two dishes and prepare them for dinner. Of course, he likes diversity and wants to know whether the two dishes are similar.

Two dishes are called similar if at least half of their ingredients are the same. In other words, at least two of four ingredients of the first dish should also be present in the second dish. The order of ingredients doesn't matter.

Your task is to examine T pairs of dishes. For each pair, check if the two dishes are similar and print "similar" or "dissimilar" accordingly.

Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains four distinct strings, denoting ingredients needed for the first dish. Each ingredient is represented by a string of length between 2 and 10 inclusive, consisting of lowercase English letters.
The second line of each test case describes the second dish in the same format.

Output
For each test case, output a single line containing the answer — "similar" if at least half of the ingredients are same, and "dissimilar" otherwise (without the quotes).

Constraints
    1 ≤ T ≤ 200
    The length of each string will be between 2 and 10 inclusive.

Input:
5
eggs sugar flour salt
sugar eggs milk flour
aa ab ac ad
ac ad ae af
cookies sugar grass lemon
lemon meat chili wood
one two three four
one two three four
gibberish jibberish lalalalala popopopopo
jibberisz gibberisz popopopopu lalalalalu

Output:
similar
similar
dissimilar
similar
dissimilar

Explanation
Test case 1. The first dish consists of ingredients: eggs, sugar, flour, salt, while the second dish consists of: sugar, eggs, milk, flour. Three of four ingredients are present in both dishes (eggs, sugar, flour) so the two dishes are similar.

input:
2
Guvi Geek
Geek guvi
G U V I
I U G V

output:
dissimilar
similar

input:
3
I Like Programming
Like Programming I
dishes are similar
dishes are similar
Guvi
Guvi

output:
similar
similar
similar

input:
1
one two three four
One Two Three Four

output:
dissimilar

input:
4
1 2 2 4
2 2 1 4
2123 23
23 2123
numbers are also string
string are also numbers

output:
similar
dissimilar
similar
similar

hint:
No two strings in each of the arrays are same. You have to tell whether the number of common strings in the arrays are more than or equal two or not.

*/
#include <bits/stdc++.h>
using namespace std;

const int N = 4;
string a[N], b[N];
void test_case()
{
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    for (int i = 0; i < N; ++i)
        cin >> b[i];
    int same = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (a[i] == b[j])
                ++same;
    if (same >= 2)
        puts("similar");
    else
        puts("dissimilar");
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
        test_case();
}
