#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

string input;
unordered_map<string, bool>all;
void make_circle(string number)
{
	all[number] = true;
	for (int i = 1; i < number.length(); i++)
	{
		string first = number.substr(i);
		string second = number.substr(0, i);
		all[first + second] = true;
	}
}
bool checking(string number)
{
	string pre = number;
	for (int i = 2; i <= number.length(); i++)
	{
		int carry = 0;
		for (int j = number.length() - 1; j >= 0; j--)
		{
			if ((number[j] - '0') + (pre[j] - '0') + carry >= 10)
			{
				pre[j] = ((number[j] - '0') + (pre[j] - '0') + carry - 10) + '0';
				carry = 1;
				if (j == 0)return false;
			}
			else
			{
				pre[j] = ((number[j] - '0') + (pre[j] - '0') + carry) + '0';
				carry = 0;
			}
		}
		if (all[pre] == false)return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	while (cin >> input)
	{
		all.clear();
		make_circle(input);
		if (checking(input))
		{
			cout << input << " " << "is cyclic" << '\n';
		}
		else
		{
			cout << input << " " << "is not cyclic" << '\n';
		}
	}
	return 0;
}