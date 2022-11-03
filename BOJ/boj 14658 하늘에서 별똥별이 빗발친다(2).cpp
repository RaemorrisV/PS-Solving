#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, l, k; //열,행
vector<pair<int, int>> star;
int cnt = 0;
int MAX = 0;
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> l >> k; //열 행  한변의 길이  수
    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e; //행 열
        star.push_back({s, e});
    }
    sort(star.begin(), star.end(), compare);
    for (int i = 0; i < k; i++)
    {
        int x = star[i].first;
        int y = star[i].second;
        for (int j = x - l; j <= x; j++)
        {
            for (int a = 0; a < k; a++)
            {
                if (j <= star[a].first && y <= star[a].second && j + l >= star[a].first && y + l >= star[a].second)
                {
                    cnt++;
                }
            }
            MAX = max(MAX, cnt);
            cnt = 0;
        }
    }
    cout << k - MAX << '\n';
    return 0;
}
