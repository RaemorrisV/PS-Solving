#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#define INF INT_MAX
using namespace std;
int dis[10001];
int n, d;
vector<vector<pair<int, int>>> road(10001);
void dijkstra(int start)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push({0, start});
  while (!q.empty())
  {
    int cur = q.top().second;
    int cur_cost = q.top().first;
    q.pop();
    for (auto it : road[cur])
    {
      int next = it.first;
      int cost = it.second;
      if (dis[next] > dis[cur] + cost)
      {
        dis[next] = dis[cur] + cost;
        q.push({dis[next], next});
      }
    }
    if (cur + 1 <= d && dis[cur + 1] > cur_cost + 1)
    {
      dis[cur + 1] = cur_cost + 1;
      q.push({dis[cur + 1], cur + 1});
    }
  }
}
int main()
{
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    int in, in1, in2;
    cin >> in >> in1 >> in2;
    road[in].push_back({in1, in2});
  }
  fill(dis, dis + d + 1, INF);
  dis[0] = 0;
  dijkstra(0);
  cout << dis[d] << endl;
  return 0;
}