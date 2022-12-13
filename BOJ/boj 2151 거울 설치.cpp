#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;
char home[51][51];
int n;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우 0 1 2 3
int dy[4] = {0, 0, -1, 1};
int cnt[51][51][4];
int MIN = INT_MAX;
vector<pair<int, int>> door;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
struct info
{
    int x;
    int y;
    int dir;
};
void bfs(int s, int e)
{
    queue<info> q;
    for (int i = 0; i < 4; i++)
    {
        cnt[s][e][i] = 0;
        q.push({s, e, i});
    }
    while (!q.empty())
    {
        int cur_r = q.front().x;
        int cur_c = q.front().y;
        int cur_d = q.front().dir;
        q.pop();
        int nx = cur_r + dx[cur_d];
        int ny = cur_c + dy[cur_d];
        if (valide(nx, ny) && home[nx][ny] == '!')
        {
            if (cnt[nx][ny][cur_d] > cnt[cur_r][cur_c][cur_d])
            {
                cnt[nx][ny][cur_d] = cnt[cur_r][cur_c][cur_d];
                q.push({nx, ny, cur_d});
            }
            if (cur_d == 0 || cur_d == 1)
            {
                for (int j = 2; j <= 3; j++)
                {
                    if (cnt[nx][ny][j] > cnt[cur_r][cur_c][cur_d] + 1)
                    {
                        cnt[nx][ny][j] = cnt[cur_r][cur_c][cur_d] + 1;
                        q.push({nx, ny, j});
                    }
                }
            }
            else
            {
                for (int j = 0; j <= 1; j++)
                {
                    if (cnt[nx][ny][j] > cnt[cur_r][cur_c][cur_d] + 1)
                    {
                        cnt[nx][ny][j] = cnt[cur_r][cur_c][cur_d] + 1;
                        q.push({nx, ny, j});
                    }
                }
            }
        }
        else if (valide(nx, ny) && home[nx][ny] != '*')
        {
            if (cnt[nx][ny][cur_d] > cnt[cur_r][cur_c][cur_d])
            {
                cnt[nx][ny][cur_d] = cnt[cur_r][cur_c][cur_d];
                q.push({nx, ny, cur_d});
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
        string in;
        cin >> in;
        for (int j = 1; j <= n; j++)
        {
            home[i][j] = in[j - 1];
            if (in[j - 1] == '#')
            {
                door.push_back({i, j});
            }
            for (int k = 0; k < 4; k++)
            {
                cnt[i][j][k] = INT_MAX;
            }
        }
    }
    bfs(door[0].first, door[0].second);
    for (int i = 0; i < 4; i++)
    {
        MIN = min(cnt[door[1].first][door[1].second][i], MIN);
    }
    cout << MIN << '\n';
    return 0;
}