#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, loc, height;
int ans = 0;
int MAX = -1;
int idx;
int MAX_R = -1;
int MAX_L = -1;
pair<int, int> max_height;
vector<pair<int, int>> pillar;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> loc >> height;
        pillar.push_back({loc, height});
        MAX = max(MAX, height);
        if (MAX == height)
        {
            max_height.first = loc;
            max_height.second = height;
        }
    }
    sort(pillar.begin(), pillar.end());
    for (int i = 0; i < n; i++)
    {
        if (pillar[i].first == max_height.first)
            idx = i;
    }
    ans += max_height.second;
    int s = idx;
    int e = idx;
    while (1)
    {
        // cout << s << " " << e << endl;
        int cur_e = e;
        int cur_s = s;
        if (e == n - 1 && s == 0)
            break;
        if (e != n - 1) //오른쪽
        {
            for (int i = cur_e + 1; i < n; i++)
            {
                MAX_R = max(MAX_R, pillar[i].second);
                if (MAX_R == pillar[i].second)
                {
                    e = i;
                }
            }
            ans += MAX_R * (pillar[e].first - pillar[cur_e].first);
            MAX_R = -1;
        }
        if (s != 0)
        {
            for (int i = 0; i < cur_s; i++)
            {
                MAX_L = max(MAX_L, pillar[i].second);
                if (MAX_L == pillar[i].second)
                {
                    s = i;
                }
            }
            ans += MAX_L * (pillar[cur_s].first - pillar[s].first);
            MAX_L = -1;
        }
    }
    cout << ans << endl;
    return 0;
}