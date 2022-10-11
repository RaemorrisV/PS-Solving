#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;
int n, s, e, num;
int dis[101];
bool visited[101];
vector<vector<int>> graph(101);
void bfs(int start)
{
    queue<int> q;
    visited[start] = true;
    dis[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (auto it : graph[a])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
                dis[it] = dis[a] + 1;
            }
        }
    }
}
int main()
{
    cin >> n;
    cin >> s >> e;
    cin >> num;
    for (int i = 1; i <= num; i++)
    {
        int st, en;
        cin >> st >> en;
        graph[st].push_back(en);
        graph[en].push_back(st);
    }
    fill(dis, dis + (n + 1), INT_MAX);
    bfs(s);
    if (dis[e] == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << dis[e] << endl;
    }
    return 0;
}