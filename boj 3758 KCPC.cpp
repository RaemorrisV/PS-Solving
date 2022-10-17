#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;
int temp[101][101];

struct info
{
    int Score; //문제에대한 점수
    int cnt;   //몇번 제출 했나
    int time;  //마지막 제출 시간
};
unordered_map<int, info> team; //아이디
bool compare(pair<int, info> a, pair<int, info> b)
{
    if (a.second.Score > b.second.Score)
        return true;
    else if (a.second.Score == b.second.Score)
    {
        if (a.second.cnt < b.second.cnt)
            return true;
        else if (a.second.cnt == b.second.cnt)
        {
            if (a.second.time < b.second.time)
                return true;
        }
    }
    return false;
}
int T, n, k, t, m;
int main()
{
    ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> n >> k >> t >> m; //팀의 수 문제 수 아이디 로그엔트리의 수
        for (int j = 0; j < m; j++)
        {
            int d, num, s;
            cin >> d >> num >> s;           // 아이디 문제번호 획득 점수
            if (team.find(d) != team.end()) // 이미 있다는거
            {
                temp[d][num] = max(temp[d][num], s); //아이디의 문제번호 점수
                team[d].cnt++;
                team[d].time = j;
            }
            else
            {
                temp[d][num] = s;
                team[d].cnt = 1;
                team[d].time = j;
            }
        }
        //총 점수를 계산해야됨
        for (int j = 1; j <= n; j++)
        {
            for (int p = 1; p <= k; p++)
            {
                team[j].Score += temp[j][p];
            }
        }
        vector<pair<int, info>> ans(team.begin(), team.end());
        sort(ans.begin(), ans.end(), compare);
        for (int j = 0; j < ans.size(); j++)
        {
            if (ans[j].first == t)
            {
                cout << j + 1 << '\n';
                break;
            }
        }
        ans.clear();
        team.clear();
        memset(temp, 0, sizeof(temp));
         //fill(&temp[0][0],&temp[n][k+1],0);
    }
    return 0;
}