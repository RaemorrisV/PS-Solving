#include <iostream>
#include <queue>

using namespace std;

int s;
bool visited[1001][1001];
int cnt[1001][1001];
bool valide(int a)
{
    if (a >= 2 && a <= 1000)return true;
    return false;
}
void bfs(int k)
{
    queue<pair<int, int>> q;
    visited[k][0] = true;
    q.push({k, 0});
    while (!q.empty())
    {
        int cur = q.front().first;
        int cur_clip = q.front().second;
        q.pop();
        if (valide(cur - 1) && visited[cur - 1][cur_clip] == false) //-1
        {
            visited[cur - 1][cur_clip] = true;
            q.push({cur - 1, cur_clip});
            cnt[cur - 1][cur_clip] = cnt[cur][cur_clip] + 1;
            if (cur - 1 == s)
            {
                cout << cnt[s][cur_clip] << "\n";
                break;
            }
        }
        if (valide(cur + cur_clip) && cur_clip != 0 && visited[cur + cur_clip][cur_clip] == false) //붙여넣기
        {
            visited[cur + cur_clip][cur_clip] = true;
            q.push({cur + cur_clip, cur_clip});
            cnt[cur + cur_clip][cur_clip] = cnt[cur][cur_clip] + 1;
            if (cur + cur_clip == s)
            {
                cout << cnt[s][cur_clip] << "\n";
                break;
            }
        }
        if (visited[cur][cur] == false)
        {
            visited[cur][cur] = true;
            q.push({cur, cur}); //클립보드 저장
            cnt[cur][cur] = cnt[cur][cur_clip] + 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    bfs(1);
    return 0;
}