#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int t, f, s;
bool visited[10000];
int temp[4];
void bfs(int st)
{
    queue<pair<int, string>> q;
    q.push({st, ""});
    visited[st] = true;
    while (!q.empty())
    {
        int cur = q.front().first;
        string cur_str = q.front().second;
        q.pop();
        if (cur == s)
        {
            cout << cur_str << '\n';
            while (!q.empty())
            {
                q.pop();
            }
            return;
        }
        if (visited[(cur * 2) % 10000] == false)
        {
            visited[(cur * 2) % 10000] = true;
            q.push({(cur * 2) % 10000, cur_str + "D"});
        }
        if (cur != 0)
        {
            if (visited[cur - 1] == false)
            {
                visited[cur - 1] = true;
                q.push({cur - 1, cur_str + "S"});
            }
        }
        else if (cur == 0)
        {
            if (visited[9999] == false)
            {
                visited[9999] = true;
                q.push({9999, cur_str + "S"});
            }
        }
        // L 연산
        temp[0] = cur / 1000;                                            // 1000자리
        temp[1] = (cur - temp[0] * 1000) / 100;                          // 100
        temp[2] = (cur - temp[0] * 1000 - temp[1] * 100) / 10;           // 10자리
        temp[3] = (cur - temp[0] * 1000 - temp[1] * 100 - temp[2] * 10); // 1자리
        int l_oper = temp[1] * 1000 + temp[2] * 100 + temp[3] * 10 + temp[0];
        if (visited[l_oper] == false)
        {
            visited[l_oper] = true;
            q.push({l_oper, cur_str + "L"});
        }
        // R연산
        int r_oper = temp[3] * 1000 + temp[0] * 100 + temp[1] * 10 + temp[2];
        if (visited[r_oper] == false)
        {
            visited[r_oper] = true;
            q.push({r_oper, cur_str + "R"});
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> f >> s;
        bfs(f);
        memset(visited, 0, sizeof(visited));
    }
    return 0;
}