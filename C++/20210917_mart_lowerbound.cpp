
/*

1
4 3 3
-4 0 1 4
0 2
-3 -2
3 -3

#1 2 3

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

int N, M;
long long D;

int cntHome;
long long cntTotal;

int main()
{
	cin >> T;

	for (int t = 1; t <= T; t++)
	{
		cntHome = 0;
		cntTotal = 0;

		cin >> N >> M >> D;

		vector <int> vStore;
		int a;
		for (int i = 0; i < N; i++)
		{
			cin >> a;
			vStore.emplace_back(a);
		}

		// sort
		sort(vStore.begin(), vStore.end());

		int x, y;
		int startX, endX;
		for (int i = 0; i < M; i++)
		{
			cin >> x >> y;

			// x축에도 도달하지 못하면
			if (abs(y) > D)
				continue;

			// startX, endX 계산
			startX = x - (D - abs(y));
			endX = x + (D - abs(y));

			vector<int>::iterator s_it, e_it;

			// 범위내 가장 앞 음식점 찾기
			s_it = lower_bound(vStore.begin(), vStore.end(), startX);

			// 가장 앞 음식점이 범위를 초과하는지 check
			if (*s_it > endX || s_it == vStore.end())
				continue;

			// 배달 가능한 집이 적어도 1개가 있음
			cntHome++;

			// 범위내 가장 뒤 음식점 찾기
			e_it = lower_bound(vStore.begin(), vStore.end(), endX);

			// 보정
			if (*e_it != endX)
				e_it--;

			// 총 배달 가능한 집 계산해서 누적
			cntTotal += (e_it - s_it + 1);
		}

		cout << "#" << t << " " << cntHome << " " << cntTotal << endl;
	}

	return 0;
}