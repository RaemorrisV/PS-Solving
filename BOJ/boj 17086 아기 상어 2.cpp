#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int space[51][51];
int cnt[51][51];
bool visited[51][51];
int MAX = 0;
int comp;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt[nx][ny] += cnt[cur_r][cur_c] + 1;
                if (space[nx][ny] == 1)
                {
                    comp = cnt[nx][ny];
                    while (!q.empty())
                    {
                        q.pop();
                    }
                    break;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> space[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (space[i][j] == 0)
            {
                bfs(i, j);
                memset(visited, 0, sizeof(visited));
                fill(&cnt[0][0], &cnt[n][m + 1], 0);
                MAX = max(comp, MAX);
            }
        }
    }
    cout << MAX << '\n';
    return 0;
}