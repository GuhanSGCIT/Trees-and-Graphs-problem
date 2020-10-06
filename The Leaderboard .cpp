/*
A lot of people participating in a contest are obsessed with looking at the leaderboard to see how they are doning (Even you might have checked it just now. Hope you are doing well :P).

Considering there are N teams participating and there are M problems in the contest. What would be the expected number of problems solved by the team at rank K on the leaderboard?

If the expected value is P/Q,you must print the value P∗Q−1%MOD, where MOD=10^9+7.

timming:3sec
level:8

Input
First line contains T, number of test case,For each test case, you are given 3 space seperated integers N, M and K.

Output
For each test case print the desired answer.

Constraints
1≤T≤10
1≤K≤N≤10^9
1≤M≤50

Sample Input
2
1 1 1
2 2 2

Sample Output
500000004
545454550

Explanation
For the first test case, there can be only 2 possiblities(Here S represents solved and U represents unsolved) -
U
S
Therefore expected number of problems solved by rank 1 = 1∗(1/2)+0∗(1/2)=1/2

input:
2
7 7 7
1 1 1

output:
364899412
500000004

input:
1
8 8 8

output:
898539263

input:
3
12 12 12
32 32 32
2 2 2

output:
851668650
928796580
545454550

input:
2
1 2 1
2 3 2

output:
1
142857145

hint:
The expected value of the number of problems solved by person k, which can be calculated for each i where i is the number of problems solved by a person at rank kkk as -
answer=∑i=0;m; p(k,i)∗i,where p(i)= the probability of solving i problems by the person at rank k,and p(k,i)=(mi)∗g(k−1,m,i)∗h(n−k,m,i)/f(n,m)

*/
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class Matrix {
public:
    int n , m;
    vector<vector<long long> > M;
    Matrix(int n , int m): n(n), m(m) {
        M.resize(n , vector<long long>(m, 0));
    }

    Matrix operator*(const Matrix& other) {
        assert(m == other.n);
        Matrix res(n , other.m);
        for(int i = 0 ; i < n ; ++i) {
            for(int j = 0 ; j < other.m ; ++j) {
                for(int k = 0 ; k < m ; ++k) {
                    res.M[i][j] = res.M[i][j] + (M[i][k] * other.M[k][j]) % MOD;
                    res.M[i][j] %= MOD;
                }
            }
        }
        return res;
    }
    Matrix operator^(long long p) {
        Matrix A = *this;
        Matrix res(n, m);

        for(int i = 0 ; i < n ; ++i) res.M[i][i] = 1;

        while(p) {
            if(p&1) {
                res = res * A;
            }
            A = A * A;
            p >>= 1ll;
        }
        return res;
    }
    friend ostream& operator<<(ostream& os , const Matrix& M) {
        for(int i = 0 ; i < M.n ; ++i) {
            for(int j = 0 ; j < M.m ; ++j) {
                cout << M.M[i][j] << " ";
            }
            cout << "\n";
        }
        return os;
    }
};

const int N = 1e3 + 5;
long long ncr[N][N];

void pre() {
    for(int i = 0 ; i < N ; ++i) {
        ncr[i][0] = 1;
    }

    for(int n = 1 ; n < N ; ++n) {
        for(int r = 1 ; r < N ; ++r) {
            ncr[n][r] = ncr[n-1][r] + ncr[n-1][r-1];
            ncr[n][r] %= MOD;
        }
    }
}


long long extended_GCD(long long a , long long b , long long &x , long long &y){
    if(a == 0){
        x = 0;
        y = 1;
        return b;
    }
    long long x1 , y1;
    long long gcd = extended_GCD(b%a , a , x1 , y1);
    x = y1 - (b/a)*x1; 
    y = x1;
    return gcd;
}

long long modinv(long long a , long long mod = MOD){
    long long x , y;
    extended_GCD(a , mod , x , y);
    if(x < 0) x += mod;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pre();

    int t;
    cin >> t;
    while(t--) {
        long long n , m , k;
        cin >> n >> m >> k;
        Matrix A(m+1, m+1);

        for(int i = 0 ; i <= m ; ++i) {
            for(int j = 0 ; j <= m ; ++j) {
                if(i > j) {
                    continue;
                }
                A.M[i][j] = ncr[m][i];
            }
        }
        Matrix pw0 = A^n;
        Matrix pw1 = A^(k-1);
        Matrix pw2 = A^(n-k);

        Matrix dp0(1 , m+1);
        for(int i = 0 ; i <= m ; ++i) {
            dp0.M[0][i] = 1;
        }

        Matrix res0 = dp0 * pw0;

        long long denominator = res0.M[0][m];

        

        long long numerator = 0;
        for(int i = 0 ; i <= m ; ++i) {
            Matrix dp1(1 , m+1);
            for(int j = i ; j <= m ; ++j) {
                dp1.M[0][j] = 1;
            }
            Matrix res1 = dp1 * pw1;
            long long topCount = res1.M[0][m];
            
            Matrix dp2(1 , m+1);
            for(int j = 0 ; j <= m ; ++j) {
                dp2.M[0][j] = 1;
            }
            Matrix res2 = dp2 * pw2;
            long long bottomCount = res2.M[0][i];
            
            long long total = (topCount * bottomCount) % MOD;
            total = (total * ncr[m][i]) % MOD;
            total = (total * i) % MOD;

            numerator = (numerator + total) % MOD;
        }

        long long res = (numerator * modinv(denominator)) % MOD;
        cout << res << "\n";
    }
}
