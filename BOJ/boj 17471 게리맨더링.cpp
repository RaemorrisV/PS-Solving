#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

bitset<11> one;
bitset<11> two;
int n;
vector<int> popul;
vector<int> idx;
int MIN = 100000000;
vector<vector<int>> graph(11);
bool visited[11];
bool flag;
bool flag2;
void bfs(int s)
{
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : graph[cur])
        {
            if (visited[it] == false)
            {
                visited[it] = true;
                q.push(it);
            }
        }
    }
}
void dfs(int s, int len)
{
    one.reset();
    two.reset();
    int sum1 = 0;
    int sum2 = 0;
    fill(visited, visited + 11, 1);
    for (int i = 0; i < idx.size(); i++)
    {
        one[idx[i]] = 1;
        sum1 += popul[idx[i]];
        visited[idx[i]] = false;
    }
    bfs(idx[0]);
    for (int i = 0; i < idx.size(); i++)
    {
        if (visited[idx[i]] == false)
        {
            flag = true;
        }
    }
    fill(visited, visited + 11, 1);
    if (flag == false)
    {
        two = one.flip();
        int start;
        for (int i = 1; i <= n; i++)
        {
            if (two[i] == 1)
            {
                start = i;
                sum2 += popul[i];
                visited[i] = false;
            }
        }
        bfs(start);
        for (int i = 1; i <= n; i++)
        {
            if (visited[i] == false)
            {
                flag2 = true;
            }
        }
        if (flag == false && flag2 == false)
        {
            MIN = min(MIN, abs(sum1 - sum2));
        }
    }
    flag = false;
    flag2 = false;
    if (len == n - 1)
    {
        return;
    }
    for (int i = s + 1; i <= n; i++)
    {
        idx.push_back(i);
        dfs(i, len + 1);
        idx.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    popul.push_back(-111);
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        popul.push_back(in);
    }
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++)
        {
            int b;
            cin >> b;
            graph[i + 1].push_back(b);
        }
    }
    for (int i = 1; i <= 2; i++)
    {
        idx.push_back(i);
        dfs(i, 1);
        idx.pop_back();
    }
    if (MIN == 100000000)
    {
        cout << "-1" << '\n';
    }
    else
    {
        cout << MIN << '\n';
    }
    return 0;
}