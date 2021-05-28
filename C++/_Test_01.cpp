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

// node - node ��ȣ, start - end : node ����, index : update ��ġ, value : update�� ����
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
		int N, K; // N - �Է� ����, K - ���� ��
		cin >> N >> K;

		// segment tree �ʱ�ȭ * 4 ???
		fill(segTree, segTree + MAX_VALUE, make_pair(0, 0));

		// �Է°�, Index
		map<int, int> mapCounting;  // �Էµ� ���� ���ڿ� index�� ����

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

			// �Է� ���� ���� nCurVal�� ���̰� K�� �Ǵ� ���� �̹� �Էµ� ���� ���� �ߴ��� ���θ� Ȯ���ϰ�
			// �� �� ������ ������ �Է°��� ��󰪺��� ū���̳� ���� ���� ������ ������ �����Ѵ�.
			for (int t = 0; t < 2; t++)
			{
				if (mapCounting.find(nTargetValue[t]) != mapCounting.end()) // ���̰� K ���� ���� ã������..
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
								// �߰��� min.max�� ������
								if (minMaxVal.first > nTargetValue[t] && minMaxVal.second < nCurValue)
									bIsValid = true;
							}
							// +K
							else
							{
								// �߰��� min. max�� ������
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