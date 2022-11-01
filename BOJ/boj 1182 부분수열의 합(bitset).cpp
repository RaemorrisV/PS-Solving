#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

vector<int> arr;
bitset<21> set;
int n, s;
int sum = 0;
int ans = 0;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    for (int i = 1; i < 1 << n; i++) // 총 31개에서..
    {
        for (int j = 0; j < n; j++)
        {
            if (i & 1 << j)
            {
                sum += arr[j];
            }
        }
        if (sum == s)ans++;
        sum = 0;
    }
     cout << ans << '\n';
    return 0;
}