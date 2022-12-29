#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int MIN = 1e9;
int lab[51][51];
bool visited[51][51];
int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> active;
vector<pair<int, int>> disable;
vector<int> order;
int totalroom = 0;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
int bfs()
{
    queue<pair<int, int>> q;
    int cnt = 0;
    int virus = disable.size();
    for (int i = 0; i < active.size(); i++)
    {
        q.push({active[i].first, active[i].second});
        visited[active[i].first][active[i].second] = true;
    }
    while (!q.empty())
    {
        int size = q.size();
        if (virus == totalroom)
        {
            return cnt;
        }
        for (int j = 0; j < size; j++)
        {
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];
                if (valide(nx, ny) && visited[nx][ny] == false && lab[nx][ny] != 1)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    if (lab[nx][ny] != 2)
                        virus++;
                }
            }
        }
        cnt++;
    }
    return MIN;
}
void dfs(int s)
{
    if (order.size() == m)
    {
        for (int i = 0; i < order.size(); i++)
        {
            active.push_back({disable[order[i]].first, disable[order[i]].second});
        }
        MIN = min(MIN, bfs());
        active.clear();
        memset(visited, 0, sizeof(visited));
        return;
    }
    for (int i = s + 1; i < disable.size(); i++)
    {
        order.push_back(i);
        dfs(i);
        order.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 2)
                disable.push_back({i, j});
            if (lab[i][j] != 1)
                totalroom++;
        }
    }
    for (int i = 0; i < disable.size(); i++)
    {
        order.push_back(i);
        dfs(i);
        order.pop_back();
    }
    if (MIN != 1e9)
    {
        cout << MIN << '\n';
    }
    else
    {
        cout << "-1" << '\n';
    }
    return 0;
}