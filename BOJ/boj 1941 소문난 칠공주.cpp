#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

char room[6][6];
bool visited[25];
bool v[6][6];
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
vector<int> com;
vector<pair<int, int>> all;
int ans = 0;
bool valide(int r, int c)
{
    if (r >= 1 && r <= 5 && c >= 1 && c <= 5)
        return true;
    return false;
}
string in;
bool bfs(int r, int c)
{
    queue<pair<int, int>> q;
    v[r][c] = true;
    q.push({r, c});
    int da = 0;
    int im = 0;
    int cnt = 1;
    if (room[r][c] == 'S')
    {
        da++;
    }
    else
    {
        im++;
    }
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && v[nx][ny] == false)
            {
                q.push({nx, ny});
                v[nx][ny] = true;
                cnt++;
                if (room[nx][ny] == 'S')
                {
                    da++;
                }
                else
                {
                    im++;
                }
            }
        }
    }
    if (cnt == 7 && da >= 4)
    {
        return true;
    }
    return false;
}
void dfs(int s)
{
    if (com.size() == 7)
    {
        fill(&v[0][0], &v[5][6], 1);
        for (int i = 0; i < 7; i++)
        {
            v[all[com[i]].first][all[com[i]].second] = false;
        }
        if (bfs(all[com[0]].first, all[com[0]].second))
        {
            ans++;
        }
        return;
    }
    for (int i = s; i < all.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            com.push_back(i);
            dfs(i);
            com.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 1; i <= 5; i++)
    {
        cin >> in;
        for (int j = 1; j <= 5; j++)
        {
            room[i][j] = in[j - 1];
            all.push_back({i, j});
        }
    }
    for (int i = 0; i <= 18; i++)
    {
        visited[i] = true;
        com.push_back(i);
        dfs(i);
        com.pop_back();
        visited[i] = false;
    }
    cout << ans << '\n';
    return 0;
}