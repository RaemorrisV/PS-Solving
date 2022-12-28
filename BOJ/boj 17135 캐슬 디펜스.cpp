#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, d;
int map[16][16];
vector<int> archer;
vector<pair<int, int>> monster;
vector<pair<int, int>> temp;
bool attack[16][16];
int MAX = 0;
bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int simul()
{
    temp = monster;
    int sum = 0;
    while (!monster.empty())
    {
        //   cout << "사이즈 체크 " << monster.size() << endl;
        for (int j = 0; j < 3; j++)
        {
            int MIN = 1e9;
            for (int i = 0; i < monster.size(); i++) // 가까운 적 구하는
            {
                int dis = abs((n + 1) - monster[i].first) + abs(archer[j] - monster[i].second);
                if (dis <= d)
                {
                    MIN = min(MIN, dis);
                }
            }
            for (int i = 0; i < monster.size(); i++) // 가까운 적 구하는
            {
                int dis = abs((n + 1) - monster[i].first) + abs(archer[j] - monster[i].second);
                if (MIN == dis && attack[monster[i].first][monster[i].second] == false)
                {
                    attack[monster[i].first][monster[i].second] = true;
                    sum++;
                    break;
                }
                else if (MIN == dis && attack[monster[i].first][monster[i].second])
                {
                    break;
                }
            }
        }
        for (int i = monster.size() - 1; i >= 0; i--)
        {
            if (attack[monster[i].first][monster[i].second]) // 공격 받았으면
            {
                attack[monster[i].first][monster[i].second] = false;
                monster.erase(monster.begin() + i);
            }
            else
            {
                if (monster[i].first == n)
                {
                    monster.erase(monster.begin() + i);
                }
                else
                {
                    monster[i].first += 1;
                }
            }
        }
    }
    monster = temp;
    return sum;
}
void dfs(int s)
{
    if (archer.size() == 3)
    {
        MAX = max(simul(), MAX);
        return;
    }
    for (int i = s + 1; i <= m; i++)
    {
        archer.push_back(i);
        dfs(i);
        archer.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m >> d;          // 행, 열, 거리 제한
    for (int i = 1; i <= n; i++) // 행
    {
        for (int j = 1; j <= m; j++) // 열
        {
            cin >> map[i][j];
            if (map[i][j] == 1)
            {
                monster.push_back({i, j});
            }
        }
    }
    sort(monster.begin(), monster.end(), compare);
    for (int i = 1; i <= m - 2; i++)
    {
        archer.push_back(i);
        dfs(i);
        archer.pop_back();
    }
    cout << MAX << '\n';
    return 0;
}