
//
// 2021. 05. 29 subway
//
// Initialize (�밢�� 0, 2�̻� 1�� setting)
// Floyd Washall
// �����, ������ Transit ����ŭ Loop
//

/*

// input
//
1
24 5 4
4 1 14 20 8
10 6 20 13 9 2 11 22 21 7 19
4 11 3 18 16
6 12 4 18 23 5 15
4 17 15 10 24
14 10
21 16
18 1
15 11

// output
//
#1 8

*/

/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define MAX_LINE 301
#define MAX_N 100001

int T, N, M, Q;

int g_nMinTransit;
int g_nTransit[MAX_N];
int g_nMatrix[MAX_LINE][MAX_LINE];
int g_nSubway[MAX_LINE][11];

int main()
{
	freopen("input_210529.txt", "r", stdin);

	int a, b;
	int nStart, nEnd;

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		g_nMinTransit = 0;

		cin >> N >> M >> Q;

		// Line
		for (int i = 1; i <= M; i++)
		{
			// #
			cin >> a;
			for (int j = 0; j < a; j++)
			{
				// Station
				cin >> b;
				g_nSubway[b][g_nTransit[b]] = i;
				g_nTransit[b]++;
			}
		}

		// matrix step 1 - �밢�� 0
		for (int i = 1; i <= M; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (i == j)
					g_nMatrix[i][j] = 0;
				else
					g_nMatrix[i][j] = INF;
			}
		}

		// g_nTransit ���� 2 �̻��̸� 1�� setting
		for (int i = 1; i <= N; i++)
		{
			if (g_nTransit[i] > 1)
			{
				for (int j = 1; j < g_nTransit[i]; j++)
				{
					g_nMatrix[g_nSubway[i][0]][g_nSubway[i][j]] = 1;
					g_nMatrix[g_nSubway[i][j]][g_nSubway[i][0]] = 1;
				}
			}
		}

		// ����
		for (int j = 1; j <= M; j++)
		{
			// ���
			for (int i = 1; i <= M; i++)
			{
				// ����
				for (int k = 1; k <= M; k++)
				{
					if (i == k)
						continue;

					if (g_nMatrix[i][k] > (g_nMatrix[i][j] + g_nMatrix[j][k]))
						g_nMatrix[i][k] = (g_nMatrix[i][j] + g_nMatrix[j][k]);
				}
			}
		}

		int nMinTransit;
		for (int i = 0; i < Q; i++)
		{
			cin >> nStart >> nEnd;

			nMinTransit = INF;

			for (int j = 0; j < g_nTransit[nStart]; j++)
			{
				for (int k = 0; k < g_nTransit[nEnd]; k++)
				{
					if (nMinTransit > g_nMatrix[g_nSubway[nStart][j]][g_nSubway[nEnd][k]])
						nMinTransit = g_nMatrix[g_nSubway[nStart][j]][g_nSubway[nEnd][k]];
				}
			}

			g_nMinTransit += nMinTransit;
		}

		cout << "#" << tc << " " << g_nMinTransit << endl;
	}

	return 0;
}

*/