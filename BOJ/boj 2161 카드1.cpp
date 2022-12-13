#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n;
deque<int> d;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        d.push_back(i);
    }
    while (!(d.size() == 1))
    {
        int out = d.front();
        ans.push_back(out);
        d.pop_front();
        d.push_back(d.front());
        d.pop_front();
    }
    ans.push_back(d.front());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}