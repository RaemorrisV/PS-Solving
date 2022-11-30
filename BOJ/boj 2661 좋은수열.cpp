#include <iostream>
#include <string>
using namespace std;

int n;
bool bad_permu(string input)
{
    for (int i = 0; i < input.length() / 2; i++)
    {
        if (input.substr(input.length() - 2 * i - 2, i + 1) == input.substr(input.length() - 1 - i, i + 1))
            return true;
    }
    return false;
}
void dfs(int s, int len, string temp)
{
    if (len >= 2)
    {
        if (bad_permu(temp))
        {
            return;
        }
    }
    if (len == n)
    {
        cout << temp << '\n';
        exit(0);
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        dfs(i, len + 1, temp + to_string(i));
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 3; i++)
    {
        dfs(i, 1, to_string(i));
    }
    return 0;
}