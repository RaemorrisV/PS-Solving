#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int f, s, g, u, d; // u d 두개의 버튼만 존재함
int dis[1000001];
int dir[2]; // 0인덱스는 U 1인덱스는 D
bool visited[2000001];
bool valid(int s)
{
  if (s >= 1 && s <= f)return true;
  return false;
}
void bfs(int start)
{
  queue<int> q;
  q.push(start);
  while (!q.empty())
  {
    int temp = q.front();
    q.pop();
    for (int i = 0; i < 2; i++)
    {
      if (valid(temp + dir[i]) && visited[temp + dir[i]] == false)
      {
        visited[temp + dir[i]] = true;
        dis[temp + dir[i]] = dis[temp] + 1;
        q.push(temp + dir[i]);
      }
    }
  }
}
int main()
{
  cin >> f >> s >> g >> u >> d;
  dir[0] = u;
  dir[1] = -d;
  fill(dis, dis + f + 1, INT_MAX);
  visited[s] = true;
  dis[s] = 0;
  bfs(s);
  if (dis[g] == INT_MAX)
  {
    cout << "use the stairs" << endl;
  }
  else
  {
    cout << dis[g] << endl;
  }
  return 0;
}