#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
int dp[1000];
int MAX = 1;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        MAX = max(MAX, dp[i]);
    }
    cout << MAX << '\n';
}