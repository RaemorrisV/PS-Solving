#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

char building[31][31][31]; // 층 행 렬
bool visited[31][31][31];
int cnt[31][31][31];
int dx[6] = {0, 0, 1, -1, 0, 0}; // 동 서 남 북 상 하
int dy[6] = {1, -1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int R, C, L;
string input;
struct info
{
    int x;
    int y;
    int z;
};
info start;
info End;
bool valide(int h, int r, int c)
{
    if (r >= 1 && r <= R && c >= 1 && c <= C && h >= 1 && h <= L)
        return true;
    return false;
}
void bfs(int h, int r, int c)
{
    queue<info> q;
    visited[h][r][c] = true;
    q.push({h, r, c});
    while (!q.empty())
    {
        int cur_r = q.front().y;
        int cur_c = q.front().z;
        int cur_h = q.front().x;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            int nz = cur_h + dz[i];
            if (valide(nz, nx, ny) && visited[nz][nx][ny] == false && building[nz][nx][ny] != '#')
            {
                visited[nz][nx][ny] = true;
                q.push({nz, nx, ny});
                cnt[nz][nx][ny] = cnt[cur_h][cur_r][cur_c] + 1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1)
    {
        cin >> L >> R >> C;
        if (R == 0 && C == 0 && L == 0)
            break;
        else
        {
            memset(visited, 0, sizeof(visited));
            memset(cnt, 0, sizeof(cnt));
            for (int i = 1; i <= L; i++) //높이
            {
                for (int j = 1; j <= R; j++) //행
                {
                    cin >> input;
                    for (int k = 1; k <= C; k++) //열
                    {
                        building[i][j][k] = input[k - 1];
                        if (input[k - 1] == 'S')
                        {
                            start = {j, k, i};
                        }
                        if (input[k - 1] == 'E')
                        {
                            End = {j, k, i};
                        }
                    }
                }
            }
            bfs(start.z, start.x, start.y);
            if (cnt[End.z][End.x][End.y] != 0)
            {
                cout << "Escaped in " << cnt[End.z][End.x][End.y] << " minute(s)." << '\n';
            }
            else
            {
                cout << "Trapped!" << '\n';
            }
        }
    }
    return 0;
}
