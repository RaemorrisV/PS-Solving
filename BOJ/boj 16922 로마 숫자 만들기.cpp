#include <iostream>
#include <vector>

using namespace std;

int n;
int rome[4] = {1, 5, 10, 50};
int ans = 0;
bool visited[1001];
void dfs(int len, int sum, int idx)
{
    if (len == n)
    {
        if (visited[sum] == false)
        {
            visited[sum] = true;
            ans++;
        }
        return;
    }
    for (int i = idx; i < 4; i++)
    {
        dfs(len + 1, sum + rome[i], i);
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    dfs(0, 0, 0);
    cout << ans << '\n';
    return 0;
}