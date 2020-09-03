/*
Varun has a clock, but it got broken today — the minute hand on Varun's clock doesn't rotate by the angle 2π/3600 each second,
but by a different fixed angle x. The coordinates of the center of the clock are (0, 0). The length of the minute hand is l.

One endpoint of the minute hand is always located at the clock center; the other endpoint is initially located at the point (0, l).
One second later, Varun observes that this endpoint is at distance d above the x-axis, i.e. the y-coordinate of this endpoint is equal to d.

Varun is curious about where the minute hand will be (specifically, its y-coordinate) after t seconds. Because t can be very large,
Varun can't wait for that moment. Please help him!

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first and only line of each test case contains three space-separated integers l, d and t.

Output
We can prove that for the given constraints, the y-coordinate of the end of the minute hand can always be written as a rational number p / q, where gcd(p, q) = gcd(q, 109 + 7) = 1. Let's denote the modular inverse of q (it's guaranteed that the modular inverse exists and is unique) by r.
For each test case, print a single line containing one number (p · r) modulo 10^9 + 7.

Constraints
    1 ≤ T ≤ 10^5
    1 ≤ d < l ≤ 10^69
    1 ≤ t ≤ 10^18

Input:
3
4 2 1
4 2 2
4 2 3

Output:
2
1000000005
1000000003

Explanation
case 2:
The y-coordinate is -2, so the answer is 1000000005.
case 3:
The y-coordinate is -4, so the answer is 1000000003.

input:
2
5 4 1
2 6 3

output:
4
198

input:
5
1 5 9
12 24 48
2 5 8
9 6 3
1 4 7

output:
456335045
55246027
277727
666666664
937444

input:
3
1 1 1
12 12 13
3 2 1

output:
1
12
2

input:
1
101 120 130

output:
184869177

hint:
By the problem statement we have cos⁡(x)=d/l, and the final answer is cos⁡(tx)⋅l. So we only need to compute cos⁡(tx).There is a formula computing cos⁡(nx):
cos⁡(nx)=2cos⁡(x)cos⁡((n−1)x)−cos⁡((n−2)x), and we can use fast matrix exponentiation to compute cos⁡(tx) in O(log⁡t) time.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <set>
#include <limits>
int debug_run = 0;
int trace = 0;
int max_array_output=30;
using namespace std;
int imin = numeric_limits<int>::min();
int imax = numeric_limits<int>::max();
#define MOD_ 1000000007
#define INF imax
#define REP(i,s,m) for(i=s;i<(m);i++)
#define REPD(i,s,m) for(int i=s;i<(m);i++)
#define REPD_(i,s,m) for(int i=s;i<=(m);i++)
#define RREPD(i,s,m) for(int i=s;i>(m);i--)
#define RREPD_(i,s,m) for(int i=s;i>=(m);i--)
#define TRACE(n) if(debug_run && trace>=n)
#define DEBUG if(debug_run)
#define MAX(A,B) ((A)>(B) ? (A):(B))
#define MIN(A,B) ((A)<(B) ? (A):(B))
// from mckrisch WEASELTX solution 
#define GET_INT(type) \
() { \
int p; \
type val; \
        while ((p = getchar_unlocked()) < '-'); \
        val = p - '0'; \
        while ((p = getchar_unlocked()) >= '0') { \
                val = (val<<3) + (val<<1) + (p - '0'); \
            } \
        return val; \
}
int get_int GET_INT(int)
typedef long long int big_int_t;
big_int_t get_bigint GET_INT(big_int_t)
int gcd(int a, int b) {
int t;
    while(b) {
    	t = b;
    	b = a % b;
	a = t;
    }
    return a;
}
/* Возвращает указатель на строку, содержащий значения опционального аргумента */
char *get_opt_val(char *(*argv_p[]),int *argc_p) {
char *ret_val=NULL;
static char zero[] = "\0";
    if((*argv_p)[0][1]) {
        ret_val = (*argv_p)[0]+1;
    } else {
        ret_val = (++(*argv_p))[0];
        (*argc_p)--;
    }
    // (*argv_p)[0]=(const char *) "\0";
    (*argv_p)[0]=zero;
    return ret_val;
}
void solution();
int main(int argc, char *argv[]) {
 char *prog = argv[0];
 char *ifile_name=NULL;
 char *ofile_name=NULL;
char *int_val_string;
    char c;
    int arguments_correct = 1;


    while (--argc > 0 && (*++argv)[0] == '-') {
        while ((c = *++argv[0]))
            switch (c) {
            case 'd':
                debug_run = 1;
                break;
            case 't':
                int_val_string = get_opt_val(&argv,&argc);
		trace = atoi(int_val_string);
                break;
            case 'i':
                ifile_name = get_opt_val(&argv,&argc);
                break;
            case 'o':
                ofile_name = get_opt_val(&argv,&argc);
                break;
            case 'm':
                max_array_output = atoi(get_opt_val(&argv,&argc));
                 break;
            default:
                cout << "find: illegal option "<<  c << endl;
                arguments_correct = 0;
                break;
            }
    }
    if (!arguments_correct ) {
        cerr << "Usage: " << prog << "[-d] [-t] [-m max_array_output ] [-i <input-file>] [-o <output-file>]\n";
        exit(1);
    }
    if(ifile_name) {
        DEBUG { cerr << "ifile_name=" << ifile_name << endl; };
static  ifstream in(ifile_name);
        cin.rdbuf(in.rdbuf());
	freopen(ifile_name,"r",stdin);
    }
    if(ofile_name) {
        DEBUG {cerr << "ofile_name=" << ofile_name << endl; };
static  ofstream out(ofile_name);
        cout.rdbuf(out.rdbuf());
	freopen(ofile_name,"w",stdout);
    }
    DEBUG{ setvbuf(stdout, NULL, _IOLBF, 0); }
    solution();
}
int solve(int l, int d, big_int_t t);
void solution() {
int T, l, d;
big_int_t t;
int res;
    T = get_int();
    while(T--) {
    	l = get_int(); d = get_int(); t=get_bigint();
	res = solve(l, d, t);
	printf("%d\n", res);
    }
}
template<int MOD, class type=big_int_t>
class ModuleInt {
big_int_t n;
public:
    ModuleInt() {n = 0;}
    ModuleInt(int np) {n = np%MOD;}
    ModuleInt(big_int_t np) {n = np%MOD;}
    ModuleInt(const ModuleInt& bi) {n = bi.n;}
    ModuleInt& operator += (ModuleInt a) {
    	(n += a.n) %= MOD;
    	return *this;
    }
    ModuleInt operator + ( ModuleInt b) {
    ModuleInt c;
	c.n = (n + b.n) % MOD;
	return c;
    }
    ModuleInt& operator -= (ModuleInt a) {
    	if(n < a.n) {
	    n += MOD;
    	}
    	n -= a.n;
    	n %= MOD;
	return *this;
    }
    ModuleInt operator - (ModuleInt b) {
    ModuleInt c;
	c.n = (n + MOD - b.n) % MOD;
	return c;
    }
    ModuleInt& operator *= (ModuleInt a) {
    	(n *= a.n) %= MOD;
    	return *this;
    }
    ModuleInt operator * (ModuleInt b) {
    ModuleInt c;
	c = (n * b.n) % MOD;
	return c;
    }
    ModuleInt& operator /= (ModuleInt a) {
    	(n *= a.inverse()) %= MOD;
    	return *this;
    }
    ModuleInt operator / (ModuleInt b) {
    ModuleInt c;
    	c = (n * (b.inverse().n)) % MOD;
    return c;
    }
    ModuleInt& operator >>= (int m) {
    	n>>=m;
    	return *this;
    }
    bool operator == (ModuleInt b) {
	return n == b.n;
    }
    bool operator != (ModuleInt b) {
	return n != b.n;
    }
    operator big_int_t() const {
    	return n;
    }
    ModuleInt inverse () {
    	big_int_t  a = n;
	ModuleInt res;
/*    "inverse" borrowed from http://www.codechef.com/viewsolution/589639 */
	int c, b = MOD, p0 = 1, p1 = 0;
	while(b) {
	    c = p0 - p1 * (a / b); p0 = p1;	p1 = c;
	    c = b; b = a % b;
	    a = c;
	}
	if ( p0 < 0)
	    return p0 + MOD;
	res.n =  p0;
	return res;
    }
     friend istream& operator >> (istream&s, ModuleInt& a) {
	s >> a.n;
	return s;
    }
};
// sin(phi0) = sqrt(1 - cos(phi0)**2) = sqrt(_1_cos_phi0) = _ir
// complex = R_ * cos(pi) + R_ * sin(phi) * i
// c_a = a_ * cos(phi_a) + a_ * sin(phi_a) * i
// c_b = b_ * cos(phi_b) + b_ * sin(phi_b) * i
// c_c = c_a * c_b =  a_ * b_ * ((cos(phi_a) * cos(phi_b) - sin(phi_a) * sin(phi_b)) +
//			i * (cos(phi_a) * sin(phi_b) + sin(phi_a) * cos(phi_b)))
// complex_ = real_part + image_part_coef * _ir * i 
// complex_a = real_part_a + image_part_coef_a * _ir * i 
// complex_b = real_part_b + image_part_coef_b * _ir * i 
// complex_ab = real_part_a * real_part_b - image_part_coef_a * image_part_coef_b * _ir ** 2  +
// + i * (real_part_a * image_part_coef_b + image_part_coef_a * real_part_b) * _ir 
// real_part_ab = real_part_a * real_part_b - image_part_coef_a * image_part_coef_b * (1-cos(phi0)**2)
// image_part_coeff_ab = real_part_a * image_part_coef_b + image_part_coef_a * real_part_b

