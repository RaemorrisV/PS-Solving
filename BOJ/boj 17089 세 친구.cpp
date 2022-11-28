#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
bool visited[4001];
vector<int> track;
vector<vector<int>> graph(4001);
int start;
int ans = 100000000;
void dfs(int s, int len)
{
    if (len == 3)
    {
        int cnt = 0;
        for (auto it : graph[s])
        {
            if (it == start)
            {
                for (int i = 0; i < track.size(); i++)
                {
                    cnt += graph[track[i]].size();
                }
                ans = min(ans, cnt - 6);
                break;
            }
        }
        return;
    }
    for (auto it : graph[s])
    {
        if (visited[it] == false)
        {
            visited[it] = true;
            track.push_back(it);
            dfs(it, len + 1);
            visited[it] = false;
            track.pop_back();
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
        graph[e].push_back(s);
    }
    for (int i = 1; i <= n; i++)
    {
        start = i;
        visited[i] = true;
        track.push_back(i);
        dfs(i, 1);
        visited[i] = false;
        track.pop_back();
    }
    if (ans == 100000000)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
    return 0;
}