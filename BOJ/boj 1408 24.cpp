#include <iostream>
#include <vector>
#include <sstream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

vector<int>t;
string ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int j = 0; j < 2; j++)
	{
		string input;
		cin >> input;
		for (int i = 0; i < input.size(); i++)
		{
			if (input[i] == ':')
				input[i] = ' ';
		}
		stringstream stream;
		stream.str(input);
		int num;
		while (stream >> num)
		{
			t.push_back(num);
		}
	}
	for (int i = 2; i >= 1; i--)
	{
		if (t[i + 3] < t[i])
		{
			t[i] = t[i + 3] + 60 - t[i];
			t[i + 2] -= 1;
		}
		else
		{
			t[i] = t[i + 3] - t[i];
		}
	}
	if(t[3]<t[0])t[0] = t[3] + 24 - t[0];
	else t[0] = t[3] - t[0];
	for (int i = 0; i < 3; i++)
	{
		string plus = to_string(t[i]);
		if (plus.length() == 1)plus = "0" + plus;
		if (i == 2)
		{
			ans += plus;
		}
		else
		{
			ans += plus + ":";
		}
	}
	cout << ans << '\n';
	return 0;
}