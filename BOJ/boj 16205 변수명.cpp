#include <iostream>
#include <vector>
using namespace std;

int n;
string input;
vector<char>arr[4];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> input;
	if (n == 1)
	{
		arr[2].push_back(input[0]);
		arr[3].push_back(input[0]-32);
		for (int i = 1; i < input.length(); i++)
		{
			arr[3].push_back(input[i]);
			if (input[i] >= 65 && input[i] < 97)
			{
				arr[2].push_back('_');
				arr[2].push_back(input[i] + 32);
			}
			else
			{
				arr[2].push_back(input[i]);
			}
		}
		cout << input << '\n';
		for (int i = 0; i < arr[2].size(); i++)
		{
			cout << arr[2][i];
		}
		cout << '\n';
		for (int i = 0; i < arr[3].size(); i++)
		{
			cout << arr[3][i];
		}
		cout << '\n';
	}
	else if (n == 2)
	{
		arr[1].push_back(input[0]);
		arr[3].push_back(input[0] - 32);
		for (int i = 1; i < input.length(); i++)
		{
			if (input[i] == '_')continue;
			if (input[i - 1] == '_')
			{
				arr[1].push_back(input[i] - 32);
				arr[3].push_back(input[i] - 32);
			}
			else
			{
				arr[1].push_back(input[i]);
				arr[3].push_back(input[i]);
			}
		}
		for (int i = 0; i < arr[1].size(); i++)
		{
			cout << arr[1][i];
		}
		cout << '\n';
		cout << input << '\n';
		for (int i = 0; i < arr[3].size(); i++)
		{
			cout << arr[3][i];
		}
		cout << '\n';
	}
	else if (n == 3)
	{
		arr[1].push_back(input[0] + 32);
		arr[2].push_back(input[0] + 32);
		for (int i = 1; i < input.length(); i++)
		{
			arr[1].push_back(input[i]);
			if (input[i] >= 65 && input[i] < 97)
			{
				arr[2].push_back('_');
				arr[2].push_back(input[i] + 32);
			}
			else
			{
				arr[2].push_back(input[i]);
			}
		}
		for (int i = 0; i < arr[1].size(); i++)
		{
			cout << arr[1][i];
		}
		cout << '\n';
		for (int i = 0; i < arr[2].size(); i++)
		{
			cout << arr[2][i];
		}
		cout << '\n';
		cout << input << '\n';
	}

	return 0;
}