
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
	// �ּ� �Ÿ� �� ����
	vector <int> dist(n + 1, INF);

	//
	// �Ʒ� �ΰ��� first, second�� �ٸ��ٴ� �� �򰥸��� ���� !!!
	//
	// adj[...]���� first -> node, second -> dist
	// queue push�� first -> dist, second -> node
	// 

	// priory_queue : �ּҰ��� ȿ�������� search
	priority_queue < PII, vector<PII>, greater<PII> > pq;

	// start cost(0), node push
	pq.push(PII(0, s)); // cost, node

	// start �ּҰŸ� 0 �ʱ�ȭ
	dist[s] = 0;

	while (!pq.empty())
	{
		int pre_dist = pq.top().first;  // dist
		int pre_node = pq.top().second; // node
		pq.pop();

		// queue���� ���� dist ���� queue���� ���� node�� �ִܰŸ� ������ ũ�� skip
		if (pre_dist > dist[pre_node]) 
			continue;

		// queue���� ���� ���� ����� ��� node ��ġ
		for (int i = 0; i < adj[pre_node].size(); i++)
		{
			int next_node = adj[pre_node][i].first;  // node
			int next_dist = adj[pre_node][i].second; // dist

			// ���� ����� node�� ������ �ִ� ���� cost ���� queue���� ���� ��� �ּҰŸ� ���� ���� ����� node�ΰ��� cost�� �պ��� ũ�� �ּҰŸ� ����, push
			if (dist[next_node] > dist[pre_node] + next_dist)
			{
				dist[next_node] = dist[pre_node] + next_dist;

				// ���� ����� node�� cost, node�� push
				pq.push(PII(dist[next_node], next_node));
			}
		}
	}

	// s���� ���۵Ǿ� ����� ��� node������ �ִܰŸ� �� return
	if (e == -1)
	{
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = res + dist[i];
		return res;
	}
	else
	{
		// e������ �ִܰŸ� return
		return dist[e];
	}
}

int main()
{
	// ù° �ٿ� ������ ���� N�� ������ ���� M, �׸��� ö���� �� ��ȣ K�� �־�����. 
	// ( 1 �� N, K �� 1,000, 1 �� M �� 100,000 ) 
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		// ��° �ٺ��� ������ ������ �־�����. 
		// �� ���� �� ���� ���� a, b, c�� �̷���� ������, �̴� ���� a���� ���� b�� �̵��ϴ� �� �ð��� c��ŭ �ɸ��ٴ� �ǹ��̴�. 
		// ����� ���ΰ� �ƴԿ� ��������. �� ������ ��ȣ�� 1������ N�������̴�.
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