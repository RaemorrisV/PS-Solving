#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<int> bisket_len;
int check(int mid)
{
    int cnt = 0;
    for (int i = 0; i < bisket_len.size(); i++)
    {
        cnt += bisket_len[i] / mid;
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n; // 조카의 수 과자의 수
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        bisket_len.push_back(in);
    }
    int s = 1;
    int e = 1000000000;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (check(mid) >= m)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}