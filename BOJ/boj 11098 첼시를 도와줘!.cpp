#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, string>>player;
int n, p;
void init()
{
	player.clear();
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		init();
		for (int j = 0; j < p; j++)
		{
			int a;
			string in;
			cin >> a >> in;
			player.push_back({ a,in });
			sort(player.begin(), player.end());
		}
		cout << player[p - 1].second << '\n';
	}
	return 0;
}