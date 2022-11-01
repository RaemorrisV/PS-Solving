#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int n;
int MIN = INT_MAX;
int sum = 0;
int w[11][11];
bool visited[11];
vector<int> road;
int start;
void dfs(int s)
{
    road.push_back(s);
    if (road.size() == n && w[s][start] != 0)
    {
        sum += w[s][start];
        MIN = min(MIN, sum);
        sum -= w[s][start];
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false && w[s][i] != 0)
        {
            visited[i] = true;
            sum += w[s][i];
            dfs(i);
            sum -= w[s][i];
            road.pop_back();
            visited[i] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        visited[i] = true;
        start = i;
        dfs(i);
        road.pop_back();
        visited[i] = false;
    }
    cout << MIN << '\n';
    return 0;
}