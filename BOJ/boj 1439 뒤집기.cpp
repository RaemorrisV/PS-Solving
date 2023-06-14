#include <iostream>
#include <algorithm>

using namespace std;

string input;
int arr[2];
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> input;
	bool zero = false;
	bool one = false;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == '0')
		{
			if (one)
			{
				arr[1]++;
				one = false;
				zero = true;
			}
			else
			{
				zero = true;
			}
		}
		else if (input[i] == '1')
		{
			if (zero)
			{
				arr[0]++;
				zero = false;
				one = true;
			}
			else
			{
				one = true;
			}
		}
	}
	if (one)arr[1]++;
	else arr[0]++;
	//cout << arr[0] << " " << arr[1] << '\n';
	cout << min(arr[0], arr[1]) << '\n';
	return 0;
}