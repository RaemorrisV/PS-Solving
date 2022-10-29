#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[501][501];
int n, m; //행 열
int paper[501][501];
int dx[4] = { -1, 1, 0, 0 }; //상 하 좌 우
int dy[4] = { 0, 0, -1, 1 };
int cnt = 0;
int sum = 1;
int MAX = 0;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({ r, c });
    visited[r][c] = true;
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && paper[nx][ny] == 1)
            {
                sum++;
                visited[nx][ny] = true;
                q.push({ nx, ny });
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
            cin >> paper[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == false&& paper[i][j]==1)
            {
                bfs(i, j);
                cnt++;
                MAX = max(MAX, sum);
                sum = 1;
            }
        }
    }
    cout << cnt << '\n' << MAX << '\n';
    return 0;
}