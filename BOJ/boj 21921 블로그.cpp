#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, x;
int sum = 0;
int MAX = -11;
int cnt = 0;
vector<int> blog;
int main()
{
  cin >> n >> x;
  for (int i = 0; i < n; i++)
  {
    int input;
    cin >> input;
    blog.push_back(input);
  }
  int s = 0;
  int e = 0; // x는 방문자수
  sum = blog[s];
  while (e != n)
  {
    if (e - s + 1 < x) //낮을때
    {
      e++;
      sum += blog[e];
    }
    else if (e - s + 1 == x) //높을때
    {
      MAX = max(MAX, sum);
      sum -= blog[s];
      s++;
    }
  }
  s = 0;
  e = 0;
  sum = blog[s];
  while (e != n)
  {
    if (e - s + 1 < x) //낮을때
    {
      e++;
      sum += blog[e];
    }
    else if (e - s + 1 == x) //높을때
    {
      if (sum == MAX)
        cnt++;
      sum -= blog[s];
      s++;
    }
  }
  if (MAX == 0)
  {
    cout << "SAD" << endl;
  }
  else
  {
    cout << MAX << endl;
    cout << cnt << endl;
  }

  return 0;
}