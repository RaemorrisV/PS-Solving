#include <iostream>
#include <vector>

using namespace std;

int n, k;
int index;
vector<char>number;
void dfs(int sum, char num)
{
	if (sum > n)return;
	if (sum == n)
	{
		index++;
		if (index == k)
		{
			for (int i = 0; i < number.size(); i++)
			{
				if (i != number.size() - 1)cout << number[i] << "+";
				else cout << number[i] << '\n';
			}
		}
	}
	for (int i = 1; i <= 3; i++)
	{
		number.push_back(i + '0');
		dfs(sum + i, i + '0');
		number.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= 3; i++)
	{
		number.push_back(i + '0');
		dfs(i, i + '0');
		number.pop_back();
	}
	if (index < k)
	{
		cout << -1 << '\n';
	}
	return 0;
}
