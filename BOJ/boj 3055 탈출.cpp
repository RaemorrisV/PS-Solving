#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int R, C;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
char map[51][51];
bool visited[51][51];
pair<int, int> biber;
pair<int, int> start;
string a;
int t = 0;
vector<pair<int, int>> water;
bool valide(int r, int c)
{
    if (r >= 1 && r <= R && c >= 1 && c <= C)return true;
    return false;
}
bool bfs(int r, int c)
{
    queue<pair<int, int>> q;
    queue<pair<int, int>> wq;
    for (int i = 0; i < water.size(); i++)
    {
        visited[water[i].first][water[i].second] = true;
        wq.push({water[i].first, water[i].second});
    }
    visited[r][c] = true;
    q.push({r, c});
    while (!q.empty())
    {
        //물 부터 실핼ㅇ
        int size = wq.size();
        for (int j = 0; j < size; j++)
        {
            int cur_r = wq.front().first;
            int cur_c = wq.front().second;
            wq.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];
                if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] != 'X' && map[nx][ny] != 'D')
                {
                    visited[nx][ny] = true;
                    wq.push({nx, ny});
                    map[nx][ny] = '*';
                }
                if (map[nx][ny] == 'S')
                {
                    wq.push({nx, ny});
                    map[nx][ny] = '*';
                }
            }
        }
        size = q.size();
        for (int j = 0; j < size; j++)
        {
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];
                if (map[nx][ny] == 'D')
                {
                    return true;
                }
                if (valide(nx, ny) && visited[nx][ny] == false && map[nx][ny] != 'X' && map[nx][ny] != '*')
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    map[nx][ny] = 'S';
                }
            }
        }
        t++;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        cin >> a;
        for (int j = 1; j <= C; j++)
        {
            map[i][j] = a[j - 1];
            if (map[i][j] == 'S')
            {
                start = {i, j};
            }
            if (map[i][j] == 'D')
            {
                biber = {i, j};
            }
            if (map[i][j] == '*')
            {
                water.push_back({i, j});
            }
        }
    }
    if (bfs(start.first, start.second))
    {
        cout << t + 1 << '\n';
    }
    else
    {
        cout << "KAKTUS " << '\n';
    }
    return 0;
}