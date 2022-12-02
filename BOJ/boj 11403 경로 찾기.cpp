#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, in;
int mat[101][101];
vector<vector<int>> graph(101);
bool visited[101];
void bfs(int s, int e)
{
    queue<int> q;
    // visited[s] = true;
    q.push(s);
    bool flag = false;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == e && flag)
        {
            mat[s][e] = 1;
        }
        flag = true;
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> in;
            if (in == 1)
            {
                graph[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            memset(visited, 0, sizeof(visited));
            bfs(i, j);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}