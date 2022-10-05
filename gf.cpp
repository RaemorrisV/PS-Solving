#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
struct ans{
   int sum;
   int idx_s;
   int idx_e;
};
bool compare(const ans& a,const ans& b)
{
    return a.sum<b.sum;
}
int n;
vector<int>glass;
vector<ans>ANS;//total 값과 start값과 end 값을 집어넣는 배열
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
      int a;
      cin>>a;
      glass.push_back(a);
    }
    sort(glass.begin(),glass.end());
    int start=0;
    int end=n-1;
    while(start<end)
    {
      ans q;
      q.sum=glass[start]+glass[end];
      q.idx_s=glass[start];
      q.idx_e=glass[end];
      ANS.push_back(q);      
      if(q.sum>=0)
      {
         if(q.sum==0)
        {
            cout<<q.idx_s<<" "<<q.idx_e<<endl;
            return 0;
        }
        end--;
      }
      else if(q.sum<0)
      {
        start++;
      }
    }
    for(int i=0;i<ANS.size();i++)
    {
        ANS[i].sum=abs(ANS[i].sum);
    }
    sort(ANS.begin(),ANS.end(),compare);
    ans temp={0,0,0};
    int idx=lower_bound(ANS.begin(),ANS.end(),temp,compare)-ANS.begin();

   /* for(int i=0;i<ANS.size();i++)
    {
        cout<<ANS[i].sum<<" "<<ANS[i].idx_s<<" "<<ANS[i].idx_e<< endl;
    }
    //cout<<idx<<endl;
    */
     cout<<ANS[idx].idx_s<<" "<<ANS[idx].idx_e<<endl;
    return 0; 
}