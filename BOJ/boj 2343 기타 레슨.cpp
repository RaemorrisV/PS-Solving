#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
int s = 0;
int e = 0;
bool simulation(int num)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum > num)
        {
            sum = arr[i];
            cnt++;
        }
        else if (sum == num)
        {
            sum = 0;
            cnt++;
        }
    }
    if (sum > 0)
        cnt++;
     //cout << cnt << endl;
    return cnt <= m;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr.push_back(a);
        s = max(a, s);
        e += a;
    }
    while (s <= e)
    {
        int mid = (s + e) / 2;
        //cout << "cj " << s << " " << e << " " << mid << endl;
        if (simulation(mid))
        {
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
    }
    cout << e + 1 << '\n';
    return 0;
}