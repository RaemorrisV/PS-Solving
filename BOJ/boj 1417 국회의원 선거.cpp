#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
vector<pair<int, int>> vote;
int idx = 0;
int ans = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        vote.push_back({in, i + 1});
    }
    while (1)
    {
        sort(vote.begin(), vote.end());
        if (vote[n - 1].second == 1)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (vote[i].second == 1)
            {
                vote[i].first++;
                break;
            }
        }
        vote[n - 1].first--;
        ans++;
        /*
        for (int i = 0; i < n; i++)
        {
            cout << "debuging " << vote[i].second << " " << vote[i].first<<" ";
        }
        cout << '\n';
        */
    }

    cout << ans << '\n';
    return 0;
}