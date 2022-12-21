#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, h;
vector<int> top;
vector<int> bottom;
vector<int> ans;
int MIN = 1e9;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
    {
        int in;
        cin >> in;
        if (i % 2 == 0) // 짝수는 종유석
        {
            top.push_back(in);
        }
        else // 석순
        {
            bottom.push_back(in);
        }
    }
    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());
    int cnt = 0;
    for (int i = 1; i <= h; i++)
    {
        int idx = lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin();
        cnt += n / 2 - idx;
        idx = lower_bound(top.begin(), top.end(), h - i + 1) - top.begin();
        cnt += n / 2 - idx;
        MIN = min(MIN, cnt);
        ans.push_back(cnt);
        cnt = 0;
    }
    int counting = 0;
    for (int i = 0; i < h; i++)
    {
        if (ans[i] == MIN)counting++;
    }
    cout << MIN << " " << counting << '\n';
    return 0;
}