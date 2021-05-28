
/*

$ input :

2
7
27 16 9 12 54 36 72
9 12 16 27 36 54 72
6
409 479 10 838 150 441
409 10 479 150 838 441


$ output : 

12 9 16 36 72 54 27
10 150 441 838 479 409


*/

/*
#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(const vector<int> &v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

// print post order result
void printPostOrder(const vector<int>& preorder, const vector<int>& inorder)
{
	// node #
	const int N = preorder.size();

	// base conditaion 
	if (preorder.empty())
		return;

	// root
	const int nRoot = preorder[0];

	// left subtree size : find root pos in inorder tree
	const int nLeftSubTreeSize = find(inorder.begin(), inorder.end(), nRoot) - inorder.begin();

	// right subtree size : N - nLeftSubTreeSize - 1
	const int nRightSubTreeSize = N - nLeftSubTreeSize - 1;

	////////////////////////////////////////
	//
	// Left -> Right -> Root
	//

	// 1 ~ nLeftSubTreeSize + 1 
	printPostOrder(slice(preorder, 1, nLeftSubTreeSize + 1), slice(inorder, 0, nLeftSubTreeSize));

	// nLeftSubTreeSize + 1 ~ N
	printPostOrder(slice(preorder, nLeftSubTreeSize + 1, N), slice(inorder, nLeftSubTreeSize + 1, N));

	// root
	cout << nRoot << " ";
}


int main(void)
{
	int test_case;
	cin >> test_case;

	for (int i = 0; i < test_case; i++)
	{
		int N;
		cin >> N;

		vector<int> preorder, inorder;

		for (int i = 0; i < N; i++)
		{
			int node;
			cin >> node;

			preorder.push_back(node);
		}

		for (int i = 0; i < N; i++)
		{
			int node;
			cin >> node;

			inorder.push_back(node);
		}

		printPostOrder(preorder, inorder);

		cout << endl;
	}

	return 0;
}
*/