#include <iostream>
#include <vector>
using namespace std;

int n, m;
int k;
bool know_truth[51];
int ans = 0;
vector<vector<int>> infomation(51);
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int in;
        cin >> in;
        know_truth[in] = true;
    }
    for (int i = 1; i <= m; i++) //여기서 초기화를 해주고
    {
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int in;
            cin >> in;
            infomation[i].push_back(in);
        }
    }
    for (int p = 0; p < m; p++)
    {
        for (int i = 1; i <= m; i++)
        {
            bool flag = false;
            for (int j = 0; j < infomation[i].size(); j++)
            {
                if (know_truth[infomation[i][j]])
                {
                    flag = true;
                }
            }
            if (flag)
            {
                for (int j = 0; j < infomation[i].size(); j++)
                {
                    know_truth[infomation[i][j]] = true;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        bool no_lie = false;
        for (int j = 0; j < infomation[i].size(); j++)
        {
            if (know_truth[infomation[i][j]])
            {
                no_lie = true;
            }
        }
        if (no_lie == false)
        {
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}