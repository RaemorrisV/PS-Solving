#include <iostream>
#include <vector>

using namespace std;

long long n, r, c;
long long sum = 0;
vector<pair<long long, long long>> matrix;
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> r >> c;
        matrix.push_back({r, c});
    }
    for (int i = n - 1; i > 0; i--)
    {
        sum += (long long)(matrix[i - 1].first * matrix[i].first * matrix[n - 1].second);
    }
    cout << sum << '\n';
    return 0;
}