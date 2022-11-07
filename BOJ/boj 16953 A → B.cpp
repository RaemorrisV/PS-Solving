#include <iostream>
#include <queue>
#include <string>
using namespace std;

long long a, b;
void bfs(int s)
{
    queue<pair<long long, int>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();
        if (cur == b)
        {
            cout << cost + 1 << '\n';
            exit(0);
        }
        if (cur * 2 <= 1000000000)
        {
            q.push({cur * 2, cost + 1});
        }
        string temp = to_string(cur);
        if (stoll(temp + '1') <= 1000000000)
        {
            q.push({stoll(temp + '1'), cost + 1});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> a >> b;
    bfs(a);
    cout << "-1" << '\n';
    return 0;
}