#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> glass;
int s;
int e;
int input;
int MIN = 2000000001;
int val;
vector<int> ans(2);

int main()
{
   cin >> n;
   for (int i = 0; i < n; i++)
   {
      cin >> input;
      glass.push_back(input);
   }
   sort(glass.begin(), glass.end());
      s = 0;
      e = n - 1;
      while (s < e)
      {
         val = (glass[s] + glass[e]);
         if (MIN > abs(val))
         {
            MIN = abs(val);    
            ans[0] = glass[s];
            ans[1] = glass[e];
         }
         if (val >= 0)e--;
         else if (val < 0)s++;
      
   }
   sort(ans.begin(), ans.end());
   for (int i = 0; i < 2; i++)
   {
      cout << ans[i] << " ";
   }
   cout << endl;
   return 0;
}