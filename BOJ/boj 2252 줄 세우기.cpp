#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int n, m;
vector<vector<int>> graph(32001);
bool visited[32001];
stack<int> order;
void dfs(int s)
{
    for (auto it : graph[s])
    {
        if (visited[it] == false)
        {
            visited[it] = true;
            dfs(it);
        }
    }
    order.push(s);
}
void topological_sort()
{
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i);
        }
    }
    while (!order.empty())
    {
        cout << order.top() << " ";
        order.pop();
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
        graph[s].push_back(e);
    }
    topological_sort();
    return 0;
}