
//

/*

N x M 의 직사각형이 주어지며, 각 칸에는 정수가 들어있다. 
이제 Q개의 질문에 대하여 답을 해야 하며, 각각의 질문은 (a, b)부터 (c, d)까지의 직사각형에 들어있는 정수의 합을 묻는다. 
예를 들어, 다음과 같이 5 x 5 의 직사각형이 주어질 때, (1, 2) 부터 (3, 3) 까지의 직사각형에 들어있는 정수의 합은 26 이다.

첫 번째 줄에 N, M, Q가 주어진다. ( 1 ≤ N, M ≤ 1,000, 1 ≤ Q ≤ 1,000,000 ) 
두 번째 줄부터 N x M 직사각형이 주어진다. 직사각형 안의 숫자 S는 -100이상 100이하이다. 
그 후 Q개의 질문이 주어진다. 
각각의 질문은 “a b c d” 로 이루어 져 있으며, 이는 (a, b) 부터 (c, d) 까지의 직사각형에 들어있는 정수의 합을 묻는다. 
(0 ≤ a ≤ c < N, 0 ≤ b ≤ d < M)

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