/*
2
6 10
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
6 17
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4
*/

#include<iostream>
#include<string>

using namespace std;

int C;
int N;
int W;
string names[100];
int info[100][2]; // [0] volume, [1] urgency

int cache[100][1000];
string res[100];
int rLen;

int getMax(int i1, int i2)
{
	return i1 < i2 ? i2 : i1;
}

int choose2(int now, int v)
{
	if (now > N)
		return 0;

	int& ret = cache[now][v];

	if (ret != -1)
	{
		cout << "ret : " << ret << ", now : " << now << ", v : " << v << endl;
		return ret;
	}

	ret = choose2(now + 1, v);
	if (v + info[now][0] <= W)
	{
		cout << "now : " << now << ", v : " << v
			 << ", v + info[now][0] : " << v + info[now][0] << endl;

		ret = getMax(ret, info[now][1] + choose2(now + 1, v + info[now][0]));

		cout << "max urgency : " << ret << endl;
	}

	return ret;
}

void setRes(int start, int v)
{
	if (start > N)
		return;

	cout << "setRes (start : " << start << ", v : " << v << ")" << endl;

	if (choose2(start, v) == choose2(start + 1, v))
		setRes(start + 1, v);
	else
	{
		res[rLen++] = names[start];
		cout << "rLen : " << rLen-1 << ", res[rLen] : " << res[rLen-1] << endl;

		setRes(start + 1, v + info[start][0]);
	}
}

int main()
{
	cin >> C;

	for (int cc  = 0; cc < C; cc++)
	{
		cin >> N >> W;
		memset(cache, -1, sizeof(cache));

		for (int nn = 1; nn <= N; nn++)
			cin >> names[nn] >> info[nn][0] >> info[nn][1];

		int maxW = choose2(0, 0);

		rLen = 0;
		setRes(0, 0);

		int idx = 0;
		cout << maxW << " " << rLen << endl;

		for (int i = 0; i < rLen; i++) 
			cout << res[i] << endl;
	}

	return 0;
}
