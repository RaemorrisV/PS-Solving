#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
queue<int>q;
vector<int>ans;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		ans.push_back(q.front());
		q.pop();
	}
	cout << "<";
	for (int i = 0; i < ans.size(); i++)
	{
		if (i != ans.size() - 1)
		{
			cout << ans[i] << ", ";
		}
		else
		{
			cout << ans[i];
		}
	}
	cout << ">" << '\n';
	return 0;
}