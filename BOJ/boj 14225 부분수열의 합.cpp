#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> arr;
vector<int> permu;
vector<int> sumarr;
bool flag;
void dfs(int s)
{
    permu.push_back(arr[s]);
    int sum = 0;
    for (int i = 0; i < permu.size(); i++)
    {
        sum += permu[i];
    }
    sumarr.push_back(sum);
    for (int i = s + 1; i < n; i++)
    {
        dfs(i);
        permu.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        dfs(i);
        permu.pop_back();
    }
    sort(sumarr.begin(), sumarr.end());
    auto r = unique(sumarr.begin(), sumarr.end());
    int start = 1;
    for (auto it = sumarr.begin(); it != r; it++)
    {
        if (*it == start)
        {
            start++;
        }
        else if (*it != start)
        {
            cout << start << '\n';
            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        cout << *(r - 1) + 1 << '\n';
    }
    return 0;
}