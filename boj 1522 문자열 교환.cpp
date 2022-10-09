#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>idx;
string str;
int cnt = 0;//a의 길이는 변하지 않음
int MIN = 1001;
int check = 0;
int main()
{
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'b')
		{
			idx.push_back(i);//b의 인덱스를 집어 넣는다
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
	else if (cnt == str.length() - ((idx[idx.size() - 1] - idx[0]) + 1))//b가 뭉쳐있어? 그럼 넌 이미 전부다 연결된거야~
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