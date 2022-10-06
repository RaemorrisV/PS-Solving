#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> glass;
int choice_one;
int s;
int e;
int input;
long long MIN = 3000000001;
long long val;
vector<int> ans(3);

int main()
{
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> input;
      glass.push_back(input);
   }
   sort(glass.begin(), glass.end());
   for (int i = 0; i < n; i++)
   {
      s = 0;
      e = n - 1;
      while (s < e)
      {
         if (s == i)
         {
            s++;
            continue;
         }
         if (e == i)
         {
            e--;
            continue;
         }
         val = (glass[i] + glass[s] + glass[e]);
         if (MIN > abs(val))
         {
            MIN = abs(val);
            ans[0] = glass[i];
            ans[1] = glass[s];
            ans[2] = glass[e];
         }
         if (val >= 0)e--;
         else if (val < 0)s++;
      }
   }
   sort(ans.begin(), ans.end());
   for (int i = 0; i < 3; i++)
   {
      cout << ans[i] << " ";
   }
   cout << endl;
   return 0;
}