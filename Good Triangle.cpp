/*
Given N points on a 2D plane and an integer K, choose 3 distinct points so that the area of the triangle whose vertices
are the chosen points does not exceed K/2. If there are multiple such triangles, among all possible triangles choose the
one which has maximum area.

timing:4.5sec
level:8
tags:geometry, binary serach

Input:
First line contains two integers N and K.
Each of the next N lines contains two integers Xi and Yi, denoting the coordinates of the i-th point.

Output:
Output a single integer, the maximum area of a triangle which does not exceed K/2, multiplied by 2.
If there's no valid triangle output -1 instead.

Constraints
    3 ≤ N ≤ 3000
    1 ≤ K ≤ 1018
    1 ≤ Xi,Yi ≤ 109
    No two points will have same coordinates
    No three points will be collinear

 
Input:
4 7
1 1
5 1
3 3
3 2

Output:
4

Input:
3 7
1 1
4 1
1 4

Output:
-1

Input:
7 1234567890123
1234567 7654321
1111111 2222222
1212121 2323232
3333333 1122334
9292929 2929292
1234456 5654645
5435733 2342134


Output:
755024295480

Explanation
Example case 1. There are 4 triangles in total, and their areas are: 1, 1, 2 and 4. The ones which does not exceed 7/2 are 1, 1 and 2 so the biggest area is 2, and since we are required to multiply the area by 2 before outputting it, it becomes 4.
Example case 2. The only triangle has an area equal to 9/2, which is more than 7/2. So the answer is -1.

Input:
5 4656185
1515 1356
1212 1221
4541 5651
6656 5684
6554 9789

ouput:
3875753

input:
7 8
1 5
7 9
6 3
2 8
4 9
5 6
2 2

output:
7

hint:
We iterate over the slopes in sorted order w.r.t their slope. We maintain the list LLL of points sorted
w.r.t their height from the slope. For each slope, we do two binary searches to find the maximum area triangle
with area less than or equal to K/2K/2K/2, and also update the list LLL by making one swap.

There are total O(n2)\mathcal{O}(n^2)O(n2) slopes and for each slope we do two binary search operations in
O(logn)\mathcal{O}(log n)O(logn) time. Thus the total time complexity will be O(n2 logn)\mathcal{O}(n^2 \, log n)O(n2logn).

*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;
typedef ll T;
struct pt {
	T x,y;
	int i;
	pt operator+(pt p) {return {x+p.x, y+p.y};}
	pt operator-(pt p) {return {x-p.x, y-p.y};}
	pt operator*(T d) {return {x*d, y*d};}
	pt operator/(T d) {return {x/d, y/d};} // only for floatingpoint
	
	bool operator == (pt a) {return x == a.x && y == a.y;}
	bool operator != (pt a) {return (x != a.x || y != a.y);}

};
T sq(pt p) {return p.x*p.x + p.y*p.y;}
double abs(pt p) {return sqrt(sq(p));}

T dot(pt v, pt w) {return v.x*w.x + v.y*w.y;}
T cross(pt v, pt w) {return v.x*w.y - v.y*w.x;}
T orient(pt a, pt b, pt c) {return cross(b-a,c-a);}


struct line {
	pt v; T c;
	int i, j;
	// From direction vector v and offset c
	line(pt v, T c) : v(v), c(c) {}
	// From equation ax+by=c
	line(T a, T b, T c) : v({b,-a}), c(c) {}
	// From points P and Q
	line(pt p, pt q) : v(q-p), c(cross(v,p)) {}
	T side(pt p) {return cross(v,p)-c;}
	// - these work with T = int
	
	// positive if in the left side and negative if in the right side
	double dist(pt p) {return side(p) / abs(v);}
};


const int N = 3010;
vector<line> v;
pt p[N];
int pos[N];
int t = 0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	ll k;
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
		p[i].i = i;
	}

	for(int i = 1; i < n; i++){
		for(int j = 0; j < i; j++){
			v.push_back(line(p[i], p[j]));
			if(v[t].v.y < 0 || v[t].v.y == 0 && v[t].v.x < 0) v[t].v = v[t].v * (-1), v[t].c *= -1;
			
			v[t].i = j; v[t].j = i;
			t++;
		}
	}

	sort(v.begin(), v.end(), [](line v, line w) {
		return 0 < cross(v.v, w.v);
	});

	sort(p, p+n, [](pt a, pt b) {
		//return a.y < b.y || (a.y == b.y && a.x < b.x);
		return v[0].dist(a) + (a.x > b.x)*1e-8 + (a.y > b.y)*1e-10 < v[0].dist(b) + (a.x < b.x)*1e-8 + (a.y < b.y)*1e-10;	
	});

	for(int i = 0; i < n; i++)
		pos[p[i].i] = i;

	ll ans = -1;
	for(auto &u : v){
		
		int pos1 = pos[u.i], pos2 = pos[u.j];
		if(pos1 > pos2) swap(pos1, pos2);

		int v_l[] = {pos1, pos2+1};
		int v_r[] = {-1, n};
		for(int o = 0; o < 2; o++){
			int l = v_l[o], r = v_r[o];
			int flag = -1 + 2 *o;
			while((r - l)*flag > 1){
				int mid = (r + l) >> 1;
				//cout << pos1 << " " << pos2 << " " << mid << endl;
				ll A = abs(orient(p[mid], p[pos1], p[pos2] ));
				if(A <= k){
					l = mid;
					ans = max(ans, A);
				}
				else r = mid;
			}
		}
		swap(p[pos1], p[pos2]);
		swap(pos[u.i], pos[u.j]);
	}
	cout << ans << "\n";

	return 0;
}
