
// ���� �����

/*

���� 1, 2, 3�� �̿��Ͽ� ���� N�� ����� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, N�� 4�� ��쿡�� ������ 7���� ��찡 �����Ѵ�.
��, ����� ���� �ſ� ���� �� �����Ƿ�, ����� ���� 1,000,007 �� ���� �������� ����Ѵ�.

1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
1 + 3
3 + 1

1. table�� ��� ����
2. ��ȭ���� ��� ��������

T(i) = 1 ~ M������ ���ڸ� �̿��ؼ� ���� i�� ����� ����� ��
T(i) = T(i-1) + T(i-2) ... T(i-M)


4
>> answer: 7

200
>> answer: 290816

*/

/*

#include <iostream>

using namespace std;

const int MAX_N = 100001;

long long Table[MAX_N];
int n, m;

int main()
{
	cin >> n; // >> m;

	m = 3;

	// m = 4
	// Table[1] = 1 (1) 
	// Table[2] = Table[1] + 1 (2)
	// Table[3] = Table[2] + Table[1] + 1              // 1 ~ 4������ ���� �̿��ؼ� 3�� ����� ����� ��
	// Table[4] = Table[3] + Table[2] + Table[1] + 1

	// Table[5] = Table[1] + Table[2] + Table[3] + Table[4]

	// 1 ~ m
	Table[1] = 1;
	long long sum = 0;

	for (int i = 2; i <= m; i++)
	{
		sum += Table[i - 1];
		Table[i] = sum + 1;

		// Table[i] = Table[1] + Table[2] ... Table[i-1] + 1
		// for (int j = 1; j < i - 1; j++)
		// sum += Table[i-1];

	}

	for (int i = m + 1; i <= n; i++)
	{
		for (int j = i - m; j <= i - 1; j++)
		{
			Table[i] += Table[j];

			Table[i] = Table[i] % 1000007;
		}
	}

	cout << Table[n] << endl;

	return 0;
}
*/