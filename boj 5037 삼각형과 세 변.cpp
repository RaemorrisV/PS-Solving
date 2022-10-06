#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> triangle;
int main()
{

   while (1)
   {
      int a, b, c; //세변
      cin >> a >> b >> c;
      if (a == 0 && b == 0 && c == 0)
         break;
      triangle.push_back(a);
      triangle.push_back(b);
      triangle.push_back(c);
      sort(triangle.begin(), triangle.end());
      if (triangle[2] >= triangle[0] + triangle[1])
      {
         cout << "Invalid" << endl;
      }
      else if (a == b && b == c)
      {
         cout << "Equilateral" << endl;
      }
      else if (a == b || b == c || a == c)
      {
         cout << "Isosceles" << endl;
      }
      else
      {
         cout << "Scalene" << endl;
      }
      triangle.clear();
   }
   return 0;
}