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
	// 최소 거리 값 저장
	vector <int> dist(n + 1, INF);

	// 최소값을 효과적으로 search
	priority_queue < PII, vector<PII>, greater<PII> > pq;

	// start cost(0), node push
	pq.push(pair<int, int>(0, s)); // cost, node

	// start 최소거리 0 초기화
	dist[s] = 0;

	while (!pq.empty())
	{
		int pre_d = pq.top().first;  // cost
		int pre_v = pq.top().second; // node
		pq.pop();

		if (pre_d > dist[pre_v]) // queue에서 꺼낸 cost가 노드가 가지고 있는 cost보다 크면 skip
			continue;


		// queue에서 꺼낸 노드와 연결된 모든 node 서치
		for (int i = 0; i < adj[pre_v].size(); i++)
		{
			int next_v = adj[pre_v][i].first;  // node
			int cost = adj[pre_v][i].second; // cost

			// 새로 연결된 node가 가지고 있는 기존 cost 값이 queue에서 꺼낸 노드 최소거리 값과 새로 연결된 node로가는 cost의 합보다 크면 최소거리 변경, push
			if (dist[next_v] > dist[pre_v] + cost)
			{
				dist[next_v] = dist[pre_v] + cost;

				// 새로 연결된 node의 cost, node값 push
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
		// e까지의 최소거리 return
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