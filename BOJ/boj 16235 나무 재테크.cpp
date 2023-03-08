#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

int n, m, k; //k년이 지난후 에
int a[11][11];
int land[11][11];
int dx[8] = { -1,-1,-1,0,0,1,1,1 };
int dy[8] = { -1,0,1,-1,1,-1,0,1 };
list<pair<int, int>>tree_idx;
vector<int> tree[11][11];
vector<pair<int, int>>new_idx;
bool valide(int r, int c)
{
	if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
	return false;
}
void spring_summer()//여름하고 봄을 섞으면 가능할 수도
{
	auto it = tree_idx.begin();
	while (it != tree_idx.end())
	{
		int x = (*it).first;
		int y = (*it).second;
		int older_not = -1;
		sort(tree[x][y].begin(), tree[x][y].end());
		for (int j = 0; j < tree[x][y].size(); j++)
		{
			if (tree[x][y][j] <= land[x][y])//먹을수 있다면
			{
				land[x][y] -= tree[x][y][j];
				tree[x][y][j] += 1;
			}
			else //먹을 수 없다면
			{
				if (older_not == -1)older_not = j;
				break;
			}
		}
		if (older_not != -1)
		{
			for (int j = older_not; j < tree[x][y].size(); j++)
			{
				land[x][y] += (tree[x][y][j] / 2);
			}
			tree[x][y].erase(tree[x][y].begin() + older_not, tree[x][y].end());
		}
		if (tree[x][y].size() == 0)
		{
			it = tree_idx.erase(it);
		}
		else
		{
			it++;
		}
	}
}
void fall()
{
	auto it = tree_idx.begin();
	while (it != tree_idx.end())
	{
		int x = (*it).first;
		int y = (*it).second;
		for (int j = 0; j < tree[x][y].size(); j++)
		{
			if (tree[x][y][j] % 5 == 0)//5의 배수라면
			{
				for (int k = 0; k < 8; k++)
				{
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (valide(nx, ny))
					{
						if (tree[nx][ny].size() == 0)new_idx.push_back({ nx, ny });
						tree[nx][ny].push_back(1);
					}
				}
			}
		}
		it++;
	}
	for (int i = 0; i < new_idx.size(); i++)
	{
		tree_idx.push_back({ new_idx[i].first,new_idx[i].second });
	}
	new_idx.clear();
}
void winter()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			land[i][j] += a[i][j];
		}
	}
}
void simulation()
{
	for (int i = 0; i < k; i++)
	{
		spring_summer();
		fall();
		winter();
	}
	auto it = tree_idx.begin();
	int ans = 0;
	while (it != tree_idx.end())
	{
		ans += tree[(*it).first][(*it).second].size();
		it++;
	}
	cout << ans << '\n';
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
			land[i][j] = 5;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b].push_back(c);
		tree_idx.push_back({ a,b });
	}
	simulation();
	return 0;
}