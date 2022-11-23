#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
vector<int> b;
int sum = 0;
bool compare(int v, int y)
{
    if (v > y)return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        a.push_back(q);
    }
    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;
        b.push_back(q);
    }
    sort(a.begin(), a.end(), compare);
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++)
    {
        sum += a[i] * b[i];
    }
    cout << sum << '\n';
    return 0;
}