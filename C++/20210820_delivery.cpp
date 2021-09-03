
//
// 2021. 08. 20
//
// floyd washall
// DFS
//

/*

// input
// 

1
9 10 4
2 6 8
1 2 2
1 5 4
2 3 10
2 4 7
8 2 3
8 4 2
4 6 3
4 7 9
6 9 5
9 7 7
1 2
4 6
5 6
3 2


// output
//

#1 35

*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9
#define MAX_N 301

int T, N, M, Q;

int g_nMinDist;

int g_nStart;
int g_nFood[2];
int g_nVisit[MAX_N];

vector <vector<int>> g_vnEdge;
vector <int> g_vnOrder[2];
vector <bool> g_vbOrder[2];

void DFS(int nStart, int nCnt)
{
	bool bDone = true;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < g_vnOrder[i].size(); j++)
		{
			if (!g_nVisit[g_vnOrder[i][j]])
			{
				bDone = false;
				break;
			}
		}

		if (!bDone)
			break;
	}

	if (!g_nVisit[g_nFood[0]] || !g_nVisit[g_nFood[1]])
		bDone = false;

	if (bDone)
	{
		if (g_nMinDist > nCnt)
			g_nMinDist = nCnt;

		return;
	}

	// food[0]
	if (!g_nVisit[g_nFood[0]])
	{
		int nDist = nCnt + g_vnEdge[nStart][g_nFood[0]];

		g_nVisit[g_nFood[0]] = true;

		for (int i = 0; i < g_vnOrder[0].size(); i++)
			g_vbOrder[0][i] = true;

		DFS(g_nFood[0], nDist);

		g_nVisit[g_nFood[0]] = false;

		for (int i = 0; i < g_vnOrder[0].size(); i++)
			g_vbOrder[0][i] = false;
	}

	// food[1]
	if (!g_nVisit[g_nFood[1]])
	{
		int nDist = nCnt + g_vnEdge[nStart][g_nFood[1]];

		g_nVisit[g_nFood[1]] = true;

		for (int i = 0; i < g_vnOrder[1].size(); i++)
			g_vbOrder[1][i] = true;

		DFS(g_nFood[1], nDist);

		g_nVisit[g_nFood[1]] = false;

		for (int i = 0; i < g_vnOrder[1].size(); i++)
			g_vbOrder[1][i] = false;
	}

	//order[0]
	for (int i = 0; i < g_vnOrder[0].size(); i++)
	{
		if (!g_nVisit[g_vnOrder[0][i]])
		{
			if (g_vbOrder[0][i])
			{
				int nDist = nCnt + g_vnEdge[nStart][g_vnOrder[0][i]];

				g_nVisit[g_vnOrder[0][i]] = true;

				DFS(g_vnOrder[0][i], nDist);

				g_nVisit[g_vnOrder[0][i]] = false;
			}
		}
	}

	//order[1]
	for (int i = 0; i < g_vnOrder[1].size(); i++)
	{
		if (!g_nVisit[g_vnOrder[1][i]])
		{
			if (g_vbOrder[1][i])
			{
				int nDist = nCnt + g_vnEdge[nStart][g_vnOrder[1][i]];

				g_nVisit[g_vnOrder[1][i]] = true;

				DFS(g_vnOrder[1][i], nDist);

				g_nVisit[g_vnOrder[1][i]] = false;
			}
		}
	}

}


int main()
{
	freopen("input_210802.txt", "r", stdin);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		g_nMinDist = INF;

		cin >> N >> M >> Q;

		for (int i = 0; i <= N; i++)
		{
			vector <int> vTemp;
			vTemp.resize(N+1, INF);
			g_vnEdge.emplace_back(vTemp);
		}

		cin >> g_nFood[0] >> g_nFood[1] >> g_nStart;

		int a, b, c;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;

			g_vnEdge[a][b] = c;
			g_vnEdge[b][a] = c;
		}

		for (int i = 0; i < Q; i++)
		{
			cin >> a >> b;

			if (b == g_nFood[0])
			{
				g_vnOrder[0].push_back(a);
				g_vbOrder[0].push_back(false);
			}
			else
			{
				g_vnOrder[1].push_back(a);
				g_vbOrder[1].push_back(false);
			}
		}
		// floyd washall
		// 경유
		for (int j = 1; j <= N; j++)
		{
			// 시작
			for (int i = 1; i <= N; i++)
			{
				// 끝
				for (int k = 0; k <= N; k++)
				{
					g_vnEdge[i][k] = g_vnEdge[i][k] < g_vnEdge[i][j] + g_vnEdge[j][k] ?
					               	 g_vnEdge[i][k] : g_vnEdge[i][j] + g_vnEdge[j][k];
				}
			}
		}

		int nCnt = 0;
		DFS(g_nStart, nCnt);

		cout << "#" << tc << " " << g_nMinDist << endl;
	}

	return 0;
}