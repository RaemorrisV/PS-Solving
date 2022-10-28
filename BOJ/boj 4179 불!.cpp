#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
char maze[1001][1001];
bool visited[1001][1001];
int row, col; //행 열
pair<int, int> jhoon_idx;
int dis[1001][1001];
queue<pair<int, int>> Q;
bool edge(int r, int c)
{
    if (r == 1 || r == row || c == 1 || c == col)
        return true;
    return false;
}
bool valide(int r, int c)
{
    if (r >= 1 && r <= row && c >= 1 && c <= col)
        return true;
    return false;
}
void bfs(int s, int e)
{
    queue<pair<int, int>> q;
    q.push({s, e});
    visited[s][e] = true;
    while (!q.empty())
    {
        int t = Q.size();
        for (int i = 0; i < t; i++)
        {
            int fire_s = Q.front().first;
            int fire_e = Q.front().second;
            Q.pop();
            for (int j = 0; j < 4; j++)
            {
                if (valide(fire_s + dx[j], fire_e + dy[j]) && maze[fire_s + dx[j]][fire_e + dy[j]] != '#' && maze[fire_s + dx[j]][fire_e + dy[j]] != 'F')
                {
                    maze[fire_s + dx[j]][fire_e + dy[j]] = 'F';
                    Q.push({fire_s + dx[j], fire_e + dy[j]});
                }
            }
        }
        int T = q.size();
        for (int j = 0; j < T; j++)
        {
            int cur_s = q.front().first;
            int cur_e = q.front().second;
            if (edge(cur_s, cur_e))
            {
                cout << dis[cur_s][cur_e] + 1 << '\n';
                exit(0);
            }
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                if (visited[cur_s + dx[i]][cur_e + dy[i]] == false && maze[cur_s + dx[i]][cur_e + dy[i]] != '#' && maze[cur_s + dx[i]][cur_e + dy[i]] != 'F')
                {
                    visited[cur_s + dx[i]][cur_e + dy[i]] = true;
                    maze[cur_s + dx[i]][cur_e + dy[i]] = 'J';
                    dis[cur_s + dx[i]][cur_e + dy[i]] = dis[cur_s][cur_e] + 1;
                    q.push({cur_s + dx[i], cur_e + dy[i]});
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> row >> col;
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'J')
            {
                jhoon_idx.first = i;
                jhoon_idx.second = j;
            }
            else if (maze[i][j] == 'F')
            {
                Q.push({i, j});
            }
        }
    }
    bfs(jhoon_idx.first, jhoon_idx.second);
    return 0;
}