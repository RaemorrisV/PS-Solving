#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k;
bool visited[100][100];
int paper[100][100];
vector<int> area;
int cnt = 1;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, 1, -1};
int division = 0;
bool valide(int r, int c)
{
    if (r > -1 && r < m && c > -1 && c < n)
        return true;
    return false;
}
void bfs(int r, int c)
{
    queue<pair<int, int>> q;
    visited[r][c] = true;
    q.push({r, c});
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (valide(cur_r + dx[i], cur_c + dy[i]) && visited[cur_r + dx[i]][cur_c + dy[i]] == false && paper[cur_r + dx[i]][cur_c + dy[i]] == 0)
            {
                visited[cur_r + dx[i]][cur_c + dy[i]] = true;
                q.push({cur_r + dx[i], cur_c + dy[i]});
                cnt++;
            }
        }
    }
    area.push_back(cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> n >> k; //행 열
    for (int i = 0; i < k; i++)
    {
        int s, e, s1, e1;
        cin >> s >> e >> s1 >> e1;
        for (int j = m - e1; j < m - e; j++)
        {
            for (int k = s; k < s1; k++)
            {
                paper[j][k] = 1;
            }
        }
    }
    for (int j = 0; j < m; j++)
    {
        for (int k = 0; k < n; k++)
        {
            if (visited[j][k] == false && paper[j][k] == 0)
            {
                bfs(j, k);
                division++;
                cnt = 1;
            }
        }
    }
    cout << division << '\n';
    sort(area.begin(), area.end());
    for (int i = 0; i < area.size(); i++)
    {
        cout << area[i] << " ";
    }
    cout << '\n';
    return 0;
}