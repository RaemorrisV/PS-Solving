#include <iostream>
#include <vector>
using namespace std;
long long e = 1e18;
long long s = 0;
int n, m;
vector<int> t;
bool check(long long num)
{
    long long cnt = 0;
    for (int i = 0; i < t.size(); i++)
    {
        cnt += (num / t[i]);
        if (cnt >= m)return true; //오버플로우 주의!!
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        t.push_back(in);
    }
    while (s + 1 < e)
    {
        long long mid = (s + e) / 2;
        if (check(mid))
        {
            e = mid;
        }
        else
        {
            s = mid;
        }
    }
    cout << e << '\n';
    return 0;
}