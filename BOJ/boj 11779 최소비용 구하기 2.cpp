#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int n, m, a, b;
int cnt[1001];
int parent[1001];
vector<int> ans;
vector<vector<pair<int, int>>> graph(1001);
void dijkstra(int d)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    cnt[d] = 0;
    q.push({0, d});
    while (!q.empty())
    {
        int cur = q.top().second;
        int cur_cost = q.top().first;
        q.pop();
        if (cnt[cur] < cur_cost)continue;
        for (auto it : graph[cur])
        {
            if (cnt[it.first] > cnt[cur] + it.second)
            {
                cnt[it.first] = cnt[cur] + it.second;
                q.push({cnt[it.first], it.first});
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
        // graph[e].push_back({s, c});
    }
    fill(cnt, cnt + 1001, INT_MAX);
    cin >> a >> b;
    dijkstra(a);
    int g = b;
    while (g != a)
    {
        ans.push_back(g);
        g = parent[g];
    }
    ans.push_back(a);
    cout << cnt[b] << '\n';
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}