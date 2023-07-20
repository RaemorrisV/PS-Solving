#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<vector<int>>graph(1001);
pair<char, int>door[1001];
int dp[1001];
void bfs(int cost)
{
    queue<pair<int, int>>q;
    q.push({ 1,cost });
    dp[1] = cost;
    while (!q.empty())
    {
        int cur = q.front().first;
        int cur_cost = q.front().second;
        q.pop();
        for (auto it : graph[cur])
        {
            if (door[it].first == 'E')
            {
                if (dp[cur] > dp[it])
                {
                    dp[it] = dp[cur];
                    q.push({ it,dp[it] });
                }
            }
            else if (door[it].first == 'L')
            {
                int temp = max(dp[cur], door[it].second);
                if (temp > dp[it])
                {
                    dp[it] = temp;
                    q.push({ it,dp[it] });
                }
            }
            else if (door[it].first == 'T')
            {
                if (dp[it] < dp[cur] - door[it].second)
                {
                    q.push({ it, dp[cur] - door[it].second });
                    dp[it] = dp[cur] - door[it].second;
                }
            }
        }
    }
}
void init()
{
    fill(dp + 1, dp + 1001, -1);
    for (int i = 1; i <= 1000; i++)
    {
        graph[i].clear();
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1)
    {
        cin >> n;
        init();
        int temp = dp[n];
        if (n == 0)break;
        for (int i = 1; i <= n; i++)
        {
            char name;
            int cost;
            cin >> name >> cost;
            door[i].first = name;
            door[i].second = cost;
            while (1)
            {
                int a;
                cin >> a;
                if (a == 0)break;
                graph[i].push_back(a);
            }
        }
        if (door[1].first == 'E' || door[1].first == 'L')bfs(door[1].second);
        if (dp[n] == -1)
        {
            cout << "No" << '\n';
        }
        else
        {
            cout << "Yes" << '\n';
        }
    }
    return 0;
}