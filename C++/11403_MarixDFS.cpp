// 11403 - 인접행렬 경로 찾기
//
// use array

#include <iostream>
#include <cstring>

#define MAP_SIZE 101

using namespace std;

int arrnMap[MAP_SIZE][MAP_SIZE];
int arrnAnswer[MAP_SIZE][MAP_SIZE];
bool arrbVisited[MAP_SIZE][MAP_SIZE];
int nSize;

void input()
{
	cin >> nSize;

	for (int nRow = 0; nRow < nSize; nRow++)
	{
		for (int nCol = 0; nCol < nSize; nCol++)
			cin >> arrnMap[nRow][nCol];
	}

	// debug
	cout << "Original Map :" << endl;
	for (int nRow = 0; nRow < nSize; nRow++)
	{
		for (int nCol = 0; nCol < nSize; nCol++)
			cout << arrnMap[nRow][nCol] << ' ';

		cout << endl;
	}
	cout << "bVisited :" << endl;
	for (int nRow = 0; nRow < nSize; nRow++)
	{
		for (int nCol = 0; nCol < nSize; nCol++)
			cout << arrbVisited[nRow][nCol] << ' ';

		cout << endl;
	}
	cout << endl;
}

void DFS(int nTarget, int nRow) 
{
	for (int nCol = 0; nCol < nSize; nCol++) 
	{
		cout << "nTarget : " << nTarget << ", nRow : " << nRow << ", nCol :" << nCol << endl;

		if (arrnMap[nRow][nCol] == 1 &&       // check 1 or not
			arrbVisited[nRow][nCol] == false) // check already visited or not
		{
			cout << "Start : " << nRow << " -> Target : " << nCol << endl;
			cout << "Answer[" << nTarget << "][" << nCol << "] -> true" << endl;

			arrnAnswer[nTarget][nCol] = 1;
			arrbVisited[nRow][nCol] = true;

			// recursive
			DFS(nTarget, nCol);
		}
	}

	// debug
	cout << endl;
}

void output() 
{
	cout << "Answer :" << endl;
	for (int nRow = 0; nRow < nSize; nRow++)
	{
		for (int nCol = 0; nCol < nSize; nCol++) 
			cout << arrnAnswer[nRow][nCol] << ' ';

		cout << endl;
	}

	// debug
	cout << "bVisited :" << endl;
	for (int nRow = 0; nRow < nSize; nRow++)
	{
		for (int nCol = 0; nCol < nSize; nCol++)
			cout << arrbVisited[nRow][nCol] << ' ';

		cout << endl;
	}
}

int main() 
{
	input();

	for (int nRow = 0; nRow < nSize; nRow++)
	{
		memset(arrbVisited, false, sizeof(arrbVisited));
		DFS(nRow, nRow);
	}
	
	output();
	
	return 0;
}

