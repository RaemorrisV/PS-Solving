#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m;
int MAX = 0;
vector<vector<int>> graph(10001);
vector<pair<int, int>> ans;
bool visited[10001];
int bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    int cnt = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
                cnt++;
            }
        }
    }
    ans.push_back({s, cnt});
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[e].push_back(s);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        MAX = max(bfs(i), MAX);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        if (ans[i].second == MAX)
        {
            cout << ans[i].first << " ";
        }
    }
    cout << '\n';
    return 0;
}