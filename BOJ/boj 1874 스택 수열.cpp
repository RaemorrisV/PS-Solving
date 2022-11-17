#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<char> ans;
stack<int> s;
bool visited[100001];
int idx = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        s.push(i);
        ans.push_back('+');
        if (s.top() == arr[idx])
        {
            while (!s.empty() && s.top() == arr[idx])
            {
                s.pop();
                ans.push_back('-');
                idx++;
            }
        }
    }
    if (!s.empty())
    {
        cout << "NO" << '\n';
    }
    else
    {
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << '\n';
        }
    }
    return 0;
}