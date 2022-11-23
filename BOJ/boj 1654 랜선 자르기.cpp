#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, k, input;
vector<int> arr;
int binary_search(int a, int b)
{
    long long s = a;
    long long e = b;
    long long mid = (s + e) / 2;
    while (s <= e)
    {
        int cnt = 0;
        for (int i = 0; i < k; i++)
        {
            cnt += arr[i] / mid;
        }
        if (cnt < n)
        {
            e = mid - 1;
            mid = (s + e) / 2;
        }
        else
        {
            s = mid + 1;
            mid = (s + e) / 2;
        }
    }
    return mid;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    cout << binary_search(1, arr[k - 1]) << '\n';
    return 0;
}