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
	// �ִܰŸ� �ʱ�ȭ INF
	vector <int> dist(n + 1, INF);

	//
	// �Ʒ� �ΰ��� first, second�� �ٸ��ٴ� �� �򰥸��� ���� !!!
	//
	// adj[...]���� first -> node, second -> dist
	// queue push�� first -> dist, second -> node
	// 
	
	priority_queue < PII, vector<PII>, greater<PII> > pq;

	// start node, cost(dist) push
	pq.push(PII(0, s)); // cost, node

	// start node �ִܰŸ� 0
	dist[s] = 0;

	while (!pq.empty())
	{
		int pre_dist = pq.top().first;
		int pre_node = pq.top().second;

		pq.pop();

		// queue�� ���� ���� node�� �ִܰŸ��� dist table�� �ִܰŸ����� ũ�� skip
		if (pre_dist > dist[pre_node])
			continue;

		// queue�� ���� ���� node�� ����� ��� loop
		for (int i = 0; i < adj[pre_node].size(); i++)
		{
			int next_node = adj[pre_node][i].first;  // ����� node
			int next_dist = adj[pre_node][i].second; // ����� node������ dist

			// ����� ����� �ִܰŸ� ���� (queue�� ���� ���� node�� �ִܰŸ� + ����� node������ �Ÿ�) ���� ũ�� 
			if (dist[next_node] > dist[pre_node] + next_dist)
			{
				// ����� ����� �ִܰŸ� �� = (queue�� ���� ���� node�� �ִܰŸ� + ����� node������ �Ÿ�)
				dist[next_node] = dist[pre_node] + next_dist;

				// ����� ��� �� ���� (dist, node) push
				pq.push(PII(dist[next_node], next_node));
			}
		}
	}

	return dist[e];
}

int main()
{
	//freopen("input_d3.txt", "r", stdin);

	// ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 4 �� N �� 1,000, 1 �� M �� N*(N-1)/2 ) 
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		// ��° �ٺ��� ������ ������ �־�����. 
		// �� ���� �� ���� ���� a, b, c�� �̷���� ������, �̴� ���� a�� ���� b�� ����ġ c�� �������� ����Ǿ� �ִٴ� �ǹ��̴�. 
		// ( 1 �� a, b �� N, 1 �� c �� 50,000, a �� b )
		cin >> u >> v >> w;

		adj[u].push_back(pair<int, int>(v, w));
		adj[v].push_back(pair<int, int>(u, w));
	}

	// ������ �ٿ��� �ݵ�� ���ľ� �ϴ� �� ���� A, B�� �־�����. 
	// ( 2 �� A, B �� N, A �� B )
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