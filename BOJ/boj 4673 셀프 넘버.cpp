#include <iostream>
#include <string>
using namespace std;

int con[10001];
void dfs(string cons)
{
    int sum = stoi(cons);
    if (sum >= 10000)
    {
        return;
    }
    for (int i = 0; i < cons.length(); i++)
    {
        sum += (cons[i] - '0');
    }
    if (sum > 10000)
    {
        return;
    }
    con[sum]++;
    dfs(to_string(sum));
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    for (int i = 1; i <= 10000; i++)
    {
        dfs(to_string(i));
    }
    for (int i = 1; i <= 10000; i++)
    {
        if (con[i] == 0)
        {
            cout << i << '\n';
        }
    }
    return 0;
}