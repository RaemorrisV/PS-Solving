#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int num;
	int a;
	int cycle = 0;
	string change;
	cin >> num;
	change = to_string(num);
	do
	{
		//if (cycle == 3)break;
		//cout << change << endl;
		if (change.length() == 1)
		{
			a = (change[0] - '0');

		}
		else if (change.length() == 2)
		{
			a = (change[0] - '0') + (change[1] - '0');
		}
		//cout << a << endl;
		string temp = to_string(a);
		if (temp.length() == 1 && change.length() == 2)
		{
			int temp1 = (((change[1] - '0') * 10) + (temp[0] - '0'));
			cycle++;
			change = to_string(temp1);
		}
		else if ((temp.length() == 1 && change.length() == 1))
		{
			int temp1 = (((change[0] - '0') * 10) + (temp[0] - '0'));
			cycle++;
			change = to_string(temp1);
		}
		else if (temp.length() == 2 && change.length() == 2)
		{
			int temp1 = (((change[1] - '0') * 10) + (temp[1] - '0'));
			cycle++;
			change = to_string(temp1);
		}
		else if (temp.length() == 2 && change.length() == 1)
		{
			int temp1 = (((change[0] - '0') * 10) + (temp[1] - '0'));
			cycle++;
			change = to_string(temp1);
		}
	} while (stoi(change) != num);
	cout << cycle << endl;
	return 0;
}