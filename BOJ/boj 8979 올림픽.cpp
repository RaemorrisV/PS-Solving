#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct info
{
  int c;
  int g;
  int s;
  int b;
};
bool compare(info a, info ff)
{
  if (a.g > ff.g)
    return true;
  else if (a.g == ff.g)
  {
    if (a.s > ff.s)
      return true;
    else if (a.s == ff.s)
    {
      if (a.b > ff.b)
        return true;
    }
  }
  return false;
}
int n, k;
int cnt = 0;
int idx;
vector<info> country;
int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; i++)
  {
    int a, a1, a2, a3;
    cin >> a >> a1 >> a2 >> a3;
    country.push_back({a, a1, a2, a3});
  }
  sort(country.begin(), country.end(), compare);
  for (int i = 0; i < n; i++)
  {
    if (country[i].c == k)
    {
      idx = i;
      //cout << "출력" << i << endl;
      for (int j = 0; j <= i; j++)
      {
        if (country[j].g == country[i].g && country[j].s == country[i].s && country[j].b == country[i].b)
        {
          cnt++;
        }
      }
    }
  }
  if (cnt == 0)
  {
    cout << idx + 1 << endl;
  }
  else
  {
    cout << idx + 2 - cnt << endl;
  }
  return 0;
}