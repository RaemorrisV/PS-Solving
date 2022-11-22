#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

int s, t;
unordered_map<long long, bool> visited;
void bfs(int st)
{
    queue<pair<long long, string>> q;
    q.push({st, ""});
    visited[st] = true;
    while (!q.empty())
    {
        long long cur = q.front().first;
        string cur_str = q.front().second;
        q.pop();
        if (cur == t)
        {
            cout << cur_str << '\n';
            exit(0);
        }
        if (visited[cur * cur] == false)
        {
            visited[cur * cur] = true;
            q.push({cur * cur, cur_str + '*'}); //곱
        }
        if (visited[cur + cur] == false)
        {
            visited[cur + cur] = true;
            q.push({cur + cur, cur_str + '+'});
        }
        if (visited[cur - cur] == false)
        {
            visited[cur - cur] = true;
            q.push({cur - cur, cur_str + '-'});
        }
        if (cur != 0 && visited[cur / cur] == false)
        {
            visited[cur / cur] = true;
            q.push({cur / cur, cur_str + '/'});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> s >> t;
    if (s == t)
    {
        cout << "0" << '\n';
        exit(0);
    }
    bfs(s);
    cout << "-1" << '\n';
    return 0;
}