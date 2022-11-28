#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool no_mix[201][201];
bool visited[201];
vector<int> check;
int ans = 0;
void dfs(int s, int depth)
{
    visited[s] = true;
    check.push_back(s);
    if (depth == 3)
    {
        ans++;
        return;
    }
    bool flag = true;
    for (int i = s; i <= n; i++)
    {
        for (int j = 0; j < check.size(); j++)
        {
            if (no_mix[check[j]][i] == true)
            {
                flag = false;
            }
        }
        if (flag && visited[i] == false)
        {
            dfs(i, depth + 1);
            visited[i] = false;
            check.pop_back();
        }
        flag = true;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        if (s < e)
        {
            no_mix[s][e] = true;
        }
        else
        {
            no_mix[e][s] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 1);
        check.pop_back();
        visited[i] = false;
    }
    cout << ans << '\n';
    return 0;
}