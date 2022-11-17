#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> graph(101);
int cnt[101];
bool visited[101];
int n, m; //사다리의 수 뱀의 수
bool valide(int a)
{
    if (a <= 100)return true;
    return false;
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    cnt[s] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : graph[cur])
        {
            if (valide(it))
            {
                if (graph[cur].size() != 1)
                {
                    if (cnt[it] > cnt[cur] + 1)
                    {
                        q.push(it);
                        cnt[it] = cnt[cur] + 1;
                    }
                }
                else if (graph[cur].size() == 1) //뱀 이나 사다리
                {
                    q.push(it);
                    cnt[it] = cnt[cur];
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) //사다리
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
    }
    for (int i = 0; i < m; i++) //뱀
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for (int i = 1; i <= 100; i++) //그래프 생성
    {
        if (graph[i].size() != 1)
        {
            for (int j = 1; j <= 6; j++)
            {
                graph[i].push_back(i + j);
            }
        }
    }
    fill(cnt, cnt + 101, 100000000);
    bfs(1);
    cout << cnt[100] << '\n';
    return 0;
}