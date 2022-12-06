#include <iostream>
#include <cmath>

using namespace std;

int n;
bool select(string a)
{
    int v = stoi(a);
    for (int i = 2; i <= sqrt(v); i++)
    {
        if (v % i == 0)return false; 
    }
    return true;
}
void dfs(string temp)
{
    if (temp.length() == n)
    {
        cout << temp << '\n';
        return;
    }
    for (int i = 1; i <= 9; i += 2)
    {
        if (select(temp + to_string(i)))
        {
            dfs(temp + to_string(i));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    dfs(to_string(2));
    dfs(to_string(3));
    dfs(to_string(5));
    dfs(to_string(7));
    return 0;
}