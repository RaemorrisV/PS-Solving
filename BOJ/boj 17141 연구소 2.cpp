#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, 1, -1};
int room[51][51];
int temp[51][51];
bool visited[51][51];
bool v[10];
int n, m;
int virus_cnt = 0;
int MIN = 1000000000;
vector<pair<int, int>> virus;
vector<int> order;
bool full()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (temp[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
int bfs()
{
    int cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < order.size(); i++)
    {
        q.push({virus[order[i]].first, virus[order[i]].second});
        visited[virus[order[i]].first][virus[order[i]].second] = true;
    }
    while (!q.empty())
    {
        int size = q.size();
        for (int j = 0; j < size; j++)
        {
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];
                if (valide(nx, ny) && visited[nx][ny] == false && temp[nx][ny] != 1)
                {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    temp[nx][ny] = 1;
                }
            }
        }
        cnt++;
    }
    if (full())
    {
        return cnt - 1;
    }
    else
    {
        return 1000000000;
    }
}
void dfs(int s)
{
    order.push_back(s);
    if (order.size() == m)
    {
        copy(&room[0][0], &room[0][0] + 51 * 51, &temp[0][0]);
        MIN = min(MIN, bfs());
        memset(visited, 0, sizeof(visited));
        return;
    }
    for (int i = s; i < virus_cnt; i++)
    {
        if (v[i] == false)
        {
            v[i] = true;
            dfs(i);
            order.pop_back();
            v[i] = false;
        }
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
            cin >> room[i][j];
            if (room[i][j] == 2)
            {
                virus.push_back({i, j});
                virus_cnt++;
            }
        }
    }
    for (int i = 0; i < virus_cnt; i++)
    {
        if (v[i] == false)
        {
            v[i] = true;
            dfs(i);
            order.pop_back();
            v[i] = false;
        }
    }
    if (MIN == 1000000000)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << MIN << '\n';
    }
    return 0;
}