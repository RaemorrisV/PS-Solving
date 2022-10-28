#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct info
{
  int x;
  int y;
  int p;
  int id;
};
vector<pair<int, int>> ice;
vector<info> in_f;
int dx[4] = {-1, 1, 0, 0}; //상하좌우
int dy[4] = {0, 0, -1, 1};
int iceburg[300][300];
bool visited[300][300];
int r, c;
int ans = 0;
int cnt = 0;
bool valid(int s, int e)
{
  if (s < 0 && s >= r && e < 0 && e >= c)
    return false;
  return true;
}
void ing()
{
  int check = 0;
  for (int i = 0; i < ice.size(); i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (valid(ice[i].first + dx[j], ice[i].second + dy[j]) && iceburg[ice[i].first + dx[j]][ice[i].second + dy[j]] == 0)
      {
        check++;
      }
    }
    if (check > 0)
    {
      in_f.push_back({ice[i].first, ice[i].second, check, i});
    }
    check = 0;
  }
  for (int i = 0; i < in_f.size(); i++)
  {
    iceburg[in_f[i].x][in_f[i].y] -= in_f[i].p;
    if (iceburg[in_f[i].x][in_f[i].y] <= 0)
    {
      iceburg[in_f[i].x][in_f[i].y] = 0;
    }
  }
  in_f.clear();
  ice.clear();
}
void bfs(int row, int col)
{
  queue<pair<int, int>> q;
  visited[row][col] = true;
  q.push({row, col});
  while (!q.empty())
  {
    int s = q.front().first;  //행
    int e = q.front().second; //열
    q.pop();
    for (int i = 0; i < 4; i++)
    {
      if (valid(s + dx[i], e + dy[i]) && visited[s + dx[i]][e + dy[i]] == false && iceburg[s + dx[i]][e + dy[i]] != 0)
      {
        q.push({s + dx[i], e + dy[i]});
        visited[s + dx[i]][e + dy[i]] = true;
      }
    }
  }
  ans++;
}
int main()
{
  cin >> r >> c;
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < c; j++)
    {
      cin >> iceburg[i][j];
      if (iceburg[i][j] != 0)
      {
        ice.push_back({i, j});
      }
    }
  }
  while (ice.size() != 0)
  {
    cnt++;
    ing();
    for (int i = 0; i < r; i++)
    {
      for (int j = 0; j < c; j++)
      {
        if (iceburg[i][j] != 0)
        {
          ice.push_back({i, j});
        }
      }
    }
    for (int i = 0; i < ice.size(); i++)
    {
      if (visited[ice[i].first][ice[i].second] == false)
      {
        bfs(ice[i].first, ice[i].second);
      }
    }
    if (ans >= 2)
    {
      cout << cnt << endl;
      break;
    }
    ans = 0;
    memset(visited, false, sizeof(visited));
  }
  if (ice.size() == 0)
  {
    cout << "0" << endl;
  }
  return 0;
}