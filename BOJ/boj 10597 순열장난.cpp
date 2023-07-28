#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

string sequence;
vector<int>ans;
int numCount;
bool visited[51];
void dfs(int index, int depth)
{
	if (depth == numCount)
	{
		int t = 0;
		for (int i = index; i < sequence.length(); i++)
		{
			t += (sequence[i] - '0') * ((sequence.length() - 1 - i) ? 10 : 1);
		}
		if (visited[t] || t > numCount)return;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << " ";
		}
		cout << t << '\n';
		exit(0);
		return;
	}
	if (index >= sequence.length())
		return;
	if (visited[sequence[index] - '0'] == false)
	{
		visited[sequence[index] - '0'] = true;
		ans.push_back(sequence[index] - '0');
		dfs(index + 1, depth + 1);
		ans.pop_back();
		visited[sequence[index] - '0'] = false;
	}
	if (index >= sequence.length() - 1)
		return;
	int temp = (sequence[index] - '0') * 10 + (sequence[index + 1] - '0');
	if (temp > numCount)return;
	if (visited[temp] == false)
	{
		visited[temp] = true;
		ans.push_back(temp);
		dfs(index + 2, depth + 1);
		ans.pop_back();
		visited[temp] = false;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> sequence;
	if (sequence.length() <= 9)
	{
		for (int i = 0; i < sequence.length(); i++)
		{
			cout << sequence[i] << " ";
		}
		cout << '\n';
	}
	else
	{
		numCount = 9 + (sequence.length() - 9) / 2;
		visited[sequence[0] - '0'] = true;
		ans.push_back(sequence[0] - '0');
		dfs(1, 2);
		visited[sequence[0] - '0'] = false;
		ans.pop_back();
		int temp = (sequence[0] - '0') * 10 + (sequence[1] - '0');
		if (temp <= numCount)
		{
			visited[temp] = true;
			ans.push_back(temp);
			dfs(2, 2);
		}
	}
	return 0;
}
