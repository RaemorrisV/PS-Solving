#include <iostream>
#include <queue>
using namespace std;

bool visited[1000000];
int cnt[1000001];
int parent[1000001];
int n;
vector<int> ans;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == 1)
        {
            cout << cnt[1] << '\n';
            int a = cur;
            while (cur != n)
            {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(cur);
            for (int i = ans.size() - 1; i >= 0; i--)
            {
                cout << ans[i] << " ";
            }
            cout << '\n';
            break;
        }
        if (cur % 3 == 0 && visited[cur / 3] == false)
        {
            q.push(cur / 3);
            visited[cur / 3] = true;
            cnt[cur / 3] = cnt[cur] + 1;
            parent[cur / 3] = cur;
        }
        if (cur % 2 == 0 && visited[cur / 2] == false)
        {
            q.push(cur / 2);
            visited[cur / 2] = true;
            cnt[cur / 2] = cnt[cur] + 1;
            parent[cur / 2] = cur;
        }
        if (visited[cur - 1] == false)
        {
            q.push(cur - 1);
            visited[cur - 1] = true;
            cnt[cur - 1] = cnt[cur] + 1;
            parent[cur - 1] = cur;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    bfs(n);
    return 0;
}