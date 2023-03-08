#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
struct info {
	int t;
	int idx;
};
queue<info>road[4];//0: A, 1: B, 2: C , 3: D;
int n, Time;
int ans[200001];
vector<int>er_idx;
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		char b;
		cin >> a >> b;
		if (b == 'A') {
			road[0].push({ a ,i + 1 });
		}
		else if (b == 'B')
		{
			road[3].push({ a ,i + 1 });
		}
		else if (b == 'C')
		{
			road[2].push({ a ,i + 1 });
		}
		else //D
		{
			road[1].push({ a ,i + 1 });
		}
	}
	while (!(road[0].empty() && road[1].empty() && road[2].empty() && road[3].empty()))
	{
		//Time 압축
		int MIN = INT_MAX;
		int cnt = 0;
		for (int i = 0; i < 4; i++)
		{
			if (road[i].empty())continue;
			if (road[i].front().t <= Time)cnt++;
			MIN = min(road[i].front().t, MIN);
		}
		// 교착상태
		if (cnt == 4)
		{
			for (int i = 0; i < 4; i++)
			{
				while (!road[i].empty())
				{
					ans[road[i].front().idx] = -1;
					road[i].pop();
				}
			}
			break;
		}
		if (MIN!=INT_MAX && MIN >= Time)Time = MIN;
		//이제 움직을 수 있는 큐를 찾아야됨
		for (int i = 0; i < 4; i++)
		{
			if (!road[i].empty() && road[i].front().t <= Time)
			{
				if (road[(i + 1) % 4].empty()) // 비어 있거나 
				{
					ans[road[i].front().idx] = Time;
					er_idx.push_back({ i });
				}
				else if (road[(i + 1) % 4].front().t > Time) // 비어 있지 않은데
				{
					ans[road[i].front().idx] = Time;
					er_idx.push_back({ i });
				}
			}
		}
		for(int i=0;i<er_idx.size();i++)road[er_idx[i]].pop();
		er_idx.clear();
		Time++;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}