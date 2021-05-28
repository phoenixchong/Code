
//

/*

N x M �� ���簢���� �־�����, �� ĭ���� ������ ����ִ�. 
���� Q���� ������ ���Ͽ� ���� �ؾ� �ϸ�, ������ ������ (a, b)���� (c, d)������ ���簢���� ����ִ� ������ ���� ���´�. 
���� ���, ������ ���� 5 x 5 �� ���簢���� �־��� ��, (1, 2) ���� (3, 3) ������ ���簢���� ����ִ� ������ ���� 26 �̴�.

ù ��° �ٿ� N, M, Q�� �־�����. ( 1 �� N, M �� 1,000, 1 �� Q �� 1,000,000 ) 
�� ��° �ٺ��� N x M ���簢���� �־�����. ���簢�� ���� ���� S�� -100�̻� 100�����̴�. 
�� �� Q���� ������ �־�����. 
������ ������ ��a b c d�� �� �̷�� �� ������, �̴� (a, b) ���� (c, d) ������ ���簢���� ����ִ� ������ ���� ���´�. 
(0 �� a �� c < N, 0 �� b �� d < M)

5 5 3
1 -2 3 2 8
-8 -9 3 4 5
2 4 7 8 2
1 4 3 1 4
-1 2 5 -6 3
1 2 3 4
0 0 1 1
2 0 2 1

37
-18
6

*/

/*
#include <iostream>

using namespace std;

const int MAX_RECT = 1001;

int Table[MAX_RECT][MAX_RECT];
int n, m, q;

int main()
{
	cin >> n >> m >> q;

	int i, j;

	// zero-padding

	for (i = 0; i <= n; i++)
		Table[i][0] = 0;

	for (i = 0; i <= m; i++)
		Table[0][i] = 0;

	int a;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			cin >> a;
			Table[i][j] = Table[i][j - 1] + Table[i - 1][j] - Table[i - 1][j - 1] + a;
		}
	}

	int si, sj, ei, ej;
	int result;

	for (i = 1; i <= q; i++)
	{
		cin >> si >> sj >> ei >> ej;

		si++;
		sj++;
		ei++;
		ej++;

		result = Table[si - 1][sj - 1] + Table[ei][ej] - Table[si - 1][ej] - Table[ei][sj - 1];
		cout << result << endl;
	}

	return 0;
}

*/