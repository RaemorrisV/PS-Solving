#include <iostream>
#include <vector>
using namespace std;

int visited[51][51];
int n;
vector<double> per;
int dx[4] = {0, 0, 1, -1}; //동 서 남 북
int dy[4] = {-1, 1, 0, 0};
double ans = 0.0;
int cnt = 0;
void dfs(int len, int cur_r, int cur_c, double t)
{
    if (len == n)
    {
        ans += t;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = cur_r + dx[i];
        int ny = cur_c + dy[i];
        if (visited[nx][ny] + 1 <= 1 && per[i] != 0)
        {
            visited[nx][ny]++;
            dfs(len + 1, nx, ny, t * per[i]);
            visited[nx][ny]--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        double in;
        cin >> in;
        per.push_back(in / 100);
    }
    visited[25][25] = 1;
    dfs(0, 25, 25, 1.00);
    cout.precision(10);
    cout << fixed;
    cout << ans << '\n';
    return 0;
}