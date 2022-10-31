#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int>> graph(3001);
int n;
int dis[3001];
int visited[3001];
bool cycle[3001];
int start;
int dfs(int v, int p)
{
    for (auto it : graph[v])
    {
        if (it == p)
            continue;
        if (visited[it] == false)
        {
            visited[it] = true;
            cycle[it] = dfs(it, v);
            if (cycle[it] == 1 && it == start)
                return 0;
            else if (cycle[it] == 1)
                return 1;
        }
        else if (visited[it]) // cycle 발생
        {
            start = it;
            return 1; // 순환임
        }
    }
    return 0; //순환 아님
}
int bfs(int s)
{
    visited[s] = true;
    queue<int> q;
    q.push(s);
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
                dis[it] = dis[cur] + 1;
            }
            if (cycle[it] == 1)
            {
                return dis[it];
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    visited[1] = true;
    cycle[1] = dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++)
    {
        if (cycle[i] == 1)
        {
            cout << "0"<< " ";
        }
        else
        {
            cout << bfs(i) << " ";
        }
        memset(dis, 0, sizeof(dis));
        memset(visited, 0, sizeof(visited));
    }
    cout << '\n';
    return 0;
}