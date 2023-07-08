#include <iostream>
#include <vector>

using namespace std;
int n, k, ans;
vector<int>kits;
bool visited[8];
void dfs(int day, int index, int weight)
{
	if (weight < 500)return;
	if (day == n)
	{
		if (weight >= 500)ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			dfs(day + 1, i, weight - k + kits[i]);
			visited[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		kits.push_back(input);
	}
	for (int i = 0; i < n; i++)
	{
		visited[i] = true;
		dfs(1, i, 500 - k + kits[i]);
		visited[i] = false;
	}
	cout << ans << '\n';
	return 0;
}