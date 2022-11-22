#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int n, input;
stack<int> s;
vector<int> ans;
int MAX;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        s.push(input);
    }
    ans.push_back(s.top());
    MAX = s.top();
    for (int i = 0; i < n - 1; i++)
    {
        int temp = s.top();
        s.pop();
        if (temp > s.top())
        {
            ans.push_back(temp);
        }
        else if (s.top() >= MAX)
        {
            ans.push_back(-1);
            MAX = s.top();
        }
        else if (temp <= s.top())
        {
            int idx = i;
            while (1)
            {
                if (s.top() < ans[idx])
                {
                    ans.push_back(ans[idx]);
                    break;
                }
                else
                {
                    idx--;
                }
            }
        }
    }
    ans[0] = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}