#include <iostream>
#include <string>
using namespace std;

int n;
string input;
string ans;
int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin>>input;
        if(i==0)
        {
          ans=input;
        }
        else
        {
            for(int j=0;j<input.length();j++)
            {
              if(ans[j]!=input[j])
              {
                ans[j]='?';
              }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}