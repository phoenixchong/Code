/*

4
7 2
-6 -4 -6 4 -4 -2 9
7 3
-6 -4 -6 4 -4 -2 9
4 2
10000 10000 10000 10000
1 1
-1

#1 1
#2 7
#3 40000
#4 -1

   // DP accumulated

   DP(1) = vBrdidge(1)
   DP(2) = DP(1) + vBrdidge(1)
   DP(3) = Max( DP(2), DP(1)...DP(3-K) ) + vBrdidge(3)
   ...
   DP(N) = Max( DP(N-1), DP(N-2), DP(N-k) ) + vBrdidge(N)

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PII pair <int, int>

int T, N, K;

typedef long long ll;
const ll g_INF = 987654321987654321;

class SegTree
{
private:
	vector <ll> m_vTree;
	int m_nDataCnt;

	ll init_sub(vector <ll>& vDP, int nCurIndex, PII& pairRange)
	{
		if (pairRange.first == pairRange.second)
			m_vTree[nCurIndex] = vDP[pairRange.second];
		else
		{
			int nMid = (pairRange.first + pairRange.second) / 2;

			ll llLeft  = init_sub(vDP, 2 * nCurIndex,     PII(pairRange.first, nMid));
			ll llRight = init_sub(vDP, 2 * nCurIndex + 1, PII(nMid+1, pairRange.second));

			m_vTree[nCurIndex] = max(llLeft, llRight);
		}

		return m_vTree[nCurIndex];
	}

	ll update_sub(int nPos, ll llValue, int nCurIndex, PII& pairRange)
	{
		if (pairRange.first <= nPos && nPos <= pairRange.second)
		{
			if (pairRange.first == pairRange.second)
				m_vTree[nCurIndex] = llValue;
			else
			{
				int nMid = (pairRange.first + pairRange.second) / 2;

				ll llLeft  = update_sub(nPos, llValue, 2 * nCurIndex,     PII(pairRange.first, nMid));
				ll llRight = update_sub(nPos, llValue, 2 * nCurIndex + 1, PII(nMid + 1, pairRange.second));

				m_vTree[nCurIndex] = max(llLeft, llRight);
			}
		}
		return m_vTree[nCurIndex];
	}

	ll getIntervalVal_sub(PII& pairRangeTarget, int nCurIndex, PII& pairRange)
	{
		if (pairRange.second < pairRangeTarget.first || pairRangeTarget.second < pairRange.first)
			return -g_INF;

		if (pairRangeTarget.first <= pairRange.first && pairRange.second <= pairRangeTarget.second)
			return m_vTree[nCurIndex];

		//if (pairRange.first == pairRange.second)
			//return m_vTree[nCurIndex];
		//else
		//{
			int nMid = (pairRange.first + pairRange.second) / 2;

			ll llLeft = getIntervalVal_sub(pairRangeTarget, 2 * nCurIndex, PII(pairRange.first, nMid));
			ll llRight = getIntervalVal_sub(pairRangeTarget, 2 * nCurIndex + 1, PII(nMid + 1, pairRange.second));

			//m_vTree[nCurIndex] = max(llLeft, llRight);

			return max(llLeft, llRight);
		//}
	}

public:
	ll init(vector <ll>& vDP)
	{
		m_nDataCnt = vDP.size();

		m_vTree.resize(4 * m_nDataCnt, -g_INF);

		return init_sub(vDP, 1, PII(0, m_nDataCnt - 1));
	}

	ll update(int nPos, ll llValue)
	{
		return update_sub(nPos, llValue, 1, PII(0, m_nDataCnt - 1));
	}

	ll getIntervalValue(PII& pairRangeTarget)
	{
		return getIntervalVal_sub(pairRangeTarget, 1, PII(0, m_nDataCnt - 1));
	}
};

ll solve(vector <int>& vBridge, int K)
{
	int N = vBridge.size();

	vector <ll> vDP(N, -g_INF);

	vDP[0] = vBridge[0];

	SegTree segTree;
	segTree.init(vDP);


	// DP(1) = vBrdidge(1)
	// DP(2) = DP(1) + vBrdidge(2)
	// DP(3) = Max(DP(2), DP(1)...DP(3 - K)) + vBrdidge(3)
	// ...
	// DP(N) = Max(DP(N - 1), DP(N - 2), DP(N - k)) + vBrdidge(N)

	for (int i = 1; i < N; i++)
	{
		ll llTemp = segTree.getIntervalValue(PII(i - K, i - 1));
		vDP[i] = llTemp + vBridge[i];
		segTree.update(i, vDP[i]);
	}

	return vDP[N - 1];
}

int main()
{
	freopen("input_210827.txt", "r", stdin);

	cin >> T;

	ll llResult;

	for (int tc = 1; tc <= T; tc++)
	{
		llResult = 0;

		cin >> N >> K;

		vector <int> vBridge;

		int nValue;
		for (int i = 0; i < N; i++)
		{
			cin >> nValue;
			vBridge.emplace_back(nValue);
		}

		llResult = solve(vBridge, K);

		cout << "#" << tc << " " << llResult << endl;
	}

	return 0;
}