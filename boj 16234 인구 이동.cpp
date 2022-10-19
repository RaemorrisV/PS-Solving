#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, L, R;
bool visited[50][50];
int country[50][50];
int dx[4] = {-1, 1, 0, 0}; //상하좌우
int dy[4] = {0, 0, -1, 1}; //상하좌우
int union_cnt = 1;
int ans = 0;
int cnt = 0;
int len = 0;
struct info
{
    int row;
    int col;
    int se;
};
vector<info> in;
bool valid(int r, int c)
{
    if (r > -1 && r < n && c > -1 && c < n)
        return true;
    return false;
}
void dfs(int r, int c)
{
    visited[r][c] = true;
    cnt += country[r][c];
    len++;
    for (int i = 0; i < 4; i++)
    {
        if (valid(r + dx[i], c + dy[i]) && visited[r + dx[i]][c + dy[i]] == false && abs(country[r][c] - country[r + dx[i]][c + dy[i]]) >= L && abs(country[r][c] - country[r + dx[i]][c + dy[i]]) <= R)
        {
            // cout<<"이동 "<<r + dx[i]<<" "<<c + dy[i]<<endl;
            visited[r + dx[i]][c + dy[i]] = true;
            dfs(r + dx[i], c + dy[i]);
        }
    }
}
void set(int r, int c, int setting)
{
    visited[r][c] = true;
    for (int i = 0; i < 4; i++)
    {
        if (valid(r + dx[i], c + dy[i]) && visited[r + dx[i]][c + dy[i]] == false && abs(country[r][c] - country[r + dx[i]][c + dy[i]]) >= L && abs(country[r][c] - country[r + dx[i]][c + dy[i]]) <= R)
        {
            visited[r + dx[i]][c + dy[i]] = true;
            set(r + dx[i], c + dy[i], setting);
        }
    }
    country[r][c] = setting;
}
int main()
{
    cin >> n >> L >> R;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> country[i][j];
        }
    }
    int k = 0;
    while (union_cnt != 0)
    {
        union_cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == false)
                {
                    dfs(i, j);
                    if (len != 1)
                    {
                        union_cnt++;
                        int num = cnt / len;
                        in.push_back({i, j, num});
                    }
                    cnt = 0;
                    len = 0;
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < in.size(); i++)
        {
            set(in[i].row, in[i].col, in[i].se);
        }
        if (union_cnt != 0)
        {
            k++;
        }
        in.clear();
        memset(visited, 0, sizeof(visited));
    }
    cout << k << endl;
    return 0;
}