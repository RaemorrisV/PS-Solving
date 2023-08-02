#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int k, n, middle;
string order;
char ladder[1200][60];
int dy[2] = { -1,1 };//좌우
vector<pair<int,int>>arr;
bool flag;
void init()
{
	fill(&ladder[0][0], &ladder[1199][60], 'o');
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> k >> n >> order;
	init();
	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		if (input[0] == '?')middle = i;
		else
		{
			for (int j = 1; j <= input.length(); j++)
			{
				ladder[i + 1][2 * j - 1] = input[j - 1];
			}
		}
	}
	for (int i = 0; i < 2 * k - 1; i += 2)
	{
		int depth = 0;
		int c = i;
		while (1) {
			int r = depth++;
			for (int j = 0; j < 2; j++)
			{
				int ny = c + dy[j];
				if (ny >= 0 && ny < 2 * k - 1 && ladder[r][ny]=='-')
				{
					c += 2 * dy[j];
					break;
				}
			}
			if (r == middle + 1) {
				arr.push_back({ c ,0});
				break;
			}
		}
	}
	int index = 0;
	for (int i = 0; i < 2 * k - 1; i += 2)
	{
		int depth = n+1;
		int c = i;
		while (1) {
			int r = depth--;
			for (int j = 0; j < 2; j++)
			{
				int ny = c + dy[j];
				if (ny >= 0 && ny < 2 * k - 1 && ladder[r][ny] == '-')
				{
					c += 2 * dy[j];
					break;
				}
			}
			if (r == middle + 1) {
				arr[order[index]-'A'].second = c;
				index++;
				break;
			}
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].first == arr[i].second)
		{
			if(arr[i].first!=0)ladder[middle + 1][arr[i].first - 1] = '*';
			ladder[middle + 1][arr[i].first + 1] = '*';
		}
		else if (arr[i].first + 2 == arr[i].second)
		{
			ladder[middle + 1][arr[i].first - 1] = '*';
			ladder[middle + 1][arr[i].first + 1] = '-';
		}
		else if (arr[i].first == arr[i].second + 2)
		{
			ladder[middle + 1][arr[i].first - 1] = '-';
			if(arr[i].first!=2*k-2)ladder[middle + 1][arr[i].first + 1] = '*';
		}
		else flag = true;
	}
	if (flag)
	{
		for (int i = 0; i < k - 1; i++)
		{
			cout << 'x';
		}
		cout << '\n';
	}
	else
	{
		for (int i = 0; i < 2 * k -2; i += 2)
		{
			cout << ladder[middle + 1][i + 1];
		}
		cout << '\n';
	}
	return 0;
}
