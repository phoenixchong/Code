/*

5 3 3
5 4
3 5
1 2
4 3
2 1

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int N, A, B;
int g_nOffset;
int g_nData[4 * MAX_N];
int g_nLOG;

void init(int nMax)
{
	int n = 1;
	g_nLOG = 0;

	while (n < nMax)
	{
		g_nLOG++;
		n *= 2;
	}

	g_nOffset = n;

	for (int i = 0; i < g_nOffset*2-1; i++)
		g_nData[i] = 0;
}

void update(int nIndex, int nCnt)
{
	// add offset
	nIndex = nIndex + g_nOffset - 1;
	
	g_nData[nIndex] = nCnt;


	// update parent node
	while (nIndex > 0)
	{
		nIndex = (nIndex - 1) / 2;

		g_nData[nIndex] = g_nData[nIndex*2+1] + g_nData[nIndex*2+2];
	}
}

// [ a ~ b ] include [ nLeft ~ nRight ] --> g_nData[nIndex]
int query(int a, int b, int nIndex, int nLeft, int nRight)
{
	if (nRight <= a || nLeft >= b)
		return 0;

	if (a <= nLeft && nRight <= b)
		return g_nData[nIndex];

	auto p1 = query(a, b, nIndex * 2 + 1, nLeft, (nLeft + nRight) / 2);
	auto p2 = query(a, b, nIndex * 2 + 2, (nLeft + nRight) / 2, nRight);

	return p1 + p2;
}

int main()
{
	freopen("input_210206.txt", "r", stdin);

	cin >> N >> A >> B;

	vector<vector<int>> vProduct(N, vector<int>(2));

	for (int i = 0; i < N; i++)
		cin >> vProduct[i][0] >> vProduct[i][1];

	sort(vProduct.begin(), vProduct.end());

	init(MAX_N);

	int nResult = 0;
	int j = 1;

	int nOffsetPos;
	int nCnt;
	for (int i = 0; i < N - 1; i++)
	{
		// update data
		while (j < N && abs(vProduct[i][0] - vProduct[j][0]) <= A)
		{
			nOffsetPos = vProduct[j][1] + g_nOffset - 1;
			nCnt = g_nData[nOffsetPos] + 1;

			update(vProduct[j][1], nCnt);

			j++;

			if (j == N)
				break;
		}

		// 1 2
		// 2 1
		// 3 5
		// 4 3
		// 5 4

		// query front pos
		if (vProduct[i][1] > B)
			nResult += query(0, vProduct[i][1] - A + 1, 0, 0, g_nOffset);

		// query forward pos
		nResult += query(vProduct[i][1] + A, g_nOffset, 0, 0, g_nOffset);

		// update data [i+1] --> -1
		nOffsetPos = vProduct[i + 1][1] + g_nOffset - 1;
		nCnt = g_nData[nOffsetPos] - 1;

		update(vProduct[i + 1][1], nCnt);
	}

	cout << nResult << endl;

	return 0;
}
