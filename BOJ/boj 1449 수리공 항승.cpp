#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
vector<int> leak;
int ans = 0;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        leak.push_back(p);
    }
    sort(leak.begin(), leak.end());
    for (int i = 0; i < n; i++)
    {
        int first = leak[i];
        for (int j = i; j < n; j++)
        {
            if (leak[j] == first) //
            {
                ans++;
            }
            else if (leak[j] >= first + l)
            {
                i = j - 1;
                break;
            }
            if(j==n-1)
            {
                i=n;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}