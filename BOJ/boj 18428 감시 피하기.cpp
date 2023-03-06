#include <iostream>
#include <vector>

using namespace std;
// T ������ S �л��� O ��ֹ�
//�������� �л� �߰��� �� �ִ����� ���� �Լ�
//��� ��츦 ��������ߵ�
//��ֹ��� 3���� ���ð���
int n;
char map[7][7];
struct loc {
	int x;
	int y;
};
vector<loc>teacher;
bool visited[7][7];
bool ans;
bool limit(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
bool valide()
{
	int find = 0;
	for (int i = 0; i < teacher.size(); i++)
	{
		//�� �� �� ��
		for (int j = 1; j <= n; j++)
		{
			int nx = teacher[i].x - j;
			if (!limit(nx, teacher[i].y))break;
			if (map[nx][teacher[i].y] == 'O')break;
			if (map[nx][teacher[i].y] == 'S')find++;
		}
		for (int j = 1; j <= n; j++)
		{
			int nx = teacher[i].x + j;
			if (!limit(nx, teacher[i].y))break;
			if (map[nx][teacher[i].y] == 'O')break;
			if (map[nx][teacher[i].y] == 'S')find++;
		}
		for (int j = 1; j <= n; j++)
		{
			int ny = teacher[i].y - j;
			if (!limit(teacher[i].x, ny))break;
			if (map[teacher[i].x][ny] == 'O')break;
			if (map[teacher[i].x][ny] == 'S')find++;
		}
		for (int j = 1; j <= n; j++)
		{
			int ny = teacher[i].y + j;
			if (!limit(teacher[i].x, ny))break;
			if (map[teacher[i].x][ny] == 'O')break;
			if (map[teacher[i].x][ny] == 'S')find++;
		}
	}
	if (find == 0)return true;
	return false;
}
void dfs(int depth)
{
	if (depth == 3)
	{
		if (valide())
		{
			ans = true;
		}
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 'X' && visited[i][j] == false)
			{
				visited[i][j] = true;
				map[i][j] = 'O';
				dfs(depth + 1);
				visited[i][j] = false;
				map[i][j] = 'X';
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'T')teacher.push_back({ i,j });
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 'X')
			{
				visited[i][j] = true;
				map[i][j] = 'O';
				dfs(1);
				visited[i][j] = false;
				map[i][j] = 'X';
			}
		}
	}
	if (ans)
	{
		cout << "YES" << "\n";
	}
	else
	{
		cout << "NO" << '\n';
	}
	return 0;
}