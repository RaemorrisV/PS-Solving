#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
char oper[4] = {'+', '-', '*', '/'};
int cnt[4];
vector<int> arr;
vector<char> ans;
int MAX = -1000000001;
int MIN = 1000000001;
int n;
int sum = 0;
void dfs(int s)
{
    ans.push_back(oper[s]);
    if (ans.size() == n - 1)
    {
        sum = arr[0];
        for (int i = 0; i < arr.size() - 1; i++)
        {
            if (ans[i] == '+')
            {
                sum += arr[i + 1];
            }
            else if (ans[i] == '-')
            {
                sum -= arr[i + 1];
            }
            else if (ans[i] == '*')
            {
                sum *= arr[i + 1];
            }
            else if (ans[i] == '/')
            {
                sum /= arr[i + 1];
            }
        }
        MAX = max(MAX, sum);
        MIN = min(MIN, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] > 0)
        {
            cnt[i]--;
            dfs(i);
            ans.pop_back();
            cnt[i]++;
        }
    }
}
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
    for (int i = 0; i < 4; i++)
    {
        cin >> cnt[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (cnt[i] > 0)
        {
            cnt[i]--;
            dfs(i);
            ans.pop_back();
            cnt[i]++;
        }
    }
    cout << MAX << '\n';
    cout << MIN << '\n';
    return 0;
}