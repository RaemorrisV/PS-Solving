#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
pair<int, int>input[21];
bool visited[21];
int damage = 0;
int ans = 0;
bool compare(pair<int, int>a, pair<int, int>b)
{
	if (a.first < b.first)return true;
	else if(a.first==b.first)return a.second > b.second;
	return false;
}
void dfs(int town, int attacked, int savePeople)
{
	if (damage > k)
	{
		return;
	}
	ans = max(ans, savePeople);
	for (int i = town + 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			damage += (attacked + input[i].first);
			dfs(i, attacked + input[i].first , savePeople + input[i].second);
			damage -= (attacked + input[i].first);
			visited[i] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i].first;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i].second;
	}
	sort(input + 1, input + n + 1, compare);
	for (int i = 1; i <= n; i++)
	{
		visited[i] = true;
		damage += input[i].first;
		dfs(i, input[i].first, input[i].second);
		damage -= input[i].first;
		visited[i] = false;
	}
	cout << ans << '\n';
	return 0;
}
