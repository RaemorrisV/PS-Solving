#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> cost;
int n, m;
long long sum = 0;
int MAX = -11;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        cost.push_back(input);
        sum += input;
    }
    cin >> m;
    sort(cost.begin(), cost.end());
    if (sum <= m)
    {
        cout << cost[n - 1] << endl;
    }
    else
    {
        int s = 0;
        int e = cost[n - 1];
        sum = 0;
        while (s <= e)
        {
            sum = 0;
            int mid = (s + e) / 2;
            for (int i = 0; i < cost.size(); i++)
            {
                if (cost[i] > mid)
                {
                    sum += mid;
                }
                else
                {
                    sum += cost[i];
                }
            }
            if (m >= sum)
            {
                s = mid + 1;
                MAX = max(MAX, mid);
            }
            else
            {
                e = mid - 1;
            }
        }
        cout << MAX << endl;
    }
    return 0;
}