/*
Fluffy the squirrel is reading a book. The page numbers of the current pages that Fluffy is reading are two consecutive numbers, for example pages 8 and 9, pages 2015 and 2016 are both possible pages that Fluffy is reading. The naughty bird Flippy has erased some of the digits from the page numbers, which made Fluffy mad because he can't know which page he's currently on. Thus, he wonders what the possible page numbers of the two pages are. You're given the two numbers (note that they are consecutive, since they are two neighbouring pages), with some of its digits replaced with a question mark ('?'). Your task is to figure out all possibilities that the page numbers could've been.
Note : The page numbers are positive, i.e. they are strictly larger than 0.

 timing:4sec
 level:7
 
Input
The input consists of two lines. Both lines contain a string of digits, where some of its digits are replaced with '?'.
The first line contains the smaller page number while the second one contains the larger page number.
It is guaranteed that there are no leading zeroes (there can be leading question marks though), and both strings have equal length.

Output
First, output a single integer, n, denoting the number of possible page numbers. Next, print n lines. On each line, print two space-seperated integers, denoting a pair of integers that might have been the page numbers. The first integer must be smaller than the second integer. Both integers must not have leading zeroes and must match the string of digits. (the '?' can be any digit from 0 to 9) Moreover, you should print the possible answers in increasing order, i.e. the first number of an earlier pair must be smaller than the first number of a later pair. See the sample for more details.

Constraints
The number has at most 5 digits.

Input:
??3
?24

Output:
9
123 124
223 224
323 324
423 424
523 524
623 624
723 724
823 824
923 924

 
Explanation
Example case 1. Indeed, there are only 9 possible pairs of numbers that match the given strings. Note that (023, 024) is invalid since leading zeroes are not allowed. Also note that the answers are printed in increasing order.

input:
?23
?2?

output:
9
123 124
223 224
323 324
423 424
523 524
623 624
723 724
823 824
923 924

input:
?1
1?

output:
1
11 12

input:
??8
?4?

output:
9
148 149
248 249
348 349
448 449
548 549
648 649
748 749
848 849
948 949

input:
?2
?3

output:
9
12 13
22 23
32 33
42 43
52 53
62 63
72 73
82 83
92 93

hint:
Since the given constraints is small, it is possible to iterate through all possible numbers with the given number of digits. It remains to have a function that checks whether each number matches a string of digits.


*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int power[6] = {1, 10, 100, 1000, 10000, 100000};
vector<ii> ans;

bool check(int x, string a)
{
	int pos = int(a.length()) - 1;
	while(x)
	{
		int dig = x%10;
		if(a[pos]!='?'&&a[pos]!=char(dig+'0')) return false;
		x/=10;
		pos--;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string a, b;
	cin>>a>>b;
	int n = a.length();
	for(int i = power[n-1]; i + 1 < power[n]; i++)
	{
		//cerr<<i<<' '<<check(i,a)<<' '<<check(i+1,b)<<'\n';
		if(check(i, a)&&check(i+1, b))
		{
			ans.pb(mp(i, i+1));
		}
	}
	cout<<ans.size()<<'\n';
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].fi << ' ' << ans[i].se << '\n';
	}
}
