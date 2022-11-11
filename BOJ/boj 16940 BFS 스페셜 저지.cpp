#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
vector<vector<int>> graph(100001);
vector<int> test;
bool visited[100001];
int idx = 1;
void bfs(int t)
{
    queue<int> q;
    q.push(t);
    visited[t] = true;
    while (!q.empty())
    {
        unordered_set<int> check;
        int cur = q.front();
        q.pop();
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                check.insert(it);
            }
        }
        for (int i = idx; i < idx + check.size(); i++) // 0 1
        {
            if (check.count(test[i]) == 0)
            {
                cout << "0" << '\n';
                exit(0);
            }
            else
            {
                q.push(test[i]);
            }
        }
        idx += check.size(); // 1
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        test.push_back(input);
    }
    if (test[0] != 1)
    {
        cout << "0" << '\n';
        exit(0);
    }
    bfs(1);
    cout << "1" << '\n';
    return 0;
}