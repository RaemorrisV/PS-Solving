#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int map[100][100];
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int n, m; //행열
int MIN = 1000000;
struct info
{
    int x;
    int y;
    int cnt;
};
struct compare
{
    bool operator()(info a, info b)
    {
        return a.cnt > b.cnt;
    }
};
bool valide(int r, int c)
{
    if (r >= 0 && r < n && c >= 0 && c < m)return true;
    return false;
}
void bfs(int r, int c)
{
    priority_queue<info, vector<info>, compare> q;
    visited[r][c] = true;
    q.push({r, c, 0});
    while (!q.empty())
    {
        int cur_r = q.top().x;
        int cur_c = q.top().y;
        int cur_cnt = q.top().cnt;
        q.pop();
        if (cur_r == n - 1 && cur_c == m - 1)
        {
            cout << cur_cnt << "\n";
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false)
            {
                visited[nx][ny] = true;
                if (map[nx][ny] == 1)
                {
                    q.push({nx, ny, cur_cnt + 1});
                }
                else
                {
                    q.push({nx, ny, cur_cnt});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            map[i][j] = input[j] - '0';
        }
    }
    bfs(0, 0);
    return 0;
}