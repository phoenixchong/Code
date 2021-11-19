
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

			// x�࿡�� �������� ���ϸ�
			if (abs(y) > D)
				continue;

			// startX, endX ���
			startX = x - (D - abs(y));
			endX = x + (D - abs(y));

			vector<int>::iterator s_it, e_it;

			// ������ ���� �� ������ ã��
			s_it = lower_bound(vStore.begin(), vStore.end(), startX);

			// ���� �� �������� ������ �ʰ��ϴ��� check
			if (*s_it > endX || s_it == vStore.end())
				continue;

			// ��� ������ ���� ��� 1���� ����
			cntHome++;

			// ������ ���� �� ������ ã��
			e_it = lower_bound(vStore.begin(), vStore.end(), endX);

			// ����
			if (*e_it != endX)
				e_it--;

			// �� ��� ������ �� ����ؼ� ����
			cntTotal += (e_it - s_it + 1);
		}

		cout << "#" << t << " " << cntHome << " " << cntTotal << endl;
	}

	return 0;
}