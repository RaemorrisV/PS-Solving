#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int map[201][201];
bool visited[201][201];
vector<vector<pair<int, int>>> virus(1001);
int s, x, y;
struct info
{
    int row;
    int col;
    int kind;
};
bool valid(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
void bfs()
{
    queue<info> q;
    for (int i = 1; i <= k; i++)
    {
        if (!virus[i].empty())
        {
            for (int j = 0; j < virus[i].size(); j++)
            {
                if (visited[virus[i][j].first][virus[i][j].second] == false)
                {
                    q.push({virus[i][j].first, virus[i][j].second, i});
                    visited[virus[i][j].first][virus[i][j].second] = true;
                }
            }
        }
    }
    for (int p = 0; p < s; p++)
    {
        int size = q.size();
        for (int z = 0; z < size; z++)
        {
            int cur_r = q.front().row;
            int cur_c = q.front().col;
            int cur_kind = q.front().kind;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];
                if (valid(nx, ny) && visited[nx][ny] == false && map[nx][ny] == 0)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny, cur_kind});
                    map[nx][ny] = cur_kind;
                }
            }
        }
        /*
        cout << p + 1 << " 째 " << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }
        */
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            if (map[i][j] != 0)
            {
                virus[map[i][j]].push_back({i, j});
            }
        }
    }
    cin >> s >> x >> y;
    bfs();
    cout << map[x][y] << '\n';
    return 0;
}