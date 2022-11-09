#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> arr;
vector<int> ans;
vector<int> idx;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    arr.resize(n);
    idx.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ans.push_back(arr[0]);
    idx[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (ans.back() < arr[i])
        {
            ans.push_back(arr[i]);
            idx[i] = ans.size();
        }
        else
        {
            auto it = lower_bound(ans.begin(), ans.end(), arr[i]);
            *it = arr[i];
            idx[i] = it - ans.begin() + 1;
        }
    }
    cout << ans.size() << '\n';
    int cnt = ans.size();
    vector<int> prin;
    for (int i = n - 1; i >= 0; i--)
    {
        if (idx[i] == cnt)
        {
            prin.push_back(arr[i]);
            cnt--;
        }
    }
    for (int i = prin.size() - 1; i >= 0; i--)
    {
        cout << prin[i] << " ";
    }
    cout << '\n';
    return 0;
}