#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
char satang[51][51];
int n;
int MAX = -111;
string input;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= n)
        return true;
    return false;
}
void check()
{
    /* cout << "____________" << endl;
     for (int i = 1; i <= n; i++)
     {
         for (int j = 1; j <= n; j++)
         {
             cout << satang[i][j] << " ";
         }
         cout << endl;
     }
     */
    //가로부터
    int cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (satang[i][j] == satang[i][j + 1])
            {
                cnt++;
            }
            else
            {
                MAX = max(MAX, cnt);
                cnt = 1;
            }
        }
        MAX = max(MAX, cnt);
        cnt = 1;
    }
    //세로
    int cnt1 = 1;
    for (int i = 1; i <= n; i++)
    {
        cnt1 = 1;
        for (int j = 1; j < n; j++)
        {
            if (satang[j][i] == satang[j + 1][i])
            {
                cnt1++;
            }
            else
            {
                MAX = max(MAX, cnt1);
                cnt1 = 1;
            }
        }
        MAX = max(MAX, cnt1);
        cnt1 = 1;
    }
    // cout << MAX << endl;
}
void dfs(int r, int c)
{
    for (int i = 0; i < 4; i++)
    {
        int x = r + dx[i];
        int y = c + dy[i];
        if (valide(x, y) && satang[r][c] != satang[x][y])
        {
            swap(satang[r][c], satang[x][y]);
            check();
            swap(satang[r][c], satang[x][y]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            satang[i][j + 1] = input[j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dfs(i, j);
        }
    }
    cout << MAX << '\n';
}