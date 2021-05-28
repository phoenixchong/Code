

/*

11 14
0 1
0 2
1 2
1 4
1 5
2 3
3 7
4 7
4 9
4 10
5 6
6 8
6 10
7 8
0 10

3
*/

/*
#include <iostream>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;


const int MAX = 10001;
bool check[MAX];

int Table[MAX];

vector <int> graph[MAX];
vector <int> cost[MAX];

int n, m, nStart, nEnd;

int main()
{
	// 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. ( 1 ≤ N ≤ 10,000, 1 ≤ M ≤ 1,000,000 ) 
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		// 둘째 줄부터 간선의 정보가 주어진다. 
		// 각 줄은 두 개의 숫자 a, b로 이루어져 있으며, 이는 정점 a와 정점 b가 연결되어 있다는 의미이다. 
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);

		cost[a].push_back(1);
		cost[b].push_back(1);

		// graph[0] - 1, 2
		// cost[0]  - 1, 1
	}

	// M+1 번째 줄에 대하여 출발점과 도착점의 정점 번호가 주어진다. 
	// 정점의 번호는 0번부터 N-1번까지이다.
	cin >> nStart >> nEnd;

	for (int i = 0; i < n; i++)
		Table[i] = INF;

	Table[nStart] = 0;

	for (int i = 0; i < n; i++)
	{
		// (1) 최소값을 구한다. 단 지금까지 최단거리로 확정되지 않았던 정점에 대해서
		// (2) 그 최소값을 갖는 노드부터 뻗어나간다.

		int minValue = INF;
		int minIndex = -1;

		for (int j = 0; j < n; j++)
		{
			if (!check[j] && minValue > Table[j])
			{
				minValue = Table[j];
				minIndex = j;
			}
		}

		check[minIndex] = true;

		for (int j = 0; j < graph[minIndex].size(); j++)
		{
			int node2 = graph[minIndex][j];
			int cost2 = cost[minIndex][j];

			// minIndex ------- (cost2) -------- node2
			if (Table[node2] > Table[minIndex] + cost2)
				Table[node2] = Table[minIndex] + cost2;
		}
	}

	printf("%d ", Table[nEnd]);

	return 0;
}

*/