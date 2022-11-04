#include <iostream>
#include <vector>
using namespace std;
int n;
int arr[101][101];
int dx[4] = {1, 0, -1, 0}; // 1 2 3 4
int dy[4] = {0, -1, 0, 1};
vector<int> dir;
int a, b, c, d, x, y;
int ans = 0;
void make_curve()
{
    int size = dir.size() - 1;
    for (int i = size; i >= 0; i--)
    {
        dir.push_back((dir[i] + 1) % 4);
        x += dx[(dir[i] + 1) % 4];
        y += dy[(dir[i] + 1) % 4];
        arr[x][y] = 1;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        dir.clear();
        cin >> a >> b >> c >> d;
        arr[a][b] = 1;
        x = a + dx[c];
        y = b + dy[c];
        arr[x][y] = 1;
        dir.push_back(c);
        for (int j = 0; j < d; j++)
        {
            make_curve();
        }
    }
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1)
            {
                ans++;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}