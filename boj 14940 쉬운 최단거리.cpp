#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
bool visited[1001][1001];
int map[1001][1001];
int cnt[1001][1001];
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
pair<int, int> s_idx;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    cnt[r][c] = 0;
    visited[r][c] = true;
    while (!q.empty())
    {
        int c_r = q.front().first;
        int c_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = c_r + dx[i];
            int ny = c_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 1)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt[nx][ny] = cnt[c_r][c_c] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m; //행 열
    fill(&cnt[0][0], &cnt[n][m + 1], -1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                s_idx.first = i;
                s_idx.second = j;
            }
            else if (map[i][j] == 0)
            {
                cnt[i][j] = 0;
            }
        }
    }
    bfs(s_idx.first, s_idx.second);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << cnt[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
