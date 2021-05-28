/*

3 3 2
1 2 3
1 3 3
2 3 1

2
1 2

*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// x node의 부모 node return 
int getRoot(vector<int>& parent, int x)  
{
	if (parent[x] == x) 
		return x;

	return parent[x] = getRoot(parent, parent[x]);
}

// 2개 node 병합 - 부모가 같은 그룹으로
void unionParent(vector<int>& parent, int a, int b)  
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);

	if (a < b) 
		parent[b] = a;
	else 
		parent[a] = b;
}

// 2개 node의 parent가 같은가 ? ... 같은 그룹인가 ?
bool find(vector<int>& parent, int a, int b)  
{
	a = getRoot(parent, a);
	b = getRoot(parent, b);

	if (a == b) 
		return true;
	else 
		return false;
}

bool compare(vector<int> a, vector<int> b)
{
	return a[2] < b[2];
}

// MST, n: node
int Kru(int n, vector<vector<int>> costs) 
{
	int answer = 0;

	// cost sort
	sort(costs.begin(), costs.end(), compare);

	vector<int> parents(n);

	// parent값을 자기로 초기화
	for (int i = 0; i < parents.size(); i++)
		parents[i] = i;

	for (int i = 0; i < costs.size(); i++)
	{
		// a, b의 parent가 같은가 ?
		if (!find(parents, costs[i][0], costs[i][1]))
		{
			unionParent(parents, costs[i][0], costs[i][1]);
			answer += costs[i][2];
		}
	}

	return answer;
}

int main()
{
	int N, M, K;

	// 첫 번째 줄에 N, M, K (N = 5000, 5⋅10 ^ 4 ≤ M ≤ 10 ^ 5, 100 ≤ K ≤ 5000)가 공백을 통해 구분하여 주어진다.
	cin >> N >> M >> K;

	// 간선의 정보 입력
	for (int i = 0; i<M; i++)
	{
		Edge e;
		cin >> e.from >> e.to >> e.val;
		edge.push_back(e);
	}

	// 간선을 가중치로 오름차순 정렬
	sort(edge.begin(), edge.end(), comp);

	for (int i = 0; i<E; i++){
		// 두 정점이 사이클을 형성하지 않는다면
		if (find(edge[i].from) != find(edge[i].to)){
			// 가중치값 더해줌
			res += edge[i].val;

			// MST 형성
			merge(edge[i].from, edge[i].to);
		}
	}

	cout << res << "\n";
	return 0;
}
*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 5000

using namespace std;

// Kruskal
typedef struct kruskal 
{
	int from, to, val;
} Edge;

bool comp(Edge e1, Edge e2)
{
	return e1.val > e2.val;
}

class Kruskal 
{

public:
	int parent[MAX + 1];
	int res;
	vector<Edge> edge;

public:
	// 생성자
	Kruskal()
	{
		for (int i = 1; i <= MAX; i++)
		{
			parent[i] = i;
		}

		// go();
	}

	// Union
	void merge(int u, int v)
	{
		u = find(u);
		v = find(v);

		if (u == v) 
			return;

		parent[u] = v;
	}

	// Find
	int find(int u)
	{
		if (parent[u] == u) 
			return u;
		else 
			return parent[u] = find(parent[u]);
	}
};

int main()
{
	Kruskal KR;

	int N, M, K;
	cin >> N >> M >> K;

	// 간선의 정보 입력
	for (int i = 0; i<M; i++)
	{
		Edge e;
		cin >> e.from >> e.to >> e.val;
		KR.edge.push_back(e);
	}

	// 간선을 가중치로 오름차순 정렬
	sort(KR.edge.begin(), KR.edge.end(), comp);

	for (int i = 0; i<M; i++)
	{
		// 두 정점이 사이클을 형성하지 않는다면
		if (KR.find(KR.edge[i].from) != KR.find(KR.edge[i].to))
		{
			// 가중치값 더해줌
			KR.res += KR.edge[i].val;

			// MST 형성
			KR.merge(KR.edge[i].from, KR.edge[i].to);
		}
	}

	cout << KR.res << "\n";

	return 0;
}
*/