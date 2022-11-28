#include <iostream>
#include <string>
#include <vector>

using namespace std;

char board[101][101];
bool visited[101][101];
int n, m; //행 열
string input;
struct cross
{
    int x;
    int y;
    int size;
};
vector<cross> out;
bool valide(int r, int c)
{
    if (r >= 1 && r <= n && c >= 1 && c <= m)return true;
    return false;
}
void simulation(int r, int c)
{
    int i = 1;
    while (1)
    {
        //상 하 좌 우
        if (valide(r - i, c) && valide(r + i, c) && valide(r, c - i) && valide(r, c + i))
        {
            if (board[r - i][c] == '*' && board[r + i][c] == '*' && board[r][c - i] == '*' && board[r][c + i] == '*')
            {
                out.push_back({r, c, i});
                if (i == 1)
                {
                    visited[r][c] = true;
                }
                visited[r - i][c] = true;
                visited[r + i][c] = true;
                visited[r][c - i] = true;
                visited[r][c + i] = true;
                i++;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }
}
bool make_possible()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == '*' && visited[i][j] == false)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        for (int j = 1; j <= m; j++)
        {
            board[i][j] = input[j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (board[i][j] == '*')
            {
                simulation(i, j);
            }
        }
    }
    if (!make_possible())
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << out.size() << '\n';
        for (auto it : out)
        {
            cout << it.x << " " << it.y << " " << it.size << '\n';
        }
    }
    return 0;
}