/*
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define MAX 100001
#define INF 987654321
#define PII pair<int,int>

using namespace std;

int n, m, k;
int u, v, w;
int KtoAll, ItoK;
int ans;

vector <PII> adj[MAX];

int dijkstra(int s, int e)
{
	// �ּ� �Ÿ� �� ����
	vector <int> dist(n + 1, INF);

	// �ּҰ��� ȿ�������� search
	priority_queue < PII, vector<PII>, greater<PII> > pq;

	// start cost(0), node push
	pq.push(pair<int, int>(0, s)); // cost, node

	// start �ּҰŸ� 0 �ʱ�ȭ
	dist[s] = 0;

	while (!pq.empty())
	{
		int pre_d = pq.top().first;  // cost
		int pre_v = pq.top().second; // node
		pq.pop();

		if (pre_d > dist[pre_v]) // queue���� ���� cost�� ��尡 ������ �ִ� cost���� ũ�� skip
			continue;


		// queue���� ���� ���� ����� ��� node ��ġ
		for (int i = 0; i < adj[pre_v].size(); i++)
		{
			int next_v = adj[pre_v][i].first;  // node
			int cost = adj[pre_v][i].second; // cost

			// ���� ����� node�� ������ �ִ� ���� cost ���� queue���� ���� ��� �ּҰŸ� ���� ���� ����� node�ΰ��� cost�� �պ��� ũ�� �ּҰŸ� ����, push
			if (dist[next_v] > dist[pre_v] + cost)
			{
				dist[next_v] = dist[pre_v] + cost;

				// ���� ����� node�� cost, node�� push
				pq.push(pair<int, int>(dist[next_v], next_v));
			}
		}
	}

	if (e == -1)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = res + dist[i];
		return res;
	}
	else
	{
		// e������ �ּҰŸ� return
		return dist[e];
	}
}

int main()
{
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> w;
		adj[u].push_back(PII(v, w));
	}

	ans = 0;

	for (int i = 1; i <= n; i++)
	{
		ItoK = dijkstra(i, k);
		ans += ItoK;
	}

	KtoAll = dijkstra(k, -1);
	ans += KtoAll;

	//ans = min(StoA + AtoB + BtoN, StoB + BtoA + AtoN);
	cout << ans << endl;

	return 0;
}
*/