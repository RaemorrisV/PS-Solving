#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, k;
int cnt = 0;
queue<int> q;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    while (!q.empty())
    {
        if (cnt == k - 1)
        {
            ans.push_back(q.front());
            q.pop();
            cnt = 0;
        }
        else
        {
            cnt++;
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    cout << "<";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size() - 1] << ">" << '\n';
    return 0;
}