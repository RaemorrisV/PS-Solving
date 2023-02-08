#include <iostream>
#include <deque>

using namespace std;

int n;
deque<int>de;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input == "push")
		{
			int a;
			cin >> a;
			de.push_back(a);
		}
		else if (input == "pop")
		{
			if (de.empty())cout << "-1" << '\n';
			else
			{
				cout << de.front() << '\n';
				de.pop_front();
			}
		}
		else if (input == "size")
		{
			cout << de.size() << '\n';
		}
		else if (input == "empty")
		{
			if (de.empty())cout << "1" << '\n';
			else cout << "0" << '\n';
		}
		else if (input == "front")
		{
			if (de.empty())cout << "-1" << '\n';
			else
			{
				cout << de.front() << '\n';
			}
		}
		else if (input == "back")
		{
			if (de.empty())cout << "-1" << '\n';
			else
			{
				cout << de.back() << '\n';
			}
		}

	}
	return 0;
}