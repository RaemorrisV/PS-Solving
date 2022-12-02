#include <iostream>
#include <string>
using namespace std;

int n;
int home[17][17];
int ans = 0;
bool visited[17][17];
int dx[3] = {0, 1, 1}; //가로 세로 대각선
int dy[3] = {1, 0, 1};
bool cross(int r, int c)
{
    if (home[r][c] == 1 || home[r][c - 1] == 1 || home[r - 1][c] == 1)
        return false;
    return true;
}
bool row(int r, int c)
{
    if (home[r][c] == 1)
        return false;
    return true;
}
bool col(int r, int c)
{
    if (home[r][c] == 1)
        return false;
    return true;
}
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
void dfs(int a, int b, string status)
{
    //cout<<a<<" "<<b<<" "<<status<<endl;
    if (a == n && b == n)
    {
        ans++;
        return;
    }
    if (status == "row")
    {
        for (int i = 0; i < 3; i += 2)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false)
            {
                if (i == 0 && row(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "row");
                    visited[nx][ny] = false;
                }
                else if (i == 2 && cross(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "cross");
                    visited[nx][ny] = false;
                }
            }
        }
    }
    else if (status == "col")
    {
        for (int i = 1; i <= 2; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false)
            {
                if (i == 1 && col(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "col");
                    visited[nx][ny] = false;
                }
                else if (i == 2 && cross(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "cross");
                    visited[nx][ny] = false;
                }
            }
        }
    }
    else if (status == "cross")
    {
        for (int i = 0; i < 3; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false)
            {
                if (i == 1 && col(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "col");
                    visited[nx][ny] = false;
                }
                else if (i == 2 && cross(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "cross");
                    visited[nx][ny] = false;
                }
                else if (i == 0 && row(nx, ny))
                {
                    visited[nx][ny] = true;
                    dfs(nx, ny, "row");
                    visited[nx][ny] = false;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> home[i][j];
        }
    }
    dfs(1, 2, "row");
    cout << ans << '\n';
    return 0;
}