#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;
int L[21];
int J[21];
bool visited[21];
int health = 100;
int enjoy = 0;
void dfs(int s)
{
	if (health <= 0)return;
	ans = max(ans, enjoy);
	for (int i = s+1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			health -= L[i];
			enjoy += J[i];
			dfs(i);
			health += L[i];
			enjoy -= J[i];
			visited[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> L[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> J[i];
	}
	for (int i = 1; i <= n; i++)
	{
		visited[i] = true;
		health -= L[i];
		enjoy += J[i];
		dfs(i);
		health += L[i];
		enjoy -= J[i];
		visited[i] = false;
	}
	cout << ans << "\n";
	return 0;
}