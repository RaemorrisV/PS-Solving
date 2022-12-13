#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[7][7];
vector<string> t;
int cnt = 0;
bool flag;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
bool valide(char r, char c)
{
    if (r >= '1' && r <= '6' && c >= 'A' && c <= 'F')return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 0; i < 36; i++)
    {
        string input;
        cin >> input;
        t.push_back(input);
        if (visited[input[1] - '0'][input[0] - 'A' + 1] == false)
        {
            visited[input[1] - '0'][input[0] - 'A' + 1] = true;
            cnt++;
        }
        else if (visited[input[1] - '0'][input[0] - 'A' + 1])
        {
            cout << "Invalid" << '\n';
            exit(0);
        }
    }
    bool f = false;
    for (int j = 0; j < 8; j++)
    {
        char nx = t[0][1] + dx[j];
        char ny = t[0][0] + dy[j];
        if (nx == t[35][1] && ny == t[35][0])f = true;
    }
    if (!f)
    {
        cout << "Invalid" << '\n';
        exit(0);
    }
    for (int i = 0; i < 35; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char nx = t[i][1] + dx[j];
            char ny = t[i][0] + dy[j];
            if (valide(nx, ny) && nx == t[i + 1][1] && ny == t[i + 1][0])
            {
                flag = true;
            }
        }
        if (flag == false)
        {
            cout << "Invalid" << '\n';
            exit(0);
        }
        flag = false;
    }
    cout << "Valid" << '\n';
    return 0;
}