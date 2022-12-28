#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n, m, k;
int ans = 0;
int counting[51][51];
int sum = 0;
int speed = 0;
int odd = 0;
int even = 0;
int nx_next(int nx)
{
    if (nx < 1)
        return nx + n;
    else if (nx > n)
        return nx - n;
    else
        return nx;
}
int ny_next(int ny)
{
    if (ny < 1)
        return ny + n;
    else if (ny > n)
        return ny - n;
    else
        return ny;
}
struct info
{
    int r; // 행
    int c; // 열
    int m; // 잘량
    int s; // 방향
    int d; // 속력
};
queue<info> fire_info;
vector<info> fireball[51][51];
vector<info> fire;
void simulation()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            fireball[i][j].clear();
        }
    }
    for (int i = 0; i < fire.size(); i++)
    {
        int nx = fire[i].r + (fire[i].s % n) * dx[fire[i].d];
        int ny = fire[i].c + (fire[i].s % n) * dy[fire[i].d];
        nx = nx_next(nx);
        ny = ny_next(ny);
        fire[i].r = nx;
        fire[i].c = ny;
        fireball[nx][ny].push_back(fire[i]);
    }
    fire.clear();
    // 이동이 모두 끝난 뒤
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (fireball[i][j].size() == 1)
            {
                fire.push_back(fireball[i][j][0]);
            }
            else if (fireball[i][j].size() >= 2)
            {
                odd = 0;
                even = 0;
                sum = 0;
                speed = 0;
                for (int z = 0; z < fireball[i][j].size(); z++)
                {
                    if (fireball[i][j][z].r == i && fireball[i][j][z].c == j)
                    {
                        sum += fireball[i][j][z].m;
                        speed += fireball[i][j][z].s;
                        if (fireball[i][j][z].d % 2 == 0)
                            even++;
                        else
                            odd++;
                    }
                }
                if (odd == fireball[i][j].size() || even == fireball[i][j].size()) // 0 2 4 6
                {
                    int size = fireball[i][j].size();
                    if (sum / 5 > 0)
                    {
                        fire.push_back({i, j, sum / 5, speed / size, 0});
                        fire.push_back({i, j, sum / 5, speed / size, 2});
                        fire.push_back({i, j, sum / 5, speed / size, 4});
                        fire.push_back({i, j, sum / 5, speed / size, 6});
                    }
                }
                else // 1 3 5 7
                {
                    int size = fireball[i][j].size();
                    if (sum / 5 > 0)
                    {
                        fire.push_back({i, j, sum / 5, speed / size, 1});
                        fire.push_back({i, j, sum / 5, speed / size, 3});
                        fire.push_back({i, j, sum / 5, speed / size, 5});
                        fire.push_back({i, j, sum / 5, speed / size, 7});
                    }
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a1, b1, c1, d1, e1;
        cin >> a1 >> b1 >> c1 >> d1 >> e1;
        fire.push_back({a1, b1, c1, d1, e1});
    }
    for (int i = 0; i < k; i++)
    {
        simulation();
    }
    for (int i = 0; i < fire.size(); i++)
    {
        ans += fire[i].m;
    }
    cout << ans << '\n';
    return 0;
}