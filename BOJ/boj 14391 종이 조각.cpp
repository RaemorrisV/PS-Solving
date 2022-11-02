#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m;
string paper[4][4];
int temp[4][4];
string input;
int sum = 0;
int MAX = 0;
void check() // 1이 가로 0이 세로
{
    for (int i = 0; i < n; i++) //가로로 더한값
    {
        string temp1 = "0";
        for (int j = 0; j < m; j++)
        {
            if (temp[i][j] == 1)
            {
                temp1 += paper[i][j];
            }
            else
            {
                sum += stoi(temp1);
                temp1 = "0";
            }
        }
        sum += stoi(temp1);
        temp1 = "0";
    }
    for (int i = 0; i < m; i++) //세로로 더한값
    {
        string temp2 = "0";
        for (int j = 0; j < n; j++)
        {
            if (temp[j][i] == 0)
            {
                temp2 += paper[j][i];
            }
            else
            {
                sum += stoi(temp2);
                temp2 = "0";
            }
        }
        sum += stoi(temp2);
        temp2 = "0";
    }
}
void dfs(int r, int c)
{
    if (r == n - 1 && c == m) //종료조건
    {
        check();
        MAX = max(MAX, sum);
        sum = 0;
        return;
    }
    if (c == m)
    {
        dfs(r + 1, 0);
        return;
    }
    temp[r][c] = 1;
    dfs(r, c + 1);
    temp[r][c] = 0;
    dfs(r, c + 1);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m; //행 열
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        for (int j = 0; j < input.length(); j++)
        {
            paper[i][j] = to_string(input[j] - '0');
        }
    }
    dfs(0, 0);
    cout << MAX << endl;
    return 0;
}
