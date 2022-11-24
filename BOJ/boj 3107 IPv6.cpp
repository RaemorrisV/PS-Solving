#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string ipv6;
vector<int> idx;
int a_idx;
int cnt = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> ipv6;
    ipv6 = ':' + ipv6 + ':';
    for (int i = 0; i < ipv6.length(); i++)
    {
        if (ipv6[i] == ':')
        {
            idx.push_back(i);
        }
    }
    for (int i = 0; i < idx.size() - 1; i++)
    {
        if (i >= 1 && i <= idx.size() - 3 && idx[i + 1] - idx[i] == 1)
        {
            a_idx = idx[i];
        }
        else
        {
            int size = 4 - (idx[i + 1] - idx[i] - 1);
            for (int j = 1; j <= 4 - (idx[i + 1] - idx[i] - 1); j++)
            {
                ipv6.insert(idx[i] + 1, "0");
            }
            for (int j = i + 1; j < idx.size(); j++)
            {
                idx[j] += size;
            }
            cnt++;
        }
    }
    for (int i = 0; i < 8 - cnt; i++)
    {
        if (i >= 1) 
        {
            ipv6.insert(a_idx + 1, ":0000");
            a_idx += 5;
        }
        else
        {
            ipv6.insert(a_idx + 1, "0000");
            a_idx += 4;
        }
    }
    for (int i = 1; i <= ipv6.length() - 2; i++)
    {
        if(ipv6[i+1]==':'&&ipv6[i]==':')continue;
        cout << ipv6[i];
    }
    cout << '\n';
    return 0;
}