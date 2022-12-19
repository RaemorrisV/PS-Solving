#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
bool visited[21][21];
int ad_like[21][21];
int emp[21][21];
int total[21][21];
int n, x, y;
int num = 0;
vector<vector<int>> like(401);
bool valid(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
void simulation(int num)
{
    int condition1 = 0;
    int MAX = 0;
    for (int i = 1; i <= n; i++) // 조건 1
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] == false)
            {
                for (int z = 0; z < 4; z++)
                {
                    int nx = i + dx[z];
                    int ny = j + dy[z];
                    if (valid(nx, ny) && find(like[num].begin(), like[num].end(), total[nx][ny]) != like[num].end())
                    {
                        ad_like[i][j]++;
                    }
                }
                MAX = max(ad_like[i][j], MAX);
            }
        }
    }
    for (int i = 1; i <= n; i++) // 조건 1
    {
        for (int j = 1; j <= n; j++)
        {
            if (visited[i][j] == false && ad_like[i][j] == MAX)
            {
                condition1++;
                x = i;
                y = j;
            }
        }
    }
    if (condition1 == 1)
    {
        visited[x][y] = true;
        total[x][y] = num;
        memset(ad_like, 0, sizeof(ad_like));
    }
    else
    {
        int MAX1 = 0;
        for (int i = 1; i <= n; i++) // 조건 2
        {
            for (int j = 1; j <= n; j++)
            {
                if (visited[i][j] == false && ad_like[i][j] == MAX)
                {
                    for (int z = 0; z < 4; z++)
                    {
                        int nx = i + dx[z];
                        int ny = j + dy[z];
                        if (valid(nx, ny) && visited[nx][ny] == false)
                        {
                            emp[i][j]++;
                        }
                    }
                    MAX1 = max(MAX1, emp[i][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++) // 조건 1
        {
            for (int j = 1; j <= n; j++)
            {
                if (visited[i][j] == false && emp[i][j] == MAX1 && ad_like[i][j] == MAX)
                {
                    visited[i][j] = true;
                    total[i][j] = num;
                    memset(emp, 0, sizeof(emp));
                    memset(ad_like, 0, sizeof(ad_like));
                    return;
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n * n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < 4; j++)
        {
            int b;
            cin >> b;
            like[a].push_back(b);
        }
        simulation(a);
    }
    for (int i = 1; i <= n; i++) // 조건 1
    {
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            for (int z = 0; z < 4; z++)
            {
                int nx = i + dx[z];
                int ny = j + dy[z];
                if (valid(nx, ny) && find(like[total[i][j]].begin(), like[total[i][j]].end(), total[nx][ny]) != like[total[i][j]].end())
                {
                    cnt++;
                }
            }
            if (cnt != 0)
                num += pow(10, cnt - 1);
        }
    }
    cout << num << '\n';
    return 0;
}