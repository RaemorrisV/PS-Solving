#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int board[6][6];
unordered_map<string, bool> hash1;
string words = "";
int dx[4] = {-1, 1, 0, 0}; // 상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int cnt = 0;
bool valide(int r, int c)
{
    if (r >= 1 && r <= 5 && c >= 1 && c <= 5)return true;
    return false;
}
void dfs(int r, int c, int len)
{
    words += to_string(board[r][c]);
    if (words.length() == 6)
    {
        if (hash1[words] == false)
        {
            hash1[words] = true;
            cnt++;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if (valide(nx, ny))
        {
            dfs(nx, ny, len + 1);
            words.pop_back();
        }
    }
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
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            dfs(i, j, 1);
            words.pop_back();
        }
    }
    cout << cnt << '\n';
    return 0;
}