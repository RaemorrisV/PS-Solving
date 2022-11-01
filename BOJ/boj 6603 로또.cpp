#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, input;
vector<int> arr;
vector<int> out;
void dfs(int s)
{
    out.push_back(arr[s]);
    if (out.size() == 6)
    {
        for (int i = 0; i < 6; i++)
        {
            cout << out[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = s + 1; i < k; i++)
    {
        dfs(i);
        out.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0; i < k; i++)
        {
            cin >> input;
            arr.push_back(input);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++)
        {
            dfs(i);
            out.pop_back();
        }
        arr.clear();
        cout << "\n";
    }
    return 0;
}