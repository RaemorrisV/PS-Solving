#include <iostream>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;
int t, n, d, c;
vector<vector<pair<int, int>>> graph(10001);
int dis[10001];
int num = 0;
int MAX = 0;
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();
        if (dis[cur] < cur_cost)continue;
        for (auto it : graph[cur])
        {
            if (dis[it.first] > dis[cur] + it.second)
            {
                dis[it.first] = dis[cur] + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> d >> c;
        fill(dis, dis + 10001, INT_MAX);
        for (int j = 0; j < d; j++)
        {
            int e, s, c;
            cin >> e >> s >> c;
            graph[s].push_back({e, c});
        }
        dijkstra(c);
        for (int k = 1; k <= n; k++)
        {
            if (dis[k] != INT_MAX)
            {
                num++;
                MAX = max(MAX, dis[k]);
            }
        }
        cout << num << " " << MAX << '\n';
        num = 0;
        MAX = 0;
        for (int j = 1; j <= n; j++)
        {
            graph[j].clear();
        }
    }
    return 0;
}