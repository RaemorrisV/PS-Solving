#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, input, b, c;
long long ans = 0;
vector<int> stu_cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        stu_cnt.push_back(input);
    }
    cin >> b >> c;
    ans = n;
    for (int i = 0; i < n; i++)
    {
        stu_cnt[i] -= b;
        if(stu_cnt[i]<0)stu_cnt[i]=0;
        ans += ceil(stu_cnt[i] / (double)c);
    }
    cout << ans << "\n";
    return 0;
}