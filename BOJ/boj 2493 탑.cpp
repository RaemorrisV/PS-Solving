#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, input;
vector<pair<int, int>> Stack;
vector<int> ans;
int MAX = 0;
int idx;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    cin >> input;
    ans.push_back(0);
    Stack.push_back({input, 1});
    for (int i = 1; i < n; i++)
    {
        cin >> input;
        if (Stack.back().first >= input) //바로앞에있다면
        {
            ans.push_back(Stack.back().second);
            Stack.push_back({input, i + 1});
        }
        else if (Stack.back().first < input)
        {
            while (!Stack.empty())
            {
                Stack.pop_back();
                if (Stack.back().first >= input)
                {
                    ans.push_back(Stack.back().second);
                    Stack.push_back({input, i + 1});
                    break;
                }
            }
            if (Stack.empty())
            {
                ans.push_back(0);
                Stack.push_back({input, i + 1});
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}