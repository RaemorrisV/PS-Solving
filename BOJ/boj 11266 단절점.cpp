#include <iostream>
#include <vector>

using namespace std;

int v, e;
int order[10001];
bool cut_vertex[10001];
int time;
vector<vector<int>>graph(10001);
int dfs(int cur,int prev)
{
	//if (order[cur] != 0)return order[cur];
	order[cur] = ++time;
	//방문 순서의 최솟값  기존 방문했던 노드중 가장 방문 순서가 작은 값이 저장됨.
	int minorder = order[cur];
	int child = 0; //루트 노드일 경우
	for (auto it : graph[cur])
	{
		if (it != prev && order[it]!=0) // 이미 방문 했던 노드
		{
			minorder= minorder < order[it] ? minorder : order[it]; 
		}
		else if (it != prev && order[it] == 0)//방문 안했던 노드
		{
			int low = dfs(it, cur);
			child++;
			if (prev!=0 && low >= order[cur])cut_vertex[cur] = true;
			minorder = minorder < low ? minorder : low;
		}
	}
	if(prev==0&&child>=2)cut_vertex[cur] = true;
	return minorder;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	//root node를 0이라고 생각해보자
	for (int i = 1; i <= v; i++)
	{
		if (order[i] == 0)
		{
			dfs(i, 0);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= v; i++)
	{
		if (cut_vertex[i])cnt++;
	}
	cout << cnt << '\n';
	for (int i = 1; i <= v; i++)
	{
		if (cut_vertex[i])
		{
			cout << i << " ";
		}
	}
	cout << '\n';
	return 0;
}