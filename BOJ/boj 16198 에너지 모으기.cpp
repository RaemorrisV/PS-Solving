#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int MAX = -1;
int sum = 0;
vector<int> w;
void dfs(int s)
{
    sum += w[s] * w[s - 1];
    if (w.size() == 2)
    {
        MAX = max(MAX, sum);
        return;
    }
    for (int i = 1; i <= w.size() - 2; i++)
    {
        int temp = w[i];
        w.erase(w.begin() + i);
        dfs(i);
        w.insert(w.begin() + i, temp);
        sum -= w[i - 1] * w[i + 1];
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    w.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n - 2; i++)
    {
        int temp = w[i];
        w.erase(w.begin() + i);
        dfs(i);
        w.insert(w.begin() + i, temp);
        sum -= w[i - 1] * w[i + 1];
    }
    cout << MAX << '\n';
    return 0;
}