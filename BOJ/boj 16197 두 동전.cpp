#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int MIN = 10000000;
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
vector<pair<int, int>> coin_idx;
char board[21][21];
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void dfs(int cnt)
{
    bool flag1 = false;
    bool flag2 = false;
    if (cnt > 10)
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int coin1_x = coin_idx[0].first + dx[i];
        int coin1_y = coin_idx[0].second + dy[i];
        int coin2_x = coin_idx[1].first + dx[i];
        int coin2_y = coin_idx[1].second + dy[i];
        if (valide(coin1_x, coin1_y) == false && valide(coin2_x, coin2_y) == false)
        {
            continue; //무시해줘야함
        }
        else if (valide(coin1_x, coin1_y) == false)
        {
            MIN = min(MIN, cnt + 1);
            return;
        }
        else if (valide(coin2_x, coin2_y) == false)
        {
            MIN = min(MIN, cnt + 1);
            return;
        }
        if (board[coin1_x][coin1_y] != '#')
        {
            flag1 = true;
        }
        if (board[coin2_x][coin2_y] != '#')
        {
            flag2 = true;
        }
        if (flag1 || flag2)
        {
            if (flag1)
            {
                coin_idx[0].first += dx[i];
                coin_idx[0].second += dy[i];
            }
            if (flag2)
            {
                coin_idx[1].first += dx[i];
                coin_idx[1].second += dy[i];
            }
            dfs(cnt + 1);
            if (flag1)
            {
                coin_idx[0].first -= dx[i];
                coin_idx[0].second -= dy[i];
            }
            if (flag2)
            {
                coin_idx[1].first -= dx[i];
                coin_idx[1].second -= dy[i];
            }
            flag1 = false;
            flag2 = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < m; j++)
        {
            board[i][j + 1] = input[j];
            if (input[j] == 'o')
            {
                coin_idx.push_back({i, j + 1});
            }
        }
    }
    dfs(0);
    if (MIN > 10)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << MIN << '\n';
    }
    return 0;
}