#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int space[7][7];
int MIN = 100000;
int n, m; //행 열
bool visited[7][7];
int dx[3] = {1, 1, 1};  //행
int dy[3] = {-1, 0, 1}; //열
int cnt = 0;
bool valid(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)
        return true;
    return false;
}
void dfs(int s, int r, int before)
{
    cnt += space[s][r];
    visited[s][r] = true;
    if (s == n) //끝까지 가면 return;
    {
        MIN = min(cnt, MIN);
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        if (i != before)
        {
            if (valid(s + dx[i], r + dy[i]) && visited[s + dx[i]][r + dy[i]] == false)
            {
                dfs(s + dx[i], r + dy[i], i);
                cnt -= space[s + dx[i]][r + dy[i]];
                visited[s + dx[i]][r + dy[i]] = false;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> space[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        dfs(1, i, 4);
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        // fill(&visited[0][0], &visited[n - 1][m], 0);
    }
    cout << MIN << endl;
    return 0;
}