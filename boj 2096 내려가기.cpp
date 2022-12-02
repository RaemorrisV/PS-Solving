#include <iostream>
#include <algorithm>
using namespace std;

int MAX = -1;
int MIN = 100000000;
int temp[3][4];
int n;
int pre[4];
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s, e, c;
        cin >> s >> e >> c;
        pre[1] = temp[1][1];
        pre[2] = temp[1][2];
        pre[3] = temp[1][3];
        temp[1][1] = max(pre[1] + s, pre[2] + s);
        temp[1][2] = max({pre[1] + e, pre[2] + e, pre[3] + e});
        temp[1][3] = max(pre[2] + c, pre[3] + c);
        pre[1] = temp[2][1];
        pre[2] = temp[2][2];
        pre[3] = temp[2][3];
        temp[2][1] = min(pre[1] + s, pre[2] + s);
        temp[2][2] = min({pre[1] + e, pre[2] + e, pre[3] + e});
        temp[2][3] = min(pre[2] + c, pre[3] + c);
    }
    MAX = max({temp[1][1], temp[1][2], temp[1][3]});
    MIN = min({temp[2][1], temp[2][2], temp[2][3]});
    cout << MAX << " " << MIN << '\n';
    return 0;
}