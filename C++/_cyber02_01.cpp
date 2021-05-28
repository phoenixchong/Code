
// 숫자 만들기

/*

숫자 1, 2, 3을 이용하여 숫자 N을 만드는 경우의 수를 출력하는 프로그램을 작성하시오.
예를 들어, N이 4일 경우에는 다음의 7가지 경우가 존재한다.
단, 경우의 수가 매우 많을 수 있으므로, 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.

1 + 1 + 1 + 1
1 + 1 + 2
1 + 2 + 1
2 + 1 + 1
2 + 2
1 + 3
3 + 1

1. table을 어떻게 정의
2. 점화식을 어떻게 세웠는지

T(i) = 1 ~ M까지의 숫자를 이용해서 숫자 i를 만드는 경우의 수
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
	// Table[3] = Table[2] + Table[1] + 1              // 1 ~ 4까지의 수를 이용해서 3을 만드는 경우의 수
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