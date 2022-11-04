#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int dx[4] = {-1, 1, 0, 0}; //상 하 좌 우
int dy[4] = {0, 0, -1, 1};
int R, C;
int t;
int room[51][51];
int sum_value[51][51];
vector<pair<int, int>> cleaner;
vector<pair<int, int>> dust_idx;
bool valide(int r, int c)
{
    if (r >= 1 && r <= R && c >= 1 && c <= C)
        return true;
    return false;
}
int totalsum()
{
    int total = 0;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (room[i][j] != 0 && room[i][j] != -1)
            {
                total += room[i][j];
            }
        }
    }
    return total;
}
void setting()
{
    dust_idx.clear();
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            if (room[i][j] != 0 && room[i][j] != -1)
            {
                dust_idx.push_back({i, j});
            }
        }
    }
}
void spread() //확산을 담당하는 함수
{
    int dust_num = dust_idx.size();
    for (int i = 0; i < dust_num; i++)
    {
        int dir_area = 0;
        for (int j = 0; j < 4; j++)
        {
            int nx = dust_idx[i].first + dx[j];
            int ny = dust_idx[i].second + dy[j];
            if (valide(nx, ny) && room[nx][ny] != -1)
            {
                dir_area++;
                sum_value[nx][ny] += room[dust_idx[i].first][dust_idx[i].second] / 5;
            }
        }
        room[dust_idx[i].first][dust_idx[i].second] -= (room[dust_idx[i].first][dust_idx[i].second] / 5) * dir_area;
    }
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            room[i][j] += sum_value[i][j];
        }
    }
    fill(&sum_value[0][0], &sum_value[R][C + 1], 0);
}
void cycle() //위는 반시계방향 아래는 시계방향으로 순환을 담당하는 함수
{
    for (int i = cleaner[0].first - 1; i >= 2; i--) //반시계 부터 시행
        room[i][1] = room[i - 1][1];
    for (int i = 1; i <= C - 1; i++) //반시계 부터 시행
        room[1][i] = room[1][i + 1];
    for (int i = 1; i <= cleaner[0].first - 1; i++) //반시계 부터 시행
        room[i][C] = room[i + 1][C];
    for (int i = C; i > 2; i--) //반시계 부터 시행
        room[cleaner[0].first][i] = room[cleaner[0].first][i - 1];
    room[cleaner[0].first][2] = 0;
    // 여기 부터 아랫 부분 구현
    for (int i = cleaner[1].first + 1; i <= R - 1; i++)
        room[i][1] = room[i + 1][1];
    for (int i = 1; i <= C - 1; i++)
        room[R][i] = room[R][i + 1];
    for (int i = R; i >= cleaner[1].first + 1; i--)
        room[i][C] = room[i - 1][C];
    for (int i = C; i > 2; i--)
        room[cleaner[1].first][i] = room[cleaner[1].first][i - 1];
    room[cleaner[1].first][2] = 0;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> R >> C >> t;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> room[i][j];
            if (room[i][j] == -1)
            {
                cleaner.push_back({i, j});
            }
            else if (room[i][j] != 0)
            {
                dust_idx.push_back({i, j});
            }
        }
    }
    for (int i = 0; i < t; i++)
    {
        spread();
        cycle();
        setting();
    }
    cout << totalsum() << '\n';
    return 0;
}