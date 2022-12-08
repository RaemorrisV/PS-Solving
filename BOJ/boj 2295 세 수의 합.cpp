#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<int> arr;
vector<int> store;
vector<int> sum;
vector<int> mi;
unordered_map<int, int> has;
int MAX = -1;
void dfs(int len, int s)
{
    if (len == 2)
    {
        int s = 0;
        int m = 0;
        s += arr[store[0]] + arr[store[1]];
        m += arr[store[1]] - arr[store[0]];
        sum.push_back(s);
        mi.push_back(m);
        if (has.find(m) == has.end())
        {
            has[m] = arr[store[1]];
        }
        else
        {
            if (has[m] < arr[store[1]])
            {
                has[m] = arr[store[1]];
            }
        }
        return;
    }
    for (int i = s; i < n; i++)
    {
        store.push_back(i);
        dfs(len + 1, i);
        store.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        arr.push_back(in);
    }
    for (int i = 0; i < n; i++)
    {
        store.push_back(i);
        dfs(1, i);
        store.pop_back();
    }
    sort(sum.begin(), sum.end());
    for (int i = 0; i < mi.size(); i++)
    {
        int idx = lower_bound(sum.begin(), sum.end(), mi[i]) - sum.begin();
        if (sum[idx] == mi[i])
        {
            MAX = max(MAX, has[mi[i]]);
        }
    }
    cout << MAX << '\n';
    return 0;
}