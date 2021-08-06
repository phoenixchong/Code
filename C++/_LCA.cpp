

#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>

#define INF 1000000000
#define SIZE 50020

using namespace std;

vector<vector<int> > ll;
int ac[SIZE][17], depth[SIZE];
int n, m, v, w, u, max_level, temp, child;

// 부모노드에서 밑으로 뻗친 애들를 이용해 getTree를 다시 호출하며 트리를 만들어 간다
void getTree(int current, int parent)
{
	depth[current] = depth[parent] + 1;
	ac[current][0] = parent;

	for (int i = 1; i <= max_level; i++)
	{
		// temp는 2^(i-1)번째 조상
		// i=1 --> 2^(1-1)번째의 2번째 즉 윗조상의 바로 윗조상인 2번째 위인 조상
		// i=2 --> 2^(2-1)번째의 2^(2-1)번째인 4번째 위인 조상을 의미
		temp = ac[current][i - 1];

		// ac[current][i]는 temp의 2^(i-1)번째 조상이므로 이것은 current의 2^i번째 조상과 동일
		ac[current][i] = ac[temp][i - 1];
	}
	
	int len = ll[current].size();
	
	for (int i = 0; i < len; i++)
	{
		int child = ll[current][i];
		if (child != parent) 
			getTree(child, current);
	}
}

int find_LCA(int a, int b)
{
	// a와 b의 깊이 같게 하기(depth[b] > depth[a]일때)
	for (int i = max_level; i >= 0; i--)
	{
		if (depth[a] <= depth[ac[b][i]]) 
			b = ac[b][i];
	}
	
	if (a == b) 
		return a;
	
	//공통 조상 찾기
	for (int i = max_level; i >= 0; i--)
	{
		if (ac[a][i] != ac[b][i])
		{
			a = ac[a][i];
			b = ac[b][i];
		}
	}
	
	return ac[a][0];
}

int main()
{
	cin >> n;
	//scanf("%d", &n);

	ll = vector<vector<int> >(n + 1);

	for (int i = 1; i < n; i++)
	{
		cin >> v, u;
		//scanf("%d %d", &v, &u);

		ll[v].push_back(u);
		ll[u].push_back(v);
	}

	depth[0] = -1;

	// Max_Level 다음과 같은 식을 이용해 구한다.
	max_level = (int)floor(log2(SIZE));

	getTree(1, 0);

	cin >> m;
	//scanf("%d", &m);

	while (m--)
	{
		cout << v << " " << u;
		//scanf("%d %d", &v, &u);
		printf("%d\n", depth[v] < depth[u] ? find_LCA(v, u) : find_LCA(u, v));
	}
}
