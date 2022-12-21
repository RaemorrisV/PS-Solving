#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, l;
vector<int> rest_loca;
int check(int mid)
{
    int cnt = 0;
    for (int i = 0; i < rest_loca.size() - 1; i++)
    {
        cnt += (rest_loca[i + 1] - rest_loca[i] - 1) / mid;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> l;
    rest_loca.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        rest_loca.push_back(in);
    }
    rest_loca.push_back(l);
    sort(rest_loca.begin(), rest_loca.end());
    int s = 1;
    int e = l - 1;
    int ans;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (check(mid) <= m)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}