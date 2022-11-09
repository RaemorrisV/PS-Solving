#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> arr;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    ans.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans.back() < arr[i])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[idx] = arr[i];
        }
    }
    cout << ans.size() << '\n';
    return 0;
}