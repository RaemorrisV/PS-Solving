#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int n;
bool visited[10];
int counting;
string ans;
bool flag;
void dfs(int end, string input)
{
	if (flag)return;
	if (input.length() == end)
	{
		counting++;
		if (counting == n)
		{
			ans = input;
			flag = true;
			return;
		}
	}
	for (int i = 0; i <= 9; i++)
	{
		if (input.length() == 0 && i != 0)
		{
			visited[i] = true;
			dfs(end, input + to_string(i));
			visited[i] = false;
		}
		else if (input.length() == 0 && i == 0)continue;
		else if (input[input.length() - 1] > i+'0' && visited[i] == false)
		{
			visited[i] = true;
			string a = input + to_string(i);
			dfs(end, a);
			visited[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if (n <= 10)cout << n - 1 << '\n';
	else
	{
		counting = 10;
		for (int i = 2; i <= 10; i++)
		{
			dfs(i, "");
		}
		if (flag == false)
		{
			cout << -1 << '\n';
		}
		else
		{
			cout << ans << '\n';
		}
	}
	return 0;
}