/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.
Input:
The first line of input contains an integer N denoting the number of elements in the stream. Then the next N lines contains integer x denoting the number to be inserted into the stream.
Output:
For each element added to the stream print the floor of the new median in a new line.
 
Constraints:
1 <= N <= 106
1 <= x <= 106
 
Example:
Input:
4
5
15
1 
3
Output:
5
10
5
4
 
Explanation:
Testcase 1:
Flow in stream : 5, 15, 1, 3
5 goes to stream --> median 5 (5)
15 goes to stream --> median 10 (5, 15)
1 goes to stream --> median 5 (5, 15, 1)
3 goes to stream --> median 4 (5, 15, 1, 3)

input:
5
5
10
15
25
55

output:
5
7
10
12
15

input:
2
105
225

output:
105
165

input:
2
1
11

output:
1
6

input:
2
4
8

output:
4
6

hint:
We can use a max heap on left side to represent elements that are less than effective median, and a min heap on right side to
represent elements that are greater than effective median.
After processing an incoming element, the number of elements in heaps differ utmost by 1 element. When both heaps contain same
number of elements, we pick average of heaps root data as effective median. When the heaps are not balanced, we select effective
median from the root of heap containing more elements.


*/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn1(i, n) for (i = 0; i < n; ++i)
#define forn2(i, n) for (i = 1; i <= n; ++i)
#define forr1(i, n) for (i = n; i > 0; --i)
#define forr2(i, n) for (i = n - 1; i >= 0; --i)
#define fori(i, s) for (i = s.begin(); i != s.end(); ++i)

class FindMedian
{
	public:
		void insertHeap(int &);
		double getMedian();
	private:
		double median; //Stores current median
		priority_queue<int> max; //Max heap for lower values
		priority_queue<int, vector<int>, greater<int> > min; //Min heap for greater values
		
		void balanceHeaps(); //Method used by insertHeap
};

void FindMedian::insertHeap(int &x)
{
	if (max.empty())
		max.push(x);
	else if (x > max.top())
		min.push(x);
	else if(min.empty())
	{
		min.push(max.top());
		max.pop();
		max.push(x);
	}
	else
		max.push(x);
	balanceHeaps();
}

void FindMedian::balanceHeaps()
{
	if (abs(max.size() - min.size()) > 1) //Heaps are not balanced
	{
		if (max.size() > min.size())
		{
			min.push(max.top());
			max.pop();
		}
		
		else
		{
			max.push(min.top());
			min.pop();
		}
	}
}

double FindMedian::getMedian()
{
	if ((max.size() + min.size()) % 2 == 0)
	{
		median = (max.top() + min.top());
		median /= 2;
	}
	else
	{
		if (min.empty())
			median = max.top();
		else if (min.size() < max.size())
			median = max.top();
		else
			median = min.top();
	}
	
	return median;
}

int main()
{
// 	ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
	int n, i;
	// cin >> t;
	FindMedian Ans;
	// while(t--){
	cin >> n;
	forn1(i, n)
	{
		int x;
		cin >> x;
		Ans.insertHeap(x);
	
		cout << floor(Ans.getMedian()) << endl;
	}
	// }
	return 0;
}
