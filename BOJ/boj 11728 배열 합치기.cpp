#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, in;
vector<int> a;
vector<int> b;
vector<int> ans;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> in;
        a.push_back(in);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> in;
        b.push_back(in);
    }
    int s = 0; // a
    int e = 0; // b
    while (s != n && e != m)
    {
        if (a[s] >= b[e])
        {
            ans.push_back(b[e]);
            e++;
        }
        else
        {
            ans.push_back(a[s]);
            s++;
        }
    }
    if (s == n)
    {
        for (int i = e; i < m; i++)
        {
            ans.push_back(b[i]);
        }
    }
    else
    {
        for (int i = s; i < n; i++)
        {
            ans.push_back(a[i]);
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}