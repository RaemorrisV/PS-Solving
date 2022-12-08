#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> graph(201);
int n, m;
int parent[201];
int dis[201];
int output[201][201];
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cur_cost = pq.top().first;
        pq.pop();
        if (dis[cur] < cur_cost)
            continue;
        for (auto it : graph[cur])
        {
            if (dis[it.first] > dis[cur] + it.second)
            {
                dis[it.first] = dis[cur] + it.second;
                pq.push({dis[it.first], it.first});
                parent[it.first] = cur;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        graph[s].push_back({e, c});
        graph[e].push_back({s, c});
    }
    for (int i = 1; i <= n; i++)
    {
        output[i][i] = '-';
    }
    for (int i = 1; i <= n; i++)
    {
        fill(dis, dis + n + 1, INT_MAX);
        fill(parent, parent + n + 1, 0);
        dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                int p = parent[j];
                int pre = j;
                while (1)
                {
                    if (p == i)
                    {
                        output[i][j] = pre;
                        break;
                    }
                    pre = p;
                    p = parent[p];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                cout << '-' << " ";
            }
            else
            {
                cout << output[i][j] << " ";
            }
        }
        cout << '\n';
    }
    return 0;
}