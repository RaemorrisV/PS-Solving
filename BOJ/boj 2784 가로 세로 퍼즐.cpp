#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string>arr;
vector<string>order;
char puzzle[3][3];
bool visited[6];
bool check()
{
	vector<string>temp = order;
	for (int i = 0; i < 3; i++)
	{
		string sero = "";
		for (int j = 0; j < 3; j++)
		{
			sero += order[j][i];
		}
		temp.push_back(sero);
	}
	sort(temp.begin(), temp.end());
	if (temp == arr)return true;
	return false;
}
void dfs(int index)
{
	if (order.size() == 3)
	{
		if (check())
		{
			for (auto it : order)
			{
				cout << it << '\n';
			}
			exit(0);
		}
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		if (visited[i] == false)
		{
			order.push_back(arr[i]);
			visited[i] = true;
			dfs(i);
			visited[i] = false;
			order.pop_back();
		}
	}
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < 6; i++)
	{
		string input;
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 0; i < 6; i++)
	{
		order.push_back(arr[i]);
		visited[i] = true;
		dfs(i);
		visited[i] = false;
		order.pop_back();
	}
	cout << 0 << '\n';
	return 0;
}