#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k, x;
vector<vector<int>> graph(300001);
vector<int> ans;
bool visited[300001];
int cnt[300001];
void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        if (cnt[cur] == k)
        {
            ans.push_back(cur);
        }
        q.pop();
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                cnt[it] = cnt[cur] + 1;
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
    }
    bfs(x);
    if (ans.empty())
    {
        cout << "-1" << '\n';
    }
    else
    {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}