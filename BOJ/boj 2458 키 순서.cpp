#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
vector<vector<int>> graph(501);
vector<vector<int>> graph2(501);
bool visited[501];
int out[501];
int in[501];
int ans = 0;
void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                q.push(it);
                visited[it] = true;
                out[s]++;
            }
        }
    }
}
void bfs2(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : graph2[cur])
        {
            if (visited[it] == false)
            {
                q.push(it);
                visited[it] = true;
                in[s]++;
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
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph2[e].push_back(s);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(visited, 0, sizeof(visited));
        bfs(i);
        memset(visited, 0, sizeof(visited));
        bfs2(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (out[i] + in[i] == n - 1)ans++;
    }
    cout << ans << '\n';
    return 0;
}