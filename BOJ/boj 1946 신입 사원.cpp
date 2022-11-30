#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int t, n;
int MIN;
int ans = 1;
vector<pair<int, int>> score;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int s, e;
            cin >> s >> e;
            score.push_back({s, e});
        }
        sort(score.begin(), score.end());
        MIN = score[0].second;
        for (int i = 1; i < n; i++)
        {
            if (MIN > score[i].second)
            {
                ans++;
                MIN = score[i].second;
            }
        }
        cout << ans << '\n';
        ans = 1;
        score.clear();
    }
    return 0;
}