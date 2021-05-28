

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
	// ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. ( 1 �� N �� 10,000, 1 �� M �� 1,000,000 ) 
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		// ��° �ٺ��� ������ ������ �־�����. 
		// �� ���� �� ���� ���� a, b�� �̷���� ������, �̴� ���� a�� ���� b�� ����Ǿ� �ִٴ� �ǹ��̴�. 
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);

		cost[a].push_back(1);
		cost[b].push_back(1);

		// graph[0] - 1, 2
		// cost[0]  - 1, 1
	}

	// M+1 ��° �ٿ� ���Ͽ� ������� �������� ���� ��ȣ�� �־�����. 
	// ������ ��ȣ�� 0������ N-1�������̴�.
	cin >> nStart >> nEnd;

	for (int i = 0; i < n; i++)
		Table[i] = INF;

	Table[nStart] = 0;

	for (int i = 0; i < n; i++)
	{
		// (1) �ּҰ��� ���Ѵ�. �� ���ݱ��� �ִܰŸ��� Ȯ������ �ʾҴ� ������ ���ؼ�
		// (2) �� �ּҰ��� ���� ������ �������.

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