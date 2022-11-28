#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, r, x;
vector<int> difficulty;
bool visited[16];
int ans = 0;
int sum;
bool valide(int f)
{
    if (f <= r)return true;
    return false;
}
void dfs(int s, int len, int MAX, int MIN)
{
    if (len >= 2)
    {
        if (sum >= l && sum <= r && (MAX - MIN) >= x)
        {
            ans++;
        }
        for (int i = s; i <= n; i++)
        {
            if (valide(sum + difficulty[i]) && visited[i] == false)
            {
                sum += difficulty[i];
                visited[i] = true;
                dfs(i, len + 1, max(difficulty[i], MAX), min(difficulty[i], MIN));
                visited[i] = false;
                sum -= difficulty[i];
            }
        }
    }
    else if (len == 1)
    {
        for (int i = s; i <= n; i++)
        {
            int MAX_t = max(difficulty[i], MAX);
            int MIN_t = min(difficulty[i], MIN);
            if (valide(sum + difficulty[i]) && visited[i] == false)
            {
                sum += difficulty[i];
                visited[i] = true;
                dfs(i, len + 1, MAX_t, MIN_t);
                visited[i] = false;
                sum -= difficulty[i];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l >> r >> x;
    difficulty.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> difficulty[i];
    }
    for (int i = 1; i < n; i++)
    {
        visited[i] = true;
        sum = difficulty[i];
        dfs(i, 1, difficulty[i], difficulty[i]);
        visited[i] = false;
    }
    cout << ans << '\n';
    return 0;
}