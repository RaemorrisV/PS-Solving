#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int map[101][101];
bool visited[101][101];
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int n, m; //행 열
int cheezecnt = 0;
int t = 0;
vector<pair<int, int>> cheeze;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)
        return true;
    return false;
}
void bfs()
{
    queue<pair<int, int>> q;
    visited[1][1] = true;
    q.push({1, 1});
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
                visited[nx][ny] = true;
                cheeze.push_back({nx, ny});
            }
            if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 0)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}
void simulation() //남아있는 치즈의 개수를 리턴하는 함수
{
    for (int i = 0; i < cheeze.size(); i++)
    {
        map[cheeze[i].first][cheeze[i].second] = 0;
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
            cin >> map[i][j];
        }
    }
    while (1)
    {
        bfs();
        simulation();
        if (cheeze.size() != 0)
        {
            cheezecnt = cheeze.size();
        }
        else
        {
            break;
        }
        t++;
        memset(visited, 0, sizeof(visited));
        cheeze.clear();
    }
    cout << t << '\n' << cheezecnt << '\n';
    return 0;
}