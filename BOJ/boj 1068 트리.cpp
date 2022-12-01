#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[50];
vector<vector<int>> graph(50);
int n, k, first, input;
int ans = 0;
bool flag;
void bfs(int s)
{
    if(visited[s])
    {
        return;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                q.push(it);
                visited[it] = true;
                flag = true;
            }
        }
        if (flag == false)
        {
            ans++;
        }
        flag = false;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        if (input == -1)
        {
            first = i;
        }
        else
        {
            graph[i].push_back(input);
            graph[input].push_back(i);
        }
    }
    cin >> k;
    visited[k] = true;
    bfs(first);
    cout << ans << '\n';
    return 0;
}