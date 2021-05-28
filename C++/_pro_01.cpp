

/*

1
10 10
1 7 9 11 3 15 13 14 5 2

4 2

*/

/*

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define PII pair<int,int>
#define MAX 100001
#define INF 1e9

using namespace std;

PII segTree[MAX];

PII update(int node, int start, int end, int index, int value)
{
	if (index < start || index > end)
		return segTree[node];

	if (start == end)
		return segTree[node] = { value, value };

	int mid = (start + end) / 2;

	auto v1 = update(node * 2, start, mid, index, value);
	auto v2 = update(node * 2 + 1, mid + 1, end, index, value);

	return segTree[node] = { min(v1.first, v2.first), max(v1.second, v2.second) };
}

PII getRangeMinMax(int node, int start, int end, int left, int right)
{
	if (right < start || left > end)
		return{ INF, 0 };

	if (left <= start && end <= right)
		return segTree[node];

	int mid = (start + end) / 2;

	auto v1 = getRangeMinMax(node * 2, start, mid, left, right);
	auto v2 = getRangeMinMax(node * 2 + 1, mid + 1, end, left, right);

	return segTree[node] = { min(v1.first, v2.first), max(v1.second, v2.second) };
}

int main()
{
	int N, K;
	cin >> N >> K;

	fill(segTree, segTree + MAX, make_pair(0, 0));
	map<int, int> mapCount;

	int nMin = INF;
	int nMinCount = 0;

	for (int index = 1; index <= N; index++)
	{
		int nCurValue;
		cin >> nCurValue;

		update(1, 1, N, index, nCurValue);

		mapCount[nCurValue] = index;

		int nTargetValue[2];

		nTargetValue[0] = nCurValue - K;
		nTargetValue[1] = nCurValue + K;

		for (int t = 0; t < 2; t++)
		{
			if (mapCount.find(nTargetValue[t]) != mapCount.end())
			{
				int nTargetIndex = mapCount[nTargetValue[t]];
				int nLength = index - nTargetIndex + 1;

				if (nLength < nMin)
					nMin = nLength;

				bool bValid = (nLength == 2);

				if (!bValid)
				{
					PII MinMax = getRangeMinMax(1, 1, N, nTargetIndex + 1, index - 1);

					// - K
					if (t == 0)
					{
						if (MinMax.first > nTargetValue[t] && MinMax.second < nCurValue)
							bValid = true;
					}
					// + K
					else
					{ 
						if (MinMax.first > nCurValue && MinMax.second < nTargetValue[t])
							bValid = true;
					}
				}

				if (bValid)
				{
					if (nMin != nLength)
					{
						nMin = nLength;
						nMinCount = 1;
					}
					else
					{
						nMinCount++;
					}
				}
			}
		}
	}

	cout << "#1 " << nMin << " " << nMinCount << endl;

	return 0;
}

*/