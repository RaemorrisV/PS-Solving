#include <iostream>
#include <string>
using namespace std;

int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int r, c, n;
int t = 1;
char board[201][201];
int boom[201][201];
string in;
bool valide(int a, int b)
{
    if (a >= 1 && a <= r && b >= 1 && b <= c)return true;
    return false;
}
void simulation()
{
    while (1)
    {
        if (t == n)
            break;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                board[i][j] = 'O';
                boom[i][j] += 1;
            }
        }
        t++;
        if (t == n)
            break;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (boom[i][j] == 3)
                {
                    boom[i][j] = 0;
                    board[i][j] = '.';
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (valide(nx, ny) && boom[nx][ny] != 3)
                        {
                            boom[nx][ny] = 0;
                            board[nx][ny] = '.';
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                if (boom[i][j] != 0)
                {
                    boom[i][j]++;
                }
            }
        }
        t++;
        if (t == n)
            break;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> r >> c >> n;
    for (int i = 1; i <= r; i++)
    {
        cin >> in;
        for (int j = 1; j <= c; j++)
        {
            board[i][j] = in[j - 1];
            if (board[i][j] == 'O')
            {
                boom[i][j] = 2;
            }
        }
    }
    simulation();
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cout << board[i][j];
        }
        cout << '\n';
    }
    return 0;
}