#include <iostream>
#include <queue>

using namespace std;
int R, C;
bool visited[251][251];
char map[251][251];
int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int wolf = 0;
int yang = 0;
bool valide(int r, int c)
{
    if (r >= 1 && r <= R && c >= 1 && c <= C)
        return true;
    return false;
}
void bfs(int s, int e)
{
    queue<pair<int, int>> q;
    visited[s][e] = true;
    q.push({s, e});
    int wolf_c = 0;
    int yang_c = 0;
    if (map[s][e] == 'v')
        wolf_c++;
    else if (map[s][e] == 'o')
        yang_c++;
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] != '#')
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                if (map[nx][ny] == 'v')
                    wolf_c++;
                else if (map[nx][ny] == 'o')
                    yang_c++;
            }
        }
    }
    if (wolf_c < yang_c)
    {
        wolf -= wolf_c;
    }
    else
    {
        yang -= yang_c;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        string in;
        cin >> in;
        for (int j = 1; j <= C; j++)
        {
            map[i][j] = in[j - 1];
            if (map[i][j] == 'v')
                wolf++;
            else if (map[i][j] == 'o')
                yang++;
        }
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (visited[i][j] == false && map[i][j] != '#')
            {
                bfs(i, j);
            }
        }
    }
    cout << yang << " " << wolf << endl;
    return 0;
}