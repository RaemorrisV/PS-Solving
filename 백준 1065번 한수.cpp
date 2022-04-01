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
	int count = 0;
	cin >> num;
	if (num >= 100)
	{
		count += 99;
		while (num > 100)
		{
			string change = to_string(num);
			int check = 0;
			int interval = int(change[1]) - int(change[0]);
			for (int i = 0; i < change.length() - 1; i++)
			{
				if (interval == int(change[i + 1]) - int(change[i]))
				{
					check++;
				}
			}
			if (check == change.length() - 1)
			{
				count++;
			}
			num--;
		}
		cout << count << endl;
	}
	else
	{
		cout << num << endl;
	}

	return 0;
}