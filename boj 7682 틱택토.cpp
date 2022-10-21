#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
string input;
char board[3][3];
char state[3][3];
bool visited[3][3];
unordered_map<string, bool> ans;
bool end_game(int row, int col) 
{
    int cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] != '.')
            {
                cnt++;
            }
            else
            {
                break;
            }
        }
    }
    if (cnt == 9)
    {
        return true; 
    }
    //좌
    char player = board[row][col]; 
    cnt = 0;
    for (int i = 0; i < 3; i++) 
    {
        if (board[row][i] == player)
            cnt++;
    }
    if (cnt == 3)
        return true;
    cnt = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board[i][col] == player)
            cnt++;
    }
    if (cnt == 3)
        return true;
    cnt = 0;
    if (col == row)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][i] == player)
                cnt++;
        }
    }
    if (cnt == 3)
        return true;
    cnt = 0;
    if (col == 2 - row) 
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][2 - i] == player)
                cnt++;
        }
    }
    if (cnt == 3)
        return true;
    return false;
}
void dfs(int row, int col, char player) 
{
    board[row][col] = player;
    if (end_game(row, col))
    {
        string save = "";
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                save += board[i][j];
            }
        }
        ans[save] = true;
        return;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                if (player == 'X')
                {
                    dfs(i, j, 'O');
                }
                else
                {
                    dfs(i, j, 'X');
                }
                board[i][j] = '.';
                visited[i][j] = false;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    fill(&board[0][0], &board[2][3], '.');
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (visited[i][j] == false)
            {
                visited[i][j] = true;
                dfs(i, j, 'X');
                board[i][j] = '.';
                visited[i][j] = false;
            }
        }
    }
    while (1)
    {
        cin >> input;
        if (input == "end")break;
        if (ans[input]==true)
        {
            cout << "valid" << '\n';
        }
        else
        {
            cout << "invalid" << '\n';
        }
    }
    return 0;
}