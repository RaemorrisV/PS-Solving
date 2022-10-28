#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <unordered_map>
using namespace std;
int n, input;
bool visited[101];
unordered_map<int, bool> ans;
vector<int> temp;
vector<vector<int>> graph(101);
int start;
void dfs(int s)
{
    visited[s] = true;
    temp.push_back(s);
    for (auto it : graph[s])
    {
        if (it == start)
        {
            for (auto it : temp)
            {
                if (ans[it] == false)
                {
                    ans[it] = true;
                }
            }
            temp.clear();
            return;
        }
        else if (visited[it] == false)
        {
            dfs(it);
        }
    }
    temp.clear();
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> input;
        graph[i].push_back(input);
    }
    for (int i = 1; i <= n; i++)
    {
        start = i;
        dfs(i);
        memset(visited, 0, sizeof(visited));
    }
    cout << ans.size() << endl;
    vector<pair<int, bool>> c(ans.begin(), ans.end());
    sort(c.begin(), c.end());
    for (auto it : c)
    {
        cout << it.first << '\n';
    }
    return 0;
}