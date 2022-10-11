#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>
#include <cstring>
using namespace std;

int t, n, x, y;
vector<pair<int, int>> songdo;
bool visited[103];
pair<int, int> home;
pair<int, int> festival;
int check = 0;
int dis(pair<int, int> a, pair<int, int> b)
{
  return abs(a.first - b.first) + abs(a.second - b.second);
}
void dfs(pair<int, int> a)
{
  if (dis(a, festival) <= 1000)
  {
    check = 1;
    return;
  }
  for (int i = 0; i < songdo.size(); i++)
  {
    if (dis(a, songdo[i]) <= 1000 && visited[i + 1] == false)
    {
      visited[i + 1] = true;
      dfs(songdo[i]);
    }
  }
}
int main()
{
  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> n;
    cin >> x >> y;
    home.first = x;
    home.second = y; // 1번
    for (int j = 0; j < n; j++)
    {
      cin >> x >> y;
      songdo.push_back({x, y});
    }
    cin >> x >> y;
    // songdo.push_back({x, y});
    festival.first = x;
    festival.second = y;
    visited[0] = true;
    dfs(home);
    if (check == 1)
    {
      cout << "happy" << endl;
    }
    else
    {
      cout << "sad" << endl;
    }
    songdo.clear();
    check = 0;
    memset(visited, false, sizeof(visited));
  }
  return 0;
}