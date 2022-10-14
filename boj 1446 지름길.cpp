//솔직히 이 문제는 다익스트라 아니면 완전탐색 만 떠오르지 dp라는 생각은 안할 것 같음
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#define INF INT_MAX
using namespace std;
int MIN = INF;
int n, d;
struct info
{
  int s;
  int e;
  int len;
};
int cnt = 0;
vector<info> road;
void dfs(int start)
{
  if (start == d)
  {
    MIN = min(MIN, cnt);
    return;
  }
  for (int i = 0; i < road.size(); i++)
  {
    if (road[i].s >= start)
    {
      cnt += road[i].s - start + road[i].len;
      dfs(road[i].e);
      cnt -= road[i].s - start + road[i].len;
    }
  }
  cnt += d - start;
  dfs(d);
  cnt -= d - start;
}
int main()
{
  cin >> n >> d;
  for (int i = 0; i < n; i++)
  {
    int in, in1, in2;
    cin >> in >> in1 >> in2;
    if (in < d && in1 <= d)
    {
      road.push_back({in, in1, in2});
    }
  }
  dfs(0);
  cout << MIN << endl;
  return 0;
}