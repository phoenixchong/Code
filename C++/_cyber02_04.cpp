
// ī�����

/*

N���� ī�尡 �־�����, ������ �ڿ����� ������ ������. 
ö���� ���� �� ī�带 ���������ν� ī�忡 �����ִ� �� ��ŭ�� ������ ��´�. 

��, ī�带 ������ �� �Ѱ��� ��Ģ�� �ִµ�, �̴� �����Ͽ� 3���� ī��� ������ �� ���ٴ� ���̴�. 
���� ���, 6���� ī�� ��1 3 5 2 7 3���� �־��� ���, 3+5+7+3 = 18 ��ŭ�� ������ ��� ���� �ִ��̴�. 
N���� ī�尡 �־��� ��, ���� �� �ִ� ������ �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�

ù ��° �ٿ� N�� �־�����. ( 1 �� N �� 100,000 ) 
�� ��° �ٿ� N���� ���ڰ� �־�����, �̴� �� ī���� ������ ��Ÿ����.

���� �� �ִ� ������ �ִ��� ����Ѵ�.

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
