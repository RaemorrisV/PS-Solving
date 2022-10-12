#include <iostream>
#include <bitset>
#include <string>
using namespace std;
bitset<21> set;
int m;
string str;
int x;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        if (str == "add")
        {
            cin >> x;
            if(set[x]==0)set[x]=1;
            continue;
        }
        else if (str == "remove")
        {
            cin>>x;
            if(set[x])set[x]=0;
            continue;
        }
        else if (str == "check")
        {
            cin >> x;
            if(set[x])cout<<"1"<<'\n';
            else cout<<"0"<<'\n';
            continue;
        }
        else if (str == "toggle")
        {
            cin>>x;
            if(set[x])set[x]=0;
            else set[x]=1;
            continue;
        }
        else if (str == "all")
        {
            set.set();
            continue;
        }
        else if (str == "empty")
        {
            set.reset();
            continue;
        }
    }
    return 0;
}