/*
Given a string S and several frequencies Fi. For each Fi output the number of substrings of S (the characters of substring should be
contiguous) that occur at least Fi times in S. Note, that we consider two substrings distinct if they have distinct length, or they
have distinct starting indices.

timing:1500
level:6

Input
The first line of input contains integer T, the number of test cases.
The first line of each test case contains string S (it contains only lowercase Latin letters).
The second line of each test case contains an integer Q, that is the number of queries to be answered.
Then Q lines follows containing Fi each.

Output
For each query, output the required answer.

Constraints
    1 ≤ |S| ≤ 200000
    1 ≤ Q ≤ 200000
    1 ≤ Fi ≤ 200000
    Sum of |S| over all test cases ≤ 200000
    Sum of Q over all test cases ≤ 200000

Input:
1
aaeddf
4
1
2
3
4

Output:
21
4
0
0

 
Explanation
There are a total of 6*(6+1)/2 substrings, all of them occur at least once. So for F1=1 answer is equal to 21. Note that substring "a" is repeated 2 times in S, both the instances are added to the answer.
Look at F2=2. Substring "a" and substring "d" occurs 2 times each in S. The answer for F2 is 4, that is all the occurrences of "a" and "d".
There are no substrings which repeat more than twice. So rest answers are 0

input:
1
asssa
5
3
2
1
4
5

output:
3
7
15
0
0

input:
1
fasa
4
1
2
4
3

output:
10
2
0
0

input:
1
llsls
3
2
3
1

output:
7
3
15

input:
1
wawaa
5
4
1
3
2
5

output:
0
15
3
7
0

hint:
Construct suffix tree of the string S, then you just need to do a dfs over it and keep updating the count of appearance of substrings.

*/
#include <bits/stdc++.h>

using namespace std;

static const int N = 200005;

typedef long long ll;

struct state {
    int len;
    int link;
    int next[ 26 ];
} st[ N << 1 ];

int node, last;
ll occur[ N << 1 ];

void init() {
    node = 0;
    last = 0;
    st[ 0 ].len = 0;
    for(int i = 0; i < 26; i += 1) {
        st[ 0 ].next[ i ] = 0;
    }
    st[ 0 ].link = -1;
}

void add(int c) {
    int cur = ++node, p;
    st[ cur ].len = st[ last ].len + 1;
    occur[ cur ] = 1;
    for(p = last; ~p && !st[ p ].next[ c ]; p = st[ p ].link)
        st[ p ].next[ c ] = cur;
    
    for(int i = 0; i < 26; i += 1) {
        st[ cur ].next[ i ] = 0;
    }

    if( p == -1 )
        st[ cur ].link = 0;
    else {
        int q = st[ p ].next[ c ];
        if( st[ p ].len + 1 == st[ q ].len)
            st[ cur ].link = q;
        else {
            int clone = ++node;
            occur[ clone ] = 0;
            st[ clone ].len = st[ p ].len + 1;
            st[ clone ].link = st[ q ].link;
            memcpy( st[ clone ].next, st[ q ].next, sizeof st[ q ].next );
            for(; ~p && st[ p ].next[ c ] == q; p = st[ p ].link)
                st[ p ].next[ c ] = clone;
            st[ q ].link = st[ cur ].link = clone;
        }
    }
    last = cur;
}


ll ans[ N ];
char s[ N ];

void process() {
    int len = strlen( s );
    for(int i = 0; s[ i ]; i += 1) {
        add( s[ i ] - 'a' );
    }
    for(int i = 0; i <= len; i += 1) {
        ans[ i ] = 0;
    }
    vector<int> v[ len + 1 ];
    for(int i = 1; i <= node; i += 1) {
        v[ st[ i ].len ].push_back( i );
    }
    for(int i = len; i >= 1; i -= 1) {
        for(auto& x : v[ i ]) {
            occur[ st[ x ].link ] += occur[ x ];
        }
    }
    for(int i = 1; i <= node; i += 1) {
        ans[ occur[ i ] ] += occur[ i ] * ( st[ i ].len - st[ st[ i ].link ].len );
    }
    for(int i = len; i >= 1; i -= 1) {
        ans[ i ] += ans[ i + 1 ];
    }
    int Q;
    scanf("%d", &Q);
    while( Q-- ) {
        int f;
        scanf("%d", &f);
        printf("%lld\n", ans[ f ]);
    }
}

int main() {
    int testcase;
    scanf("%d", &testcase);
    while( testcase-- ) {
        init();
        scanf("%s", s);
        process();
    }
    return 0;
}
