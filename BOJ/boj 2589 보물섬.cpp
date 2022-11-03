#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
char map[51][51];
bool visited[51][51];
int cnt[51][51];
int n, m; //행 열
int MAX = 0;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = true;
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        MAX = max(MAX, cnt[cur_r][cur_c]);
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 'L')
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt[nx][ny] = cnt[cur_r][cur_c] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m; //행 열
    for (int i = 1; i <= n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            map[i][j + 1] = input[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (map[i][j] == 'L' && visited[i][j] == false)
            {
                bfs(i, j);
                fill(&visited[0][0], &visited[n][m + 1], 0);
                fill(&cnt[0][0], &cnt[n][m + 1], 0);
            }
        }
    }
    cout << MAX << '\n';
    return 0;
}