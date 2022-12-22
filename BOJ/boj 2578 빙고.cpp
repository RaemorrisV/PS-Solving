#include <iostream>
#include <cmath>
using namespace std;

int board[6][6];
bool bingo[6][6];
int bingo_count()
{
    int total = 0;
    int cnt = 0;
    // 가로 체크
    for (int i = 1; i <= 5; i++)
    {
        cnt = 0;
        for (int j = 1; j <= 5; j++)
        {
            if (bingo[i][j])cnt++;
        }
        if (cnt == 5)total++;
    }
    // 세로 체크
    for (int i = 1; i <= 5; i++)
    {
        cnt = 0;
        for (int j = 1; j <= 5; j++)
        {
            if (bingo[j][i])cnt++;
        }
        if (cnt == 5)total++;
    }
    // 대각선 체크
    cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (bingo[i][i])cnt++;      
    }
    if (cnt == 5)total++;

    cnt = 0;
    for (int i = 1; i <= 5; i++)
    {
        if (bingo[i][abs(i - 6)])cnt++;
    }
    if (cnt == 5)total++;
    return total;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> board[i][j];
        }
    }
    for (int i = 0; i < 25; i++)
    {
        int in;
        cin >> in;
        for (int i = 1; i <= 5; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (board[i][j] == in)bingo[i][j] = true;
            }
        }
        if (bingo_count() >= 3)
        {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}