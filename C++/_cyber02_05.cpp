

// ��ư ������

/*

ö�����Դ� ������, �ʷϻ�, �Ķ��� �� ���� ��ư�� �ִ�. 
��ư �ϳ��� ���� �� ���� Ư�� ������ ���� �� ������, ö���� 1�ʿ� �� ���� ��ư�� ���� �� �ִ�. 
����, Ư�� �ð����� �� ���� ��ư �߿��� �� ���� ��ư���� ���� �� �ִ�. 
�� �ð����� Ư�� ��ư�� ������ �� ��� ������ ��� �ٸ� �� �ִ�. 
���� ���, �ð� 1�� ������, �ʷϻ�, �Ķ��� ��ư�� ���� ������ 3, 5, 7 �� �־��� �� �ִ�. 
�� ��쿡�� �Ķ����� ������ ���� ������ ���� ���� ���� �� �ִ�. 
����, �ð� 2�� �� ��ư�� ���� ������ �� �ٸ� �� �ִ�. 
��ư�� ���� ������ �� ���� ��Ģ�� �ִµ�, �����Ͽ� ������ ���� ��ư�� �� �� ���� �� ���ٴ� ���̴�. 
���� ���, �ð� 1�� �ʷϻ� ��ư�� �����ٸ�, �ð� 2���� �ʷϻ� ��ư�� ���� �� ����. 
�̿� ���� ��Ģ���� �� �ð����� ��ư�� �����ٰ� �� ��, ö���� ���� �� �ִ� ������ �ִ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

ù ��° �ٿ� ö������ �־��� �ð� N�� �־�����. ( 1 �� N �� 100,000 ) 
�� ��° �ٺ��� N���� �ð��� ���Ͽ� ������, �ʷϻ�, �Ķ��� ��ư�� ������ �� ���� �� �ִ� ������ �־�����.

ö���� ���� �� �ִ� ������ �ִ��� ����Ѵ�.

3
27 8 28
18 36 40
7 20 8

87

*/

/*
#include <iostream>

using namespace std;

const int MAX_CNT = 100001;

int n;

int main()
{
	cin >> n;

	int red, green, blue;
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> red >> green >> blue;

		if (i % 3 ==0)
			sum += red;
		else if (i % 3 == 1)
			sum += green;
		else if (i % 3 == 2)
			sum += blue;

	}

	cout << sum << endl;

	return 0;
}
*/