#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, a, b;
vector<vector<pair<int, int>>> graph(10001);
pair<int, int> factory;
int max_w = -1;
bool visited[10001];
bool bfs(int cost)
{
    queue<int> q;
    q.push(factory.first);
    visited[factory.first] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == factory.second)return true;
        for (auto it : graph[cur])
        {
            if (visited[it.first] == false && cost <= it.second)
            {
                visited[it.first] = true;
                q.push(it.first);
            }
        }
    }
    return false;
}
int binary_search()
{
    int s = 1;
    int e = max_w;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        memset(visited, 0, sizeof(visited));
        if (bfs(mid))
        {
            s = mid + 1;
            mid = (s + e) / 2;
        }
        else
        {
            e = mid - 1;
            mid = (s + e) / 2;
        }
    }
    return mid;
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
        max_w = max(max_w, c);
    }
    cin >> a >> b;
    factory = {a, b};
    cout << binary_search() << '\n';
    return 0;
}