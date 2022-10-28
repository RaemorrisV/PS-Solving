#include <iostream>
using namespace std;
int row, col, n, m;
long long cnt = 0;
int main()
{
   cin >> row >> col >> n >> m; //세로줄 n 가로줄 m
   for (int i = 0; i < row; i += n + 1)
   {
      for (int j = 0; j < col; j += m + 1)
      {
         cnt++;
         // cout<<i<<" "<<j<<endl;
      }
   }
   cout << cnt << endl;
   return 0;
}