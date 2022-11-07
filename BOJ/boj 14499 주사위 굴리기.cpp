#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y, k;
int map[20][20];
int dx[5] = {0, 0, 0, -1, 1}; //동 서 북 남
int dy[5] = {0, 1, -1, 0, 0};
pair<int, int> location;
bool valide(int r, int c)
{
    if (r >= 0 && r < n && c >= 0 && c < m)return true;
    return false;
}
struct dice
{
    int bottom = 0;
    int top = 0;
    int left = 0;
    int right = 0;
    int back = 0;
    int front = 0;
};
dice a;
void simulation(int dir)
{
    if (dir == 1) //동쪽
    {
        int temp = a.top;
        a.top = a.left;
        a.left = a.bottom;
        a.bottom = a.right;
        a.right = temp;
        if (map[location.first][location.second] == 0)
        {
            map[location.first][location.second] = a.bottom;
        }
        else
        {
            a.bottom = map[location.first][location.second];
            map[location.first][location.second] = 0;
        }
    }
    else if (dir == 2) //서쪽
    {
        int temp = a.top;
        a.top = a.right;
        a.right = a.bottom;
        a.bottom = a.left;
        a.left = temp;
        if (map[location.first][location.second] == 0)
        {
            map[location.first][location.second] = a.bottom;
        }
        else
        {
            a.bottom = map[location.first][location.second];
            map[location.first][location.second] = 0;
        }
    }
    else if (dir == 3) //북쪽
    {
        int temp = a.top;
        a.top = a.front;
        a.front = a.bottom;
        a.bottom = a.back;
        a.back = temp;
        if (map[location.first][location.second] == 0)
        {
            map[location.first][location.second] = a.bottom;
        }
        else
        {
            a.bottom = map[location.first][location.second];
            map[location.first][location.second] = 0;
        }
    }
    else if (dir == 4) //남쪽
    {
        int temp = a.top;
        a.top = a.back;
        a.back = a.bottom;
        a.bottom = a.front;
        a.front = temp;
        if (map[location.first][location.second] == 0)
        {
            map[location.first][location.second] = a.bottom;
        }
        else
        {
            a.bottom = map[location.first][location.second];
            map[location.first][location.second] = 0;
        }
    }
    cout << a.top << '\n';
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> x >> y >> k;
    location.first = x;
    location.second = y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int dir;
        cin >> dir;
        if (valide(location.first + dx[dir], location.second + dy[dir]))
        {
            location.first += dx[dir];
            location.second += dy[dir];
            simulation(dir);
        }
    }
    return 0;
}