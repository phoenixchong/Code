/*

4 6
1 2 3
2 3 3
3 4 1
1 3 5
2 4 5
1 4 4
2 3

7


*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

// priority_queue + greater
#include <queue>
#include <functional>

#define MAX 1001
#define INF 987654321

#define PII pair<int,int>

using namespace std;

int n, m;
int u, v, w;
int a, b;
int StoA, AtoB, BtoN;
int StoB, BtoA, AtoN;
int ans;
bool flag1, flag2;

vector <PII> adj[MAX];

int dijkstra(int s, int e)
{
	// 최단거리 초기화 INF
	vector <int> dist(n + 1, INF);

	//
	// 아래 두개의 first, second가 다르다는 걸 헷갈리지 말것 !!!
	//
	// adj[...]에는 first -> node, second -> dist
	// queue push는 first -> dist, second -> node
	// 
	
	priority_queue < PII, vector<PII>, greater<PII> > pq;

	// start node, cost(dist) push
	pq.push(PII(0, s)); // cost, node

	// start node 최단거리 0
	dist[s] = 0;

	while (!pq.empty())
	{
		int pre_dist = pq.top().first;
		int pre_node = pq.top().second;

		pq.pop();

		// queue로 부터 얻은 node의 최단거리가 dist table의 최단거리보다 크면 skip
		if (pre_dist > dist[pre_node])
			continue;

		// queue로 부터 얻은 node와 연결된 노드 loop
		for (int i = 0; i < adj[pre_node].size(); i++)
		{
			int next_node = adj[pre_node][i].first;  // 연결된 node
			int next_dist = adj[pre_node][i].second; // 연결된 node까지의 dist

			// 연결된 노드의 최단거리 값이 (queue로 부터 얻은 node의 최단거리 + 연결된 node까지의 거리) 보다 크면 
			if (dist[next_node] > dist[pre_node] + next_dist)
			{
				// 연결된 노드의 최단거리 값 = (queue로 부터 얻은 node의 최단거리 + 연결된 node까지의 거리)
				dist[next_node] = dist[pre_node] + next_dist;

				// 연결된 노드 값 정보 (dist, node) push
				pq.push(PII(dist[next_node], next_node));
			}
		}
	}

	return dist[e];
}

int main()
{
	//freopen("input_d3.txt", "r", stdin);

	// 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 4 ≤ N ≤ 1,000, 1 ≤ M ≤ N*(N-1)/2 ) 
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		// 둘째 줄부터 간선의 정보가 주어진다. 
		// 각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a와 정점 b가 가중치 c인 간선으로 연결되어 있다는 의미이다. 
		// ( 1 ≤ a, b ≤ N, 1 ≤ c ≤ 50,000, a ≠ b )
		cin >> u >> v >> w;

		adj[u].push_back(pair<int, int>(v, w));
		adj[v].push_back(pair<int, int>(u, w));
	}

	// 마지막 줄에는 반드시 거쳐야 하는 두 정점 A, B가 주어진다. 
	// ( 2 ≤ A, B ≤ N, A ≠ B )
	cin >> a >> b;

	flag1 = true;

	StoA = dijkstra(1, a);
	AtoB = dijkstra(a, b);
	BtoN = dijkstra(b, n);

	if (StoA == INF || AtoB == INF || BtoN == INF)
		flag1 = false;

	flag2 = true;

	StoB = dijkstra(1, b);
	BtoA = dijkstra(b, a);
	AtoN = dijkstra(a, n);

	if (StoB == INF || BtoA == INF || AtoN == INF)
		flag2 = false;

	if (!flag1 && !flag2)
	{
		cout << -1 << endl;
	}
	else
	{
		ans = min(StoA + AtoB + BtoN, StoB + BtoA + AtoN);
		cout << ans << endl;
	}

	return 0;
}

*/