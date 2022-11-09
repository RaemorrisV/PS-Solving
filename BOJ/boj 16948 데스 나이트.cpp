#include <iostream>
#include <queue>

using namespace std;

int n, s, t, e1, e2;
int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};
int cnt[200][200];
bool visited[200][200];
bool valide(int r, int c)
{
    if (r >= 0 && r < n && c >= 0 && c < n)return true;
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
        if (cur_r == e1 && cur_c == e2)
        {
            cout << cnt[e1][e2] << '\n';
            exit(0);
        }
        for (int i = 0; i < 6; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false)
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
    cin >> n;
    cin >> s >> t >> e1 >> e2;
    bfs(s, t);
    cout << "-1" << '\n';
    return 0;
}