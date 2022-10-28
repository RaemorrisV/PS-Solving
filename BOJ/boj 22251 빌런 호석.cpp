#include <iostream>
#include <string>
using namespace std;
int N, K, P;
string X;
int ans = 0;
bool LED[10][7] = {
    1, 1, 0, 1, 1, 1, 1, // 0
    0, 1, 0, 1, 0, 0, 0, // 1
    1, 1, 1, 0, 1, 1, 0, // 2
    1, 1, 1, 1, 1, 0, 0, // 3
    0, 1, 1, 1, 0, 0, 1, // 4
    1, 0, 1, 1, 1, 0, 1, // 5
    1, 0, 1, 1, 1, 1, 1, // 6
    1, 1, 0, 1, 0, 0, 0, // 7
    1, 1, 1, 1, 1, 1, 1, // 8
    1, 1, 1, 1, 1, 0, 1, // 9
};
bool possible(string change)
{
    int num_change = 0;
    for (int i = 0; i < K; i++)
    {
        if (X[i] != change[i]) //다르다면...
        {
            int cnt = 0;
            for (int j = 0; j < 7; j++)
            {
                if (LED[X[i] - '0'][j] != LED[change[i] - '0'][j])
                {
                    cnt++;
                }
            }
            num_change += cnt;
        }
    }
    if (num_change > P)return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> P >> X;
    int len = X.length();
    for (int i = 0; i < K - len; i++)
    {
        X = '0' + X;
    }
    for (int i = 1; i <= N; i++)
    {
        string num = to_string(i);
        int len = num.length();
        for (int j = 0; j < K - len; j++)
        {
            num = '0' + num;
        }
        if (num != X)
        {
            if (possible(num))ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}