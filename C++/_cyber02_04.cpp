
// 카드놀이

/*

N개의 카드가 주어지고, 각각은 자연수의 점수를 가진다. 
철수는 이제 이 카드를 가져감으로써 카드에 적혀있는 수 만큼의 점수를 얻는다. 

단, 카드를 가져갈 때 한가지 규칙이 있는데, 이는 연속하여 3개의 카드는 가져갈 수 없다는 것이다. 
예를 들어, 6개의 카드 “1 3 5 2 7 3”가 주어질 경우, 3+5+7+3 = 18 만큼의 점수를 얻는 것이 최대이다. 
N개의 카드가 주어질 때, 얻을 수 있는 점수의 최댓값을 출력하는 프로그램을 작성하시오

첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 
두 번째 줄에 N개의 숫자가 주어지며, 이는 각 카드의 점수를 나타낸다.

얻을 수 있는 점수의 최댓값을 출력한다.

6
1 3 5 2 7 3

18

*/


#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_CNT = 100001;

int n;
int sum[3] = {0, };

int main()
{
	cin >> n;

	int score;
	int max_score;

	for (int i = 0; i < n; i++)
	{
		cin >> score;

		if (i == 0)
		{
			sum[1] = score;
			sum[0] = 0;
			sum[2] = 0;
		}
		else
		{
			max_score = max(sum[0], sum[1]);
			max_score = max(sum[2], max_score);
			sum[2] = sum[1] + score;
			sum[1] = sum[0] + score;
			sum[0] = max_score;
		}
	}

	max_score = max(sum[0], sum[1]);
	max_score = max(sum[2], max_score);

	cout << max_score << endl;

	return 0;
}
