#include <iostream>
#include <string>

using namespace std;

int n, k;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        string num = to_string(i);
        k -= num.length();
        if (k <= 0)
        {
            cout << num[num.length() - 1 + k] << '\n';
            return 0;
        }
    }
    cout<<"-1"<<'\n';
    return 0;
}