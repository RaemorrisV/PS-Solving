#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>idx;
string str;
int cnt = 0;//a�� ���̴� ������ ����
int MIN = 1001;
int check = 0;
int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b')
		{
			idx.push_back(i);//b�� �ε����� ���� �ִ´�
		}
		else
		{
			cnt++;
		}
	}
	if (cnt == str.length())
	{
		cout << "0" << endl;
	}
	else if (cnt == str.length() - ((idx[idx.size() - 1] - idx[0]) + 1))//b�� �����־�? �׷� �� �̹� ���δ� ����Ȱž�~
	{
		cout << "0" << endl;
	}
	else
	{
		for (int i = 0; i < idx.size(); i++)
		{
			for (int j = idx[i]; j < idx[i] + idx.size(); j++)
			{
				if (j < str.length())
				{
					if (str[j] == 'a')
					{
						check++;
					}
				}
				else
				{
					if (str[j - str.length()] == 'a')
					{
						check++;
					}
				}
			}
			MIN = min(MIN, check);
			check = 0;
		}
		cout << MIN << endl;
	}

	return 0;
}