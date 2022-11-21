#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct info
{
    int a;
    int b;
    int c;
};
int n, m, k; // 행 열 회전 연산의 개수
int arr[51][51];
vector<info> oper;
int MIN = 100000000;
int temp[51][51];
bool visited[6];
vector<int> order;
void ans()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            sum += temp[i][j];
        }
        MIN = min(MIN, sum);
        sum = 0;
    }
}
void rotate(int r, int c, int s)
{
    for (int i = 0; i < s; i++)
    {
        int tem = temp[r - s + i][c - s + i];
        for (int j = r - s + i; j < r + s - i; j++)
        {
            temp[j][c - s + i] = temp[j + 1][c - s + i];
        }
        for (int k = c - s + i; k < c + s - i; k++)
        {
            temp[r + s - i][k] = temp[r + s - i][k + 1];
        }
        for (int j = r + s - i; j > r - s + i; j--)
        {
            temp[j][c + s - i] = temp[j - 1][c + s - i];
        }
        for (int k = c + s - i; k > c - s + i; k--)
        {
            temp[r - s + i][k] = temp[r - s + i][k - 1];
        }
        temp[r - s + i][c - s + i + 1] = tem;
    }
}
void dfs(int len, int idx)
{
    order.push_back(idx);
    if (len == oper.size() - 1)
    {
        copy(&arr[0][0], &arr[0][0] + 51 * 51, &temp[0][0]);
        for (int i = 0; i < order.size(); i++)
        {
            rotate(oper[order[i]].a, oper[order[i]].b, oper[order[i]].c);
        }
        ans();
        return;
    }
    for (int i = 0; i < oper.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(len + 1, i);
            order.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < k; i++)
    {
        int t, y, u;
        cin >> t >> y >> u;
        oper.push_back({t, y, u});
    }
    for (int i = 0; i < oper.size(); i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(0, i);
            order.pop_back();
            visited[i] = false;
        }
    }
    cout << MIN << '\n';
    return 0;
}