// Palindrome 
//
// use stack<char> stackchPre;

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool comparePreAndPost(stack<char> stackchPre, string strInput, int nStartIndex)
{
	while (stackchPre.size() != 0)
	{
		if (stackchPre.top() != strInput[nStartIndex++])
			return false;
		else 
		{
			if (!stackchPre.empty())
				stackchPre.pop();
		}
	}

	return true;
}

bool isPalindrome(string strInput) 
{
	// size
	int nInputLength = strInput.size();
	int nStartIndex;

	// stack ch pre
	stack<char> stackchPre;

	for (int i = 0; i < nInputLength / 2; i++)
	{
		// debug
		cout << "push : " << strInput[i] << endl;
		stackchPre.push(strInput[i]);
	}

	// if input length is even, start index to input length
	if (nInputLength % 2 == 0) 
	{
		nStartIndex = nInputLength / 2;

		// debug
		cout << "compare " << strInput << ", start index : " << nStartIndex << endl;

		if (comparePreAndPost(stackchPre, strInput, nStartIndex))
			return true;
		else
			return false;
	}
	// if input lengh is odd, start index to input length + 1
	else 
	{
		nStartIndex = nInputLength / 2 + 1;

		// debug
		cout << "compare " << strInput << ", start index : " << nStartIndex << endl;

		if (comparePreAndPost(stackchPre, strInput, nStartIndex))
			return true;
		else
			return false;
	}
}

int main() 
{
	string strInput;
	cin >> strInput;

	if (isPalindrome(strInput))
		cout << strInput << " is Palindrome !~" << endl;
	else
		cout << strInput << " is not Palindrome." << endl;

	return 0;
}
