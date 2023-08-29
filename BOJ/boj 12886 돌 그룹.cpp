#include <iostream>
#include <algorithm>

using namespace std;

int group[3];
int total;
bool visited[1501][1501];
void dfs(int s, int e)
{
	if (visited[group[0]][group[1]] && visited[group[1]][group[2]])return;
	visited[group[0]][group[1]] = true;
	visited[group[1]][group[2]] = true;
	int temp2[3];
	temp2[0] = group[0]; temp2[1] = group[1]; temp2[2] = group[2];
	if (group[0] == total / 3 && group[1] == total / 3 && group[2] == total / 3)
	{
		cout << 1 << '\n';
		exit(0);
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (group[i] < group[j])
			{
				group[j] -= group[i];
				group[i] += group[i];
				if (visited[group[0]][group[1]] && visited[group[1]][group[2]])
				{
					group[i] = temp2[i];
					group[j] = temp2[j];
					continue;
				}
				dfs(i, j);
				group[i] = temp2[i];
				group[j] = temp2[j];
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 3; i++)
	{
		cin >> group[i];
		total += group[i];
	}
	if (total % 3 != 0)cout << 0 << '\n';
	else
	{
		dfs(0,0);
		cout << 0 << '\n';
	}
	return 0;
}