typedef ModuleInt<MOD_> ModuleInt_;
template <class BigInt=ModuleInt_>
class complex_ {
    static int r;	// (1-cos(phi0)**2)
    BigInt real_part;
    BigInt image_part_coef;
    public:
    	static void set_r(int r_) { r = r_; }
    	complex_():real_part(0), image_part_coef(0) {}
	complex_(BigInt a, BigInt b):real_part(a), image_part_coef(b) {}
    	int Real() { return real_part; }
	complex_& operator *= (const complex_& a) {
	    complex_ res;
	    BigInt real_part = this-> real_part * a.real_part - this -> image_part_coef * a.image_part_coef * BigInt(r);
	    BigInt image_part_coef =  this -> real_part * a.image_part_coef + this -> image_part_coef * a.real_part;
	    this -> real_part = real_part;
	    this -> image_part_coef = image_part_coef;
	    return *this;
	}
	complex_ operator * (const complex_& a) {
	    complex_ res;
	    res.real_part = this-> real_part * a.real_part - this -> image_part_coef * a.image_part_coef * BigInt(r);
	    res.image_part_coef =  this -> real_part * a.image_part_coef + this -> image_part_coef * a.real_part;
	    return res;
	}
};
template <class BigInt>
int complex_<BigInt>::r=0;
template <class BigInt>
complex_<BigInt> power(complex_<BigInt> a,big_int_t n) {
complex_<BigInt> res;
    if (n == 0) return complex_<BigInt>(1,0);
    if (n == 1) return a;

     complex_<BigInt> tmp = power(a, n/2);
     if (n%2 == 0) {
        res =  tmp * tmp;
        return res;
     } else {
        res =  tmp * tmp;
        res *= a;
        return res;
    }
}
int solve(int l, int d, big_int_t t) {
int gcd_ = gcd(l,d);
ModuleInt_ l_ = l / gcd_;
ModuleInt_ d_ = d / gcd_;
ModuleInt_ cos_phi = d_ / l_;
ModuleInt_ sin_phi_2 = ModuleInt_(1) - cos_phi * cos_phi;
complex_<>::set_r(sin_phi_2);
complex_<> z(cos_phi,1);
complex_<> p = power(z, t);
complex_<> res = p * complex_<>(l,0);
return res.Real();
}
