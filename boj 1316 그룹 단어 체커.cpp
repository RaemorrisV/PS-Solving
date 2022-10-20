#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
int n;
int ans = 0;
string input;
vector<int> check(27);
int main()
{
    cin >> n;
    ans = n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        fill(check.begin(), check.end(), -1);
        for (int j = 0; j < input.length(); j++)
        {
            if (check[input[j] - 'a'] == -1)
            {
                check[input[j] - 'a'] = j;
            }
            else
            {
                if ((j - check[input[j] - 'a']) > 1)
                {
                    ans--;
                    break;
                }
                check[input[j] - 'a'] = j;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
