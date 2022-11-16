#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

int t, s, e;
bool prime[10001];
bool visited[10001];
int cnt[10001];
vector<vector<int>> graph(10000);
void find_prime()
{
    for (int i = 2; i <= sqrt(10000); i++)
    {
        for (int j = i * 2; j <= 10000; j += i)
        {
            if (prime[j])
            {
                prime[j] = false;
            }
        }
    }
}
bool one_change(int a, int b)
{
    string com1 = to_string(a);
    string com2 = to_string(b);
    int diff = 0;
    for (int i = 0; i < 4; i++)
    {
        if (com1[i] != com2[i])diff++;
    }
    if (diff == 1)return true;
    return false;
}
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
            if (visited[it] == false && one_change(cur, it))
            {
                visited[it] = true;
                cnt[it] = cnt[cur] + 1;
                q.push(it);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(prime, 1, sizeof(prime));
    find_prime();
    for (int j = 1000; j < 10000; j++)
    {
        for (int k = 1000; k < 10000; k++)
        {
            if (prime[j] && prime[k])
            {
                graph[j].push_back(k);
                graph[k].push_back(j);
            }
        }
    }
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> s >> e;
        bfs(s);
        if(s==e)
        {
            cout << cnt[e] << '\n';
        }
        else if (cnt[e] == 0)
        {
            cout << "Impossible" << '\n';
        }
        else
        {
            cout << cnt[e] << '\n';
        }
        memset(visited, 0, sizeof(visited));
        fill(cnt, cnt + 10001, 0);
    }
    return 0;
}