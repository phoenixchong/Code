/*

#include <iostream>
//#include <vector>
#include <map>
#include <algorithm>

#define PII   pair<int,int>

#define MAX_VALUE  100001
#define INF    1e9

using namespace std;

PII segTree[MAX_VALUE];

// node - node 번호, start - end : node 구간, index : update 위치, value : update할 숫자
PII Update(int node, int start, int end, int index, int value)
{
	// index bound check - return prev segTree value
	if (index < start || index > end)
		return segTree[node];

	// start == end check - return new value
	if (start == end)
		return segTree[node] = { value, value };

	int mid = (start + end) / 2;

	// child node update
	auto v1 = Update(node * 2, start, mid, index, value);
	auto v2 = Update(node * 2 + 1, mid + 1, end, index, value);

	return segTree[node] = { min(v1.first, v2.first), max(v1.second, v2.second) };
}

PII GetRangeMinMax(int node, int start, int end, int left, int right)
{
	if (start > right || end < left)
		return{ INF, 0 };

	if (left <= start && end <= right)
		return segTree[node];

	int mid = (start + end) / 2;

	auto v1 = GetRangeMinMax(node * 2, start, mid, left, right);
	auto v2 = GetRangeMinMax(node * 2 + 1, mid + 1, end, left, right);

	return{ min(v1.first, v2.first), max(v1.second, v2.second) };
}

int main()
{
	//freopen("input.txt", "r", stdin);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N, K; // N - 입력 갯수, K - 차이 값
		cin >> N >> K;

		// segment tree 초기화 * 4 ???
		fill(segTree, segTree + MAX_VALUE, make_pair(0, 0));

		// 입력값, Index
		map<int, int> mapCounting;  // 입력된 값의 숫자와 index를 저장

		int nMinLength = INF;
		int nMinCount = 0;

		for (int index = 1; index <= N; index++)
		{
			int nCurValue;
			cin >> nCurValue;

			// update ???
			Update(1, 1, N, index, nCurValue);


			mapCounting[nCurValue] = index;

			int nTargetValue[2];
			nTargetValue[0] = nCurValue - K;
			nTargetValue[1] = nCurValue + K;

			// 입력 받은 숫자 nCurVal과 차이가 K가 되는 값이 이미 입력된 값에 존재 했는지 여부를 확인하고
			// 두 값 사이의 구간에 입력값과 대상값보다 큰값이나 작은 값이 없으면 정답을 갱신한다.
			for (int t = 0; t < 2; t++)
			{
				if (mapCounting.find(nTargetValue[t]) != mapCounting.end()) // 차이가 K 값이 값을 찾았으면..
				{
					int nTargetIndex = mapCounting[nTargetValue[t]];
					int length = index - nTargetIndex + 1;
					if (length <= nMinLength)
					{
						bool bIsValid = (length == 2);
						if (!bIsValid)
						{
							PII minMaxVal = GetRangeMinMax(1, 1, N, nTargetIndex + 1, index - 1);

							// -K 
							if (t == 0)
							{
								// 중간에 min.max가 없으면
								if (minMaxVal.first > nTargetValue[t] && minMaxVal.second < nCurValue)
									bIsValid = true;
							}
							// +K
							else
							{
								// 중간에 min. max가 없으면
								if (minMaxVal.first > nCurValue && minMaxVal.second < nTargetValue[t])
									bIsValid = true;
							}
						}

						if (bIsValid)
						{
							if (length < nMinLength)
							{
								nMinLength = length;
								nMinCount = 1;
							}
							// =
							else
							{
								nMinCount++;
							}
						}
					}
				}
			}
		}

		if (nMinLength == INF)
			cout << "#" << tc << " -1\n";
		else
			cout << "#" << tc << " " << nMinLength << " " << nMinCount << "\n";

	}
	
	return 0;
}


*/