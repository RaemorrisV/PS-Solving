#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, c;
int MIN = 1000000000;
vector<int>order;
pair<int, int>open;
void dfs(int f, int s, int sum,int o)
{
	if (o == order.size())
	{
		MIN = min(MIN, sum);
		return;
	}
	//두가지 경우 first로 갈 경우에
	dfs(order[o], s, sum + abs(f - order[o]), o + 1);
	//두가지 경우 second로 갈 경우에
	dfs(f, order[o], sum + abs(s - order[o]), o + 1);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	cin >> open.first >> open.second;
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		int a;
		cin >> a;
		order.push_back(a);
	}
	dfs(open.first, open.second, 0,0);
	cout << MIN << '\n';
	return 0;
}