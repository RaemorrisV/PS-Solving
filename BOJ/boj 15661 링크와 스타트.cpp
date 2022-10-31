#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int table[21][21];
int n;
int MIN = 1000000;
bitset<21> start;
bitset<21> link;
void dfs(int human, int len)
{
    start[human] = 1;
    bitset<21> temp = start;
    link = temp.flip();
    int sum_s = 0;
    int sum_l = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (start[i] == 1 && start[j] == 1)
            {
                sum_s += table[i][j] + table[j][i];
            }
            else if (link[i] == 1 && link[j] == 1)
            {
                sum_l += table[i][j] + table[j][i];
            }
        }
    }
    MIN = min(MIN, abs(sum_l - sum_s));
    if (len == n - 1)
    {
        return;
    }
    for (int i = human + 1; i <= n; i++)
    {
        dfs(i, len + 1);
        start[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> table[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {

        dfs(i, 1);
        start[i] = 0;
    }
    cout << MIN << "\n";
    return 0;
}