#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n;
bool visited[51];
bool isFriend[51];
int twoFriend;
int ans;
vector<vector<int>>graph(51);
void dfs(int s,int depth)
{
	if (depth == 2)return;
	for (auto it : graph[s])
	{
		if (visited[it] == false)
		{
			visited[it] = true;
			if(isFriend[it]==false)twoFriend++;
			isFriend[it] = true;
			dfs(it, depth + 1);
			visited[it] = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < input.length(); j++)
		{
			if (input[j] == 'Y')graph[i].push_back(j + 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		visited[i] = true;
		dfs(i, 0);
		if (ans < twoFriend)
		{
			ans = twoFriend;
		}
		twoFriend = 0;
		visited[i] = false;
		memset(isFriend, 0, sizeof(isFriend));
	}
	cout << ans << '\n';
	return 0;
}
