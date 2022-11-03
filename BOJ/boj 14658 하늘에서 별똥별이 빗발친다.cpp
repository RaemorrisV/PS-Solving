#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, l, k; //열,행
vector<pair<int, int>> star;
int cnt = 0;
int MAX = 0;
int main()
{
    cin >> n >> m >> l >> k; //열 행  한변의 길이  수
    for (int i = 0; i < k; i++)
    {
        int s, e;
        cin >> s >> e; //행 열
        star.push_back({s, e});
    }
    sort(star.begin(), star.end());
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            for (int a = 0; a < k; a++)
            {
                if (star[i].first <= star[a].first && star[j].second <= star[a].second && star[i].first + l >= star[a].first && star[j].second + l >= star[a].second)
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