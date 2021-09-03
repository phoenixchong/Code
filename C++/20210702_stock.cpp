

/*

3
10 10
8 11 3 10 11 7 7 13 10 15
10 10
15 17 3 10 11 7 7 13 10 15
1 1
10000000

#1 9
#2 7
#3 1

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 100001
#define INF   1e9

int T, N, K;

//int g_nLongestDays;

struct SegTree
{
	pair <int, int> tree[4*MAX_N];
	int size;

	void reset(int n) { fill_n(tree, 4 * n, make_pair(INF, 0)); size = n; }

	void update(int i, int v) { _update(1, size, 1, i, v); }

	pair <int, int> _update(int s, int e, int n, int i, int v)
	{
		if (i<s || i>e)
			return tree[n];

		if (s == e)
			return tree[n] = make_pair(v, v);

		int mid = (s + e) / 2;

		auto p1 = _update(s, mid, n << 1, i, v);
		auto p2 = _update(mid+1, e, ((n << 1) | 1), i, v);

		return{ min(p1.first, p2.first), max(p1.second, p2.second) };
	}

	int query(int l, int r) { auto p = _query(1, size, 1, l, r); return (p.second - p.first); }

	pair <int, int> _query(int s, int e, int n, int l, int r)
	{
		if (r < s || e < l)
			return{ INF, 0 };

		if (l < s && e < r)
			return tree[n];

		int mid = (s + e) / 2;

		auto p1 = _query(s, mid, n << 1, l, r);
		auto p2 = _query(mid + 1, e, ((n << 1) | 1), l, r);

		return{ min(p1.first, p2.first), max(p1.second, p2.second) };

	}

};

SegTree segtree;

int main()
{
	freopen("input_210702.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		//g_nLongestDays = 0;

		cin >> N >> K;

		segtree.reset(N);

		int price;
		int longest_days = 0;
		int from = 1;
		int days = 0;

		for (int i= 1; i <= N; i++)
		{
			cin >> price;
			segtree.update(i, price);

			while (segtree.query(from, i) > K)
			{
				++from;
				--days;
			}

			longest_days = max(longest_days, ++days);
		}

		cout << "#" << tc << " " << longest_days << endl;
	}


	return 0;
}