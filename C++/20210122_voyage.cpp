/*

3
8 9 2
2 1 4
1 3 2
1 4 3
3 5 6
4 5 4
5 6 17
5 7 10
6 8 8
7 8 4
3 1
6 3
6 6 2
1 2 3
1 3 3
2 4 1
3 5 2
4 6 2
5 6 5
3 5
5 10
6 6 2
1 2 1
1 3 3
2 5 1
3 5 2
4 6 2
5 6 5
3 5
5 10

#1 
#2
#3
*/

/*
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define MAX_N 100001
#define PII pair <int, int>
#define INF 1e9

int T, N, M, K;

int g_nMinFood[MAX_N];
int g_nFriendFood[MAX_N];

vector <PII> g_vEdge[MAX_N];

void dijkstra(int nStart)
{
	g_nMinFood[nStart] = 0;

	priority_queue <PII, vector<PII>, greater<PII>> pq;

	// first cost, second pos
	pq.push(PII(0, nStart));

	while (!pq.empty())
	{
		int nCurCost = pq.top().first;
		int nCurPos  = pq.top().second;

		pq.pop();

		if (g_nMinFood[nCurPos] < nCurCost)
			continue;

		for (int i = 0; i < g_vEdge[nCurPos].size(); i++)
		{
			// first pos, second cost
			int nNextPos = g_vEdge[nCurPos][i].first;
			int nNextCost = g_vEdge[nCurPos][i].second;

			if (g_nMinFood[nNextPos] > max(0, g_nMinFood[nCurPos] + nNextCost - g_nFriendFood[nNextPos]))
				g_nMinFood[nNextPos] = max(0, g_nMinFood[nCurPos] + nNextCost - g_nFriendFood[nNextPos]);

			pq.push(PII(g_nMinFood[nNextPos], nNextPos));
		}
	}
}

int main()
{
	freopen("input_210122.txt", "r", stdin);

	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		//g_nMinFood = 0;

		cin >> N >> M >> K;

		for (int i = 1; i <= N; i++)
		{
			g_nFriendFood[i] = 0;
			g_nMinFood[i] = INF;
		}

		int a, b, c;
		for (int i = 0; i < M; i++)
		{
			// from, to, food
			// --> to, from, food
			cin >> a >> b >> c;

			g_vEdge[b].push_back({ a, c });
		}

		for (int i = 0; i < K; i++)
		{
			// pos, food
			cin >> a >> b;
			g_nFriendFood[a] = b;
		}

		dijkstra(N);

		cout << "#" << tc << " " << g_nMinFood[1] << endl;

		for (int i = 1; i <= N; i++)
			g_vEdge[i].clear();
	}

	return 0;
}
*/