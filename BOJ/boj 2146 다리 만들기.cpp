#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int map[101][101];
bool visited[101][101];
short int island[101][101];
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int n;
int cnt = 1;
int MIN = 1000000000;
struct info
{
    int x;
    int y;
    int dis;
};
vector<pair<int, int>> idx;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)return true;
    return false;
}
void bfs1(int r, int c, int num)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    island[r][c] = num;
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 1)
            {
                island[nx][ny] = num;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
void bfs2(int r, int c)
{
    queue<info> q;
    q.push({r, c, 0});
    visited[r][c] = true;
    while (!q.empty())
    {
        int cur_r = q.front().x;
        int cur_c = q.front().y;
        int cur_dis = q.front().dis;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 1 && island[r][c] != island[nx][ny])
            {
                MIN = min(MIN, cur_dis);
                return;
            }
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 0)
            {
                visited[nx][ny] = true;
                q.push({nx, ny, cur_dis + 1});
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
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j] == 1)
            {
                if (visited[i][j] == false)
                {
                    bfs1(i, j, cnt++);
                }
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (valide(nx, ny) && map[nx][ny] == 0)
                    {
                        idx.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < idx.size(); i++)
    {
        memset(visited, 0, sizeof(visited));
        bfs2(idx[i].first, idx[i].second);
    }
    cout << MIN << '\n';
    return 0;
}