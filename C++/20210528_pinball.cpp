
//
// 2021. 05. 28 pinball game
//
// DFS(nStart, nDepth)
// setParent()
// LCA(nA, nB)
//

/*

// input 
//
1
8 5
5 2 6 1 3 3 8 5
0 1 1 3 3 2 4 4
4 5
6 7
3 5
7 2
6 3

// ouput
//
#1 42 39

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

// clock
#include <time.h>

using namespace std;

#define MAX_N 100001
#define MAX_DEPTH 17 // 2^17 > 100,000

const int INF = (int)1e9;

int T, N, Q;

int g_nParent[MAX_N][MAX_DEPTH];

int g_nCheck[MAX_N];
int g_nDepth[MAX_N];

long long g_llSum[MAX_N];
long long g_llMySum;
long long g_llLiaSum;

vector <int> g_vnEdge[MAX_N];
vector <int> g_vnPinHoleGrade;

void DFS(int nStart, int nDepth)
{
	g_nCheck[nStart] = true;

	g_nDepth[nStart] = nDepth;

	int nNext;
	for (int i = 0; i < (int)g_vnEdge[nStart].size(); i++)
	{
		nNext = g_vnEdge[nStart][i];

		if (g_nCheck[nNext])
			continue;

		g_llSum[nNext] = g_llSum[nStart] + g_vnPinHoleGrade[nNext];

		g_nParent[nNext][0] = nStart;

		DFS(nNext, nDepth + 1);
	}
}

void setParent()
{
	g_llSum[1] = g_vnPinHoleGrade[1];

	DFS(1, 0);

	for (int j = 1; j < MAX_DEPTH; j++)
	{
		for (int i = 1; i <= N; i++)
		{
			g_nParent[i][j] = g_nParent[g_nParent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int nA, int nB)
{
	if (g_nDepth[nA] > g_nDepth[nB])
		swap(nA, nB);

	for (int i = MAX_DEPTH - 1; i >= 0; i--)
	{
		if ((g_nDepth[nB] - g_nDepth[nA]) >= (1 << i))
			nB = g_nParent[nB][i];
	}

	if (nA == nB)
		return nA;

	for (int i = MAX_DEPTH - 1; i >= 0; i--)
	{
		if (g_nParent[nA][i] != g_nParent[nB][i])
		{
			nA = g_nParent[nA][i];
			nB = g_nParent[nB][i];
		}
	}

	return g_nParent[nA][0];
}

int main()
{
	freopen("input_210528.txt", "r", stdin);

	//clock
	clock_t nStart, nEnd;

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		// clock
		nStart = clock();

		g_llMySum = 0;
		g_llLiaSum = 0;

		cin >> N >> Q;

		g_vnPinHoleGrade.resize(N + 1, 0);
		for (int i = 1; i <= N; i++)
			cin >> g_vnPinHoleGrade[i];

		
		//for (int i = 0; i <= N; i++)
		//{
		//	vector <int> vnTemp;
		//	g_vnEdge.emplace_back(vnTemp);
		//}

		int a;
		for (int i = 1; i <= N; i++)
		{
			cin >> a;
			g_vnEdge[a].push_back(i);
		}

		setParent();

		int nMyPos, nLiaPos;
		int nResultNode;
		for (int i = 0; i < Q; i++)
		{
			cin >> nMyPos >> nLiaPos;

			nResultNode = LCA(nMyPos, nLiaPos);

			g_llMySum  += g_llSum[nMyPos];
			g_llLiaSum += g_llSum[nLiaPos];

			if (g_nDepth[nMyPos] == g_nDepth[nLiaPos])
			{
				g_llMySum  -= g_llSum[nResultNode];
				g_llLiaSum -= g_llSum[nResultNode];
			}
			else if (g_nDepth[nMyPos] > g_nDepth[nLiaPos])
			{
				g_llMySum -= g_llSum[nResultNode];
			}
			else 
			{
				g_llLiaSum -= g_llSum[nResultNode];
			}
		}

		// clock
		nEnd = clock();
		
		// millisecond
		clock_t nElapsed = nEnd - nStart;

		cout << "elapsed time : " << nElapsed << " [msec]" << endl;


		cout << "#" << tc << " " << g_llMySum << " " << g_llLiaSum << endl;
	}

	return 0;
}
