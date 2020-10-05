/*
Alexandra has some distinct integer numbers a1,a2...an. Count number of pairs (i,j).

 
Input
The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.The first line of each test case contains a single integer n denoting the number of numbers Alexandra has. The second line contains n space-separated distinct integers a1, a2, ..., an denoting these numbers.

 
Output
For each test case, output a single line containing number of pairs for corresponding test case.

 
Constraints
    1 ≤ T ≤ 4
    1 ≤ n ≤ 100000
    0 ≤ ai ≤ 109
    All the ai are distinct 

 
Example
2
2
2 1
3
3 1 2

Output:
1
3

 
Explanation
Case 1: Only one such pair: (2,1)
Case 2: 3 possible pairs: (2,1), (2,3), (3,1)

input:
4
3
3 3 2
5
4 5 2 1 5
4
5 2 4 3 1
2
12 21

output:
3
10
6
1

input:
1
8
4 5 2 1 8 3 7 8

output:
28

input:
2
5
4 5 2 2 7
3
2 5 8

output:
10
3

input:
1
6
5 4 3 2 6 7


output:
15

hint:
The problem describes that all integers are distinct. Therefore any two integers, say (ai, aj), will satisfy the property ai < aj or aj < ai. Two integers can be picked up in NC2 ways. So the answer is simply N*(N-1)/2.

*/
#define INCLUDE_ALL
#include <bits/stdc++.h>
//#include "stdafx.h"
using namespace std;
#if defined DEBUGGG
#include "first.hpp"
using namespace mydetails;
#include "printers.hpp"
using namespace printers;
#endif
typedef long long ll;

template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value> scan(T& x)
  {
    char c = getchar_unlocked();
    x = 0;
    bool minus = false;
    for(; (c < 48) || (c > 57); c = getchar_unlocked())
    if(c == '-')
      minus = true;
    for(; (c > 47) && (c < 58); c = getchar_unlocked())
      x = (T)(((x << 1) + (x << 3)) + c - 48);
    if(minus)
      x *= -1;
  }

  template<typename T>
  inline std::enable_if_t<std::is_integral<T>::value, T> scan()
  {
    T _x;
    scan(_x);
    return _x;
  }

  template<typename T, typename...Tmnciitbhu>
  inline std::enable_if_t<std::is_integral<T>::value, T>
  scan(T& val, Tmnciitbhu&... mnciitbhu)
  {
    scan(val);
    scan(mnciitbhu...);
  }

int main()
{
#if defined DEBUGGG
  freopen("input.txt", "r", stdin);
#endif
  int t = scan<int>();
  while(t--)
  {
    ll n = scan<ll>();
    cout << (n * (n - 1)) / 2 << '\n';
    while(n--) scan<ll>();
  }

  return 0;
}
