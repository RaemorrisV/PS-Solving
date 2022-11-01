#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> relation(2000);
bool visited[2000];
bool flag = false;
int n, m;
void dfs(int se, int len)
{
    if (len == 4)
    {
        flag = true;
        return;
    }
    for (auto it : relation[se])
    {
        if (visited[it] == false)
        {
            visited[it] = true;
            dfs(it, len + 1);
            visited[it] = false;
        }
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
        relation[s].push_back(e);
        relation[e].push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i, 0);
        if (flag)break;
        visited[i] = false;
    }
    if (flag)
    {
        cout << "1" << '\n';
    }
    else
    {
        cout << "0" << '\n';
    }
    return 0;
}