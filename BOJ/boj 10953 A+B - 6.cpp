#include <iostream>
#include <sstream>

using namespace std;

int t;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> t;
	for (int tc = 1; tc <= t; tc++)
	{
		string input;
		int num;
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			if (input[i] == ',')input[i] = ' ';
		}
		stringstream stream;
		stream.str(input);
		int sum = 0;
		while (stream >> num)
		{
			sum += num;
		}
		cout << sum << '\n';
	}
	return 0;
}