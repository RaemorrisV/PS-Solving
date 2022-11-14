#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int n, m;
char map[51][51];
bool visited[51][51];
int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
string input;
int c_s, c_e;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void dfs(int r, int c, int len)
{
    visited[r][c] = true;
   // cout << r << " " << c << endl;
    int cyclecheck = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == map[c_s][c_e])
        {
            cyclecheck++;
            dfs(nx, ny, len + 1);
        }
    }
    if (cyclecheck == 0 && len >= 4)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = r + dx[i];
            int ny = c + dy[i];
            if (nx == c_s && ny == c_e && visited[nx][ny])
            {
                cout << "Yes" << '\n';
                exit(0);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            map[i + 1][j + 1] = input[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == false)
            {
                c_s = i;
                c_e = j;
                dfs(i, j, 1);
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}