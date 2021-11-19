

/*
2
9 9
0 1
1 2
2 4
2 5
5 7
3 8
8 9
1 3
2 6
5 6 5 6 8 8 5 4 9
10 11
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
6 7 8 9 10 9 8 7 6 5 5

#1 6
#2 10

*/

/*
#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 100001

int T, N, M;
int cnt;

int nextUp[MAX_N];
bool check[MAX_N];

int task[MAX_N];

int find(int curTask)
{
	vector <int> v;
	v.push_back(curTask);

	while (true)
	{
		// root
		if (curTask == 0)
			return 1;

		// 이미 할당
		if (check[curTask] == true)
		{
			curTask = nextUp[curTask];
			v.push_back(curTask);
		}
		// 할당
		else
		{
			check[curTask] = true;
			cnt++;

			// 지나온 모든 직원들을 할달이 가능한 선임으로 대체
			curTask = nextUp[curTask];
			for (int i = 0; i < v.size(); i++)
				nextUp[v[i]] = curTask;

			return 0;
		}
	}

}

int main()
{
	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		cnt = 0;

		cin >> N >> M;

		int a, b;
		for (int j = 0; j < N; j++)
		{
			cin >> a >> b;
			nextUp[b] = a;
			check[j] = false;
		}

		for (int j = 1; j <= M; j++)
			cin >> task[j];

		int curTask;
		for (int j = 1; j <= M; j++)
		{
			curTask = find(task[j]);

			// 1 : root
			// 0 : ok

			if (curTask > 0)
			{
				cout << "#" << i << " " << cnt << endl;
				break;
			}
		}

		// 모든 이슈 할당 했을때
		if (curTask == 0)
			cout << "#" << i << " " << cnt << endl;
	}

	return 0;
}
*/