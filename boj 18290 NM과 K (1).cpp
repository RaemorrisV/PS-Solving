#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
//인접을 어떻게 구현 할 것이냐
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int table[11][11];
bool visited[11][11];
int n, m, k;
int MAX = -100000000;
int sum = 0;
bool possible(int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        if (r + dx[i] >= 1 && r + dx[i] <= n && c + dy[i] >= 1 && c + dy[i] <= m)
        {
            if (visited[r + dx[i]][c + dy[i]] == true)
            {
                return false;
            }
        }
    }
    return true;
}
void dfs(int s, int r, int c, int cnt)
{
    sum += s;
    if (cnt == k)
    {
        MAX = max(MAX, sum);
        return;
    }
    for (int i = r; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == false && possible(i, j))
            {
                visited[i][j] = true;
                dfs(table[i][j], i, j, cnt + 1);
                visited[i][j] = false;
                sum -= table[i][j];
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                dfs(table[i][j], i, j, 1);
                visited[i][j] = false;
                sum -= table[i][j];
            }
        }
    }
    cout << MAX << '\n';
    return 0;
}