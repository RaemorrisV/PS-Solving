#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int sum = 0;
int MAX = 0;
vector<int> arr;
vector<int> mix;
bool visited[8];
void dfs(int s)
{
    mix.push_back(arr[s]);
    if (mix.size() == n)
    {
        for (int i = 0; i < n - 1; i++)
        {
            sum += abs(mix[i] - mix[i + 1]);
        }
        MAX = max(MAX, sum);
        sum = 0;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            visited[i] = true;
            dfs(i);
            mix.pop_back();
            visited[i] = false;
        }
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
    for (int i = 0; i < n; i++)
    {
        visited[i] = true;
        dfs(i);
        mix.pop_back();
        visited[i] = false;
    }
    cout << MAX << '\n';
    return 0;
}