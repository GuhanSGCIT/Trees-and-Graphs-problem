/*
You are given N sets of integers A1,A2,…,AN. For each valid i, let's denote the elements of the set Ai by {ci,1,ci,2,…,ci,|Ai|}.
Find the number of ways to choose a sequence (a1,a2,…,aN) such that:
ai∈Ai for each valid i
ai≠ai+1 for each valid i and a1≠aN

Since this number may be large, compute it modulo 998,244,353.

Input
The first line of the input contains a single integer N.
N lines follow. For each valid i, the i-th of these lines contains an integer |Ai| followed by a space 
and |Ai| space-separated non-negative integers ci,1,ci,2,…,ci,|Ai|.

Output
Print a single line containing one integer ― the number of ways to choose (a1,a2,…,aN) , modulo 998,244,353.

Constraints
2≤N≤200,000
|Ai|≥1 for each valid i
|A1|+|A2|+…+|AN|≤200,000
1≤ci,j≤200000 for each valid i,j

Example Input
3
3 1 2 3
2 1 2
2 2 3

Example Output
3

Explanation
There are three possible sequences: (1,2,3), (2,1,3) and (3,1,2).

input:
2
12 23 24
1 2 3

output:
139

input:
5
2 5 8 5
2 6 9
1 4 7
2 3 6
7 8 9

output:
2688

input:
2
2 5 8
1 2 3

output:
2

input:
4
2 5 8 6
12 24 48
56 69 44
2 4 7

output:
48

hint:
If n ≤ sqrt{m}, then count the number of ways by continously replacing pairs of adjacent sets with their intersection.
If n > sqrt{m}, then there is a pair of adjacent sets with intersection of size at most sqrt{m}.
Break the circle in the position of that pair of sets, and solve it as a line.

*/
c #include<bits / stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
    using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int const INF = (int)1e9 + 1e3;
const int MOD = 998244353;

void add(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int sum(int a, int b)
{
    add(a, b);
    return a;
}

int calc(vector<vector<int>> const &arr)
{
    vector<pii> vars, next;
    for (int num : arr[0])
    {
        vars.push_back({num, 1});
    }
    for (int i = 1; i < szof(arr); ++i)
    {
        int tot = 0;
        for (auto p : vars)
        {
            add(tot, p.ss);
        }
        next.clear();
        int pos = 0;
        for (int num : arr[i])
        {
            while (pos < szof(vars) && vars[pos].ff < num)
            {
                ++pos;
            }
            int cur = tot;
            if (pos < szof(vars) && vars[pos].ff == num)
            {
                add(cur, MOD - vars[pos].ss);
            }
            next.push_back({num, cur});
        }
        swap(next, vars);
    }

    int ret = 0;
    for (auto p : vars)
    {
        add(ret, p.ss);
    }

    return ret;
}

vector<int> intersection(vector<int> const &a, vector<int> const &b)
{
    vector<int> ret(szof(a));
    ret.erase(set_intersection(a.begin(), a.end(), b.begin(), b.end(), ret.begin()), ret.end());
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> arr;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        arr.push_back({});
        for (int j = 0; j < k; ++j)
        {
            int num;
            cin >> num;
            --num;
            arr[i].push_back(num);
        }
        sort(arr[i].begin(), arr[i].end());
    }

    const int Q = 448;
    if (n <= Q)
    {
        int ans = 0;
        bool sign = false;
        while (szof(arr) > 1)
        {
            int cur = calc(arr);
            if (sign)
            {
                cur = MOD - cur;
            }
            add(ans, cur);

            arr[0] = intersection(arr[0], arr.back());
            arr.pop_back();

            sign ^= 1;
        }

        cout << ans << "\n";
    }
    else
    {
        int best = INF;
        int mem = -1;
        for (int i = 0; i < n; ++i)
        {
            int prev = (i + n - 1) % n;
            auto tmp = intersection(arr[i], arr[prev]);
            if (szof(tmp) < best)
            {
                best = szof(tmp);
                mem = i;
            }
        }

        rotate(arr.begin(), arr.begin() + mem, arr.end());

        int ans = calc(arr);
        auto intr = intersection(arr.front(), arr.back());
        for (int val : intr)
        {
            arr.front().clear();
            arr.front().push_back(val);
            arr.back().clear();
            arr.back().push_back(val);
            add(ans, MOD - calc(arr));
        }

        cout << ans << "\n";
    }
}