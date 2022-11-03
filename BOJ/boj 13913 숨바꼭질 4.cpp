#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> ans;
bool visited[100001];
int cnt[100001];
int parent[100001];
int dx[2] = {-1, 1};
int n, k;
bool valid(int s)
{
    if (s >= 0 && s <= 100000)return true;
    return false;
}
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[n] = s;
    while (!q.empty())
    {
        int cur = q.front();
        if (cur == k)
        {
            while (cur != n)
            {
                ans.push_back(cur);
                cur = parent[cur];
            }
            ans.push_back(n);
            return;
        }
        q.pop();
        for (int i = 0; i < 2; i++)
        {
            int nx = cur + dx[i];
            if (valid(nx) && visited[nx] == false)
            {
                q.push(nx);
                visited[nx] = true;
                parent[nx] = cur;
                cnt[nx] += cnt[cur] + 1;
            }
        }
        int nx = cur * 2;
        if (valid(nx) && visited[nx] == false)
        {
            q.push(nx);
            parent[nx] = cur;
            visited[nx] = true;
            cnt[nx] += cnt[cur] + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    bfs(n);
    cout << cnt[k] << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}