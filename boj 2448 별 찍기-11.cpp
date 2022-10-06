#include<iostream>
#include<algorithm>
using namespace std;
char star[3072][6143];
int n;
void dfs(int deep,int row,int col)
{
   if(deep==3)
   {
      star[row][col]='*';
      star[row+1][col-1]='*';
      star[row+1][col+1]='*';
      for(int i=-2;i<=2;i++)//-2 -1 0 1 2 
      {
         star[row+2][col+i]='*';
      }
      return;
   }
   dfs(deep/2,row,col);
   dfs(deep/2,row+deep/2,col-(2*deep-1)/4-1);
   dfs(deep/2,row+deep/2,col+(2*deep-1)/4+1);
}
int main()
{
    cin>>n;
    fill(&star[0][0],&star[n-1][2*n-1],' ');
    dfs(n,0,(2*n-1)/2);
    for(int i=0;i<n;i++)
    {
      for(int j= 0;j<2*n-1;j++)
      {
         cout<<star[i][j];
      }
      cout<<endl;
    }
    return 0;
}