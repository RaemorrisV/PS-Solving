#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int MAX = 0;
vector<int> t(16);
vector<int> p(16);
int sum = 0;
void dfs(int s)
{
    sum += p[s];
    MAX = max(MAX, sum);
    for (int i = s + t[s]; i <= n; i++)
    {
        if (i + t[i] - 1 <= n)
        {
            dfs(i);
            sum -= p[i];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i + t[i] - 1 <= n)
        {
            dfs(i);
            sum -= p[i];
        }
    }
    cout << MAX << "\n";
    return 0;
}
