#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
vector<int> arr;
int cnt[200001];
int MAX = -1;
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    int s = 0;
    int e = 0;
    cnt[arr[e]]++;
    while (e != n)
    {
        if (cnt[arr[e]] <= k)
        {
            MAX = max(MAX, e - s + 1);
            e++;
            cnt[arr[e]]++;
        }
        else
        {
            cnt[arr[s]]--;
            s++;
        }
    }
    cout << MAX << endl;
    return 0;
}