#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
#include <vector>
using namespace std;

int w, h;
int cnt[101][101];
vector<pair<int, int>> raiser;
string in;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
char map[101][101];
struct info
{
    int x;
    int y;
    int dir;
    int dis;
};
bool valide(int r, int c)
{
    if (r >= 1 && r <= h && c >= 1 && c <= w)
        return true;
    return false;
}
struct compare
{
    bool operator()(info a, info b)
    {
        return a.dis > b.dis;
    }
};
void bfs(int s, int e)
{
    priority_queue<info, vector<info>, compare> q;
    cnt[s][e] = 0;
    for (int i = 0; i < 4; i++)
    {
        q.push({raiser[0].first, raiser[0].second, i, 0});
    }
    while (!q.empty())
    {
        int cur_r = q.top().x;
        int cur_c = q.top().y;
        int cur_d = q.top().dir;
        int cur_dis = q.top().dis;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && map[nx][ny] != '*')
            {
                if (cur_d != i)
                {
                    if (cnt[nx][ny] >= cur_dis + 1)
                    {

                        cnt[nx][ny] = cur_dis + 1;
                        q.push({nx, ny, i, cnt[nx][ny]});
                    }
                }
                else
                {
                    if (cnt[nx][ny] >= cur_dis)
                    {
                        cnt[nx][ny] = cur_dis;
                        q.push({nx, ny, i, cnt[nx][ny]});
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> w >> h;
    for (int i = 1; i <= h; i++)
    {
        cin >> in;
        for (int j = 1; j <= w; j++)
        {
            map[i][j] = in[j - 1];
            if (map[i][j] == 'C')
            {
                raiser.push_back({i, j});
            }
        }
    }
    fill(&cnt[0][0], &cnt[100][101], INT_MAX);
    bfs(raiser[0].first, raiser[0].second);
    cout << cnt[raiser[1].first][raiser[1].second] << '\n';
    return 0;
}