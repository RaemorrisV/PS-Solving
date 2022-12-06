#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

bool visited[13][7];
char field[13][7];
int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int conse = 0;
int flag = 1;
string in;
bool valide(int r, int c)
{
    if (r >= 1 && r <= 12 && c >= 1 && c <= 6)return true;
    return false;
}
void simulation()
{
    for (int i = 1; i <= 11; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (field[i][j] != '.' && field[i + 1][j] == '.') //시뮬레이션 경우
            {
                for (int k = 12; k >= 1; k--)
                {
                    if (field[k][j] == '.')
                    {
                        for (int z = k - 1; z >= 1; z--)
                        {
                            if (field[z][j] != '.')
                            {
                                field[k][j] = field[z][j];
                                field[z][j] = '.';
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}
bool bfs(int s, int e, char color)
{
    int n = 1;
    queue<pair<int, int>> q;
    q.push({s, e});
    visited[s][e] = true;
    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = cur_r + dx[i];
            int ny = cur_c + dy[i];
            if (valide(nx, ny) && visited[nx][ny] == false && field[nx][ny] == color)
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
                n++;
            }
        }
    }
    if (n >= 4)
    {
        memset(visited, 0, sizeof(visited));
        q.push({s, e});
        field[s][e] = '.';
        visited[s][e] = true;
        while (!q.empty())
        {
            int cur_r = q.front().first;
            int cur_c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_r + dx[i];
                int ny = cur_c + dy[i];
                if (valide(nx, ny) && visited[nx][ny] == false && field[nx][ny] == color)
                {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    field[nx][ny] = '.';
                }
            }
        }
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 1; i <= 12; i++)
    {
        cin >> in;
        for (int j = 1; j <= 6; j++)
        {
            field[i][j] = in[j - 1];
        }
    }
    while (flag != 0)
    {
        flag = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 1; i <= 12; i++)
        {
            for (int j = 1; j <= 6; j++)
            {
                if (field[i][j] != '.')
                {
                    if (bfs(i, j, field[i][j]))
                    {
                        flag++;
                    }
                }
            }
        }
        if (flag != 0)
        {
            conse++;
        }
        simulation();
    }
    cout << conse << '\n';
    return 0;
}