#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n, m;
int map[51][51];
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}; // 이동방향
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int d, s;
bool visited[51][51];
int sum = 0;
vector<pair<int, int>> cloud;
int nx_next(int nx)
{
    if (nx > n)
        return 1;
    else if (nx < 1)
        return n;
    else
        return nx;
}
int ny_next(int ny)
{
    if (ny > n)
        return 1;
    else if (ny < 1)
        return n;
    else
        return ny;
}
bool valid(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
void simulation()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j])
            {
                cloud.push_back({i, j});
            }
        }
    }
    memset(visited, 0, sizeof(visited));
    // 1단계
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < cloud.size(); j++)
        {
            int nx = cloud[j].first + dx[d];
            int ny = cloud[j].second + dy[d];
            nx = nx_next(nx);
            ny = ny_next(ny);
            cloud[j] = {nx, ny};
        }
    }
    // 2단계
    for (int j = 0; j < cloud.size(); j++)
    {
        map[cloud[j].first][cloud[j].second]++;
        visited[cloud[j].first][cloud[j].second] = true;
    }
    // 4단계
    for (int j = 0; j < cloud.size(); j++)
    {
        int cnt = 0;
        for (int i = 2; i <= 8; i += 2)
        {
            int nx = cloud[j].first + dx[i];
            int ny = cloud[j].second + dy[i];
            if (valid(nx, ny))
            {
                if (map[nx][ny] > 0)
                    cnt++;
            }
        }
        map[cloud[j].first][cloud[j].second] += cnt;
    }
    // 5단계
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] == false && map[i][j] >= 2)
            {
                map[i][j] -= 2;
                visited[i][j] = true;
            }
        }
    }
    // 여기다 초기화
    for (int i = 0; i < cloud.size(); i++)
    {
        visited[cloud[i].first][cloud[i].second] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }
    cloud.push_back({n, 1});
    cloud.push_back({n, 2});
    cloud.push_back({n - 1, 1});
    cloud.push_back({n - 1, 2});
    for (int i = 0; i < m; i++)
    {
        cin >> d >> s;
        simulation();
        cloud.clear();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            sum += map[i][j];
        }
    }
    cout << sum << '\n';
    return 0;
}