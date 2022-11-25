#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

int n;
unordered_map<int, int> info;
vector<int> arr;
vector<int> ans;
stack<int> s;
int MAX;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
        info[input]++;
    }
    ans.push_back(-1);
    s.push(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (info[s.top()] > info[arr[i]]) //그냥 들어갈수 있는 경우
        {
            ans.push_back(s.top());
            s.push(arr[i]);
        }
        else
        {
            while (!s.empty())
            {
                if (info[s.top()] <= info[arr[i]])
                {
                    s.pop();
                }
                else
                {
                    ans.push_back(s.top());
                    s.push(arr[i]);
                    break;
                }
            }
            if (s.empty())
            {
                s.push(arr[i]);
                ans.push_back(-1);
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}