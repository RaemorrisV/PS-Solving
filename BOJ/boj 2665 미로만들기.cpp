#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int n, m, a, b;
int cnt[51][51];
int room[51][51];
int parent[1001];
string input;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
vector<vector<pair<int, int>>> graph(1001);
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
void dijkstra(int r, int c)
{
    queue<pair<int, int>> q;
    cnt[r][c] = 0;
    q.push({r, c});
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && room[nx][ny] == 1) //흰방을 지나감
            {
                if (cnt[nx][ny] > cnt[cur_r][cur_c])
                {
                    cnt[nx][ny] = cnt[cur_r][cur_c];
                    q.push({nx, ny});
                }
            }
            if (valide(nx, ny) && room[nx][ny] == 0) //검은방을 지나감
            {
                if (cnt[nx][ny] > cnt[cur_r][cur_c] + 1)
                {
                    cnt[nx][ny] = cnt[cur_r][cur_c] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < n; j++)
        {
            room[i + 1][j + 1] = input[j] - '0';
        }
    }
    fill(&cnt[0][0], &cnt[50][51], INT_MAX);
    dijkstra(1, 1);
    cout << cnt[n][n] << '\n';
    return 0;
}