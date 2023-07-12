#include <iostream>
#include <queue>

using namespace std;

int n;
int ans[1000];
queue<pair<int,int>>q;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		q.push({ i,input });
	}
	int count = 0;
	while (!q.empty())
	{
		if (q.front().second == 0)
		{
			q.pop();
		}
		else
		{
			count++;
			int temp = q.front().second;
			int index = q.front().first;
			ans[index]=count;
			q.pop();
			temp -= 1;
			q.push({index ,temp });
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}