
/*

6 10 3
1 2 1
2 5 2
3 1 5
3 2 3
3 4 1
3 6 4
4 1 1
5 3 1
6 5 3
6 4 2

32

*/

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

	//
	// 아래 두개의 first, second가 다르다는 걸 헷갈리지 말것 !!!
	//
	// adj[...]에는 first -> node, second -> dist
	// queue push는 first -> dist, second -> node
	// 

	// priory_queue : 최소값을 효과적으로 search
	priority_queue < PII, vector<PII>, greater<PII> > pq;

	// start cost(0), node push
	pq.push(PII(0, s)); // cost, node

	// start 최소거리 0 초기화
	dist[s] = 0;

	while (!pq.empty())
	{
		int pre_dist = pq.top().first;  // dist
		int pre_node = pq.top().second; // node
		pq.pop();

		// queue에거 꺼낸 dist 값이 queue에서 꺼낸 node의 최단거리 값보다 크면 skip
		if (pre_dist > dist[pre_node]) 
			continue;

		// queue에서 꺼낸 노드와 연결된 모든 node 서치
		for (int i = 0; i < adj[pre_node].size(); i++)
		{
			int next_node = adj[pre_node][i].first;  // node
			int next_dist = adj[pre_node][i].second; // dist

			// 새로 연결된 node가 가지고 있는 기존 cost 값이 queue에서 꺼낸 노드 최소거리 값과 새로 연결된 node로가는 cost의 합보다 크면 최소거리 변경, push
			if (dist[next_node] > dist[pre_node] + next_dist)
			{
				dist[next_node] = dist[pre_node] + next_dist;

				// 새로 연결된 node의 cost, node값 push
				pq.push(PII(dist[next_node], next_node));
			}
		}
	}

	// s부터 시작되어 연결된 모든 node까지의 최단거리 합 return
	if (e == -1)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = res + dist[i];
		return res;
	}
	else
	{
		// e까지의 최단거리 return
		return dist[e];
	}
}

int main()
{
	// 첫째 줄에 정점의 개수 N과 간선의 개수 M, 그리고 철수의 집 번호 K가 주어진다. 
	// ( 1 ≤ N, K ≤ 1,000, 1 ≤ M ≤ 100,000 ) 
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		// 둘째 줄부터 간선의 정보가 주어진다. 
		// 각 줄은 두 개의 숫자 a, b, c로 이루어져 있으며, 이는 정점 a에서 정점 b로 이동하는 데 시간이 c만큼 걸린다는 의미이다. 
		// 양방향 도로가 아님에 주의하자. 각 정점의 번호는 1번부터 N번까지이다.
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

	cout << ans << endl;

	return 0;
}

*/