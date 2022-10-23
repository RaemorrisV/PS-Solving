#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int p, m;
vector<vector<pair<string, int>>>room(301);//���� ���� �÷��̾� �̸��� ������ ������
int current_room_num = 0;
bool enter = false;
int main()
{
	cin >> p >> m;
	for (int i = 0; i < p; i++)
	{
		int level;
		string name;
		cin >> level >> name;
		for (int j = 1; j <= current_room_num; j++)
		{
			int differ = abs(room[j][0].second - level);
			if (differ <= 10 && room[j].size() < m)//���� ����
			{
				room[j].push_back({ name,level });
				enter = true;
				break;
			}
		}
		if (enter == false)//����� ������
		{
			++current_room_num;
			room[current_room_num].push_back({ name,level });//�̸��� ������ �������
		}
		enter = false;
	}
	for (int i = 1; i <= current_room_num; i++)
	{
		if (room[i].size() == m)
		{
			cout << "Started!" << '\n';
			sort(room[i].begin(), room[i].end());
			for (int j = 0; j < room[i].size(); j++)
			{
				cout << room[i][j].second << " " << room[i][j].first << '\n';
			}
		}
		else
		{
			cout << "Waiting!" << '\n';
			sort(room[i].begin(), room[i].end());
			for (int j = 0; j < room[i].size(); j++)
			{
				cout << room[i][j].second << " " << room[i][j].first << '\n';
			}
		}
	}
	return 0;
}