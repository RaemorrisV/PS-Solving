#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> belt;
int n, d, k, c;
int cnt[3001];
int MAX = -1313;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> d >> k >> c;
  cnt[c]++;
  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    belt.push_back(input);
  }
  int num = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < k; j++)
    {
      if (i + j >= n) //넘을경우에
      {
        if (cnt[belt[i + j - n]] == 0)
        {
          cnt[belt[i + j - n]]++;
          num++;
        }
        else
        {
          cnt[belt[i + j - n]]++;
        }
      }
      else
      {
        if (cnt[belt[i + j]] == 0)
        {
          cnt[belt[i + j]]++;
          num++;
        }
        else
        {
          cnt[belt[i + j]]++;
        }
      }
    }
    MAX = max(MAX, num);
    num = 1;
    memset(cnt, 0, sizeof(cnt));
    cnt[c]++;
  }
  cout << MAX << endl;
  return 0;
}